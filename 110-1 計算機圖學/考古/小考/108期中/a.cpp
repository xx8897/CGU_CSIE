#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>


const int n =1000;
float pi = 3.1415926536f;
const GLfloat R = 4.85;

void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,100.0,0.0,100.0);
}
void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    /*glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (int i=0;i<6;++i){
            glVertex2f(50+15*cos(0.52+2*Pi/6*i),50+15*sin(0.52+2*Pi/6*i));
        }
    glEnd();
    glFlush();*/

    /*glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (int i=0;i<6;++i){
            glVertex2f(50+30*cos(0.525+2*Pi/6*i),50+30*sin(0.525+2*Pi/6*i));
        }
    glEnd();
    glFlush();*/

	glColor3f(0.0,0.0,0.0);
    float x[3] = {0};
	float y[3] = {0};
    glBegin(GL_LINE_LOOP);
      for (int i=0;i<3;++i){
      		x[i] = 50+15*cos(1.57+2*pi/3*i);
        	y[i] = 50+15*sin(1.57+2*pi/3*i);
        	glVertex2f(x[i],y[i]);
            //glVertex2f(50+20*cos(0.53+2*Pi/6*i),50+20*sin(0.53+2*Pi/6*i));
        }
    glEnd();
    glFlush();
	
	glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<10000;i++)
        	glVertex2f(x[0]+7.4*cos(2*pi/100*i),y[0]+7.4*sin(2*pi/100*i));
    glEnd(); 
	glFlush(); 
	
	glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<10000;i++) //左圓 
        	glVertex2f(x[1]+7.1*cos(2*pi/100*i),y[1]+7.1*sin(2*pi/100*i));
    glEnd(); 
	glFlush(); 
	
	glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<10000;i++)  //右圓 
        	glVertex2f(x[2]+7.4*cos(2*pi/100*i),y[2]+7.4*sin(2*pi/100*i));
    glEnd(); 
	glFlush(); 
	
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex2f(50,80);
        glVertex2f(50,50);
		
        /*glVertex2f(37,58);
        glVertex2f(63,58);

        glVertex2f(37,58);
        glVertex2f(50,35);

        glVertex2f(50,35);
        glVertex2f(63,58);*/

        glVertex2f(50,80);
        glVertex2f(24.5,35.5);
        glVertex2f(24.5,35.5);   //底邊 
        glVertex2f(76,35.5);

        glVertex2f(76,35.5);  //右邊 
        glVertex2f(50,80);
        glVertex2f(24.5,35.5);
        glVertex2f(50,50);
        glVertex2f(50,50);
        glVertex2f(76,35.5);

        glVertex2f(24.5,65); //倒三角形 (大) 
        glVertex2f(76,65);
        glVertex2f(24.5,65); //左邊 
        glVertex2f(50,20);
        glVertex2f(50,20);
        glVertex2f(76,65);

    glEnd();
    glFlush();
    
    glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<10000;i++)
        	glVertex2f(50+7.4*cos(2*pi/100*i),35.5+7.4*sin(2*pi/100*i));
    glEnd(); 
	glFlush();

	glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<10000;i++)
        	glVertex2f(63+7.4*cos(2*pi/100*i),57.5+7.4*sin(2*pi/100*i));
    glEnd(); 
	glFlush();
	
	glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<10000;i++)
        	glVertex2f(37+7.2*cos(2*pi/100*i),57.5+7.2*sin(2*pi/100*i));
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
