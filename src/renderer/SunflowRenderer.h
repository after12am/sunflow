//
//  SunflowRenderer.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/27.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _SunflowRenderer_h
#define _SunflowRenderer_h

#include "SunflowRenderOption.h"
#include "BufferStream.h"
#include "BaseBlock.h"
#include "ImageBlock.h"
#include "CameraBlock.h"
#include "PinholeCameraBlock.h"
#include "GlobalIlluminationBlock.h"
#include "AmbientOcclusionBlock.h"
#include "LightBlock.h"
#include "PointLightBlock.h"
#include "MeshBlock.h"
#include "BoxGenericMeshBlock.h"
#include "InstanceBlock.h"
#include "SphereBlock.h"
#include "PlaneBlock.h"
#include "QuadsBlock.h"
#include "ShaderBlock.h"
#include "DiffuseShader.h"
#include "ShinyShaderBlock.h"

class SunflowRenderer {
	
protected:
	
	struct CodeBlock {
		ImageBlock* image;
		CameraBlock* camera;
		GlobalIlluminationBlock* gi;
		vector<LightBlock*> lights;
		vector<ShaderBlock*> shaders;
		vector<MeshBlock*> objects;
	};
	
	CodeBlock sc;
	BufferStream bufferStream;
	ShaderBlock* currShader;
	
public:
	
	struct SunflowRenderOption option;
	
	SunflowRenderer() {
		currShader = 0;
		sc.image = new ImageBlock();
		sc.camera = 0;
		sc.gi = 0;
	}
	
	~SunflowRenderer();
	
	string bid();
	
	// call sunflow command
	void call(SunflowRenderOption option);
	void clear();
	void flush(string name);
	void render();
	void render(string format);
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

#endif
