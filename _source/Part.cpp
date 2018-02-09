/*
* Oscar Emiliano Cervantes del Valle A01332891
* Alison Ricardo González Cortés A01064754
* Alfredo Puente Vasconcelos A01332573
* Irvin Uriel Mundo Rivera A01333820
*/

#include "../header/cPart.h"

Part::Part(float _r, float _g, float _b)
{
	r = _r;
	g = _g;
	b = _b;
}

Part::~Part()
{
}

void Part::draw()
{
	glPushMatrix();
	{
		glColor3f(r, g, b);
		glutSolidCube(1);
	}
	glPopMatrix();
}

void Part::update()
{

}