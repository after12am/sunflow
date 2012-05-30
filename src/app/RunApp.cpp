//
//  RunApp.cpp
//  emptyExample
//
//  Created by Okami Satoshi on 12/04/27.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "RunApp.h"
#include <iostream.h>
#include <GLUT/GLUT.h>
#include <cmath>
#include <time.h>
#include "GLRenderer.h"
#include "SFRenderer.h"

using namespace sf;

BaseApp* RunApp::app;
Trackball RunApp::tb;

//--------------------------------------------------------------

void RunApp::setup() {
	
	// clear seed
	srand((unsigned int)time(NULL));
	
	// glutIdleFunc is forbidden for too heavy process
	//glutIdleFunc(update);
	glutDisplayFunc(draw);
	glutKeyboardFunc(keyPressed);
	glutReshapeFunc(windowResized);
	glutMouseFunc(mousePressed);
	glutMotionFunc(mouseDragged);
	glutPassiveMotionFunc(mouseMoved);
	
	// setup openGL 
	GLRenderer::setup();
	
	// process user setup function
	RunApp::app->setup();
	
	timer(1);
	glutMainLoop();
}

//--------------------------------------------------------------
void RunApp::update(){
	RunApp::app->update();
}

//--------------------------------------------------------------
void RunApp::draw(){
	
	// cleanup sunflow renderer buffer and etc...
	_clear();
	
	// call for processing testApp::update()
	update();
	
	glPushMatrix();
	glMultMatrixd(RunApp::tb.rotate());
	RunApp::app->draw();
	glPopMatrix();
	glutSwapBuffers();
}

//--------------------------------------------------------------
void RunApp::keyPressed(unsigned char key, int x, int y){
	RunApp::app->keyPressed((char)key);
}

//--------------------------------------------------------------
void RunApp::mouseMoved(int x, int y) {
	RunApp::app->mouseMoved(x, y);
}

//--------------------------------------------------------------
void RunApp::mouseDragged(int x, int y) {
	RunApp::tb.drag(x, y);
	RunApp::app->mouseDragged(x, y);
}

//--------------------------------------------------------------
void RunApp::mousePressed(int button, int state, int x, int y){
	RunApp::tb.click(button, state, x, y);
	RunApp::app->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void RunApp::windowResized(int w, int h){
	
	// resize image resolution of sunflow renderer
	setSize(w, h);
	
	BaseApp::Camera camera = RunApp::app->camera;
	
	float dist = h  * 0.5f / tan(ofDegToRad(camera.fovy * 0.5f));
	float aspect = (float)w / h;
	
	RunApp::tb.resize(w, h);
	
	// set display range on screen
	glViewport(0, 0, w, h);
	
	// As we use perspective camera as default, 
	// mesh size is constant even if window is resized.
	setupScreenPerspective(vec3f(16, 4, dist / camera.scale), vec3f(0, 0, 0), vec3f(0, 1, 0), 30, aspect, camera.near, camera.far);
	
	RunApp::app->windowResized(w, h);
}

//--------------------------------------------------------------
void RunApp::timer(int value) {
	update();
	glutPostRedisplay();
	glutTimerFunc(1000 / frameRate(), timer, 0);
}