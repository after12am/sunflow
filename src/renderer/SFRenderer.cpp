//
//  SFRenderer.cpp
//  quickExample
//
//  Created by Okami Satoshi on 12/04/28.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "SFRenderer.h"
#include <iostream.h>
#include <sstream>
#include <GLUT/GLUT.h>

using namespace sf;


string SFRenderer::bid() {
	stringstream ss;
	// 'b' means 'block'
	ss << "b" << (blocks.size() + 1);
	return ss.str();
}

void SFRenderer::flush(const string type) {
	
	for (int i = 0; i < blocks.size(); i++) {
		
		if (blocks[i]->type == type) {
			blocks[i]->flush(bufferStream);
		}
	}
}

int SFRenderer::flush() {
	
	flush("image");
	flush("camera");
	flush("gi");
	flush("shader");
	
	BoxObjectBlock boxScheme;
	boxScheme.flush(bufferStream);
	
	flush("generic-mesh");
	flush("object");
	flush("instance");
	
#ifdef DEBUG
	bufferStream.dump();
#endif
	
	bufferStream.save();
	return 0;
}

void SFRenderer::clear() {
	
	string deleteList[] = {"generic-mesh", "object", "instance", "light", "shader"};
	vector<BaseBlock*> _blocks;
	
	for (int i = 0; i < blocks.size(); i++) {
		
		bool nodelete = true;
		
		for (int j = 0; j < sizeof(deleteList) / sizeof(string); j++) {
			
			if (blocks[i]->type == deleteList[j]) {
				delete blocks[i];
				nodelete = false;
				break;
			}
		}
		
		if (nodelete) {
			_blocks.push_back(blocks[i]);
		}
	}
	
	blocks.swap(_blocks);
}


void SFRenderer::render() {
	
	// save output.sc
	flush();
	
	// execute render command
	stringstream options;
	
	if (commandOption.output != "") {
		options << " -o " << commandOption.output << " ";
	}
	
	if (commandOption.nogui) {
		options << " -nogui ";
	}
	
	if (commandOption.ipr) {
		options << " -ipr ";
	}
	
	stringstream ss;
	ss << "cd " << SUNFLOW_FILE_PATH << ";";
	ss << "./" << SUNFLOW_COMMAND;
	ss << options.str();
	ss << filePath();
	
#ifdef DEBUG
	cout << "[INFO] execute " << ss.str() << endl;
#endif
	
	string command = ss.str();
	
	if (system(command.c_str()) != 0) {
		cout << "[ERROR] sunflow render command error has occured." << endl;
	}
}

void SFRenderer::smooth(const int min, const int max) {
	ImageBlock* image = getImagePtr();
	image->aaMin = min;
	image->aaMax = max;
}

BaseBlock* SFRenderer::getPtr(string type) {
	
	for (int i = 0; i < blocks.size(); i++) {
		
		if (blocks[i]->type == type) {
			return blocks[i];
		}
	}
	
	return 0;
}

ImageBlock* SFRenderer::getImagePtr() {
	return dynamic_cast<ImageBlock*>(getPtr("image"));
}

CameraBlock* SFRenderer::getCameraPtr() {
	return dynamic_cast<CameraBlock*>(getPtr("camera"));
}

GIBlock* SFRenderer::getGIPtr() {
	return dynamic_cast<GIBlock*>(getPtr("gi"));
}

vector<ShaderBlock*> SFRenderer::getShaders() {
	
	vector<ShaderBlock*> shaders;
	
	for (int i = 0; i < blocks.size(); i++) {
		
		if (blocks[i]->type == "shader") {
			
			ShaderBlock* shader = dynamic_cast<ShaderBlock*>(blocks[i]);
			shaders.push_back(shader);
		}
	}
	return shaders;
}

string SFRenderer::filePath() {
	return bufferStream.getPath();
}

void SFRenderer::setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect) {
	
	PinholeCameraBlock* camera = dynamic_cast<PinholeCameraBlock*>(getCameraPtr());
	
	if (camera) {
		camera->eye = eye;
		camera->target = target;
		camera->up = up;
		camera->fov = fov;
		camera->aspect = aspect;
	} else {
		blocks.push_back(new PinholeCameraBlock(eye, target, up, fov, aspect));
	}
}

