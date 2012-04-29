//
//  RunApp.h
//  emptyExample
//
//  Created by Okami Satoshi on 12/04/27.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _RunApp_h
#define _RunApp_h

#include "sunflow.h"
#include <iostream.h>

namespace sf {
	
	void setWindowSize(int width, int height);
	void setFrameRate(int frameRate);
	int getFrameRate();
}

namespace sf {
	
	class RunApp {
		
	public:
		
		RunApp(BaseApp* app) {
			setup(app);
		}
		
		~RunApp() {
			
		}
		
		void setup(BaseApp* app);
		static void update();
		static void draw();
		static void keyPressed(unsigned char key, int x, int y);
		static void mouseMoved(int x, int y );
		static void mouseDragged(int x, int y);
		static void mousePressed(int button, int state, int x, int y);
		static void windowResized(int w, int h);
		static void timer(int value);
	};
}

#endif
