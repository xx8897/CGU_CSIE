#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, 400.0, 0.0, 400.0);
}
void lineSegment(void)
{

    float x[4];
    float y[4];
    int number=0;
    x[0]=200+100*cos(90*3.1415926/180);
    y[0]=200+100*sin(90*3.1415926/180);
    x[1]=200+100*cos(210*3.1415926/180);
    y[1]=200+100*sin(210*3.1415926/180);
	x[2]=200+100*cos(330*3.1415926/180);
    y[2]=200+100*sin(330*3.1415926/180);




    glClear (GL_COLOR_BUFFER_BIT);

    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =0 ; i <= 360; i+=0.01)
    {
		glVertex2f (200+200*cos(i*3.14159265359/180),200+200*sin(i*3.14159265359/180));
	}
    glEnd ( );

    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =0 ; i <= 360; i+=0.01)
    {
		glVertex2f (200+100*cos(i*3.14159265359/180),200+100*sin(i*3.14159265359/180));
	}
    glEnd ( );

    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =0 ; i <= 360; i+=0.01)
    {
		glVertex2f (x[0]+30*cos(i*3.14159265359/180),y[0]+30*sin(i*3.14159265359/180));
	}
    glEnd ( );

    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =0 ; i <= 360; i+=0.01)
    {
		glVertex2f (x[1]+30*cos(i*3.14159265359/180),y[1]+30*sin(i*3.14159265359/180));
	}
    glEnd ( );

    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =0 ; i <= 360; i+=0.01)
    {
		glVertex2f (x[2]+30*cos(i*3.14159265359/180),y[2]+30*sin(i*3.14159265359/180));
	}
    glEnd ( );

    glBegin (GL_POLYGON);
    glColor3f (1.0, 1.0, 1.0);
    for(float i =90 ; i <= 450; i+=120)
    {
		glVertex2f (200+100*cos(i*3.14159265359/180),200+100*sin(i*3.14159265359/180));
	}
    glEnd ( );

    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =90 ; i <= 450; i+=120)
    {
		glVertex2f (200+100*cos(i*3.14159265359/180),200+100*sin(i*3.14159265359/180));
	}
    glEnd ( );

    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =0 ; i <= 360; i+=0.01)
    {
		glVertex2f (200+30*cos(i*3.14159265359/180),200+30*sin(i*3.14159265359/180));
	}
    glEnd ( );


    glFlush ( );
}
int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50, 100);//µøµ¡¦ì¸m
    glutInitWindowSize (400, 400);
    glutCreateWindow ("B0429012");
    init ( );
    glutDisplayFunc (lineSegment);
    glutMainLoop ( );
}
