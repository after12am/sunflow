
#include "testApp.h"
#include <GLUT/GLUT.h>
#include <iostream.h>

//--------------------------------------------------------------
void testApp::setRnadColor(int n) {
	
	switch (n) {
		case 0:
			sf::setColor(.8f, .8f, 0);
			break;
		case 1:
			sf::setColor(.8f, 0, .8f);
			break;
		case 2:
			sf::setColor(0, .8f, .8f);
			break;
		case 3:
			sf::setColor(.8f, .8f, .8f);
			break;
	}
}

//--------------------------------------------------------------
void testApp::setup(){
	
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	// FILTER_MITCHELL is nice filter
	sf::setFilter(SF_FILTER_MITCHELL);
	
	// apply anti-aliasing
	sf::smooth();
	
	int n = 31;
	
	sf::translate(-12, 0, -12);
	
	for (int i = -n; i <= n; i++) {
		for (int j = -n; j <= n; j++) {
			setRnadColor(abs((i + j) % 4));
			sf::pushMatrix();
			sf::translate(i, .5f, j);
			sf::scale(.7f, .7f, .7f);
			sf::box(1);
			sf::popMatrix();
		}
	}
	
	sf::setColor(0, .8f, .8f);
	sf::floor();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if (key == 'r') {
		sf::render();
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
	
	float dist = h  * 0.5f / tan(ofDegToRad(camera.fovy * 0.5f));
	float aspect = (float)w / h;
	float z = dist / camera.scale * 2;
	
	sf::setupScreenPerspective(vec3f(z, 28, z), vec3f(0, 0, 0), vec3f(0, 1, 0), 30, aspect, camera.near, camera.far);
}