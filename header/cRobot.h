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

#include "cPart.h"

#ifndef ROBOTPARTS
	#define ROBOTPARTS 19
#endif

enum RobotPart
{
	BODY, ABDOMEN, NECK, HEAD, HIP,
	LSHOULDER, LFOREARM, LARM, LHAND, LTIGH, LLEG, LFOOT,
	RSHOULDER, RFOREARM, RARM, RHAND, RTIGH, RLEG, RFOOT
};

class Robot
{
	public:
		Robot();
		~Robot();

		void draw();
		void update();

		float anguloCabeza = 0.0, anguloBrazo = 0.0, anguloPierna = 0.0, anguloBody = 0.0, anguloHip = 0.0;
		float subirPiernaPie = 0.0;
		float dirIzq = 2.0, dirDerecha = 2.0;

		float rotX[ROBOTPARTS];
		/*float rotY[ROBOTPARTS];
		float rotZ[ROBOTPARTS];*/
		float rotYbody;
		Part* parts[ROBOTPARTS];
};

