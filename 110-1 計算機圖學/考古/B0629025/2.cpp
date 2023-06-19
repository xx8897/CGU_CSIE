#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-120,120.0,-120.0,120.0);
}

const int n =100;
float pi = 3.1415926536f;
const GLfloat R = 10;
int a,b;

void lineSegment(void)
{	
	//rand()%(max-min+1)+min
    glClear(GL_COLOR_BUFFER_BIT);
	
	/*for(int i=0;i<100;i++)
		{
			a=i;
			b=i;
		}*/ 
	glColor3f(0.0,0.0,0.0);  
    glBegin(GL_POLYGON);
        for(int i=0;i<10000;i++)
        	glVertex2f(10*cos(2*pi/100*i),10*sin(2*pi/100*i));
    glEnd(); 
	glFlush(); 
	
	glColor3f(1.0,0.0,0.0);  
    glBegin(GL_POLYGON);
        for(int i=0;i<10000;i++)
        	glVertex2f(1+10*cos(2*pi/100*i),1+10*sin(2*pi/100*i));
    glEnd(); 
	glFlush();
	
	glColor3f(0.0,1.0,0.0);  
    glBegin(GL_POLYGON);
        for(int i=0;i<10000;i++)
        	glVertex2f(2+10*cos(2*pi/100*i),2+10*sin(2*pi/100*i));
    glEnd(); 
	glFlush();
	
	glColor3f(0.0,0.0,1.0);  
    glBegin(GL_POLYGON);
        for(int i=0;i<10000;i++)
        	glVertex2f(3+10*cos(2*pi/100*i),3+10*sin(2*pi/100*i));
    glEnd(); 
	glFlush();

}


int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("My Program");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
    return 0;
}
