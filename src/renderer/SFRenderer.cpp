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


// if has error, return value( > 0).
// if has no error, return 0.
int SFRenderer::flush()
{
	string ss;
	
	ImageBlock* image = getImagePtr();
	
	image->flush(bufferStream);
	
	CameraBlock* camera = getCameraPtr();
	camera->flush(bufferStream);
	
	ss = "gi";
	for (int i = 0; i < blocks.size(); i++) {
		if (blocks[i]->type == ss) {
			blocks[i]->flush(bufferStream);
		}
	}
	
	ss = "shader";
	for (int i = 0; i < blocks.size(); i++) {
		if (blocks[i]->type == ss) {
			blocks[i]->flush(bufferStream);
		}
	}
	
	// flush box scheme
	BoxScheme boxScheme;
	boxScheme.flush(bufferStream);
	
	// flush objects
	ss = "mesh";
	for (int i = 0; i < blocks.size(); i++) {
		if (blocks[i]->type == ss) {
			blocks[i]->flush(bufferStream);
		}
	}
	
//	if (camera > 0) camera->flush(fstream);
//	if (gi > 0) gi->flush(fstream);
//	
//	for (int i = 0; i < objects.size(); i++) if (objects[i] > 0) objects[i]->flush(fstream);
	
#ifdef DEBUG
	bufferStream.dump();
#endif
	
	bufferStream.save();
	cout << "test" << endl;
	return 0;
}

void SFRenderer::clear()
{
	vector<BaseBlock*> _blocks;
	vector<string> deleteList;
	
	deleteList.push_back("mesh");
	deleteList.push_back("light");
	deleteList.push_back("shader");
	
	for (int i = 0; i < blocks.size(); i++)
	{
		bool deleted = false;
		
		for (int j = 0; j < deleteList.size(); j++) {
			
			if (blocks[i]->type == deleteList[j]) {
				delete blocks[i];
				deleted = true;
				break;
			}
		}
		
		if (!deleted) {
			_blocks.push_back(blocks[i]);
		}
	}
	
	blocks.swap(_blocks);
}

void SFRenderer::render() {
	//	renderer.setResolution(width, height);
	//	renderer.setAA(aaMin, aaMax);
	//	renderer.setSamples(samples);
	//	renderer.setFilter(filter);
	
	ImageBlock* image = getImagePtr();
	image->resolution = vec2f(glRenderer.getWindowWidth(), glRenderer.getWindowHeight());
	
	flush();
}


/* get pointer
 ===============*/
BaseBlock* SFRenderer::getPtr(string type)
{
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

void SFRenderer::setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect, const float near, const float far) {
	blocks.push_back(new PinholeCameraBlock(eye, target, up, fov, aspect));
}

void SFRenderer::setAmbientOcclusion(const Color bright, const Color dark, const int samples, const float maxdist, const string colorSpace) {
	blocks.push_back(new AmbientOcclusion(bright, dark, samples, maxdist, colorSpace));
}

void SFRenderer::setPointLight(const vec3f _position, const Color _color, const float _power, const string _colorSpace) {
	blocks.push_back(new PointLight(_position, _color, _power, _colorSpace));
}

void SFRenderer::setColor(const float r, const float g, const float b, const float a) {
	
	// search shader
	vector<ShaderBlock*> shaders = getShaders();
	for (int i = 0; i < shaders.size(); i++) {
		
		Color c = shaders[i]->getColor();
		
		if (c.r == r && c.g == g && c.b == b && c.a == a) {
			return;
		}
	}
	
	// name value have to be unique if using instance
	stringstream ss;
	ss << "Shader" << (blocks.size() + 1);
	
	DiffuseShader* shader = new DiffuseShader(ss.str(), Color(r, g, b, a), COLORSPACE_SRGB_NONLINEAR);
	
	blocks.push_back(shader);
	
	// set current shader
	currShader = dynamic_cast<ShaderBlock*>(shader);
}

void SFRenderer::box() {
	
	matrix4x4 m;
	glGetFloatv(GL_MODELVIEW_MATRIX, m.getPtr());
	
	// name value have to be unique if using instance
	stringstream ss;
	ss << "Box" << (blocks.size() + 1);
	
	Box* box = new Box();
	box->name = ss.str();
	box->m = m;
	
	if (currShader) {
		box->shader = currShader->name;
	}
	
	blocks.push_back(box);
}

