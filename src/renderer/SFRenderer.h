//
//  SFRenderer.h
//  emptyExample
//
//  Created by Okami Satoshi on 12/04/27.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _SFRenderer_h
#define _SFRenderer_h

#include "sunflow.h"
#include "GLRenderer.h"
#include "BufferStream.h"

#include "BaseBlock.h"
#include "ImageBlock.h"


namespace sf {
	
	class SFRenderer {
		
	protected:
		
		GLRenderer glRenderer;
		
		BufferStream bufferStream;
		
		vector<BaseBlock*> blocks;
		
		// return pointer by name
		BaseBlock* getPtr(string name);
		
		// flush sc file
		int flush();
		
	public:
		
		string currShader;
		
		SFRenderer(GLRenderer& _glRenderer) {
			
			glRenderer = _glRenderer;
			currShader = SHADER_NONE;
			blocks.push_back(new ImageBlock());
		}
		
		~SFRenderer() {
			
			for (int i = 0; i < blocks.size(); i++) {
				delete blocks[i];
			}
		}
		
		// return sc file path
		string filePath();
		
		ImageBlock* getImagePtr();
		
		
		
		void setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect, const float near, const float far);
		
		
		void clear();
		void render();
	};
}

#endif
