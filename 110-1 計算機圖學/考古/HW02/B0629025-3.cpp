#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>      // (or others, depending on the system in use)
#include<math.h>

void init (void)
{    
	glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.     
	glMatrixMode (GL_PROJECTION);       // Set projection parameters.    
	gluOrtho2D (0.0, 400.0, 0.0, 400.0);
}

float pi = 3.1415926536f;

void polygon (void)
{  
	
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
      glVertex2i(0,0);
      glVertex2i(0,400);
      glVertex2i(0,400);
      glVertex2i(400,400);
      glVertex2i(400,400);
      glVertex2i(400,0);
      glVertex2i(400,0);
      glVertex2i(0,0);
    glEnd();
    glFlush();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
      glVertex2i(0,200);
      glVertex2i(200,400);
      glVertex2i(200,400);
      glVertex2i(400,200);
      glVertex2i(400,200);
      glVertex2i(200,0);
      glVertex2i(200,0);
      glVertex2i(0,200);
    glEnd();
    glFlush();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
      glVertex2i(100,100);
      glVertex2i(100,300);
      glVertex2i(100,300);
      glVertex2i(300,300);
      glVertex2i(300,300);
      glVertex2i(300,100);
      glVertex2i(300,100);
      glVertex2i(100,100);
    glEnd();
    glFlush();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
      glVertex2i(100,200);
      glVertex2i(200,300);
      glVertex2i(200,300);
      glVertex2i(300,200);
      glVertex2i(300,200);
      glVertex2i(200,100);
      glVertex2i(200,100);
      glVertex2i(100,200);
    glEnd();
    glFlush();

    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
      glVertex2i(150,150);
      glVertex2i(150,250);
      glVertex2i(150,250);
      glVertex2i(250,250);
      glVertex2i(250,250);
      glVertex2i(250,150);
      glVertex2i(250,150);
      glVertex2i(150,150);
    glEnd();
    glFlush();

    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
      glVertex2i(200,150);
      glVertex2i(150,200);
      glVertex2i(150,200);
      glVertex2i(200,250);
      glVertex2i(200,250);
      glVertex2i(250,200);
      glVertex2i(250,200);
      glVertex2i(200,150);
    glEnd();
    glFlush();
			
}                                                        

int main (int argc, char** argv)
{    
	glutInit (&argc, argv);                         // Initialize GLUT.    
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.    
	glutInitWindowPosition (50, 100);   // Set top-left display-window position.    
	glutInitWindowSize (400, 400);      // Set display-window width and height.    
	glutCreateWindow ("CYLIN's OpenGL Program"); // Create display window.    
	init ( );                            // Execute initialization procedure.    
	glutDisplayFunc (polygon);       // Send graphics to display window.    
	glutMainLoop ( );                    // Display everything and wait.
}


