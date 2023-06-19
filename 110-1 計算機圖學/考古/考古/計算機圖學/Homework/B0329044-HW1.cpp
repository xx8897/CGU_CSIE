#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <GL/glut.h>
#include <math.h> 

void init(void)
{
     glClearColor(1.0,1.0,1.0,0.0);
     glMatrixMode(GL_PROJECTION);
     gluOrtho2D(0.0,400.0,0.0,400.0);
}

const GLfloat Pi = 3.1415926536f;
const GLfloat R = 80;
const GLint N = 40;
GLfloat Ver[5][2];

void draw_wired_circle(float x, float y, float r, float g, float b)
{
	glLineWidth(5.0f);
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);                                                   //GL_POLYGON
    for(int i=0; i<N; ++i)
        glVertex2f(x+R*cos(2*Pi/N*i), y+R*sin(2*Pi/N*i));
    glEnd();
}


void drow_line(void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     
     
     for(int i=0; i<400; i++)
     {
     	glColor3f(1.0-0.001*i,1.0-0.001*i,1.0-0.001*i);
     	glBegin(GL_QUADS);                                                //GL_QUADS
     	glVertex2i(0,400-i);
        glVertex2i(400,400-i);
        glVertex2i(400,0);
        glVertex2i(0,0);
        glEnd();
     }
     
     glLineWidth(5.0f);
     glColor3f(1.0,1.0,1.0);
     glBegin(GL_LINES);                                                    //GL_LINES
     glVertex2i(20,20);
     glVertex2i(380,20);
     glVertex2i(380,20);
     glVertex2i(380,380);
     glVertex2i(380,380);
     glVertex2i(20,380);
     glVertex2i(20,380);
     glVertex2i(20,20);
     glEnd();
     
     glColor3f(0.78,0.9098,0.8471);
     glBegin(GL_QUAD_STRIP);                                               //GL_QUAD_STRIP
     glVertex2i(20,375);
     glVertex2i(20,385);
     for(int i=1; i<=18; i++)
     {
     	if(i%2==0)
     	{
     		glVertex2i(20+20*i,380);
     		glVertex2i(20+20*i,390);
     	}
     	else
     	{
     		glVertex2i(20+20*i,370);
     		glVertex2i(20+20*i,380);
     	}
     	
     }
     glEnd();
     
     glColor3f(0.78,0.9098,0.8471);
     glBegin(GL_QUAD_STRIP);
     glVertex2i(20,15);
     glVertex2i(20,25);
     for(int i=1; i<=18; i++)
     {
     	if(i%2==0)
     	{
     		glVertex2i(20+20*i,20);
     		glVertex2i(20+20*i,30);
     	}
     	else
     	{
     		glVertex2i(20+20*i,10);
     		glVertex2i(20+20*i,20);
     	}
     	
     }
     glEnd();
     
     glColor3f(0.78,0.9098,0.8471);
     glBegin(GL_TRIANGLE_STRIP);                                           //GL_TRIANGLE_STRIP
     glVertex2i(20,380);
     for(int i=1; i<=18; i++)
     {
     	if(i%2==0)
     	{
     		glVertex2i(20+20,380-20*i);
     		glVertex2i(20,380-20*i);
     	}
     	else
     	{
     		glVertex2i(20-20,380-20*i);
     		glVertex2i(20,380-20*i);
     	}
     	
     }
     glEnd();
     
     glColor3f(0.78,0.9098,0.8471);
     glBegin(GL_TRIANGLE_STRIP);
     glVertex2i(380,385);
     for(int i=1; i<=18; i++)
     {
     	if(i%2==0)
     	{
     		glVertex2i(380-20,380-20*i);
     		glVertex2i(380,380-20*i);
     	}
     	else
     	{
     		glVertex2i(380+20,380-20*i);
     		glVertex2i(380,380-20*i);
     	}
     	
     }
     glEnd();
  
     GLfloat r=80;
     GLfloat x,y;
     
     for(int j=0; j<5; j++)
     {
             Ver[j][1]=200+r*sin(2*Pi/5*j);
             Ver[j][2]=200+r*cos(2*Pi/5*j);
     }
     
     draw_wired_circle(Ver[4][1],Ver[4][2],0.39,0.68,0.96);
     draw_wired_circle(Ver[0][1],Ver[0][2],0.65,0.8,0.93);
     draw_wired_circle(Ver[1][1],Ver[1][2],0.51,0.63,0.74);
	 draw_wired_circle(Ver[2][1],Ver[2][2],0.24,0.26,0.33);
     draw_wired_circle(Ver[3][1],Ver[3][2],0.09,0.16,0.3);
  	 
  	 glColor3f(0.737,0.69,0.655);
     glBegin(GL_TRIANGLE_FAN);                                                   //GL_TRIANGLE_FAN 
     for(int j=0; j<5; j++)
     	glVertex2f(200+r*sin(2*Pi/5*j),200+r*cos(2*Pi/5*j));
     glEnd();
     
     glColor3f(1.0,0.98,0.8);
     glBegin(GL_LINE_STRIP);                                                     //GL_LINE_STRIP
     for(int j=0; j<5; j++)
     {
     	glVertex2f(200+80*sin(2*Pi/5*j),200+80*cos(2*Pi/5*j));
     	glVertex2f(200+30*sin(2*Pi/10*(j*2+1)),200+30*cos(2*Pi/10*(j*2+1)));
     	if(j==4)
     	glVertex2f(200+80*sin(2*Pi/5*0),200+80*cos(2*Pi/5*0));
     }
     glEnd();
     

     
     glColor3f(1.0,0.98,0.8);
     glBegin(GL_TRIANGLES);                                                      //GL_TRIANGLES
     for(int j=0; j<5; j++)
     {
     	if(j==4)
     	{
     		glVertex2f(200+80*sin(2*Pi/5*0),200+80*cos(2*Pi/5*0));
     		glVertex2f(200+30*sin(2*Pi/10*1),200+30*cos(2*Pi/10*1));
     		glVertex2f(200+30*sin(2*Pi/10*9),200+30*cos(2*Pi/10*9));
		} 
     	glVertex2f(200+80*sin(2*Pi/5*(j+1)),200+80*cos(2*Pi/5*(j+1)));
     	glVertex2f(200+30*sin(2*Pi/10*(j*2+1)),200+30*cos(2*Pi/10*(j*2+1)));
     	glVertex2f(200+30*sin(2*Pi/10*(j*2+3)),200+30*cos(2*Pi/10*(j*2+3)));
     	
     }
     glEnd();
     
     for(int j=0; j<30; j++)
     {
             glLineWidth(5.0f);
    		 
    		 for(int i=0; i<30; ++i)
    		 {
    		 	glColor3f(1.0,0.98,0.8);
    		 	glBegin(GL_POINTS);                                             //GL_POINTS
    		 	for(int j=0; j<(30-i)*8; ++j)
             	glVertex2f(200+(30-i)*cos(2*Pi/((30-i)*8)*j), 200+(30-i)*sin(2*Pi/((30-i)*8)*j));
             	glEnd();
    		 }
     }
  	 
	 glLineWidth(5.0f);
     glColor3f(0.78,0.9098,0.8471);
     glBegin(GL_LINE_LOOP);                                                     //GL_LINE_LOOP
     for(int j=0; j<5; j++)
     	glVertex2f(200+r*sin(2*Pi/5*j),200+r*cos(2*Pi/5*j));
     glEnd();
     

     
     glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("B0329044's");
    init();
    glutDisplayFunc(drow_line);
    glutMainLoop();
}
