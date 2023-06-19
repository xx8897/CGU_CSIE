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

    float x[4],x1[4];
    float y[4],y1[4];
    int number=0;
    x[0]=200+200*cos(45*3.1415926/180);
    y[0]=200+200*sin(45*3.1415926/180);
    x[1]=200+200*cos(60*3.1415926/180);
    y[1]=200+200*sin(60*3.1415926/180);
	x[2]=200+200*cos(120*3.1415926/180);
    y[2]=200+200*sin(120*3.1415926/180);
    x[3]=200+200*cos(135*3.1415926/180);
    y[3]=200+200*sin(135*3.1415926/180);

    x1[0]=200+150*cos(45*3.1415926/180);
    y1[0]=200+150*sin(45*3.1415926/180);
    x1[1]=200+150*cos(60*3.1415926/180);
    y1[1]=200+150*sin(60*3.1415926/180);
	x1[2]=200+150*cos(120*3.1415926/180);
    y1[2]=200+150*sin(120*3.1415926/180);
    x1[3]=200+150*cos(135*3.1415926/180);
    y1[3]=200+150*sin(135*3.1415926/180);

    glClear (GL_COLOR_BUFFER_BIT);

    glBegin (GL_POLYGON);
    glColor3f (0.0, 0.0, 1.0);
    for(float i =0 ; i <= 180; i+=0.01)
    {
		glVertex2f (200+200*cos(i*3.14159265359/180),200+200*sin(i*3.14159265359/180));
	}
    glEnd ( );

    glBegin (GL_POLYGON);
    glColor3f (1.0, 0.9, 0.9);
    for(float i =180 ; i <= 360; i+=0.01)
    {
		glVertex2f (200+200*cos(i*3.14159265359/180),200+200*sin(i*3.14159265359/180));
	}
    glEnd ( );

    glBegin (GL_POLYGON);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =0 ; i <= 360; i+=0.01)
    {
		glVertex2f (200+80*cos(i*3.14159265359/180),200+80*sin(i*3.14159265359/180));
	}
    glEnd ( );

    glBegin (GL_POLYGON);
    glColor3f (0.0, 0.0, 0.0);
    glVertex2f (0,195);
	glVertex2f (400,195);
	glVertex2f (400,205);
	glVertex2f (0,205);
    glEnd ( );


    glBegin (GL_POLYGON);
    glColor3f (1.0, 0.9, 0.8);
    for(float i =0 ; i <= 360; i+=0.01)
    {
		glVertex2f (200+50*cos(i*3.14159265359/180),200+50*sin(i*3.14159265359/180));
	}
    glEnd ( );

    glBegin (GL_POLYGON);
    glColor3f (1.0, 1.0, 0.9);
    for(float i =0 ; i <= 360; i+=0.01)
    {
		glVertex2f (200+30*cos(i*3.14159265359/180),200+30*sin(i*3.14159265359/180));
	}
    glEnd ( );

    //
    glBegin (GL_POLYGON);
    glColor3f (1.0, 0.0, 0.0);
    glVertex2f (x[0],y[0]);
	glVertex2f (x[1],y[1]);
	glVertex2f (x1[1],y1[1]);
	glVertex2f (x1[0],y1[0]);
    glEnd ( );

    glBegin (GL_POLYGON);
    glColor3f (1.0, 0.0, 0.0);
    glVertex2f (x[2],y[2]);
	glVertex2f (x[3],y[3]);

	glVertex2f (x1[3],y1[3]);
	glVertex2f (x1[2],y1[2]);
    glEnd ( );



/*
    glBegin (GL_POLYGON);
    glColor3f (0.0, 1.0, 1.0);
    for(float i =0 ; i <= 360; i+=0.01)
    {
		glVertex2f (x[2]+80*cos(i*3.14159265359/180),y[2]+80*sin(i*3.14159265359/180));
	}
    glEnd ( );
    glLineWidth(2.5);
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);

    for(float i =90 ; i < 450 ; i+=72)
    {
		glVertex2f (200+80*cos(i*3.1415926/180),200+80*sin(i*3.1415926/180));
	}
    glEnd ( );*/
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
