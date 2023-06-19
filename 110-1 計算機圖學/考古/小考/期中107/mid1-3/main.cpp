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

    float x[6],y1[6];
    float y[6],x1[6];
    int number=0,num=0;
    for(int i=0;i<360;i+=60)
    {
        x[number]=200+85*cos(i*3.1415926/180);
        y[number]=200+85*sin(i*3.1415926/180);
        number++;
    }

    for(int i=0;i<360;i+=60)
    {
        x1[num]=200+85*cos(i*3.1415926/180);
        y1[num]=200+85*sin(i*3.1415926/180);
        num++;
    }

    glClear (GL_COLOR_BUFFER_BIT);

    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =15 ; i <= 375; i+=30)
    {
		glVertex2f (200+60*cos(i*3.14159265359/180),200+60*sin(i*3.14159265359/180));
	}
    glEnd ( );


    //
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =15 ; i <= 375; i+=30)
    {
		glVertex2f (x[0]+60*cos(i*3.14159265359/180),y[0]+60*sin(i*3.14159265359/180));
	}
    glEnd ( );

    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =90 ; i <= 450; i+=60)
    {
		glVertex2f (x1[0]+31*cos(i*3.14159265359/180),y1[0]+31*sin(i*3.14159265359/180));
	}
    glEnd ( );
    //
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =15 ; i <= 375; i+=30)
    {
		glVertex2f (x[1]+60*cos(i*3.14159265359/180),y[1]+60*sin(i*3.14159265359/180));
	}
    glEnd ( );
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =90 ; i <= 450; i+=60)
    {
		glVertex2f (x1[1]+31*cos(i*3.14159265359/180),y1[1]+31*sin(i*3.14159265359/180));
	}
    glEnd ( );
    //
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =15 ; i <= 375; i+=30)
    {
		glVertex2f (x[2]+60*cos(i*3.14159265359/180),y[2]+60*sin(i*3.14159265359/180));
	}
    glEnd ( );
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =90 ; i <= 450; i+=60)
    {
		glVertex2f (x1[2]+31*cos(i*3.14159265359/180),y1[2]+31*sin(i*3.14159265359/180));
	}
    glEnd ( );
    //
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =15 ; i <= 375; i+=30)
    {
		glVertex2f (x[3]+60*cos(i*3.14159265359/180),y[3]+60*sin(i*3.14159265359/180));
	}
    glEnd ( );
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =90 ; i <= 450; i+=60)
    {
		glVertex2f (x1[3]+31*cos(i*3.14159265359/180),y1[3]+31*sin(i*3.14159265359/180));
	}
    glEnd ( );
    //
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =15 ; i <= 375; i+=30)
    {
		glVertex2f (x[4]+60*cos(i*3.14159265359/180),y[4]+60*sin(i*3.14159265359/180));
	}
    glEnd ( );
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =90 ; i <= 450; i+=60)
    {
		glVertex2f (x1[4]+31*cos(i*3.14159265359/180),y1[4]+31*sin(i*3.14159265359/180));
	}
    glEnd ( );
    //
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =15 ; i <= 375; i+=30)
    {
		glVertex2f (x[5]+60*cos(i*3.14159265359/180),y[5]+60*sin(i*3.14159265359/180));
	}
    glEnd ( );
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    for(float i =90 ; i <= 450; i+=60)
    {
		glVertex2f (x1[5]+31*cos(i*3.14159265359/180),y1[5]+31*sin(i*3.14159265359/180));
	}
    glEnd ( );
    int t=0;
    for(int i=0;i<6;i++)
    {
        glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    glVertex2f (x1[t]+31*cos(330*3.14159265359/180),y1[t]+31*sin(330*3.14159265359/180));
    glVertex2f (x1[t]+31*cos(390*3.14159265359/180),y1[t]+31*sin(390*3.14159265359/180));
    glVertex2f (x[t]+60*cos(15*3.14159265359/180),y[t]+60*sin(15*3.14159265359/180));
    glVertex2f (x[t]+60*cos(345*3.14159265359/180),y[t]+60*sin(345*3.14159265359/180));
    glEnd ( );
    t++;
    }
    t=0;
    //
    for(int i=0;i<6;i++)
    {
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    glVertex2f (x1[t]+31*cos(390*3.14159265359/180),y1[t]+31*sin(390*3.14159265359/180));
    glVertex2f (x1[t]+31*cos(90*3.14159265359/180),y1[t]+31*sin(90*3.14159265359/180));
    glVertex2f (x[t]+60*cos(75*3.14159265359/180),y[t]+60*sin(75*3.14159265359/180));
    glVertex2f (x[t]+60*cos(45*3.14159265359/180),y[t]+60*sin(45*3.14159265359/180));
    glEnd ( );
    t++;
    }

    t=0;
    //
    for(int i=0;i<6;i++)
    {
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    glVertex2f (x1[t]+31*cos(90*3.14159265359/180),y1[t]+31*sin(90*3.14159265359/180));
    glVertex2f (x1[t]+31*cos(150*3.14159265359/180),y1[t]+31*sin(150*3.14159265359/180));
    glVertex2f (x[t]+60*cos(135*3.14159265359/180),y[t]+60*sin(135*3.14159265359/180));
    glVertex2f (x[t]+60*cos(105*3.14159265359/180),y[t]+60*sin(105*3.14159265359/180));
    glEnd ( );
    t++;
    }

    t=0;
    //
    for(int i=0;i<6;i++)
    {
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    glVertex2f (x1[t]+31*cos(150*3.14159265359/180),y1[t]+31*sin(150*3.14159265359/180));
    glVertex2f (x1[t]+31*cos(210*3.14159265359/180),y1[t]+31*sin(210*3.14159265359/180));
    glVertex2f (x[t]+60*cos(195*3.14159265359/180),y[t]+60*sin(195*3.14159265359/180));
    glVertex2f (x[t]+60*cos(165*3.14159265359/180),y[t]+60*sin(165*3.14159265359/180));
    glEnd ( );
    t++;
    }

    t=0;
    //
    for(int i=0;i<6;i++)
    {
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    glVertex2f (x1[t]+31*cos(210*3.14159265359/180),y1[t]+31*sin(210*3.14159265359/180));
    glVertex2f (x1[t]+31*cos(270*3.14159265359/180),y1[t]+31*sin(270*3.14159265359/180));
    glVertex2f (x[t]+60*cos(255*3.14159265359/180),y[t]+60*sin(255*3.14159265359/180));
    glVertex2f (x[t]+60*cos(225*3.14159265359/180),y[t]+60*sin(225*3.14159265359/180));


    glEnd ( );
    t++;
    }

    t=0;
    //
    for(int i=0;i<6;i++)
    {
    glBegin (GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);
    glVertex2f (x1[t]+31*cos(270*3.14159265359/180),y1[t]+31*sin(270*3.14159265359/180));
    glVertex2f (x1[t]+31*cos(330*3.14159265359/180),y1[t]+31*sin(330*3.14159265359/180));
    glVertex2f (x[t]+60*cos(315*3.14159265359/180),y[t]+60*sin(315*3.14159265359/180));
    glVertex2f (x[t]+60*cos(285*3.14159265359/180),y[t]+60*sin(285*3.14159265359/180));


    glEnd ( );
    t++;
    }
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
