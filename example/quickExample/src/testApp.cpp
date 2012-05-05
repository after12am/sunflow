
#include "testApp.h"
#include <GLUT/GLUT.h>
#include <iostream.h>

bool doRender = false;

//--------------------------------------------------------------
void testApp::setup(){
	
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	
	glPushMatrix();
	sf::box(1);
	glPopMatrix();
	
	if (doRender) {
		sf::quickRender();
		doRender = false;
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if (key == 'r') {
		doRender = true;
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}