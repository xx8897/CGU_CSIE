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
float r = 0.1; //©ñ¤j 
float R = 0.5; //¦ì²¾ 
float Pi = 3.1415926536f;
void lineSegment(void)
{
	
	//0.27*180/pi
	//15*pi/180
	
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    for(int k=0;k<10;++k)
    {
        for(int j=0;j<12;++j)
        {
            glBegin(GL_POLYGON);
            for (int i=0;i<n;++i)
            {
                glVertex2f(50+R*cos(0.27+2*Pi/12*j)+r*cos(2*Pi/n*i),50+R*sin(0.27+2*Pi/12*j)+r*sin(2*Pi/n*i));
            }
            glEnd();
        }
        r=r+1;
        R=r*2+R;
    }
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
