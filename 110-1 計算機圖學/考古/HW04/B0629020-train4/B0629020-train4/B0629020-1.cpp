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
     
     //紅色 
     translate(35,40); //第一次引用translate 使(x,y) = (35,40) 
     glColor3f(1,0,0);
     glBegin(GL_POLYGON);
     for(int i=0;i<4;i++)
	 {
	 	glVertex2f(x+20*cos((45+90*i)*PI/180),y+20*sin((45+90*i)*PI/180));
     }
     glEnd();
     
     //綠色 
     translate(28.5,20);  //第二次引用 從(x,y) = (35,40)開始 往右增加28.5 往上增加20  所以綠色 (x,y) = (63.5,60) 
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
