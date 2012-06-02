//
//  AppRenderer.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _AppRenderer_h
#define _AppRenderer_h

#include "SunflowRenderOption.h"
#include "Constants.h"
#include <iostream.h>

class AppRenderer {
	
public:
	
	struct Camera {
		float fovy;
		float scale;
		float near;
		float far;
	} camera;
};

namespace sf {
	
	// We have to call every frame.
	// If you are a user, dont worry about this. This clear method is calling at background every RunApp::draw(). 
	void _clear();
	
	void setResolution(int width, int height);
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
	void setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fovy, const float aspect, const float near, const float far);
	
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
	SunflowRenderOption* getRenderOption();
	void setRenderOption(SunflowRenderOption option);
	void quickRender();
	void render();
	void renderWithFormat(const string formatPath);
	void flush(string name);
}

#endif
