//
//  sunflow.cpp
//  quickExample
//
//  Created by Okami Satoshi on 12/04/28.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "sunflow.h"
#include <iostream.h>
#include "GLRenderer.h"
#include "SFRenderer.h"
#include <sstream>

sf::GLRenderer glRenderer;
sf::SFRenderer sfRenderer;
vector<sf::vec3f> vertices;

int _frameRate = FRAME_RATE;

int sf::getWindowWidth() {
	return glRenderer.getWindowWidth();
}

int sf::getWindowHeight() {
	return glRenderer.getWindowHeight();
}

void sf::setWindowSize(int width, int height) {
	IMPL
}

void sf::setFrameRate(int i) {
	_frameRate = i;
}

int sf::frameRate() {
	return _frameRate;
}

void sf::_clear() {
	glRenderer.clear();
	sfRenderer.clear();
}

void sf::setSize(int width, int height) {
	sfRenderer.setImageResolution(width, height);
}

void sf::noSmooth() {
	sfRenderer.smooth(0, 0);
}

void sf::smooth() {
	sfRenderer.smooth(1, 2);
}

void sf::smooth(const int min, const int max) {
	sfRenderer.smooth(min, max);
}

void sf::setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect, const float near, const float far) {
	glRenderer.setupScreenPerspective(eye, target, up, fov, aspect, near, far);
	sfRenderer.setupScreenPerspective(eye, target, up, fov, aspect);
}

void sf::setAmboccBright(const Color bright) {
	sfRenderer.setAmboccBright(bright);
}

void sf::setAmboccDark(const Color dark) {
	sfRenderer.setAmboccDark(dark);
}

void sf::setAmbocc(const Color bright, const Color dark, const int samples, const float maxdist, const string colorSpace) {
	sfRenderer.setAmbocc(bright, dark, samples, maxdist, colorSpace);
}

void sf::setColor(float r, float g, float b, float a) {
	glRenderer.setColor(r, g, b, a);
	sfRenderer.setColor(r, g, b, a);
}

void sf::pushMatrix() {
	glRenderer.pushMatrix();
}

void sf::popMatrix() {
	glRenderer.popMatrix();
}

void sf::translate(float x, float y, float z) {
	glRenderer.translate(x, y, z);
}

void sf::rotate(float angle, float axisX, float axisY, float axisZ) {
	glRenderer.rotate(angle, axisX, axisY, axisZ);
}

void sf::scale(float scaleX, float scaleY, float scaleZ) {
	glRenderer.scale(scaleX, scaleY, scaleZ);
}

void sf::begin() {
	glRenderer.begin();
	vertices.clear();
}

void sf::vertex(float x, float y, float z) {
	glRenderer.vertex(x, y, z);
	vertices.push_back(sf::vec3f(x, y, z));
}

void sf::end() {
	glRenderer.end();
	sfRenderer.quads(vertices);
}

void sf::sphere(float size)
{
	sphere(size, size, size);
}

void sf::sphere(float sizeX, float sizeY, float sizeZ)
{
	glRenderer.sphere(sizeX, sizeY, sizeZ);
	sfRenderer.sphere();
}

void sf::box(float size) {
	sf::box(size, size, size);
}

void sf::box(float sizeX, float sizeY, float sizeZ) {
	glRenderer.box(sizeX, sizeY, sizeZ);
	sfRenderer.box();
}

void sf::floor() {
	glRenderer.floor();
	sfRenderer.floor();
}

void sf::quickRender(const bool nogui, const string output) {
	render(nogui, true, output);
}

void sf::render(const bool nogui, const bool ipr, const string output) {
	sfRenderer.option.nogui = nogui;
	sfRenderer.option.ipr = ipr;
	sfRenderer.option.output = output;
	sfRenderer.render();
}
