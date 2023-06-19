#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

const int n =1000;
float pi = 3.1415926536f;
const GLfloat R = 4.85;
//const int d =0;

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,100.0,0.0,100.0);
}

void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0,0.0,0.0);
    	float x[6] = {0};
		float y[6] = {0};
    	glBegin(GL_LINE_LOOP);
      		for (int i=0;i<6;++i){
      			x[i] = 50+20*cos(1.57+2*pi/6*i);
        		y[i] = 50+20*sin(1.57+2*pi/6*i);
        	glVertex2f(x[i],y[i]);
        }
    glEnd();
    glFlush();
    
    glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<10000;i++)
        	for(int d=0;d<10;d++)
        		for(float m=0;m<0.9;m++)
        	glVertex2f(50+d*cos(m+2*pi/100*i),50+d*sin(2*pi/100*i));
    glEnd(); 
	glFlush(); 
	

}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("My Program");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
    return 0;
}
