#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>
#include <GL/glui.h>
#include "./include/table.h"
#include "./include/utilities.h"

#include <iostream>
#include <stdlib.h> 
#include <GL/glut.h>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
int sockfd;
int sockfd1;
int sockfd2;
int svr;
GLUI_StaticText *scor_e[4];
int flag2 = 0;
int flag10 = 0;
int flag_display = 0;
int main_window;
GLUI *glui, *glui2;
int difficulty = 0;

struct abc{
char player_name0[20];
char player_name1[20];
char player_name2[20];
char player_name3[20];
};

struct abc names;

int N;
int M;
int myturn;
int players;
struct Coin
{
	float radius;
	float x;
	float y;
	float vx;
	float vy;
	int collision_no;
};
struct Coin * Arr;
struct start
{
	int p;
	int m;
};
struct start tur;
void rules();
void place(char ch);
#include "./src/rules.cpp"
#define aimlen 0.25
#define aimlen_back 0.15

#define dt 0.017


void proceed2(int a);
void proceed1(int a);
void proceed(int a);
void initial(int a);
void drawTable(void);
void drawCircle(float, float, float, float);
void drawCircle_trans(float x, float y,float z, float r);
void makeFan(float, float);
void makeCircle1(float x);
void handleKeypress(unsigned char key, int x, int y);
void update(int value);
void error(const char *msg);
void collision(struct Coin* A,struct Coin* B,double d1,double K);
void* physics(char *ch);


void processMouse(int button, int state, int x, int y);
void processMousePassiveMotion(int x, int y);
void update_scores();

using namespace std;

#define L 690
#define d 0.7
#define r 0.04
#define r1 r-0.005
#define Rh 0.06

float mousex=0;
float mousey=-d;
int clickl=0;
#define E 0.5
#define EW 0.8
#define mu .33
int bot=0;

#define mass_ratio 2
#include "./src/bot.cpp"
#include "./src/physics.cpp"
#include "./src/mouse.cpp"
#include "./src/glui.cpp"
void handleKeypress(unsigned char key, int x, int y)
{					//Listens to key press and terminates the program if esc key is pressed
	switch(key)
	{
	case 27:
	exit(0);
	}
}

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.85f, 0.67f, 0.37f, 0.0f);
}

void myGlutIdle( void )
{
if ( glutGetWindow() != main_window ) 
	glutSetWindow(main_window);  
glutPostRedisplay();
}

void myGlutReshape( int x, int y )
{					//Handles reshape of the board
glutReshapeWindow(L+240, L);
glViewport(0,0,L,L);
glutPostRedisplay();
}

void drawScene()	
{                                       // Draws openGL window while playing the game
if (flag_display==0)
	{
	glClearColor(0.85f, 0.67f, 0.37f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode( GL_PROJECTION );
   	glLoadIdentity();
   	gluOrtho2D( 0.0, 100.0, 0.0, 100.0  );
    	glMatrixMode( GL_MODELVIEW );
    	glLoadIdentity();
    	glColor3ub( 0.34, 0.56, 0.69 );
    	glRasterPos2i( 45, 55 );
	int i;
	char carrom[10] = "CARROM";
    	for( i=0; i<(int)strlen( carrom ); i++ )
      		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24 , carrom[i] );
	glutSwapBuffers();
	}
else
	{
	if(flag2==1)
	{
		update_scores();
		flag2=0;
	}
	glClearColor(0.85f, 0.67f, 0.37f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode( GL_PROJECTION );
   	glLoadIdentity();
   	gluOrtho2D( 0.0, 100.0, 0.0, 100.0  );
    	glMatrixMode( GL_MODELVIEW );
    	glLoadIdentity();
    	glColor3ub( 0.34, 0.56, 0.69 );
    	glRasterPos2i( 45, 6 );
	int i;
    	for( i=0; i<(int)strlen( my_name ); i++ )
      		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24 , my_name[i] );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glRotatef(90*myturn,0,0,1);
	drawTable(d,r,r1,Rh);
	for(int i=0;i<=N;i++)
	{
		if(Arr[i].radius==-1)
		continue;
		if(i==N)
		glColor3f(0,0.7,0.7);
		else if(i==0)
		glColor3f(1,0,1);
		else if(i % 2==0)
		glColor3f(1,1,1);
		else
		glColor3f(0.4,0.4,0.4);
		if(i==N)
		drawCircle(Arr[i].x,Arr[i].y,-0.12,Arr[i].radius);
		else
		drawCircle(Arr[i].x,Arr[i].y,-0.1,Arr[i].radius);
		glColor3f(0,0,0);
		if(i!=N)
		{
		drawCircle_trans(Arr[i].x,Arr[i].y,-0.11,Arr[i].radius);
		drawCircle_trans(Arr[i].x,Arr[i].y,-0.11,Arr[i].radius-0.01);
		drawCircle_trans(Arr[i].x,Arr[i].y,-0.11,Arr[i].radius-0.027);
		}
	}	
	if(clickl==1)
	{
		glColor3f(0,0,0);
		glLineWidth(2);
		glBegin(GL_LINES);
		glVertex3f(Arr[N].x,Arr[N].y,-0.13);
		glVertex3f(mousex,mousey,-0.13);
		glEnd();
	}
	glRotatef(-90*myturn,0,0,1);
	glutSwapBuffers();
}
}

