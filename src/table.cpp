#include "../include/table.h"
#include "../include/utilities.h"
#include <GL/glut.h>
#include <cmath>

void drawTable(float d, float r, float r1, float Rh)
{			//Draws the table without the coins. The table brawn is same everytime.
	glColor3f(0, 0, 0);

	glLineWidth(1);
	glBegin(GL_QUADS);

	
	glVertex3f(0.95,-1,0);
	glVertex3f(1,-1,0);
	glVertex3f(1,1,0);
	glVertex3f(0.95,1,0);

	glVertex3f(-0.95,-1,0);
	glVertex3f(-1,-1,0);
	glVertex3f(-1,1,0);
	glVertex3f(-0.95,1,0);
	
	glVertex3f(-0.95,-0.95,0);
	glVertex3f(0.95,-0.95,0);
	glVertex3f(0.95,-1,0);
	glVertex3f(-0.95,-1,0);
	
	glVertex3f(-0.95,0.95,0);
	glVertex3f(0.95,0.95,0);
	glVertex3f(0.95,1,0);
	glVertex3f(-0.95,1,0);
	
	glEnd();


	
	drawCircle_trans(d-0.1,d,0,r);
	drawCircle_trans(d,d-0.1,0,r);
	drawCircle_trans(-(d-0.1),d,0,r);
	drawCircle_trans(-d,d-0.1,0,r);
	drawCircle_trans(-d,-d+0.1,0,r);
	drawCircle_trans(-d+0.1,-d,0,r);
	drawCircle_trans(d,-d+0.1,0,r);
	drawCircle_trans(d-0.1,-d,0,r);

	
	glColor3f(0.2,0.2,0.2);
	drawCircle(-0.89,-0.89,0,Rh);
	drawCircle(-0.89,0.89,0,Rh);
	drawCircle(0.89,-0.89,0,Rh);
	drawCircle(0.89,0.89,0,Rh);
	

	glColor3f(.8, 0, 0);
	drawCircle(d-0.1,d,0,r1);
	drawCircle(d,d-0.1,0,r1);
	drawCircle(-(d-0.1),d,0,r1);
	drawCircle(-d,d-0.1,0,r1);
	drawCircle(-d,-d+0.1,0,r1);
	drawCircle(-d+0.1,-d,0,r1);
	drawCircle(d,-d+0.1,0,r1);
	drawCircle(d-0.1,-d,0,r1);
	

	glColor3f(0, 0, 0);

	
	glBegin(GL_LINES);
	glVertex3f(d-0.1,d-r,0);
	glVertex3f(-d+0.1,d-r,0);
	glVertex3f(d-0.1,r-d,0);
	glVertex3f(-d+0.1,r-d,0);
	glVertex3f(d-r,d-0.1,0);
	glVertex3f(d-r,-d+0.1,0);
	glVertex3f(r-d,d-0.1,0);
	glVertex3f(r-d,-d+0.1,0);
	glEnd();
	
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(d-0.1,d+r,0);
	glVertex3f(-d+0.1,d+r,0);
	glVertex3f(d-0.1,-r-d,0);
	glVertex3f(-d+0.1,-r-d,0);
	glVertex3f(d+r,d-0.1,0);
	glVertex3f(d+r,-d+0.1,0);
	glVertex3f(-r-d,d-0.1,0);
	glVertex3f(-r-d,-d+0.1,0);
	glEnd();
	
	
	glBegin(GL_LINES);
	glVertex3f(0.45,0.45,0);
	glVertex3f(0.76,0.76,0);
	glVertex3f(-0.45,0.45,0);
	glVertex3f(-0.76,0.76,0);
	glVertex3f(0.45,-0.45,0);
	glVertex3f(0.76,-0.76,0);
	glVertex3f(-0.45,-0.45,0);
	glVertex3f(-0.76,-0.76,0);
	glEnd();

	glLineWidth(1);
	
	glBegin(GL_TRIANGLES);
	glVertex3f(0.76,0.76,0);
	glVertex3f(0.73,0.75,0);
	glVertex3f(0.75,0.73,0);
	glVertex3f(-0.76,0.76,0);
	glVertex3f(-0.73,0.75,0);
	glVertex3f(-0.75,0.73,0);
	glVertex3f(-0.76,-0.76,0);
	glVertex3f(-0.73,-0.75,0);
	glVertex3f(-0.75,-0.73,0);
	glVertex3f(0.76,-0.76,0);
	glVertex3f(0.73,-0.75,0);
	glVertex3f(0.75,-0.73,0);
	glEnd();

	drawCircle_trans(0,0,0,5*r);
	
	glColor3f(0.8,0,0);
	drawCircle(0,0,0,r);
	glColor3f(0,0,0);
	drawCircle_trans(0,0,0,r+0.005);
	drawCircle_trans(0,0,0,5*r);
	drawCircle_trans(0,0,0,5*r+0.01);

	makeFan(r+0.01,5*r);
	glLineWidth(2);
	drawCircle_trans(0.65,0.65,0,0.03);
	drawCircle_trans(-0.65,0.65,0,0.03);
	drawCircle_trans(-0.65,-0.65,0,0.03);
	drawCircle_trans(0.65,-0.65,0,0.03);

	makeCircle1(0.45);
}

