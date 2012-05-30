//
//  main.cpp
//  emptyExample
//
//  Created by Okami Satoshi on 12/04/27.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream.h>
#include <GLUT/GLUT.h>
#include "sunflow.h"
#include "testApp.h"


int main (int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("emptyExample");
	
	sf::RunApp(new testApp());
	return 0;
}
