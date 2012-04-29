
#ifndef TRACKBALL_H
#define TRACKBALL_H

#include <time.h>

class Trackball {

private:
	
	int cx, cy;
	double sx, sy;
	double cq[4];
	double tq[4];
	double rt[16];
	bool dragged;
	int btn;
	clock_t lastClickTime;
	
	void start(int x, int y);
	void stop(int x, int y);
	void doubleClick(int button, int state, int x, int y);
	void motion(int x, int y);
	void reset();
	
public:
	
	Trackball(void);
	~Trackball(void) {};
	
	void resize(int w, int h);
	void drag(int x, int y);
	void click(int button, int state, int x, int y);
	const double *rotate(void);
};

#endif