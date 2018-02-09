/*
* Oscar Emiliano Cervantes del Valle A01332891
* Alison Ricardo González Cortés A01064754
* Alfredo Puente Vasconcelos A01332573
* Irvin Uriel Mundo Rivera A01333820
*/

#include "..\header\cRobot.h"

Robot::Robot()
{
	for (int i = 0; i < ROBOTPARTS; i++)
	{
		parts[i] = new Part(1, 1, 1);
		rotX[i] = 0.0f;
	}
	parts[HEAD]->r = 0;
	parts[HEAD]->g = 0;
	parts[HEAD]->b = 1;
	
	parts[BODY]->r = 0.8;
	parts[BODY]->g = 0;
	parts[BODY]->b = 0;
	
	parts[LSHOULDER]->r = 0.8;
	parts[LSHOULDER]->g = 0;
	parts[LSHOULDER]->b = 0;
	
	parts[RSHOULDER]->r = 0.8;
	parts[RSHOULDER]->g = 0;
	parts[RSHOULDER]->b = 0;
	
	parts[LFOREARM]->r = 0.8;
	parts[LFOREARM]->g = 0;
	parts[LFOREARM]->b = 0;
	
	parts[RFOREARM]->r = 0.8;
	parts[RFOREARM]->g = 0;
	parts[RFOREARM]->b = 0;

	//Forearm between wrist and elbow
	
	parts[LHAND]->r = 0;
	parts[LHAND]->g = 0;
	parts[LHAND]->b = 1;
	
	parts[RHAND]->r = 0;
	parts[RHAND]->g = 0;
	parts[RHAND]->b = 1;
	
	parts[HIP]->r = 0.5;
	parts[HIP]->g = 0.5;
	parts[HIP]->b = 0.5;
	
	parts[LLEG]->r = 0;
	parts[LLEG]->g = 0;
	parts[LLEG]->b = 1;
	
	parts[RLEG]->r = 0;
	parts[RLEG]->g = 0;
	parts[RLEG]->b = 1;
	
	parts[LFOOT]->r = 0;
	parts[LFOOT]->g = 0;
	parts[LFOOT]->b = 1;
	
	parts[RFOOT]->r = 0;
	parts[RFOOT]->g = 0;
	parts[RFOOT]->b = 1;
}

Robot::~Robot()
{
}

void Robot::draw()
{
	glPushMatrix();
	{
		//glTranslatef(0, 2, 0);		//Mueve las cosas
		glRotatef(anguloBody, 0, 1, 0);
		glScalef(1.0f, 0.7f, 1.0f);		//Escalar (agrandar, ensanchar, etc).
		parts[BODY]->draw();	// cube, side 1
		glPushMatrix();
		{
			//glRotatef(rotY[NECK], 0, 1, 0);
			glTranslatef(0, 0.5, 0);
			glPushMatrix();
			{
				glRotatef(anguloCabeza, 0, 1, 0);
				glScalef(0.3, 0.45, 0.3);
				parts[NECK]->draw();
			}
			glPopMatrix();
			glRotatef(anguloCabeza, 0, 1, 0);
			glTranslatef(0, 0.5, 0);
			glScalef(0.4f, 0.6f, 0.4f);
			parts[HEAD]->draw();
		}
		glPopMatrix();

		//LEFT ARM
		glPushMatrix();
		{
			glRotatef(anguloHombroBrazo, 1, 0, 0);
			glTranslatef(0.7, 0.5, 0);
			glScalef(0.3, 0.3, 0.3);
			parts[LSHOULDER]->draw();
			glPushMatrix();
			{
				glTranslatef(0.0, -1.1, 0);
				glScalef(0.7, 0.8, 0.8);
				parts[LARM]->draw();
				glPushMatrix();
				{
					glTranslatef(0.0, -3.5, 0);
					glScalef(1.5, 6, 1.5);
					parts[LFOREARM]->draw();
					glPushMatrix();
					{
						glTranslatef(0.0, -0.7, 0);
						glScalef(0.7, 0.3, 1);
						parts[LHAND]->draw();
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();

		//RIGHT ARM
		glPushMatrix();
		{
			glTranslatef(-0.7, 0.5, 0);
			glScalef(0.3, 0.3, 0.3);
			parts[RSHOULDER]->draw();
			glPushMatrix();
			{
				glTranslatef(0.0, -1.1, 0);
				glScalef(0.7, 0.8, 0.8);
				parts[RARM]->draw();
				glPushMatrix();
				{
					glTranslatef(0.0, -1.2, 0);
					glScalef(1.5, 6, 1.5);
					parts[RFOREARM]->draw();
					glPushMatrix();
					{
						glTranslatef(0.0, -0.7, 0);
						glScalef(0.7, 0.3, 1);
						parts[RHAND]->draw();
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();

		//Parte Baja
		glPushMatrix();
		{
			glTranslatef(0.0, -0.85, 0);
			glScalef(0.8, 0.5, 0.8);
			parts[ABDOMEN]->draw();
			glPushMatrix();
			{
				glTranslatef(0.0, -0.9, 0);
				glScalef(1.05, 0.6, 1.05);
				parts[HIP]->draw();

				//Pierna izquierda
				glPushMatrix();
				{
					glTranslatef(0.4, -2.5, 0);
					glScalef(0.4, 4, 0.5);
					parts[LTIGH]->draw();
					glPushMatrix();
					{
						glTranslatef(0, -1, 0);
						glScalef(1.1, 1, 1);
						parts[LLEG]->draw();
						glPushMatrix();
						{
							glTranslatef(0, -0.3, 0.8);
							glScalef(1, 0.3, 0.8);
							parts[LFOOT]->draw();
						}
						glPopMatrix();
					}
					glPopMatrix();
				}
				glPopMatrix();

				//Pierna derecha
				glPushMatrix();
				{
					glTranslatef(-0.3, -2.5, 0);
					glScalef(0.4, 4, 0.5);
					parts[RTIGH]->draw();
					glPushMatrix();
					{
						glTranslatef(0, -1, 0);
						glScalef(1.1, 1, 1);
						parts[RLEG]->draw();
						glPushMatrix();
						{
							glTranslatef(0, -0.3, 0.8);
							glScalef(1, 0.3, 0.8);
							parts[RFOOT]->draw();
						}
						glPopMatrix();
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Robot::update()
{
	anguloCabeza += dirCabeza * 0.001f;				//Velocidad a la que se mueve
	if (anguloCabeza > 10 || anguloCabeza < -10) {
		dirCabeza = -dirCabeza;
	}
	anguloBody += dirBody * 0.002f;
	if (anguloBody > 5 || anguloBody < -5) {
		dirBody = -dirBody;
	}
	anguloHombroBrazo += dirHombroBrazo * 0.005f;
	if (anguloHombroBrazo > 15 || anguloHombroBrazo < -15) {
		dirHombroBrazo = -dirHombroBrazo;
	}
}