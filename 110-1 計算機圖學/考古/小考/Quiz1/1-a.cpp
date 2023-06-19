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
	
	//三角形 
  	glColor3f (0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
	   	for(i=0;i<n;i+=120)
		{
	   		glVertex2f(50 + r*sin(2*PI/n*i), 50 + r*cos(2*PI/n*i));
	   	}
    glEnd();
    
    //小三角形 
    glColor3f (1.0, 1.0, 1.0);
    glBegin (GL_POLYGON);
	   	glVertex2i (50-13,50+7);
		glVertex2i (50+13,50+7);
		glVertex2i (50,50-15);
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
