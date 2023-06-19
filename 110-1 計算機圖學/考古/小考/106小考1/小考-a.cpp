#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,150.0,0.0,100.0);
}
const int n =1000;
float Pi = 3.1415926536f;
void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    /*glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
      glVertex2i(50,70);
      glVertex2i(33,40);
      glVertex2i(33,40);
      glVertex2i(67,40);
      glVertex2i(67,40);
      glVertex2i(50,70);
    glEnd();
    glFlush();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
      glVertex2i(50,40);
      glVertex2i(41.5,55);
      glVertex2i(41.5,55);
      glVertex2i(58.5,55);
      glVertex2i(58.5,55);
      glVertex2i(50,40);
    glEnd();
    glFlush();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
      glVertex2i(41.5,55);
      glVertex2i(33,60);
      glVertex2i(58.5,55);
      glVertex2i(67,60);
      glVertex2i(50,40);
      glVertex2i(50,30);
    glEnd();
    glFlush();*/ 

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
      for (int i=0;i<6;++i){
            glVertex2f(50+20*cos(0.53+2*Pi/6*i),50+20*sin(0.53+2*Pi/6*i));
        }
    glEnd();
    glFlush();


}


int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(600,400);
    glutCreateWindow("My Program");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
    return 0;
}
