#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>
#include <time.h>
void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, 600.0, 0.0, 600.0);
}
void lineSegment(void)
{

    float xy[80][2];
    float xy1[80][2];
     int w [80] ;
     int b [80] ;
    int number=0;

    int r,t;
    for(int i =0 ; i < 80 ; i++)
    {

		xy[number][0]=rand() % 18;
        xy[number][1]=rand() % 18;
        start:
        xy1[number][0]=rand() % 18;
        xy1[number][1]=rand() % 18;
        if(xy[number][0]==xy1[number][0]&&xy[number][1]==xy1[number][1])
            goto start;




            number++;
	}
    number=0;





    glClear (GL_COLOR_BUFFER_BIT);


   for(int i=0;i<19;i++)
    {
        glBegin (GL_LINES);
        glColor3f (0.0, 0.0, 0.0);
        glVertex2f (i*30,0);
        glVertex2f (i*30,570);
        glEnd ( );
    }

    for(int i=0;i<19;i++)
    {
        glBegin (GL_LINES);
        glColor3f (0.0, 0.0, 0.0);
        glVertex2f (0,i*30);
        glVertex2f (570,i*30);
        glEnd ( );
    }
    for(int j=0;j<80;j++)
    {
        glBegin (GL_POLYGON);//
       for(float i =0 ; i <= 360; i+=0.01)
            {

                glColor3f (0, 0, 0);
                glVertex2f (30*(xy[j][0])+3*cos(i*M_PI/180), 30*(xy[j][1])+3*sin(i*M_PI/180));
            }
    glEnd();
    }

    for(int j=0;j<80;j++)
    {
        glBegin (GL_POLYGON);//
       for(float i =0 ; i <= 360; i+=0.01)
            {

                glColor3f (1, 0.9, 0.9);
                glVertex2f (30*(xy1[j][0])+3*cos(i*M_PI/180), 30*(xy1[j][1])+3*sin(i*M_PI/180));
            }
    glEnd();
    }








    glFlush ( );
}
int main (int argc, char** argv)
{
    srand( time(NULL) );
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50, 100);//µøµ¡¦ì¸m
    glutInitWindowSize (600, 600);
    glutCreateWindow ("B0429012");
    init ( );
    glutDisplayFunc (lineSegment);
    glutMainLoop ( );
}
