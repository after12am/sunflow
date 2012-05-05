//
//  sunflow.h
//  emptyExample
//
//  Created by Okami Satoshi on 12/04/27.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _sunflow_h
#define _sunflow_h

// app
#include "BaseApp.h"
#include "RunApp.h"

// utils
#include "Constants.h"
#include "Trackball.h"



#define DEBUG 1


namespace sf {
	
	const char FILTER_BLACKMAN_HARRIS[32] = "blackman-harris";
	const char FILTER_BOX[32] = "box";
	const char FILTER_CATMULL_ROM[32] = "catmull-rom";
	const char FILTER_GAUSSIAN[32] = "gaussian";
	const char FILTER_LANCZOS[32] = "lanczos";
	const char FILTER_MITCHELL[32] = "mitchell";
	const char FILTER_SINC[32] = "sinc";
	const char FILTER_TRIANGLE[32] = "triangle";
	const char FILTER_BSPLINE[32] = "bspline";
	const char SHADER_NONE[32] = "none";
//	const char SHADER_AMBIENT_OCCLUSION[32] = "ambient_occlusion";
//	const char SHADER_TEXTURED_AMBIENT_OCCLUSION[32] = "textured_ambient_occlusion";
//	const char SHADER_CONSTANT[32] = "constant";
//	const char SHADER_DIFFUSE[32] = "diffuse";
//	const char SHADER_TEXTURED_DIFFUSE[32] = "textured_diffuse";
//	const char SHADER_GLASS[32] = "glass";
//	const char SHADER_MIRROR[32] = "mirror";
//	const char SHADER_PHONG[32] = "phong";
//	const char SHADER_TEXTURED_PHONG[32] = "textured_phong";
//	const char SHADER_SHINY_DIFFUSE[32] = "shiny_diffuse";
//	const char SHADER_TEXTURED_SHINY_DIFFUSE[32] = "textured_shiny_diffuse";
//	const char SHADER_UBER[32] = "uber";
//	const char SHADER_WARD[32] = "ward";
//	const char SHADER_TEXTURED_WARD[32] = "textured_ward";
//	const char SHADER_WIREFRAME[32] = "wireframe";
	const char COLORSPACE_SRGB_NONLINEAR[32] = "sRGB nonlinear";
	const char COLORSPACE_SRGB_LINEAR[32] = "sRGB linear";
//	const char COLORSPACE_XYZ[32] = "XYZ";
//	const char GI_AMBIENT_OCCLUSION[32] = "ambocc";
//	const char GI_FAKE[32] = "fake";
//	const char GI_INSTANT_GI[32] = "igi";
//	const char GI_IRRADIANCE_CACHE[32] = "irr-cache";
//	const char GI_PATH[32] = "path";
//	const char LIGHT_DIRECTIONAL[32] = "directional";
//	const char LIGHT_IMAGEBASED[32] = "ibl";
//	const char LIGHT_POINT[32] = "point";
//	const char LIGHT_SPHERE[32] = "sphere";
//	const char LIGHT_SUNSKY[32] = "sunsky";
//	const char LIGHT_MESH[32] = "triangle_mesh";	
//	const char MODIFIER_BUMP_MAP[32] = "bump_map";
//	const char MODIFIER_NORMAL_MAP[32] = "normal_map";
//	const char MODIFIER_PERLIN_MAP[32] = "perlin";
	
	// we have to call every frame.
	void clear();
	
	
	// camera setting
	void setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect, const float near, const float far);
	
	
	
	void box(float size = 1);
	void box(float sizeX, float sizeY, float sizeZ);
	
	// for getting quick preview method
	void quickRender();
	void quickRender(const string output, const bool nogui);
	
	// if you change ipr from true to false, you would get better result.
	// but it need too much time.
	void render(const string output, const bool nogui, const bool ipr);
}

#endif
