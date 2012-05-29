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
sf::SFRenderer sfRenderer(glRenderer);

int frameRate = DEFAULT_FRAME_RATE;

void sf::setWindowSize(int width, int height) {
	IMPL
}

void sf::setFrameRate(int _frameRate) {
	frameRate = _frameRate;
}

int sf::getFrameRate() {
	return frameRate;
}

void sf::clear() {
	glRenderer.clear();
	sfRenderer.clear();
}

void sf::setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect, const float near, const float far) {
	glRenderer.setupScreenPerspective(eye, target, up, fov, aspect, near, far);
	sfRenderer.setupScreenPerspective(eye, target, up, fov, aspect, near, far);
}

void sf::setAmbientOcclusion(const Color bright, const Color dark, const int samples, const float maxdist, const string colorSpace) {
	sfRenderer.setAmbientOcclusion(bright, dark, samples, maxdist, colorSpace);
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



/* render
 =================*/

// SFRendererにうつす
// prototype statement
void command(string command);
void command(string filePath, string output, bool nogui, bool ipr);

void command(string command)
{
#ifdef DEBUG
	cout << "[INFO] command execute " << command.c_str() << endl;
#endif
	
	if (system(command.c_str()) != 0)
	{
		cout << "[ERROR] command error" << endl;
	}
}

void command(string filePath, string output, bool nogui, bool ipr)
{
	stringstream cmd;
	stringstream options;
	
	if (output != "") options << " -o " << output << " ";
	if (nogui) options << " -nogui ";
	if (ipr) options << " -ipr ";
	
	string optstr = options.str().c_str();
	
	cmd << "cd ../../../lib; ./sunflow " << optstr << filePath;
	
	command(cmd.str());
}

void sf::quickRender()
{
	sfRenderer.render();
	command(sfRenderer.filePath(), "", false, true);
}

void sf::render(const string output, const bool nogui, const bool ipr)
{
	sfRenderer.render();
	command(sfRenderer.filePath(), output, nogui, ipr);
}