void makeCircle1(float x)
{			//Make special kinds of circles with arrows present along four diagonals of the board
	glLineWidth(1);
	float r=0.1;
	glBegin(GL_LINES);
	for(int i=80;i<=370;)
	{
		double t=i*M_PI/180;
		glVertex3f(x+r*cos(t),x+r*sin(t),0);
		i++;
		t=i*M_PI/180;
		glVertex3f(x+r*cos(t),x+r*sin(t),0);
	}
	for(int i=-190;i<=100;)
	{
		double t=i*M_PI/180;
		glVertex3f(-x+r*cos(t),x+r*sin(t),0);
		i++;
		t=i*M_PI/180;
		glVertex3f(-x+r*cos(t),x+r*sin(t),0);
	}
	for(int i=-100;i<=190;)
	{
		double t=i*M_PI/180;
		glVertex3f(-x+r*cos(t),-x+r*sin(t),0);
		i++;
		t=i*M_PI/180;
		glVertex3f(-x+r*cos(t),-x+r*sin(t),0);
	}
	for(int i=-10;i<=280;)
	{
		double t=i*M_PI/180;
		glVertex3f(x+r*cos(t),-x+r*sin(t),0);
		i++;
		t=i*M_PI/180;
		glVertex3f(x+r*cos(t),-x+r*sin(t),0);
	}
	glEnd();
	double t1=80*M_PI/180;
	double t2=370*M_PI/180;
	double t3=100*M_PI/180;
	double t4=-190*M_PI/180;
	double t5=280*M_PI/180;
	double t6=-10*M_PI/180;
	double t7=-100*M_PI/180;
	double t8=190*M_PI/180;
	glBegin(GL_TRIANGLES);
	glVertex3f(x+r*cos(t1),x+r*sin(t1),0);
	glVertex3f(x+r*cos(t1)-0.03,x+r*sin(t1)+0.01,0);
	glVertex3f(x+r*cos(t1)-0.03,x+r*sin(t1)-0.01,0);
	glVertex3f(x+r*cos(t2),x+r*sin(t2),0);
	glVertex3f(x+r*cos(t2)-0.01,x+r*sin(t2)-0.03,0);
	glVertex3f(x+r*cos(t2)+0.01,x+r*sin(t2)-0.03,0);

	glVertex3f(-x+r*cos(t3),x+r*sin(t3),0);
	glVertex3f(-x+r*cos(t3)+0.03,x+r*sin(t3)+0.01,0);
	glVertex3f(-x+r*cos(t3)+0.03,x+r*sin(t3)-0.01,0);
	glVertex3f(-x+r*cos(t4),x+r*sin(t4),0);
	glVertex3f(-x+r*cos(t4)+0.01,x+r*sin(t4)-0.03,0);
	glVertex3f(-x+r*cos(t4)-0.01,x+r*sin(t4)-0.03,0);

	glVertex3f(x+r*cos(t5),-x+r*sin(t5),0);
	glVertex3f(x+r*cos(t5)-0.03,-x+r*sin(t5)+0.01,0);
	glVertex3f(x+r*cos(t5)-0.03,-x+r*sin(t5)-0.01,0);
	glVertex3f(x+r*cos(t6),-x+r*sin(t6),0);
	glVertex3f(x+r*cos(t6)-0.01,-x+r*sin(t6)+0.03,0);
	glVertex3f(x+r*cos(t6)+0.01,-x+r*sin(t6)+0.03,0);

	glVertex3f(-x+r*cos(t7),-x+r*sin(t7),0);
	glVertex3f(-x+r*cos(t7)+0.03,-x+r*sin(t7)+0.01,0);
	glVertex3f(-x+r*cos(t7)+0.03,-x+r*sin(t7)-0.01,0);
	glVertex3f(-x+r*cos(t8),-x+r*sin(t8),0);
	glVertex3f(-x+r*cos(t8)+0.01,-x+r*sin(t8)+0.03,0);
	glVertex3f(-x+r*cos(t8)-0.01,-x+r*sin(t8)+0.03,0);
	glEnd();
}
