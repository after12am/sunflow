//
//  GLRenderer.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/27.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _GLRenderer_h
#define _GLRenderer_h

#include "sunflow.h"

namespace sf {
	
	class GLRenderer {
		
	public:
		
		GLRenderer() {
			
		}
		
		~GLRenderer() {
			
		}
		
		static void setup();
		void clear();
		
		int getWindowWidth();
		int getWindowHeight();
		
		void setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect, const float near, const float far);
		
		void setColor(float r, float g, float b, float a);
		
		void pushMatrix();
		void popMatrix();
		void translate(float x, float y, float z);
		void rotate(float angle, float axisX, float axisY, float axisZ);
		void scale(float scaleX, float scaleY, float scaleZ);
		
		void begin();
		void vertex(float x, float y, float z);
		void end();
		void sphere(float sizeX, float sizeY, float sizeZ);
		void box(float sizeX, float sizeY, float sizeZ);
		void floor();
	};
}

#endif
