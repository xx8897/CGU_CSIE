#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <GL/glut.h>
#include<math.h>
#define PI 3.1415926535898

void init(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D (0.0, 100.0, 0.0, 100.0);
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	int n=360,r=30,i,j;	//n是圓周角度；r是圓半徑 
	
	//三角形-上 
  	glColor3f (0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
		glVertex2i (37,63);
	   	glVertex2i (50,85);
		glVertex2i (63,63);
    glEnd();
    
    //三角形-下 
  	glColor3f (0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
	   	glVertex2i (37,37);
		glVertex2i (50,15);
		glVertex2i (63,37);
    glEnd();
    
    //三角形-右 
   	glColor3f (0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
	   	glVertex2i (63,63);
		glVertex2i (63,37);
		glVertex2i (85,50);
    glEnd();
    
    //三角形-左 
   	glColor3f (0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
	   	glVertex2i (37,63);
		glVertex2i (37,37);
		glVertex2i (15,50);
    glEnd();
    
    glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(350,350);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Q1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
