//
//  sunflow.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/27.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _sunflow_h
#define _sunflow_h

#include "Constants.h"
#include "BaseApp.h"
#include "RunApp.h"
#include "RenderOption.h"

namespace sf {
	
	// -------------------------------------------------------------------------
	//   FILTER GUIDE
	// -------------------------------------------------------------------------
	// Triangle and box are better for previews since they are faster. 
	// The other filters are recommended for final image rendering.
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
	// -------------------------------------------------------------------------
	const char FILTER_BLACKMAN_HARRIS[32] = "blackman-harris";
	const char FILTER_BOX[32] = "box";
	const char FILTER_CATMULL_ROM[32] = "catmull-rom";
	const char FILTER_GAUSSIAN[32] = "gaussian";
	const char FILTER_LANCZOS[32] = "lanczos";
	const char FILTER_MITCHELL[32] = "mitchell";
	const char FILTER_SINC[32] = "sinc";
	const char FILTER_TRIANGLE[32] = "triangle";
	const char FILTER_BSPLINE[32] = "bspline";
	
	// -------------------------------------------------------------------------
	//   SHADER TYPE
	// -------------------------------------------------------------------------
	const char SHADER_NONE[32] = "none";
	//const char SHADER_CONSTANT[32] = "constant";
	const char SHADER_DIFFUSE[32] = "diffuse";
	//const char SHADER_TEXTURED_DIFFUSE[32] = "textured_diffuse";
	//const char SHADER_PHONG[32] = "phong";
	//const char SHADER_TEXTURED_PHONG[32] = "textured_phong";
	const char SHADER_SHINY[32] = "shiny";
	//const char SHADER_TEXTURED_SHINY[32] = "textured_shiny";
	//const char SHADER_GLASS[32] = "glass";
	//const char SHADER_MIRROR[32] = "mirror";
	//const char SHADER_WARD[32] = "ward";
	//const char SHADER_TEXTURED_WARD[32] = "textured_ward";
	//const char SHADER_AMBIENT_OCCLUSION[32] = "ambient_occlusion";
	//const char SHADER_TEXTURED_AMBIENT_OCCLUSION[32] = "textured_ambient_occlusion";
	//const char SHADER_UBER[32] = "uber";
	//const char SHADER_WIREFRAME[32] = "wireframe";
	
	// -------------------------------------------------------------------------
	//   COLORSPACE GUIDE
	// -------------------------------------------------------------------------
	//   Sunflow has 6 color spaces available to use in your shaders. 
	// - internal
	// - sRGB nonlinear
	// - sRGB linear
	// - XYZ
	// - blackbody
	// - spectrum
	// -------------------------------------------------------------------------
	const char COLORSPACE_SRGB_INTERNAL[32] = "internal";
	const char COLORSPACE_SRGB_NONLINEAR[32] = "sRGB nonlinear";
	const char COLORSPACE_SRGB_LINEAR[32] = "sRGB linear";
	const char COLORSPACE_XYZ[32] = "XYZ";
	//const char COLORSPACE_XYZ[32] = "blackbody";
	//const char COLORSPACE_XYZ[32] = "spectrum";
	
	// -------------------------------------------------------------------------
	//   SHADER GUIDE
	// -------------------------------------------------------------------------
	//   Sunflow supports 5 main global illumination (gi) types
	//   though this toolkit supports only ambocc now.
	// -------------------------------------------------------------------------
	//const char GI_INSTANT_GI[32] = "igi";
	//const char GI_IRRADIANCE_CACHE[32] = "irr-cache";
	//const char GI_PATH[32] = "path";
	const char GI_AMBIENT_OCCLUSION[32] = "ambocc";
	//const char GI_FAKE[32] = "fake";
	
	//const char LIGHT_DIRECTIONAL[32] = "directional";
	//const char LIGHT_IMAGEBASED[32] = "ibl";
	//const char LIGHT_POINT[32] = "point";
	//const char LIGHT_SPHERE[32] = "sphere";
	//const char LIGHT_SUNSKY[32] = "sunsky";
	//const char LIGHT_MESH[32] = "triangle_mesh";
	//const char MODIFIER_BUMP_MAP[32] = "bump_map";
	//const char MODIFIER_NORMAL_MAP[32] = "normal_map";
	//const char MODIFIER_PERLIN_MAP[32] = "perlin";
	
