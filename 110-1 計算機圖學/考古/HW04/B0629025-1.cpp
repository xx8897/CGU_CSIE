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
    //Two-Dimensional Translation
    int tx=100;
    int ty=80;
    
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(150,150);
        glVertex2f(150,250);
        glVertex2f(250,250);
        glVertex2f(250,150);
    glEnd();
    glFlush();
    
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(150-tx,150-ty);
        glVertex2f(150-tx,250-ty);
        glVertex2f(250-tx,250-ty);
        glVertex2f(250-tx,150-ty);
    glEnd();
    glFlush();

}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("hw04-1");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
    return 0;
}
