#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>      // (or others, depending on the system in use)
#include<math.h>

void init (void)
{    
glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.    
glMatrixMode (GL_PROJECTION);       // Set projection parameters.    
gluOrtho2D (0.0, 500.0, 0.0, 500.0);
}

const int n = 1000;
const GLfloat Pi = 3.1415926536f;	
GLfloat r = 200;
GLfloat RED = 1.0;
GLfloat GREEN = 0.0;
GLfloat BLUE = 0.0;
void lineSegment (void)
{    
glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.    

glLineWidth(3); 
	for(int c=0;c<100;c++)
    {
   		glBegin(GL_POINTS);
        glColor3f(RED,GREEN,BLUE);
        for (int i=0;i<n;++i)
        {
            glVertex2f(250+r*cos(2*Pi/n*i),250+r*sin(2*Pi/n*i));
        }
        r-=2.0;
        RED-=0.01;
        GREEN+=0.005;
        BLUE+=0.0025;
        
    }
	glEnd();
    glFlush();

    
}



int main (int argc, char** argv)
{    
glutInit (&argc, argv);                         // Initialize GLUT.    
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.    
glutInitWindowPosition (100, 100);   // Set top-left display-window position.   
glutInitWindowSize (600, 600);      // Set display-window width and height.    
glutCreateWindow ("HWO3-2"); // Create display window.    
init ( );                            // Execute initialization procedure.    
glutDisplayFunc (lineSegment);       // Send graphics to display window.    
glutMainLoop ( );                    // Display everything and wait.
}
