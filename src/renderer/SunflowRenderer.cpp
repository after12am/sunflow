//
//  SunflowRenderer.cpp
//  sunflow
//
//  Created by Okami Satoshi on 12/04/28.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#include "SunflowRenderer.h"
#include "BaseApp.h"
#include <iostream.h>
#include <sstream>
#include <GLUT/GLUT.h>

SunflowRenderer::~SunflowRenderer() {
	
	delete sc.image;
	delete sc.camera;
	delete sc.gi;
	
	for (int i = 0; i < sc.shaders.size(); i++) {
		delete sc.shaders[i];
	}
	
	sc.shaders.clear();
	
	for (int i = 0; i < sc.lights.size(); i++) {
		delete sc.lights[i];
	}
	
	sc.lights.clear();
	
	for (int i = 0; i < sc.objects.size(); i++) {
		delete sc.objects[i];
	}
	
	sc.objects.clear();
}

string SunflowRenderer::bid() {
	
	int n = 0;
	
	if (sc.image) {
		n++;
	}
	if (sc.camera) {
		n++;
	}
	if (sc.gi) {
		n++;
	}
	n += sc.lights.size();
	n += sc.shaders.size();
	n += sc.objects.size();
	
	stringstream ss;
	// 'b' means 'block'
	ss << "b" << n;
	return ss.str();
}

void SunflowRenderer::call(SunflowRenderOption option) {
	
	stringstream options;
	
	if (option.output != "") {
		options << " -o " << getBinDir() << "/" << option.output << " ";
	}
	
	if (option.nogui) {
		options << " -nogui ";
	}
	
	if (option.ipr) {
		options << " -ipr ";
	}
	
	stringstream ss;
	ss << "cd " << SF_LIB_PATH << ";";
	ss << "./sunflow " << options.str() << option.formatPath;
	
	string command = ss.str();
	if (system(command.c_str()) != -1) {
		cout << "[INFO] execute " << ss.str() << endl;
	} else {
		cout << "[ERROR] sunflow render command error has occured." << endl;
		cout << ss.str() << endl;
		exit(0);
	}
}

void SunflowRenderer::clear() {
	
	currShader = 0;
	
	for (int i = 0; i < sc.shaders.size(); i++) {
		delete sc.shaders[i];
	}
	
	sc.shaders.clear();
	
	for (int i = 0; i < sc.lights.size(); i++) {
		delete sc.lights[i];
	}
	
	sc.lights.clear();
	
	for (int i = 0; i < sc.objects.size(); i++) {
		delete sc.objects[i];
	}
	
	sc.objects.clear();
}

void SunflowRenderer::flush(string name) {
	
	sc.image->flush(bufferStream);
	sc.camera->flush(bufferStream);
	sc.gi->flush(bufferStream);
	
	for (int i = 0; i < sc.lights.size(); i++) {
		sc.lights[i]->flush(bufferStream);
	}
	
	for (int i = 0; i < sc.shaders.size(); i++) {
		sc.shaders[i]->flush(bufferStream);
	}
	
	BoxGenericMeshBlock box;
	box.flush(bufferStream);
	
	for (int i = 0; i < sc.objects.size(); i++) {
		sc.objects[i]->flush(bufferStream);
	}
	
#ifdef false
	bufferStream.dump();
#endif
	
	bufferStream.save(name);
}

void SunflowRenderer::render() {
	
	// save sc
	string name = SF_SC;
	flush(name);
	
	// set sc path
	option.formatPath = bufferStream.getPath();
	
	// start rendering
	call(option);
}

void SunflowRenderer::render(string format) {
	
	option.formatPath = getBinDir() + "/" + format;
	
	// start rendering
	call(option);
}

void SunflowRenderer::setImageResolution(int width, int height) {
	sc.image->resolution = vec2f(width, height);
}

void SunflowRenderer::setFilter(string filter) {
	sc.image->filter = filter;
}

void SunflowRenderer::smooth(const int min, const int max) {
	sc.image->aaMin = min;
	sc.image->aaMax = max;
}

