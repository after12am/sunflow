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


using namespace sf;


// if has error, return value( > 0).
// if has no error, return 0.
int SFRenderer::flush()
{
	ImageBlock* image = getImagePtr();
	
	image->flush(bufferStream);
	
	
//	if (camera > 0) camera->flush(fstream);
//	if (gi > 0) gi->flush(fstream);
//	
//	for (int i = 0; i < objects.size(); i++) if (objects[i] > 0) objects[i]->flush(fstream);
	
#ifdef DEBUG
	bufferStream.dump();
#endif
	bufferStream.save();
	
	return 0;
}


/* get pointer
 ===============*/
BaseBlock* SFRenderer::getPtr(string name)
{
	for (int i = 0; i < blocks.size(); i++)
	{
		if (blocks[i]->name == name) return blocks[i];
	}
	return 0;
}

ImageBlock* SFRenderer::getImagePtr() {
	return dynamic_cast<ImageBlock*>(getPtr("image"));
}



string SFRenderer::filePath() {
	return bufferStream.getPath();
}


void SFRenderer::setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect, const float near, const float far) {
	
	//renderer.setCamera(new PinholeCamera(eye, target, up, fov, aspect));
}

void SFRenderer::clear()
{
	vector<BaseBlock*> _blocks;
	ostringstream ss;
	
	for (int i = 0; i < blocks.size(); i++)
	{
		ss.clear();
		ss << "mesh";
		
		if (blocks[i]->type == ss.str()) {
			delete blocks[i];
			return;
		}
		
		ss.clear();
		ss << "light";
		
		if (blocks[i]->type == ss.str()) {
			delete blocks[i];
			return;
		}
		
		ss.clear();
		ss << "shader";
		
		if (blocks[i]->type == ss.str()) {
			delete blocks[i];
			return;
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