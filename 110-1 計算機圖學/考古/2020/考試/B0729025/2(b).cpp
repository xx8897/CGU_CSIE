#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.
	glMatrixMode (GL_PROJECTION);       // Set projection parameters.
	gluOrtho2D (50.0, 100.0, 50.0, 100.0);
}

void lineSegment (void){
	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0); 
		glVertex2f(0,0);
		glVertex2f(100,100);
		glVertex2f(0,100);
    glEnd();
    glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0); 
		glVertex2f(0,0);
		glVertex2f(100,100);
		glVertex2f(100,0);
    glEnd();
    glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,1.0); 
		glVertex2f(0,50);
		glVertex2f(50,100);
		glVertex2f(100,50);
		glVertex2f(50,0);
    glEnd();
    glFlush();
}

int main (int argc, char** argv){
	glutInit (&argc, argv); // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
	glutInitWindowPosition (100,50);   // Set top-left display-window position.
	glutInitWindowSize (500, 500);// Set display-window width and height.
	glutCreateWindow ("2(b)"); // Create display window.
	init ( );
	glutDisplayFunc (lineSegment); // Send graphics to display window.
	glutMainLoop ( );  // Display everything and wait.
}
