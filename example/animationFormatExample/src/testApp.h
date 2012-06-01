
#ifndef _testApp_h
#define _testApp_h

#include "sunflow.h"

class testApp : public sf::BaseApp {
	
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y);
	void mousePressed(int x, int y, int button);
	void windowResized(int w, int h);
	
	int no;
	sf::vec3f pos;
};

#endif
