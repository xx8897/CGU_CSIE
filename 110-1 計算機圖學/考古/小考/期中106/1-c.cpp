#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <GL/glut.h>
#include<math.h>
#define PI 3.1415926535898
GLfloat color[5][3]={{1.0, 0.0, 0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,0.0},{0.0,1.0,1.0}};

void init(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D (0.0, 100.0, 0.0, 100.0);
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	const int NPOINTS=24;
	const float TWOPI=2*3.14159268;
	const float STEP=TWOPI/NPOINTS;
	int r=35,i,j;	//n是圓周角度；r是圓半徑 
	
	//十二邊形 
	glColor3f(0, 0, 0);
	int k=5;
	glBegin(GL_LINE_LOOP);
		glVertex2i(50-k,50+3.4*k);
        glVertex2i(50+k,50+3.4*k);
        glVertex2i(50+2.4*k,50+2.7*k);
        glVertex2i(50+3.4*k,50+k);
        glVertex2i(50+3.4*k,50-k);
        
        glVertex2i(50+2.4*k,50-2.7*k);
        glVertex2i(50+k,50-3.4*k);
        glVertex2i(50-k,50-3.4*k);
        glVertex2i(50-2.4*k,50-2.7*k);
        glVertex2i(50-3.4*k,50-k);
        
        glVertex2i(50-3.4*k,50+k);
        glVertex2i(50-2.4*k,50+2.7*k);
	glEnd();
	
	//1
	glBegin(GL_LINE_LOOP);
		glVertex2i(2.5*k+50-k,4.3*k+50+3.4*k);
        glVertex2i(2.5*k+50+k,4.3*k+50+3.4*k);
        glVertex2i(2.5*k+50+2.4*k,4.3*k+50+2.7*k);
        glVertex2i(2.5*k+50+3.4*k,4.3*k+50+k);
        glVertex2i(2.5*k+50+3.4*k,4.3*k+50-k);
        
        glVertex2i(2.5*k+50+2.4*k,4.3*k+50-2.7*k);
        glVertex2i(2.5*k+50+k,4.3*k+50-3.4*k);
        glVertex2i(2.5*k+50-k,4.3*k+50-3.4*k);
        glVertex2i(2.5*k+50-2.5*k,4.3*k+50-2.7*k);
        glVertex2i(2.5*k+50-3.4*k,4.3*k+50-k);
        
        glVertex2i(2.5*k+50-3.4*k,4.3*k+50+k);
        glVertex2i(2.5*k+50-2.5*k,4.3*k+50+2.7*k);
	glEnd();
	
	//2
	int m=5.1*k;
	glBegin(GL_LINE_LOOP);
		glVertex2i(m+50-k,50+3.4*k);
        glVertex2i(m+50+k,50+3.4*k);
        glVertex2i(m+50+2.4*k,50+2.7*k);
        glVertex2i(m+50+3.4*k,50+k);
        glVertex2i(m+50+3.4*k,50-k);
        
        glVertex2i(m+50+2.4*k,50-2.7*k);
        glVertex2i(m+50+k,50-3.4*k);
        glVertex2i(m+50-k,50-3.4*k);
        glVertex2i(m+50-2.4*k,50-2.7*k);
        glVertex2i(m+50-3.4*k,50-k);
        
        glVertex2i(m+50-3.4*k,50+k);
        glVertex2i(m+50-2.4*k,50+2.7*k);
	glEnd();
	
	//3
	int n=1.7*2*k;
	glBegin(GL_LINE_LOOP);
		glVertex2i(-2+n+50-k,2-n*1.5+50+3.4*k);
        glVertex2i(-2+n+50+k,2-n*1.5+50+3.4*k);
        glVertex2i(-2+n+50+2.4*k,2-n*1.5+50+2.7*k);
        glVertex2i(-2+n+50+3.4*k,2-n*1.5+50+k);
        glVertex2i(-2+n+50+3.4*k,2-n*1.5+50-k);
        
        glVertex2i(-2+n+50+2.4*k,2-n*1.5+50-2.7*k);
        glVertex2i(-2+n+50+k,2-n*1.5+50-3.4*k);
        glVertex2i(-2+n+50-k,2-n*1.5+50-3.4*k);
        glVertex2i(-2+n+50-2.4*k,2-n*1.5+50-2.7*k);
        glVertex2i(-2+n+50-3.4*k,2-n*1.5+50-k);
        
        glVertex2i(-2+n+50-3.4*k,2-n*1.5+50+k);
        glVertex2i(-2+n+50-2.4*k,2-n*1.5+50+2.7*k);
	glEnd();
	
	//4
	glBegin(GL_LINE_LOOP);
		glVertex2i(1.7-n+50-k,1.7-n*1.5+50+3.4*k);
        glVertex2i(1.7-n+50+k,1.7-n*1.5+50+3.4*k);
        glVertex2i(1.7-n+50+2.4*k,1.7-n*1.5+50+2.7*k);
        glVertex2i(1.7-n+50+3.4*k,1.7-n*1.5+50+k);
        glVertex2i(1.7-n+50+3.4*k,1.7-n*1.5+50-k);
        
        glVertex2i(1.7-n+50+2.4*k,1.7-n*1.5+50-2.7*k);
        glVertex2i(1.7-n+50+k,1.7-n*1.5+50-3.4*k);
        glVertex2i(1.7-n+50-k,1.7-n*1.5+50-3.4*k);
        glVertex2i(1.7-n+50-2.4*k,1.7-n*1.5+50-2.7*k);
        glVertex2i(1.7-n+50-3.4*k,1.7-n*1.5+50-k);
        
        glVertex2i(1.7-n+50-3.4*k,1.7-n*1.5+50+k);
        glVertex2i(1.7-n+50-2.4*k,1.7-n*1.5+50+2.7*k);
	glEnd();
	
	//6
	glBegin(GL_LINE_LOOP);
		glVertex2i(1.7+-n+50-k,-1.7+n*1.5+50+3.4*k);
        glVertex2i(1.7+-n+50+k,-1.7+n*1.5+50+3.4*k);
        glVertex2i(1.7+-n+50+2.4*k,-1.7+n*1.5+50+2.7*k);
        glVertex2i(1.7+-n+50+3.4*k,-1.7+n*1.5+50+k);
        glVertex2i(1.7+-n+50+3.4*k,-1.7+n*1.5+50-k);
        
        glVertex2i(1.7+-n+50+2.4*k,-1.7+n*1.5+50-2.7*k);
        glVertex2i(1.7+-n+50+k,-1.7+n*1.5+50-3.4*k);
        glVertex2i(1.7+-n+50-k,-1.7+n*1.5+50-3.4*k);
        glVertex2i(1.7+-n+50-2.4*k,-1.7+n*1.5+50-2.7*k);
        glVertex2i(1.7+-n+50-3.4*k,-1.7+n*1.5+50-k);
        
        glVertex2i(1.7+-n+50-3.4*k,-1.7+n*1.5+50+k);
        glVertex2i(1.7+-n+50-2.4*k,-1.7+n*1.5+50+2.7*k);
	glEnd();
	
	//5
	glBegin(GL_LINE_LOOP);
		glVertex2i(-m+50-k,50+3.4*k);
        glVertex2i(-m+50+k,50+3.4*k);
        glVertex2i(-m+50+2.4*k,50+2.7*k);
        glVertex2i(-m+50+3.4*k,50+k);
        glVertex2i(-m+50+3.4*k,50-k);
        
        glVertex2i(-m+50+2.4*k,50-2.7*k);
        glVertex2i(-m+50+k,50-3.4*k);
        glVertex2i(-m+50-k,50-3.4*k);
        glVertex2i(-m+50-2.4*k,50-2.7*k);
        glVertex2i(-m+50-3.4*k,50-k);
        
        glVertex2i(-m+50-3.4*k,50+k);
        glVertex2i(-m+50-2.4*k,50+2.7*k);
	glEnd();
	
    glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(350,350);
	glutInitWindowPosition(100,100);
	glutCreateWindow("1-c");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
