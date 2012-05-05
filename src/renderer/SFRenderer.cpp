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
	ImageBlock* image = getImagePtr();
	
	image->flush(bufferStream);
	
	CameraBlock* camera = getCameraPtr();
	camera->flush(bufferStream);
	
	// flush box scheme
	BoxScheme boxScheme;
	boxScheme.flush(bufferStream);
	
	string ss;
	
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
	string ss;
	
	for (int i = 0; i < blocks.size(); i++)
	{
		ss = "mesh";
		if (blocks[i]->type == ss) {
			delete blocks[i];
			continue;
		}
		
		ss = "light";
		if (blocks[i]->type == ss) {
			delete blocks[i];
			continue;
		}
		
		ss = "shader";
		if (blocks[i]->type == ss) {
			delete blocks[i];
			continue;
		}
		
		_blocks.push_back(blocks[i]);
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
BaseBlock* SFRenderer::getPtr(string name)
{
	for (int i = 0; i < blocks.size(); i++) {
		
		if (blocks[i]->name == name) {
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



string SFRenderer::filePath() {
	return bufferStream.getPath();
}


void SFRenderer::setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect, const float near, const float far) {
	
	blocks.push_back(new PinholeCameraBlock(eye, target, up, fov, aspect));
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

