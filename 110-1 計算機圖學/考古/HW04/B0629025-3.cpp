#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

const int n = 10000;
const int k = 360;
float pi = 3.1415926536f;

void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,300.0,0.0,300.0);
}
void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //Two-Dimensional Scaling
	
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		for(int i=0;i<3;i++)
			glVertex2f(150+50*cos(-0.524+2*pi/3*i),150+50*sin(-0.524+2*pi/3*i));
	glEnd();
    glFlush();
	
    glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
		for(int i=0;i<3;i++)
			glVertex2f(150+25*cos(-0.524+2*pi/3*i),150+25*sin(-0.524+2*pi/3*i));
	glEnd();
    glFlush();
    

}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("hw04-3");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
    return 0;
}
