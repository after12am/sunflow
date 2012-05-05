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


void sf::clear() {
	sfRenderer.clear();
}

void sf::setupScreenPerspective(const vec3f eye, const vec3f target, const vec3f up, const float fov, const float aspect, const float near, const float far) {
	
	glRenderer.setupScreenPerspective(eye, target, up, fov, aspect, near, far);
	sfRenderer.setupScreenPerspective(eye, target, up, fov, aspect, near, far);
}








void sf::box(float size) {
	sf::box(size, size, size);
}

void sf::box(float sizeX, float sizeY, float sizeZ) {
	
//	if (shader != 0)
//	{
//		float color[4];
//		memcpy(color, shader->getColor(), 32);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
//	}
	
	// draw box
	glRenderer.box(sizeX, sizeY, sizeZ);
	sfRenderer.box();
}



/* render
 =================*/

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
	
	cmd << "cd ./lib; ./sunflow " << optstr << filePath;
	
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