
#include "testApp.h"
#include <GLUT/GLUT.h>
#include <iostream.h>
#include <sstream>

//--------------------------------------------------------------
void testApp::setup(){
	no = 0;
	pos = vec3f(-5, .5f, 0);
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	sf::setFilter(SF_FILTER_MITCHELL);
	sf::smooth();
	
	sf::pushMatrix();
	sf::setColor(.8f, .8f, 0);
	sf::translate(pos.x, pos.y, pos.z);
	sf::scale(.7f, .7f, .7f);
	sf::box(1);
	sf::popMatrix();
	
	sf::setColor(0, .8f, .8f);
	sf::floor();
	
	stringstream output;
	output << "img/" << no << ".png";
	
	sf::nogui(true);
	sf::ipr(true);
	sf::output(output.str());
	sf::render();
	
	no++;
	pos.x += .1f;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if (key == 'q') {
		exit(0);
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