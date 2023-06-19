#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,100.0,0.0,100.0);
}
const int n =1000;
float Pi = 3.1415926536f;
void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (int i=0;i<n;++i){
            glVertex2f(45+10*cos(2*Pi/n*i),75+10*sin(2*Pi/n*i));
        }
    glEnd();
    glFlush();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (int i=0;i<n;++i){
            glVertex2f(45+10*cos(2*Pi/n*i),65+10*sin(2*Pi/n*i));
        }
    glEnd();
    glFlush();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (int i=0;i<n;++i){
            glVertex2f(53+10*cos(2*Pi/n*i),70+10*sin(2*Pi/n*i));
        }
    glEnd();
    glFlush();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (int i=0;i<n;++i){
            glVertex2f(53+10*cos(2*Pi/n*i),60+10*sin(2*Pi/n*i));
        }
    glEnd();
    glFlush();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (int i=0;i<n;++i){
            glVertex2f(45+10*cos(2*Pi/n*i),55+10*sin(2*Pi/n*i));
        }
    glEnd();
    glFlush();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (int i=0;i<n;++i){
            glVertex2f(36+10*cos(2*Pi/n*i),60+10*sin(2*Pi/n*i));
        }
    glEnd();
    glFlush();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (int i=0;i<n;++i){
            glVertex2f(36+10*cos(2*Pi/n*i),70+10*sin(2*Pi/n*i));
        }
    glEnd();
    glFlush();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (int i=0;i<n;++i){
            glVertex2f(45+21*cos(2*Pi/n*i),65+21*sin(2*Pi/n*i));
        }
    glEnd();
    glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("My Program");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
    return 0;
}