	int getWindowWidth();
	int getWindowHeight();
	void setWindowSize(int width, int height);
	void setFrameRate(int i);
	int getFrameRate();
	string getBinDir(int bufSize = 1024);
	
	// We have to call every frame.
	// If you are a user, dont worry about this. This clear method is calling at background every RunApp::draw(). 
	void _clear();
	
	void setSize(int width, int height);
	void setFilter(string filter);
	
	// -------------------------------------------------------------------------
	//   ANTI-ALIASING GUIDE
	// -------------------------------------------------------------------------
	// - noSmooth is no anti-aliasing
	// - smooth is final rendering
	// 
	//   no anti-aliasing:                     0 0
	//   quick undersampled preview:          -2 0
	//   preview with some edge refinement:    0 1
	//   final rendering:                      1 2
	// -------------------------------------------------------------------------
	void noSmooth();
	void smooth();
	void smooth(const int min, const int max);
	
	// -------------------------------------------------------------------------
	//   CAMERA GUIDE
	// -------------------------------------------------------------------------
	//   only perspective camera is available now
	// -------------------------------------------------------------------------
	void setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect, const float near, const float far);
	
	// -------------------------------------------------------------------------
	//   AMBIENT OCCLUSION
	// -------------------------------------------------------------------------
	void setAmboccBright(const Color bright);
	void setAmboccDark(const Color dark);
	void setAmbocc(const Color bright, const Color dark, const int samples, const float maxdist, const string colorSpace);
	
	// set color with r, g, b, a from 0 to 1.
	void setColor(float r, float g, float b, float a = 1.f);
	
	// -------------------------------------------------------------------------
	//   TRANSFORMATION
	// -------------------------------------------------------------------------
	void pushMatrix();
	void popMatrix();
	void translate(float x, float y, float z);
	void rotate(float angle, float axisX, float axisY, float axisZ);
	void scale(float scaleX, float scaleY, float scaleZ);
	
	// -------------------------------------------------------------------------
	//   VERTEX GUIDE
	// -------------------------------------------------------------------------
	// 
	// sf::begin("shader name");
	// sf::vertex( 2,  2, 0);
	// sf::vertex( 2, -2, 0);
	// sf::vertex(-2, -2, 0);
	// sf::vertex(-2,  2, 0);
	// sf::end();
	// 
	// 
	//  (-2,  2, 0) ----------- ( 2,  2, 0);
	//             |           |
	//             |           |
	//             |           |
	//             |           |
	//             |           |
	//  (-2, -2, 0) ----------- ( 2, -2, 0);
	// 
	// -------------------------------------------------------------------------
	void begin();
	void vertex(float x, float y, float z);
	void end();
	
	// -------------------------------------------------------------------------
	//   PROVIDED PRIMITIVE
	// -------------------------------------------------------------------------
	void sphere(float size = 1.f);
	void sphere(float sizeX, float sizeY, float sizeZ);
	void box(float size = 1.f);
	void box(float sizeX, float sizeY, float sizeZ);
	
	// -------------------------------------------------------------------------
	//   FLOOR PRIMITIVE GUIDE
	// -------------------------------------------------------------------------
	// - infinite plane
	//   
	//   center point p(0, 0, 0)
	//   normal       n(0, 1, 0)
	// -------------------------------------------------------------------------
	void floor();
	
	// -------------------------------------------------------------------------
	//   RENDER GUIDE
	// -------------------------------------------------------------------------
	// - quickRender is for quick preview
	// - render is customizable with render option
	//   
	//   if you change ipr to false, you would get better result 
	//   at the expense of too much time.
	// -------------------------------------------------------------------------
	sf::RenderOption getRenderOption();
	void setRenderOption(sf::RenderOption option);
	void quickRender();
	void quickRenderWithFormat(const string formatPath);
	void render();
	void renderWithFormat(const string formatPath);
	
	//void flush(string name);
}

#endif
