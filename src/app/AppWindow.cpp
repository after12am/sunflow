//
//  AppWindow.cpp
//  sunflow
//
//  Created by Okami Satoshi on 12/06/03.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
//

#include "AppWindow.h"
#include <GLUT/GLUT.h>
#include <iostream.h>

int frameRate;

AppWindow::AppWindow() {
	frameRate = 30;
}

AppWindow::~AppWindow() {
	
}

int AppWindow::getWidth() {
	return glutGet(GLUT_WINDOW_WIDTH);
}

int AppWindow::getHeight() {
	return glutGet(GLUT_WINDOW_HEIGHT);
}

void AppWindow::setFrameRate(float targetRate) {
	frameRate = targetRate;
}

int AppWindow::getFrameRate() {
	return frameRate;
}