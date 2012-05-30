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
		
		struct Blocks {
			ImageBlock* image;
			CameraBlock* camera;
			GIBlock* gi;
			vector<Light*> lights;
			vector<ShaderBlock*> shaders;
			vector<MeshBlock*> objects;
		} sc;
		
		BufferStream bufferStream;
		ShaderBlock* currShader;
		
	public:
		
		struct Option {
			bool nogui;
			bool ipr;
			string output;
			string filePath;
		} option;
		
		SFRenderer() {
			
			currShader = 0;
			
			sc.image = new ImageBlock();
			sc.camera = 0;
			sc.gi = 0;
			
			option.nogui = false;
			option.ipr = true;
			option.output = "";
		}
		
		~SFRenderer();
		
		string bid();
		
		// call sunflow command
		void call(Option option);
		
		void clear();
		void flush();
		void render();
		void setImageResolution(int width, int height);
		void setFilter(string filter);
		void smooth(const int min, const int max);
		void setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect);
		void setAmboccBright(const Color bright);
		void setAmboccDark(const Color dark);
		void setAmbocc(const Color bright, const Color dark, const int samples, const float maxdist, const string colorSpace);
		void setPointLight(const vec3f _position, const Color _color, const float _power, const string _colorSpace);
		void setColor(const float r, const float g, const float b, const float a);
		void sphere();
		void box();
		void quads(vector<vec3f> vertices);
		void floor();
	};
}

#endif
