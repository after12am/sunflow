//
//  GLRenderer.cpp
//  sunflow
//
//  Created by Okami Satoshi on 12/04/28.
//  Copyright (c) 2012 Okami Satoshi. All rights reserved.
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
	
	// setup call list for performance
	glNewList(1, GL_COMPILE);
	glutSolidSphere(1, 40, 40);
	glEndList();
	glNewList(2, GL_COMPILE);
	glutSolidCube(1);
	glEndList();
	glNewList(3, GL_COMPILE);
	glBegin(GL_QUADS);
	glVertex3f(-.5f, 0, -.5f);
	glVertex3f( .5f, 0, -.5f);
	glVertex3f( .5f, 0,  .5f);
	glVertex3f(-.5f, 0,  .5f);
	glEnd();
	glEndList();
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);
	
	// enable front and back
	glDisable(GL_CULL_FACE);
}

void GLRenderer::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
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

void GLRenderer::begin() {
	glBegin(GL_QUADS);
}

void GLRenderer::vertex(float x, float y, float z) {
	glVertex3f(x, y, z);
}

void GLRenderer::end() {
	glEnd();
}

void GLRenderer::sphere(float sizeX, float sizeY, float sizeZ) {
	glPushMatrix();
	glScalef(sizeX * .5f, sizeY * .5f, sizeZ * .5f);
	glCallList(1);
	glPopMatrix();
}

void GLRenderer::box(float sizeX, float sizeY, float sizeZ) {
	// switch to glCallList
	glPushMatrix();
	glScalef(sizeX, sizeY, sizeZ);
	glCallList(2);
	glPopMatrix();
}

void GLRenderer::floor() {
	glPushMatrix();
	glScalef(10000, 1, 10000);
	glCallList(3);
	glPopMatrix();
}