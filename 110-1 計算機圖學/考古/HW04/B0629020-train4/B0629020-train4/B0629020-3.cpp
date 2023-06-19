#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <GL/glut.h> 
#define PI 3.1415926535898
GLfloat arr[3][2];
 
void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D(-50,50,-50,50);
}
 
void scale(float sx, float sy, float arr[][2], int i)
{
     arr[i][0]=arr[i][0]*sx; // x = x*s  s���Y�p�T�� 
     arr[i][1]=arr[i][1]*sy; // y = y*s  s���Y�p�T�� 
}

void display(void)
{
     glClearColor(1,1,1,0);
     glClear(GL_COLOR_BUFFER_BIT);
     
     //���� 
     glColor3f(1,0,0);
     glBegin(GL_POLYGON);
     for(int i=0;i<3;i++)
	 {
		arr[i][0]=20*cos((90+120*i)*PI/180);
		arr[i][1]=20*sin((90+120*i)*PI/180);
		glVertex2fv(arr[i]);
     }
     glEnd();
     
     //��� 
     glColor3f(0,1,0);
     glBegin(GL_POLYGON);
     for(int i=0;i<3;i++)
	 {
		scale(0.5,0.5,arr,i); // ���T���ά�����T�����Y�p0.5�� 
		glVertex2fv(arr[i]); //�L�X�Y�p�᪺���T���� 
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
	glutCreateWindow("Q3");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
