//
//  BaseApp.h
//  sunflow
//
//  Created by Okami Satoshi on 12/04/29.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#ifndef _BaseApp_h
#define _BaseApp_h

#include "AppWindow.h"
#include "AppRenderer.h"

class BaseApp : public AppWindow, public AppRenderer {
	
public:
	
	BaseApp() {}
	
	virtual void setup() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void keyPressed(int key) = 0;
	virtual void mouseMoved(int x, int y ) = 0;
	virtual void mouseDragged(int x, int y) = 0;
	virtual void mousePressed(int x, int y, int button) = 0;
	virtual void windowResized(int w, int h) = 0;
};

string getBinDir(int bufSize = 1024);

#endif
