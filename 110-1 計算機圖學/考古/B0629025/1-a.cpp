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
float pi = 3.1415926536f;
const GLfloat R = 4.85;

void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0,0.0,0.0);
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
    glFlush();

	glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    //glScalef(50,50,0);
    for(int i=0; i<n; ++i)
        glVertex2f(50+R*cos(2*pi/n*i), 50+R*sin(2*pi/n*i));
    glEnd();
	glFlush();
	
    glColor3f(0.0,0.0,0.0);
    float x[6] = {0};
	float y[6] = {0};
    glBegin(GL_LINE_LOOP);
      for (int i=0;i<6;++i){
      		x[i] = 50+20*cos(0.53+2*pi/6*i);
        	y[i] = 50+20*sin(0.53+2*pi/6*i);
        	glVertex2f(x[i],y[i]);
            //glVertex2f(50+20*cos(0.53+2*Pi/6*i),50+20*sin(0.53+2*Pi/6*i));
        }
    glEnd();
    glFlush();
	
	glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINES);
        for(int i=0;i<10000;i++)
        	glVertex2f(x[0]+4.85*cos(2*pi/100*i),y[0]+4.85*sin(2*pi/100*i));
    glEnd(); 
	glFlush(); 
	
	glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINES);
        for(int i=0;i<10000;i++)
        	glVertex2f(x[1]+4.85*cos(2*pi/100*i),y[1]+4.85*sin(2*pi/100*i));
    glEnd(); 
	glFlush(); 
	
	glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINES);
        for(int i=0;i<10000;i++)
        	glVertex2f(x[2]+4.85*cos(2*pi/100*i),y[2]+4.85*sin(2*pi/100*i));
    glEnd(); 
	glFlush(); 
	
	glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINES);
        for(int i=0;i<10000;i++)
        	glVertex2f(x[3]+4.85*cos(2*pi/100*i),y[3]+4.85*sin(2*pi/100*i));
    glEnd(); 
	glFlush(); 
	
	glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINES);
        for(int i=0;i<10000;i++)
        	glVertex2f(x[4]+4.85*cos(2*pi/100*i),y[4]+4.85*sin(2*pi/100*i));
    glEnd(); 
	glFlush(); 
	
	glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINES);
        for(int i=0;i<10000;i++)
        	glVertex2f(x[5]+4.85*cos(2*pi/100*i),y[5]+4.85*sin(2*pi/100*i));
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
