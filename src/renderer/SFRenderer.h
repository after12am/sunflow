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
#include "CameraBlock.h"
#include "GIBlock.h"
#include "LightBlock.h"
#include "MeshBlock.h"
#include "ShaderBlock.h"


namespace sf {
	
	class SFRenderer {
		
	protected:
		
		GLRenderer glRenderer;
		
		BufferStream bufferStream;
		
		vector<BaseBlock*> blocks;
		
		// return pointer by name
		BaseBlock* getPtr(string name);
		
		// return block unique id
		string bid();
		
		// flush sc file
		void flush(const string type);
		int flush();
		
	public:
		
		struct CommandOption {
			bool nogui;
			bool ipr;
			string output;
		} commandOption;
		
		ShaderBlock* currShader;
		
		SFRenderer(GLRenderer& _glRenderer) {
			
			// setup command option
			commandOption.nogui = false;
			commandOption.ipr = true;
			commandOption.output = "";
			
			glRenderer = _glRenderer;
			currShader = 0;
			blocks.push_back(new ImageBlock());
		}
		
		~SFRenderer() {
			
			for (int i = 0; i < blocks.size(); i++) {
				delete blocks[i];
			}
		}
		
		string filePath();
		ImageBlock* getImagePtr();
		CameraBlock* getCameraPtr();
		vector<ShaderBlock*> getShaders();
		
		void smooth(const int min, const int max);
		void setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect);
		void setAmbientOcclusion(const Color bright, const Color dark, const int samples, const float maxdist, const string colorSpace);
		void setPointLight(const vec3f _position, const Color _color, const float _power, const string _colorSpace);
		void setColor(const float r, const float g, const float b, const float a);
		
		void sphere();
		void box();
		void quads(vector<vec3f> vertices);
		void floor();
		
		void clear();
		void render();
	};
}

#endif
