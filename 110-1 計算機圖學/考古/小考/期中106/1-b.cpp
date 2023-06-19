#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <GL/glut.h>
#include<math.h>
#define PI 3.1415926535898

void init(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D (-20.0, 120.0, -20.0, 120.0);
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	const int NPOINTS=24;
	const float TWOPI=2*3.14159268;
	const float STEP=TWOPI/NPOINTS;
	int n=360,r=35,i,j;	//n是圓周角度；r是圓半徑 
	glLineWidth(2);
    
    //外圈大圓 
    glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	for(float angle=0; angle<TWOPI; angle+=STEP){
		glVertex2f((50+ 50 * cos(angle)), (50+50* sin(angle)));
	}
	glEnd();
	
	//外圈中圓 
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	for(float angle=0; angle<TWOPI; angle+=STEP){
		glVertex2f((50+ 35 * cos(angle)), (50 + 35* sin(angle)));
	}
	glEnd();
    
    //圓形*3
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	for(float angle=0; angle<TWOPI; angle+=STEP){
		glVertex2f((50+13 * cos(angle)), (83+13* sin(angle)));
	}
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	for(float angle=0; angle<TWOPI; angle+=STEP){
		glVertex2f((20+13 * cos(angle)), (33+13* sin(angle)));
	}
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	for(float angle=0; angle<TWOPI; angle+=STEP){
		glVertex2f((80+13 * cos(angle)), (33+13* sin(angle)));
	}
	glEnd();
	
	//大三角形-框 
  	glColor3f (0, 0, 0);
    glBegin (GL_LINE_LOOP);
	   	for(i=0;i<n;i+=120)
		{
	   		glVertex2f(50 + 35*sin(2*PI/n*i), 50 + 35*cos(2*PI/n*i));
	   	}
    glEnd();
    
    //大三角形-白色填滿 
  	glColor3f (1, 1, 1);
    glBegin (GL_POLYGON);
	   	for(i=0;i<n;i+=120)
		{
	   		glVertex2f(50 + 34*sin(2*PI/n*i), 50 + 34*cos(2*PI/n*i));
	   	}
    glEnd();
    
    //中心小圓 
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	for(float angle=0; angle<TWOPI; angle+=STEP){
		glVertex2f((50 + 7 * cos(angle)), (50+ 7 * sin(angle)));
	}
	glEnd();
    
    glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(350,350);
	glutInitWindowPosition(100,100);
	glutCreateWindow("1-b");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
