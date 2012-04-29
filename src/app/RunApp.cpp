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

using namespace sf;

//--------------------------------------------------------------
int _frameRate = DEFAULT_FRAME_RATE;

void sf::setWindowSize(int width, int height) {
	IMPL
}

void sf::setFrameRate(int frameRate) {
	_frameRate = frameRate;
}

int sf::getFrameRate() {
	return _frameRate;
}

//--------------------------------------------------------------

BaseApp* _app;
Trackball tb;

void RunApp::setup(BaseApp* app) {
	
	// clear seed
	srand((unsigned int)time(NULL));
	
	_app = app;
	glutIdleFunc(update);
	glutDisplayFunc(draw);
	glutKeyboardFunc(keyPressed);
	glutReshapeFunc(windowResized);
	glutMouseFunc(mousePressed);
	glutMotionFunc(mouseDragged);
	glutPassiveMotionFunc(mouseMoved);
	_app->setup();
	timer(1);
	glutMainLoop();
}

//--------------------------------------------------------------
void RunApp::update(){
	
	// cleanup sunflow renderer buffer
	sf::clear();
	
	_app->update();
}

//--------------------------------------------------------------
void RunApp::draw(){
	glPushMatrix();
	glMultMatrixd(tb.rotate());
	_app->draw();
	glPopMatrix();
}

//--------------------------------------------------------------
void RunApp::keyPressed(unsigned char key, int x, int y){
	_app->keyPressed((char)key);
}

//--------------------------------------------------------------
void RunApp::mouseMoved(int x, int y ) {
	_app->mouseMoved(x, y);
}

//--------------------------------------------------------------
void RunApp::mouseDragged(int x, int y) {
	tb.drag(x, y);
	_app->mouseDragged(x, y);
}

//--------------------------------------------------------------
void RunApp::mousePressed(int button, int state, int x, int y){
	tb.click(button, state, x, y);
	_app->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void RunApp::windowResized(int w, int h){
	
	// 構造体にしてsunflow.hへ移す
	float fovy = 30.0;
	float scale = 100;
	float near = 1;
	float far = 100;
	float d = h  * 0.5 / tan(ofDegToRad(fovy * 0.5));
	float aspect = (float)w / h;
	
	tb.resize(w, h);
	
	// set display range on screen
	glViewport(0, 0, w, h);
	
	// As we use perspective camera as default, 
	// mesh size is constant even if window is resized.
	sf::setupScreenPerspective(sf::vec3f(16, 4, d / scale), sf::vec3f(0, 0, 0), sf::vec3f(0, 1, 0), 30, aspect, near, far);
	
	_app->windowResized(w, h);
}

//--------------------------------------------------------------
void RunApp::timer(int value) {
	update();
	glutPostRedisplay();
	glutTimerFunc(1000 / sf::getFrameRate(), timer, 0);
}