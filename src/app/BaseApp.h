//
//  BaseApp.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _BaseApp_h
#define _BaseApp_h

namespace sf {
	
	class BaseApp {
		
	public:
		
		struct Camera {
			float fovy;
			float scale;
			float near;
			float far;
		} camera;
		
		BaseApp() {
			camera.fovy = 30.0;
			camera.scale = 100;
			camera.near = 1;
			camera.far = 1000;
		}
		
		virtual void setup() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void keyPressed(int key) = 0;
		virtual void mouseMoved(int x, int y ) = 0;
		virtual void mouseDragged(int x, int y) = 0;
		virtual void mousePressed(int x, int y, int button) = 0;
		virtual void windowResized(int w, int h) = 0;
	};
}

#endif
