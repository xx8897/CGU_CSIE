#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

void init (void){
	glClearColor (0.0, 0.0, 0.5, 0.0);  // Set display-window color to white.
	glMatrixMode (GL_PROJECTION);       // Set projection parameters.
	gluOrtho2D (0.0, 100.0, 0.0, 100.0);
}

const int n = 3600;
const GLfloat R = 47; //圓形半徑 
const GLfloat pi = 3.1415926536f;

void lineSegment (void){
	glClear(GL_COLOR_BUFFER_BIT);
	//正方形 
	glLineWidth(2);
    glBegin(GL_LINE_LOOP);
		glColor3f(0.0,1.0,1.0);
		glVertex2f(3,97);
		glVertex2f(97,97);
		glVertex2f(97,3);
		glVertex2f(3,3);
    glEnd();
    //圓形
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,1.0,1.0); 
		for (int i=1; i<=n;i++){
			glVertex2f(50+R*cos(2*pi/n*i),50+R*sin(2*pi/n*i));
		}
	glEnd();
	//線
	glColor3f (0.0, 1.0, 1.0);
	glBegin (GL_LINE_STRIP);
	glVertex2i (3,97);
	glVertex2i (50,3);
	glEnd ( );
	glColor3f (0.0, 1.0, 1.0);
	glBegin (GL_LINE_STRIP);
	glVertex2i (3,97);
	glVertex2i (97,50);
	glEnd ( );  
	
	glColor3f (0.0, 1.0, 1.0);
	glBegin (GL_LINE_STRIP);
	glVertex2i (3,50);
	glVertex2i (97,3);
	glEnd ( );
	glColor3f (0.0, 1.0, 1.0);
	glBegin (GL_LINE_STRIP);
	glVertex2i (3,50);
	glVertex2i (97,97);
	glEnd ( ); 
	
	glColor3f (0.0, 1.0, 1.0);
	glBegin (GL_LINE_STRIP);
	glVertex2i (3,3);
	glVertex2i (50,97);
	glEnd ( );
	glColor3f (0.0, 1.0, 1.0);
	glBegin (GL_LINE_STRIP);
	glVertex2i (3,3);
	glVertex2i (97,50);
	glEnd ( ); 
	
	glColor3f (0.0, 1.0, 1.0);
	glBegin (GL_LINE_STRIP);
	glVertex2i (50,3);
	glVertex2i (3,97);
	glEnd ( );
	glColor3f (0.0, 1.0, 1.0);
	glBegin (GL_LINE_STRIP);
	glVertex2i (50,3);
	glVertex2i (97,97);
	glEnd ( ); 	
	
	glColor3f (0.0, 1.0, 1.0);
	glBegin (GL_LINE_STRIP);
	glVertex2i (97,3);
	glVertex2i (3,50);
	glEnd ( );
	glColor3f (0.0, 1.0, 1.0);
	glBegin (GL_LINE_STRIP);
	glVertex2i (97,3);
	glVertex2i (50,97);
	glEnd ( ); 	
	
	glColor3f (0.0, 1.0, 1.0);
	glBegin (GL_LINE_STRIP);
	glVertex2i (97,50);
	glVertex2i (3,3);
	glEnd ( );
	glColor3f (0.0, 1.0, 1.0);
	glBegin (GL_LINE_STRIP);
	glVertex2i (97,50);
	glVertex2i (3,97);
	glEnd ( ); 	
	
    glFlush();
}

int main (int argc, char** argv){
	glutInit (&argc, argv); // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
	glutInitWindowPosition (100,50);   // Set top-left display-window position.
	glutInitWindowSize (600, 600);// Set display-window width and height.
	glutCreateWindow ("1(a)"); // Create display window.
	init ( );
	glutDisplayFunc (lineSegment); // Send graphics to display window.
	glutMainLoop ( );  // Display everything and wait.
}
