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
	int n=360,r=35,i,j;	//n是圓周角度；r是圓半徑 
	glLineWidth(2);
	
	//右側直線
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_LINES);
	      glVertex2i(86,85);
          glVertex2i(86,15);
     glEnd();
	
	//藍色半圓 
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
	for(int i=180; i>=0; i--){
			glVertex2f(50+35*cos(i*M_PI/180),50+35*sin(i*M_PI/180));
	}
	glEnd();
	
	//白色半圓 
	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
	for(int i=360; i>=180; i--){
			glVertex2f(50+35*cos(i*M_PI/180),48+35*sin(i*M_PI/180));
	}
	glEnd();
	
	//黑色橫線 
	glColor3f(0,0,0);      
    glBegin(GL_POLYGON);
        glVertex2i(15,48);  
        glVertex2i(15,52);
        glVertex2i(85,52);
        glVertex2i(85,48);
    glEnd();
    
    //中心黑色圓形 
    glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	for(float angle=0; angle<TWOPI; angle+=STEP){
		glVertex2f((50+12 * cos(angle)), (50+12* sin(angle)));
	}
	glEnd();
	
	//中心白色圓形 
    glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	for(float angle=0; angle<TWOPI; angle+=STEP){
		glVertex2f((50+8 * cos(angle)), (50+8* sin(angle)));
	}
	glEnd();
	
	//紅色四邊形(左)
	int k=5;
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	      glVertex2i(27-k,65+k);
	      glVertex2i(23+k,72+k);
	      glVertex2i(30+k,73-k);
	      glVertex2i(34-k,68-k);
    glEnd();
    
    //紅色四邊形(右)
	glBegin(GL_POLYGON);
	
	glColor3f(1,0,0);
	      glVertex2i(44+27-k,64+k);
	      glVertex2i(45+23+k,72+k);//左上 
	      glVertex2i(44+30+k,74-k);//右上 
	      glVertex2i(44+34-k,67-k);
    glEnd();
	
	
	
    glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(350,350);
	glutInitWindowPosition(100,100);
	glutCreateWindow("1-a");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