void SunflowRenderer::setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect) {
	
	if (sc.camera) {
		PinholeCameraBlock* camera = dynamic_cast<PinholeCameraBlock*>(sc.camera);
		camera->eye = eye;
		camera->target = target;
		camera->up = up;
		camera->fov = fov;
		camera->aspect = aspect;
	} else {
		sc.camera = new PinholeCameraBlock(eye, target, up, fov, aspect);
	}
}

void SunflowRenderer::setAmboccBright(const Color bright) {
	
	AmbientOcclusionBlock* ambocc = dynamic_cast<AmbientOcclusionBlock*>(sc.gi);
	
	if (ambocc) {
		ambocc->bright = bright;
	}
}

void SunflowRenderer::setAmboccDark(const Color dark) {
	
	AmbientOcclusionBlock* ambocc = dynamic_cast<AmbientOcclusionBlock*>(sc.gi);
	
	if (ambocc) {
		ambocc->dark = dark;
	}
}

void SunflowRenderer::setAmbocc(const Color bright, const Color dark, const int samples, const float maxdist, const string colorSpace) {
	
	AmbientOcclusionBlock* ambocc = dynamic_cast<AmbientOcclusionBlock*>(sc.gi);
	
	if (ambocc) {
		ambocc->bright = bright;
		ambocc->dark = dark;
		ambocc->samples = samples;
		ambocc->maxdist = maxdist;
		ambocc->colorSpace = colorSpace;
	} else {
		sc.gi = new AmbientOcclusionBlock(bright, dark, samples, maxdist, colorSpace);
	}
}

void SunflowRenderer::setPointLight(const vec3f _position, const Color _color, const float _power, const string _colorSpace) {
	sc.lights.push_back(new PointLightBlock(_position, _color, _power, _colorSpace));
}

void SunflowRenderer::setColor(const float r, const float g, const float b, const float a) {
	
	// search shader
	for (int i = 0; i < sc.shaders.size(); i++) {
		
		Color c = sc.shaders[i]->getColor();
		
		if (c.r == r && c.g == g && c.b == b && c.a == a) {
			// set current shader
			currShader = dynamic_cast<ShaderBlock*>(sc.shaders[i]);
			return;
		}
	}
	
	DiffuseShader* shader = new DiffuseShader(bid(), Color(r, g, b, a), SF_COLORSPACE_SRGB_NONLINEAR);
	sc.shaders.push_back(shader);
	
	// set current shader
	currShader = dynamic_cast<ShaderBlock*>(shader);
}

void SunflowRenderer::sphere() {
	
	matrix4x4 m;
	glPushMatrix();
	glScalef(.5f, .5f, .5f);
	glGetFloatv(GL_MODELVIEW_MATRIX, m.getPtr());
	glPopMatrix();
	
	SphereBlock* sphere = new SphereBlock(bid());
	sphere->m = m;
	
	if (currShader) {
		sphere->shader = currShader->getName();
	}
	
	sc.objects.push_back(sphere);
}

void SunflowRenderer::box() {
	
	matrix4x4 m;
	glGetFloatv(GL_MODELVIEW_MATRIX, m.getPtr());
	
	InstanceBlock* box = new InstanceBlock(bid(), "\"Box\"");
	box->m = m;
	
	if (currShader) {
		box->shader = currShader->getName();
	}
	
	sc.objects.push_back(box);
}

void SunflowRenderer::quads(vector<vec3f> vertices) {
	
	matrix4x4 m;
	glGetFloatv(GL_MODELVIEW_MATRIX, m.getPtr());
	
	QuadsBlock* quads = new QuadsBlock(bid());
	quads->vertices = vertices;
	quads->m = m;
	
	if (currShader) {
		quads->shader = currShader->getName();
	}
	
	sc.objects.push_back(quads);
}

void SunflowRenderer::floor() {
	
	matrix4x4 m;
	glGetFloatv(GL_MODELVIEW_MATRIX, m.getPtr());
	
	// name value have to be unique if using instance
	PlaneBlock* plane = new PlaneBlock(bid());
	plane->m = m;
	plane->p = vec3f(0, 0, 0);
	plane->n = vec3f(0, 1, 0);
	
	if (currShader) {
		plane->shader = currShader->getName();
	}
	
	sc.objects.push_back(plane);
}
