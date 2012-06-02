//
//  RunApp.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/27.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _RunApp_h
#define _RunApp_h

#include "BaseApp.h"
#include "Trackball.h"

class RunApp {
	
protected:
	
	static BaseApp* app;
	static Trackball tb;
	
public:
	
	RunApp(BaseApp* _app);
	~RunApp();
	
	void setup();
	static void update();
	static void draw();
	static void keyPressed(unsigned char key, int x, int y);
	static void mouseMoved(int x, int y );
	static void mouseDragged(int x, int y);
	static void mousePressed(int button, int state, int x, int y);
	static void windowResized(int w, int h);
	static void timer(int value);
};

#endif
