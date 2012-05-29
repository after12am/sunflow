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

void GLRenderer::setup() {
	
	// set light setting
	float position[] = { 0, 1, 2, 0 };
	float color[] = { 0.8, 0.2, 0.2 };
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, color);
}

void GLRenderer::setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect, const float near, const float far) {
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, aspect, near, far);
	gluLookAt(eye.x, eye.y, eye.z, target.x, target.y, target.z, up.x, up.y, up.z);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GLRenderer::setColor(float r, float g, float b, float a) {
	float color[] = { r, g, b, a };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
}

void GLRenderer::pushMatrix() {
	glPushMatrix();
}

void GLRenderer::popMatrix() {
	glPopMatrix();
}

void GLRenderer::translate(float x, float y, float z) {
	glTranslatef(x, y, z);
}

void GLRenderer::rotate(float angle, float axisX, float axisY, float axisZ) {
	glRotatef(angle, axisX, axisY, axisZ);
}

void GLRenderer::scale(float scaleX, float scaleY, float scaleZ) {
	glScalef(scaleX, scaleY, scaleZ);
}

void GLRenderer::box(float sizeX, float sizeY, float sizeZ) {
	// switch to glCallList
	glPushMatrix();
	glScalef(sizeX, sizeY, sizeZ);
	glutSolidCube(1);
	glPopMatrix();
}

void GLRenderer::floor() {
	glPushMatrix();
	glScalef(10000, 1, 10000);
	glBegin(GL_QUADS);
	glVertex3f(-.5f, 0, -.5f);
	glVertex3f( .5f, 0, -.5f);
	glVertex3f( .5f, 0,  .5f);
	glVertex3f(-.5f, 0,  .5f);
	glEnd();
	glPopMatrix();
}