void *timer(void* s)
{				//Redraws the board
	glutPostRedisplay();
}

void update(int value)
{				//Updates the positions of coins, includes physics, rules, computer player(if any), and board redrawing function
	static int end_flag=0;
	pthread_t thread1, thread2;
	char message1[10] = "Thread 1";
	int iret1 = pthread_create( &thread1, NULL, physics, (void*) message1);
	int iret2 = pthread_create( &thread2, NULL, timer, (void*) message1);
	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);
	if(M==0 && foul==0 && Arr[N].vx==0 && Arr[N].vy==0 && end_flag==0)
	{
		end();
		end_flag=1;
	}
	else
	glutTimerFunc(15, update, 0);
}

void error(const char *msg)
{				//Prints error message on standard error output in case of error in networking
    perror(msg);
    exit(1);
}

int main(int argc,char**argv) 
{				//main function-->registers callback functions, creates glui window and takes inputs from file 
glutInit(&argc, argv);
glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
glutInitWindowPosition( 0, 0 );
glutInitWindowSize( L + 240, L );
main_window = glutCreateWindow( "Carrom" );
glutDisplayFunc( drawScene );
glutReshapeFunc ( myGlutReshape );  
glutKeyboardFunc ( handleKeypress );
glutMouseFunc(processMouse);
glutPassiveMotionFunc(processMousePassiveMotion);
strcpy (names.player_name1 ,"BOT 1");
strcpy (names.player_name2 ,"BOT 2");
strcpy (names.player_name3 ,"BOT 3");
  	ifstream ifs( "./src/data.txt" );
 	string temp;
	char * ch;
	int i=0;
	getline(ifs,temp);
	ch = new char [temp.size()+1];
	strcpy(ch,temp.c_str());
	N=atoi(ch);
	M=N;
	Arr=new struct Coin [N+1+3];
	for(int i=0;i<N;i++)
	{
		getline( ifs, temp );
		char * cstr, *p;
		cstr = new char [temp.size()+1];
		strcpy (cstr, temp.c_str());
		p= strtok(cstr,"\t");
		p=strtok(NULL,"\t");
		Arr[i].radius=atof(p);
		p=strtok(NULL,"\t");
		Arr[i].x=atof(p);
		p=strtok(NULL,"\t");
		Arr[i].y=atof(p);
		p=strtok(NULL,"\t");
		Arr[i].vx=atof(p);
		p=strtok(NULL,"\t");
		Arr[i].vy=atof(p);
		p=strtok(NULL,"\t");
		Arr[i].collision_no=-5;
		
	}
	Arr[N].radius=0.05;
	Arr[N].x=0;
	Arr[N].y=-d;
	Arr[N].vx=0;
	Arr[N].vy=0;
	Status0=new int[N+1];
	Status1=new int[N+1];
	Status2=new int[N+1];
	Status3=new int[N+1];
	Status_current=new int[N+1];
	for(int i=0;i<=N;i++)
	{
		Status0[i]=0;
		Status1[i]=0;
		Status2[i]=0;
		Status3[i]=0;
		Status_current[i]=0;;
	}
glEnable(GL_DEPTH_TEST);
glui = GLUI_Master.create_glui_subwindow( main_window, GLUI_SUBWINDOW_RIGHT );
glui->add_statictext( "WELCOME TO COMPUTER GAMES" );
glui->add_statictext( "CARROM 3.0" );
initial(1);
GLUI_Master.set_glutIdleFunc( myGlutIdle );
glutDisplayFunc( drawScene );
glutTimerFunc(15, update, 0);
glutMainLoop();
return EXIT_SUCCESS;
}
