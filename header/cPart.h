/*
* Oscar Emiliano Cervantes del Valle A01332891
* Alison Ricardo González Cortés A01064754
* Alfredo Puente Vasconcelos A01332573
* Irvin Uriel Mundo Rivera A01333820
*/

#pragma once
#ifdef __APPLE__
// See: http://lnx.cx/docs/opengl-in-xcode/
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include "freeglut.h"
#endif
#include <stdio.h>
#include <math.h>

class Part
{
public:
	Part(float _r, float _g, float _b);
	~Part();

	void draw();
	void update();

	float r, g, b;
};