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
     GLfloat Ver[3][2]={{200,300},{100,150},{300,150}};
     GLfloat Ver1[3][2];
     
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_POLYGON);
     glVertex2i(Ver[0][0],Ver[0][1]);
     glVertex2i(Ver[1][0],Ver[1][1]);
     glVertex2i(Ver[2][0],Ver[2][1]);
     glEnd();
     
     for(int i=0; i<3; i++)
     {
     		 
             Ver1[i][0]=200+(Ver[i][0]-200)*cos(30)-(Ver[i][1]-200)*sin(30);
             Ver1[i][1]=200+(Ver[i][0]-200)*sin(30)+(Ver[i][1]-200)*cos(30);      
     }
     
     glColor3f(0.0,1.0,0.0);
     glBegin(GL_POLYGON);
     glVertex2i(Ver1[0][0],Ver1[0][1]);
     glVertex2i(Ver1[1][0],Ver1[1][1]);
     glVertex2i(Ver1[2][0],Ver1[2][1]);
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