void SFRenderer::setImageResolution(int width, int height) {
	
	ImageBlock* image = getImagePtr();
	image->resolution = vec2f(width, height);
}

void SFRenderer::setAmboccBright(const Color bright) {
	
	AmbientOcclusionBlock* ambocc = dynamic_cast<AmbientOcclusionBlock*>(getGIPtr());
	
	if (ambocc) {
		ambocc->bright = bright;
	}
}

void SFRenderer::setAmboccDark(const Color dark) {
	
	AmbientOcclusionBlock* ambocc = dynamic_cast<AmbientOcclusionBlock*>(getGIPtr());
	
	if (ambocc) {
		ambocc->dark = dark;
	}
}

void SFRenderer::setAmbocc(const Color bright, const Color dark, const int samples, const float maxdist, const string colorSpace) {
	
	AmbientOcclusionBlock* ambocc = dynamic_cast<AmbientOcclusionBlock*>(getGIPtr());
	
	if (ambocc) {
		ambocc->bright = bright;
		ambocc->dark = dark;
		ambocc->samples = samples;
		ambocc->maxdist = maxdist;
		ambocc->colorSpace = colorSpace;
	} else {
		blocks.push_back(new AmbientOcclusionBlock(bright, dark, samples, maxdist, colorSpace));
	}
}

void SFRenderer::setPointLight(const vec3f _position, const Color _color, const float _power, const string _colorSpace) {
	blocks.push_back(new PointLightBlock(_position, _color, _power, _colorSpace));
}

void SFRenderer::setColor(const float r, const float g, const float b, const float a) {
	
	// search shader
	vector<ShaderBlock*> shaders = getShaders();
	for (int i = 0; i < shaders.size(); i++) {
		
		Color c = shaders[i]->getColor();
		
		if (c.r == r && c.g == g && c.b == b && c.a == a) {
			// set current shader
			currShader = dynamic_cast<ShaderBlock*>(shaders[i]);
			return;
		}
	}
	
	DiffuseShader* shader = new DiffuseShader(bid(), Color(r, g, b, a), COLORSPACE_SRGB_NONLINEAR);
	blocks.push_back(shader);
	
	// set current shader
	currShader = dynamic_cast<ShaderBlock*>(shader);
}

void SFRenderer::sphere() {
	
	matrix4x4 m;
	glGetFloatv(GL_MODELVIEW_MATRIX, m.getPtr());
	
	SphereObjectBlock* sphere = new SphereObjectBlock();
	sphere->name = bid();
	sphere->m = m;
	
	if (currShader) {
		sphere->shader = currShader->name;
	}
	
	blocks.push_back(sphere);
}

void SFRenderer::box() {
	
	matrix4x4 m;
	glGetFloatv(GL_MODELVIEW_MATRIX, m.getPtr());
	
	BoxInstanceBlock* box = new BoxInstanceBlock();
	box->name = bid();
	box->m = m;
	
	if (currShader) {
		box->shader = currShader->name;
	}
	
	blocks.push_back(box);
}

void SFRenderer::quads(vector<vec3f> vertices) {
	
	matrix4x4 m;
	glGetFloatv(GL_MODELVIEW_MATRIX, m.getPtr());
	
	QuadsObjectBlock* quads = new QuadsObjectBlock();
	quads->name = bid();
	quads->vertices = vertices;
	quads->m = m;
	
	if (currShader) {
		quads->shader = currShader->name;
	}
	
	blocks.push_back(quads);
}

void SFRenderer::floor() {
	
	matrix4x4 m;
	glGetFloatv(GL_MODELVIEW_MATRIX, m.getPtr());
	
	// name value have to be unique if using instance
	PlaneObjectBlock* plane = new PlaneObjectBlock();
	plane->name = bid();
	plane->m = m;
	plane->p = vec3f(0, 0, 0);
	plane->n = vec3f(0, 1, 0);
	
	if (currShader) {
		plane->shader = currShader->name;
	}
	
	blocks.push_back(plane);
}
