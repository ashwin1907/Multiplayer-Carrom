#include "../include/utilities.h"
#include <GL/glut.h>
#include <cmath>
void drawCircle(float x, float y,float z, float r)
{			//Draws solid circles on the board using triangle fan
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(x,y,z);
	for(int i=0;i<=180;i++)
	{
		double t=i*M_PI/90;
		glVertex3f(x+r*cos(t),y+r*sin(t),z);
	}
	glEnd();
}
void drawCircle_trans(float x, float y,float z, float r)
{			//Draws hollow circles on the board using line loop
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<=180;i++)
	{
		double t=i*M_PI/90;
		glVertex3f(x+r*cos(t),y+r*sin(t),z);
	}
	glEnd();
}

void makeFan(float r,float R)
{			//Makes the fan present at the centre of the board
	glPushMatrix();
	float deg=45;
	for(int i=1;i<=8;i++)
	{
		glBegin(GL_TRIANGLES);
		glVertex3f(r,0,0);
		glVertex3f(R,0,0);
		glVertex3f(r,r-0.03,0);
		glEnd();
		glColor3f(0.8,0,0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(r,0,0);
		glVertex3f(R,0,0);
		glVertex3f(r,-r+0.03,0);
		glEnd();
		glColor3f(0,0,0);
		glRotatef(deg,0,0,1);
		deg+=45;
	}
	glPopMatrix();
}


