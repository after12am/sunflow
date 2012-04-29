
#include <cmath>
#include <iostream>
#include "Trackball.h"
#include <GLUT/GLUT.h>

#ifndef M_PI
#  define M_PI 3.14159265358979323846
#endif

#define SCALE (2.0 * M_PI)

/*
** r <- p x q
*/
static void qmul(double r[], const double p[], const double q[])
{
	r[0] = p[0] * q[0] - p[1] * q[1] - p[2] * q[2] - p[3] * q[3];
	r[1] = p[0] * q[1] + p[1] * q[0] + p[2] * q[3] - p[3] * q[2];
	r[2] = p[0] * q[2] - p[1] * q[3] + p[2] * q[0] + p[3] * q[1];
	r[3] = p[0] * q[3] + p[1] * q[2] - p[2] * q[1] + p[3] * q[0];
}

static void qrot(double r[], double q[])
{
	double x2 = q[1] * q[1] * 2.0;
	double y2 = q[2] * q[2] * 2.0;
	double z2 = q[3] * q[3] * 2.0;
	double xy = q[1] * q[2] * 2.0;
	double yz = q[2] * q[3] * 2.0;
	double zx = q[3] * q[1] * 2.0;
	double xw = q[1] * q[0] * 2.0;
	double yw = q[2] * q[0] * 2.0;
	double zw = q[3] * q[0] * 2.0;

	r[ 0] = 1.0 - y2 - z2;
	r[ 1] = xy + zw;
	r[ 2] = zx - yw;
	r[ 4] = xy - zw;
	r[ 5] = 1.0 - z2 - x2;
	r[ 6] = yz + xw;
	r[ 8] = zx + yw;
	r[ 9] = yz - xw;
	r[10] = 1.0 - x2 - y2;
	r[ 3] = r[ 7] = r[11] = r[12] = r[13] = r[14] = 0.0;
	r[15] = 1.0;
}

Trackball::Trackball(void)
{
	dragged = false;

	cq[0] = 1.0;
	cq[1] = 0.0;
	cq[2] = 0.0;
	cq[3] = 0.0;

	rt[ 0] = 1.0; rt[ 1] = 0.0; rt[ 2] = 0.0; rt[ 3] = 0.0;
	rt[ 4] = 0.0; rt[ 5] = 1.0; rt[ 6] = 0.0; rt[ 7] = 0.0;
	rt[ 8] = 0.0; rt[ 9] = 0.0; rt[10] = 1.0; rt[11] = 0.0;
	rt[12] = 0.0; rt[13] = 0.0; rt[14] = 0.0; rt[15] = 1.0;
}

void Trackball::resize(int w, int h)
{
	sx = 1.0 / (double)w;
	sy = 1.0 / (double)h;
}

void Trackball::start(int x, int y)
{
	dragged = true;

	cx = x;
	cy = y;
}

void Trackball::motion(int x, int y)
{
	if (dragged) {
		double dx, dy, a;

		dx = (x - cx) * sx;
		dy = (y - cy) * sy;

		a = sqrt(dx * dx + dy * dy);

		if (a != 0.0)
		{
			double ar = a * SCALE * 0.5;
			double as = sin(ar) / a;
			double dq[4] = { cos(ar), dy * as, dx * as, 0.0 };

			qmul(tq, dq, cq);

			qrot(rt, tq);
		}
	}
}

void Trackball::stop(int x, int y)
{
	motion(x, y);

	cq[0] = tq[0];
	cq[1] = tq[1];
	cq[2] = tq[2];
	cq[3] = tq[3];

	dragged = false;
}

void Trackball::doubleClick(int button, int state, int x, int y)
{
	reset();
}

void Trackball::click(int button, int state, int x, int y)
{
	btn = button;
	
	clock_t clickTime = clock();
	
	switch (btn)
	{
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN) {
				start(x, y);
			}
			else {
				stop(x, y);
			}
			
			if (state == GLUT_UP)
			{
				if (clickTime - lastClickTime < 300 * 1000)
					doubleClick(button, state, x, y);
				lastClickTime = clickTime;
			}
			break;
			
		case GLUT_RIGHT_BUTTON:
			break;
			
		default:
			break;
	}
}

void Trackball::drag(int x, int y)
{
	switch (btn)
	{
		case GLUT_LEFT_BUTTON:
			motion(x, y);
			break;
			
		case GLUT_RIGHT_BUTTON:
			break;
			
		default:
			break;
	}
}

void Trackball::reset()
{
	rt[ 0] = 1.0; rt[ 1] = 0.0; rt[ 2] = 0.0; rt[ 3] = 0.0;
	rt[ 4] = 0.0; rt[ 5] = 1.0; rt[ 6] = 0.0; rt[ 7] = 0.0;
	rt[ 8] = 0.0; rt[ 9] = 0.0; rt[10] = 1.0; rt[11] = 0.0;
	rt[12] = 0.0; rt[13] = 0.0; rt[14] = 0.0; rt[15] = 1.0;	
}


const double* Trackball::rotate(void)
{
  return rt;
}

