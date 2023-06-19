#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <GL/glut.h>
#include<math.h>

void init(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D (0.0, 100.0, 0.0, 100.0);
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	int n=360,r=30,i,j;	//n�O��P���סFr�O��b�| 
	int k=10; 
	
	//�T����-�W 
  	glColor3f (0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
		glVertex2i (50,50+3.4*k);
	   	glVertex2i (50-k,50+1.7*k);
		glVertex2i (50+k,50+1.7*k);
    glEnd();
    
    //�T����-�k�W 
  	glColor3f (0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
	   	glVertex2i (50+k,50+1.7*k);
	   	glVertex2i (50+2*k,50);
		glVertex2i (50+3*k,50+1.7*k);
    glEnd();
    
    //�T����-�k�U 
   	glColor3f (0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
	   	glVertex2i (50+2*k,50);
	   	glVertex2i (50+3*k,50-1.7*k);
		glVertex2i (50+k,50-1.7*k);
    glEnd();
    
    //�T����-�U 
   	glColor3f (0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
	   	glVertex2i (50+k,50-1.7*k);
	   	glVertex2i (50,50-3.4*k);
		glVertex2i (50-k,50-1.7*k);
    glEnd();
    
    //�T����-���U 
   	glColor3f (0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
	   	glVertex2i (50-k,50-1.7*k);
	   	glVertex2i (50-2*k,50);
		glVertex2i (50-3*k,50-1.7*k);
    glEnd();
    
    //�T����-���W 
   	glColor3f (0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
	   	glVertex2i (50-2*k,50);
	   	glVertex2i (50-3*k,50+1.7*k);
		glVertex2i (50-k,50+1.7*k);
    glEnd();
    
    glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(350,350);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Q1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
