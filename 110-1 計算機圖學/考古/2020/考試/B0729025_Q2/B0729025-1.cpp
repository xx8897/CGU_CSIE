#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>

using namespace std;

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.
	glMatrixMode (GL_PROJECTION);       // Set projection parameters.
	gluOrtho2D (0.0,600.0,0.0,600.0);
}
const int n=3600;
const GLfloat R=6; //圓形半徑 
const GLfloat pi = 3.1415926536f;

void lineSegment (void){
	glClear(GL_COLOR_BUFFER_BIT);
	//有顏色三角形 
	//green
	glColor3f (0.0, 1.0, 0.0);
	glBegin (GL_TRIANGLE_STRIP);
		glVertex2i (50,175);
		glVertex2i (215,175);
		glVertex2i (133,300);
	glEnd ( );
	glBegin (GL_TRIANGLE_STRIP);
		glVertex2i (468,300);
		glVertex2i (550,425);
		glVertex2i (382,425);
	glEnd ( );
	//red
	glColor3f (1.0, 0.0, 0.0);
	glBegin (GL_TRIANGLE_STRIP);
		glVertex2i (382,175);
		glVertex2i (550,175);
		glVertex2i (468,300);
	glEnd ( );
	glBegin (GL_TRIANGLE_STRIP);
		glVertex2i (133,300);
		glVertex2i (215,425);
		glVertex2i (50,425);
	glEnd ( );
	//yellow
	glColor3f (1.0, 1.0, 0.0);
	glBegin (GL_TRIANGLE_STRIP);
		glVertex2i (300,50);
		glVertex2i (382,175);
		glVertex2i (215,175);
	glEnd ( );
	glBegin (GL_TRIANGLE_STRIP);
		glVertex2i (300,550);
		glVertex2i (382,425);
		glVertex2i (215,425);
	glEnd ( );
	//大三角形 
	glColor3f (0.0, 0.0, 0.0);
	glBegin (GL_LINE_LOOP);
		glVertex2i (50,175);
		glVertex2i (550,175);
		glVertex2i (300,550);
	glEnd ( );
	glBegin (GL_LINE_LOOP);
		glVertex2i (50,425);
		glVertex2i (550,425);
		glVertex2i (300,50);
	glEnd ( );
	//黑線
	
	//白點 
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		for(float j=50;j<=550;j=j+(500/12.18)){
			glBegin(GL_POLYGON);
			for (int i=1;i<=n;i++){
				glVertex2f(j+R*cos(2*pi/n*i),175+R*sin(2*pi/n*i));
			}
		glEnd();
		}
    glEnd();
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		for(float j=50;j<=550;j=j+(500/12.18)){
			glBegin(GL_LINE_LOOP);
			for (int i=1;i<=n;i++){
				glVertex2f(j+R*cos(2*pi/n*i),175+R*sin(2*pi/n*i));
			}
		glEnd();
		}
    glEnd();
    
    glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		for(float j=68;j<=540;j=j+(472/11)){
			glBegin(GL_POLYGON);
			for (int i=1;i<=n;i++){
				glVertex2f(j+R*cos(2*pi/n*i),175+375/13+R*sin(2*pi/n*i));
			}
		glEnd();
		}
    glEnd();
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		for(float j=68;j<=540;j=j+(472/11)){
			glBegin(GL_LINE_LOOP);
			for (int i=1;i<=n;i++){
				glVertex2f(j+R*cos(2*pi/n*i),175+375/13+R*sin(2*pi/n*i));
			}
		glEnd();
		}
    glEnd();
	///
    glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		for(float j=86;j<=516;j=j+(430/10)){
			glBegin(GL_POLYGON);
			for (int i=1;i<=n;i++){
				glVertex2f(j+R*cos(2*pi/n*i),175+2*(375/13)+R*sin(2*pi/n*i));
			}
		glEnd();
		}
    glEnd();
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		for(float j=86;j<=516;j=j+(430/10)){
			glBegin(GL_LINE_LOOP);
			for (int i=1;i<=n;i++){
				glVertex2f(j+R*cos(2*pi/n*i),175+2*(375/13)+R*sin(2*pi/n*i));
			}
		glEnd();
		}
    glEnd();
    glFlush();
}

int main (int argc, char** argv){
	glutInit (&argc, argv); // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
	glutInitWindowPosition (100,50);   // Set top-left display-window position.
	glutInitWindowSize (600, 600);// Set display-window width and height.
	glutCreateWindow ("B0729025_1"); // Create display window.
	init ( );
	glutDisplayFunc (lineSegment); // Send graphics to display window.
	glutMainLoop ( );  // Display everything and wait.
}
