#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <GL/glut.h>
#include<math.h>

void init(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D (-100, 100, -100, 100);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex2f (-100,100);
		glVertex2f (100,100);
		glVertex2f (-100,-100);
	glEnd();
	
	glColor3f (0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex2f (-100,-100);
		glVertex2f (100,-100);
		glVertex2f (100, 100);
	glEnd();
	
	int i=100;
	glRotatef(45,0,0,1);	//在xy平面上旋轉45度 
    glColor3f(0.0,0.0,1.0); 
    i=i*0.70710678;	//根號二分之一 
	glBegin(GL_POLYGON);
		glVertex2f (-i,-i);
		glVertex2f (i,-i);
		glVertex2f (i, i);
		glVertex2f (-i,i);
	glEnd();
	glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(350,350);
	glutInitWindowPosition(100,100);
	glutCreateWindow("2-(a)");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
