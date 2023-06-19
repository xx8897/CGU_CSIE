#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <GL/glut.h>
#include <math.h> 

void init(void)
{
     glClearColor(1.0,1.0,1.0,0.0);
     glMatrixMode(GL_PROJECTION);
     gluOrtho2D(0.0,400.0,0.0,400.0);
}


void drow(void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     GLfloat Ver[4][2]={{100,100},{200,100},{200,200},{100,200}};
     
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_POLYGON);
     glVertex2i(Ver[0][0],Ver[0][1]);
     glVertex2i(Ver[1][0],Ver[1][1]);
     glVertex2i(Ver[2][0],Ver[2][1]);
     glVertex2i(Ver[3][0],Ver[3][1]); 
     glEnd();
     
     for(int i=0; i<4; i++)
     {
             Ver[i][0]=Ver[i][0]+100;
             Ver[i][1]=Ver[i][1]+100;      
     }
     
     glColor3f(0.0,1.0,0.0);
     glBegin(GL_POLYGON);
     glVertex2i(Ver[0][0],Ver[0][1]);
     glVertex2i(Ver[1][0],Ver[1][1]);
     glVertex2i(Ver[2][0],Ver[2][1]);
     glVertex2i(Ver[3][0],Ver[3][1]); 
     glEnd();
     
     glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("B0329044's-1");
    init();
    glutDisplayFunc(drow);
    glutMainLoop();
}
