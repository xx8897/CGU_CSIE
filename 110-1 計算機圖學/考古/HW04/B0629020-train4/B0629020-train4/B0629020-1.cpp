#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <GL/glut.h> 
#define PI 3.1415926535898
GLfloat x=0,y=0;
 
void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D(0,100,0,100);
}
 
void translate(float tx, float ty)
{
     x=x+tx;
     y=y+ty;
}

void display(void)
{
     glClearColor(1,1,1,0);
     glClear(GL_COLOR_BUFFER_BIT);
     
     //���� 
     translate(35,40); //�Ĥ@���ޥ�translate ��(x,y) = (35,40) 
     glColor3f(1,0,0);
     glBegin(GL_POLYGON);
     for(int i=0;i<4;i++)
	 {
	 	glVertex2f(x+20*cos((45+90*i)*PI/180),y+20*sin((45+90*i)*PI/180));
     }
     glEnd();
     
     //��� 
     translate(28.5,20);  //�ĤG���ޥ� �q(x,y) = (35,40)�}�l ���k�W�[28.5 ���W�W�[20  �ҥH��� (x,y) = (63.5,60) 
     glColor3f(0,1,0);
     glBegin(GL_POLYGON);
     for(int i=0;i<4;i++)
	 {
     	glVertex2f(x+20*cos((45+90*i)*PI/180),y+20*sin((45+90*i)*PI/180));
	 }
	 glEnd();
	  
	 glFlush();
}
 
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Q1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
