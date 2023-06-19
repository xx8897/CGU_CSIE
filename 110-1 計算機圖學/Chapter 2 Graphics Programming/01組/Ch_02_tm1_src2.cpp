#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<cmath>

#define pi acos(-1)

void init (void)
{    
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 300.0, 0.0, 300.0);
}

void show (void)
{    
	glClear (GL_COLOR_BUFFER_BIT);
	glLineWidth(1);
	glBegin (GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i (25, 205);
		glVertex2i (25, 225);
		glVertex2i (55, 225);
		glVertex2i (55, 205);		
	glEnd ( );
	
	glBegin (GL_POLYGON);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2i (25, 190);
		glVertex2i (55, 190);
		glVertex2i (55, 170);
		glVertex2i (25, 170);		
	glEnd ( );
	
	glBegin (GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i (25, 155);
		glVertex2i (55, 155);
		glVertex2i (55, 135);
		glVertex2i (25, 135);		
	glEnd ( );
	
	glBegin (GL_LINE_LOOP);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i (25, 155);
		glVertex2i (55, 155);
		glVertex2i (55, 135);
		glVertex2i (25, 135);	
	glEnd ( );
	
	glEnable (GL_LINE_SMOOTH);
	glHint (GL_LINE_SMOOTH, GL_NICEST);
	glLineWidth(10);
	
	glBegin (GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 1.0);
		for(float i=0; i<10000; i++)
		{
			glVertex2f(110+25*cos(2*i*pi/10000), 200+25*sin(2*i*pi/10000));
		}	
	glEnd ( );
	
	glBegin (GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		for(float i=0; i<10000; i++)
		{
			glVertex2f(175+25*cos(2*i*pi/10000), 200+25*sin(2*i*pi/10000));
		}	
	glEnd ( );
	
	glBegin (GL_LINE_LOOP);
		glColor3f(1.0, 0.0, 0.0);
		for(float i=0; i<10000; i++)
		{
			glVertex2f(240+25*cos(2*i*pi/10000), 200+25*sin(2*i*pi/10000));
		}	
	glEnd ( );
	
	glBegin (GL_LINE_LOOP);
		glColor3f(1.0, 1.0, 0.0);
		for(float i=0; i<10000; i++)
		{
			glVertex2f(142.5+25*cos(2*i*pi/10000), 175+25*sin(2*i*pi/10000));
		}	
	glEnd ( );
	
	glBegin (GL_LINE_LOOP);
		glColor3f(0.0, 1.0, 0.0);
		for(float i=0; i<10000; i++)
		{
			glVertex2f(207.5+25*cos(2*i*pi/10000), 175+25*sin(2*i*pi/10000));
		}	
	glEnd ( );
	
	glFlush ( );
}

int main (int argc, char** argv)
{    
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (50, 100);
	glutInitWindowSize (600, 600);
	glutCreateWindow ("B0729056_Training-1");
	
	init ( ); 
	glutDisplayFunc (show);
	glutMainLoop ( );
}
