//
//  Constants.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/28.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _Constants_h
#define _Constants_h

#define IMPL printf("[FUNCTION NOT IMPLEMENTED YET] %s\n", __PRETTY_FUNCTION__); exit(1);

// relative path from bin directory
#define SF_LIB_PATH "../../../lib"
#define SF_SC "output.sc"

#include "ofMath.h"
#include "ofVec2f.h"
#include "ofVec3f.h"
#include "ofVec4f.h"
#include "ofQuaternion.h"
#include "ofMatrix3x3.h"
#include "ofMatrix4x4.h"

// set alias
typedef ofVec2f vec2f;
typedef ofVec3f vec3f;
typedef ofVec4f vec4f;
typedef ofQuaternion quaternion;
typedef ofMatrix3x3 matrix3x3;
typedef ofMatrix4x4 matrix4x4;

class Color {
	
public:
	
	float r;
	float g;
	float b;
	float a;
	
	Color(const float _r = 0.f, const float _g = 0.f, const float _b = 0.f, const float _a = 0.f) {
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}
};


// triangle and box are better for previews since they are faster. 
// the other filters are recommended for final image rendering.

// 
// box             (filter size = 1)
// triangle        (filter size = 2)
// gaussian        (filter size = 3)
// mitchell        (filter size = 4)
// catmull-rom     (filter size = 4)
// blackman-harris (filter size = 4)
// sinc            (filter size = 4) 
// lanczos         (filter size = 4)
// bspline         (filter size = 4)
// 

#define SF_FILTER_BLACKMAN_HARRIS "blackman-harris"
#define SF_FILTER_BOX "box"
#define SF_FILTER_CATMULL_ROM "catmull-rom"
#define SF_FILTER_GAUSSIAN "gaussian"
#define SF_FILTER_LANCZOS "lanczos"
#define SF_FILTER_MITCHELL "mitchell"
#define SF_FILTER_SINC "sinc"
#define SF_FILTER_TRIANGLE "triangle"
#define SF_FILTER_BSPLINE "bspline"

// http://sfwiki.geneome.net/index.php5?title=File:Ibl-test-with-lock-true.jpg
#define SF_SHADER_NONE "none"
//#define SF_SHADER_CONSTANT "constant"
#define SF_SHADER_DIFFUSE "diffuse"
//#define SF_SHADER_TEXTURED_DIFFUSE "textured_diffuse"
//#define SF_SHADER_PHONG "phong"
//#define SF_SHADER_TEXTURED_PHONG "textured_phong"
#define SF_SHADER_SHINY "shiny"
//#define SF_SHADER_TEXTURED_SHINY "textured_shiny"
//#define SF_SHADER_GLASS "glass"
//#define SF_SHADER_MIRROR "mirror"
//#define SF_SHADER_WARD "ward"
//#define SF_SHADER_TEXTURED_WARD "textured_ward"
//#define SF_SHADER_AMBIENT_OCCLUSION "ambient_occlusion"
//#define SF_SHADER_TEXTURED_AMBIENT_OCCLUSION "textured_ambient_occlusion"
//#define SF_SHADER_UBER "uber"
//#define SF_SHADER_WIREFRAME "wireframe"

// sunflow has 6 color spaces available to use in your shaders.
#define SF_COLORSPACE_SRGB_INTERNAL "internal"
#define SF_COLORSPACE_SRGB_NONLINEAR "sRGB nonlinear"
#define SF_COLORSPACE_SRGB_LINEAR "sRGB linear"
#define SF_COLORSPACE_XYZ "XYZ"
//#define SF_COLORSPACE_XYZ "blackbody"
//#define SF_COLORSPACE_XYZ "spectrum"

// sunflow supports 5 main global illumination (gi) types
// though this toolkit supports only ambocc now.
//#define SF_GI_INSTANT_GI "igi"
//#define SF_GI_IRRADIANCE_CACHE "irr-cache"
//#define SF_GI_PATH "path"
#define SF_GI_AMBIENT_OCCLUSION "ambocc"
//#define SF_GI_FAKE "fake"

//#define SF_LIGHT_DIRECTIONAL "directional"
//#define SF_LIGHT_IMAGEBASED "ibl"
//#define SF_LIGHT_POINT "point"
//#define SF_LIGHT_SPHERE "sphere"
//#define SF_LIGHT_SUNSKY "sunsky"
//#define SF_LIGHT_MESH "triangle_mesh"
//#define SF_MODIFIER_BUMP_MAP "bump_map"
//#define SF_MODIFIER_NORMAL_MAP "normal_map"
//#define SF_MODIFIER_PERLIN_MAP "perlin"

#endif