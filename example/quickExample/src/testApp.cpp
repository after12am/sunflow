
#include "testApp.h"
#include <GLUT/GLUT.h>
#include <iostream.h>


//--------------------------------------------------------------
void testApp::setup(){
	
	sf::setAmbientOcclusion(sf::Color(1.f, 1.f, 1.f), sf::Color(0.f, 0.f, 0.f), 32, 3.0, sf::COLORSPACE_SRGB_LINEAR);
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
//	renderer.setAA(aaMin, aaMax);
//	renderer.setSamples(samples);
//	renderer.setFilter(filter);
	
	// box test
//	sf::pushMatrix();
//	sf::translate(-2, 0, 0);
//	sf::setColor(.8f, .8f, 0);
//	sf::box(1);
//	sf::popMatrix();
//	
	// sphere test
//	sf::pushMatrix();
//	sf::setColor(.8f, 0, .8f);
//	sf::sphere(1);
//	sf::popMatrix();
	
	// quads test
	sf::setColor(0, .8f, .8f);
	sf::begin();
	sf::vertex(-.5f, -.5f, 0);
	sf::vertex( .5f, -.5f, 0);
	sf::vertex( .5f,  .5f, 0);
	sf::vertex(-.5f,  .5f, 0);
	sf::end();
	
	sf::setColor(0, .8f, .8f);
	sf::floor();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if (key == 'r') {
		sf::quickRender();
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