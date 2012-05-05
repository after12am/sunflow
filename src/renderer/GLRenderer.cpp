//
//  GLRenderer.cpp
//  quickExample
//
//  Created by Okami Satoshi on 12/04/28.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "GLRenderer.h"
#include <iostream.h>
#include <GLUT/GLUT.h>

using namespace sf;

int GLRenderer::getWindowWidth() {
	return glutGet(GLUT_WINDOW_WIDTH);
}

int GLRenderer::getWindowHeight() {
	return glutGet(GLUT_WINDOW_HEIGHT);
}

void GLRenderer::setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect, const float near, const float far) {
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, aspect, near, far);
	gluLookAt(eye.x, eye.y, eye.z, target.x, target.y, target.z, up.x, up.y, up.z);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GLRenderer::box(float sizeX, float sizeY, float sizeZ) {
	
	// switch to glCallList
	glPushMatrix();
	glScalef(sizeX, sizeY, sizeZ);
	glutSolidCube(1);
	glPopMatrix();
}