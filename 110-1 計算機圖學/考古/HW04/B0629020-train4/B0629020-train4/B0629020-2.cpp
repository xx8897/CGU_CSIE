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
 
void rotate(float angle, GLfloat arr[][2],int i)
{	// arr[i][0] �sx  arr[i][1]�sy 
     arr[i][0]=arr[i][0]*cos(angle/180)-arr[i][1]*sin(angle/180); // x = x*cos(angle)-y*sin(angle) 
     arr[i][1]=arr[i][0]*sin(angle/180)+arr[i][1]*cos(angle/180); // y = x*sin(angle)-y*cos(angle)
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
		glVertex2fv(arr[i]); //�s����T���Ψ�}�C 
     }
     glEnd();
     
     //��� 
     glColor3f(0,1,0);
     glBegin(GL_POLYGON);
     for(int i=0;i<3;i++)
	 {
		rotate(45,arr,i); //½��45�� 
		glVertex2fv(arr[i]); //�L�X½��᪺���T���� 
     }
     glEnd();
      
     glFlush();
}
 
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Q2");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
