#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>      // (or others, depending on the system in use)
#include<math.h>

void init (void)
{    
glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.    
glMatrixMode (GL_PROJECTION);       // Set projection parameters.    
gluOrtho2D (0.0, 150.0, 0.0, 100.0);
}
const int n = 500000;
const GLfloat Pi = 3.1415926536f;	
int i = 0;
void lineSegment (void)
{    
glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.    
glColor3f (0.0, 0.0, 1.0); 
glLineWidth(1);     // Set line segment color to red.    
glBegin (GL_LINES);        
	glVertex2i(10,85);       // Specify line-segment geometry.        
    glVertex2i(25,85);
    glVertex2i(25,85);
    glVertex2i(25,75);
    glVertex2i(25,75);
    glVertex2i(10,75);
    glVertex2i(10,75);
    glVertex2i(10,85);
glEnd ( );    
glFlush ( );
glColor3f (0.0, 0.0, 0.0);
glBegin (GL_POLYGON);
	glVertex2i(10,70);
    glVertex2i(25,70);
    glVertex2i(25,70);
    glVertex2i(25,60);
    glVertex2i(25,60);
    glVertex2i(10,60);
    glVertex2i(10,60);
    glVertex2i(10,70);  
glEnd ( );    
glFlush ( );     // Process all OpenGL routines as quickly as possible.
glColor3f (1.0, 0.0, 0.0); 
glLineWidth(3.5);     // Set line segment color to red.    
glBegin (GL_LINES);        
	glVertex2i(10,55);       // Specify line-segment geometry.        
    glVertex2i(25,55);
    glVertex2i(25,55);
    glVertex2i(25,45);
    glVertex2i(25,45);
    glVertex2i(10,45);
    glVertex2i(10,45);
    glVertex2i(10,55);
glEnd ( );    
glFlush ( );
glColor3f (0.0, 0.0, 1.0);
glBegin (GL_POLYGON);
	glVertex2i(10,55);       // Specify line-segment geometry.        
    glVertex2i(25,55);
    glVertex2i(25,55);
    glVertex2i(25,45);
    glVertex2i(25,45);
    glVertex2i(10,45);
    glVertex2i(10,45);
    glVertex2i(10,55); 
glEnd ( );    
glFlush ( );     // Process all OpenGL routines as quickly as possible.

glColor3f(0.1,0.1,1.0);
glLineWidth(3); 
    glBegin(GL_LINE_LOOP);
        for (i=0;i<n;++i){
            glVertex2f(40+10*cos(2*Pi/n*i),70+10*sin(2*Pi/n*i));
            glVertex2f(40+10.1*cos(2*Pi/n*i),70+10.1*sin(2*Pi/n*i));
            glVertex2f(40+10.2*cos(2*Pi/n*i),70+10.2*sin(2*Pi/n*i));
            glVertex2f(40+10.3*cos(2*Pi/n*i),70+10.3*sin(2*Pi/n*i));
            glVertex2f(40+10.4*cos(2*Pi/n*i),70+10.4*sin(2*Pi/n*i));
            glVertex2f(40+10.5*cos(2*Pi/n*i),70+10.5*sin(2*Pi/n*i));
        }
    glEnd();
    glFlush();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (i=0;i<n;++i){
            glVertex2f(65+10*cos(2*Pi/n*i),70+10*sin(2*Pi/n*i));
            glVertex2f(65+10.1*cos(2*Pi/n*i),70+10.1*sin(2*Pi/n*i));
            glVertex2f(65+10.2*cos(2*Pi/n*i),70+10.2*sin(2*Pi/n*i));
            glVertex2f(65+10.3*cos(2*Pi/n*i),70+10.3*sin(2*Pi/n*i));
            glVertex2f(65+10.4*cos(2*Pi/n*i),70+10.4*sin(2*Pi/n*i));
            glVertex2f(65+10.5*cos(2*Pi/n*i),70+10.5*sin(2*Pi/n*i));
        }
    glEnd();
    glFlush();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (i=0;i<n;++i){
            glVertex2f(90+10*cos(2*Pi/n*i),70+10*sin(2*Pi/n*i));
            glVertex2f(90+10.1*cos(2*Pi/n*i),70+10.1*sin(2*Pi/n*i));
            glVertex2f(90+10.2*cos(2*Pi/n*i),70+10.2*sin(2*Pi/n*i));
            glVertex2f(90+10.3*cos(2*Pi/n*i),70+10.3*sin(2*Pi/n*i));
            glVertex2f(90+10.4*cos(2*Pi/n*i),70+10.4*sin(2*Pi/n*i));
            glVertex2f(90+10.5*cos(2*Pi/n*i),70+10.5*sin(2*Pi/n*i));
        }
    glEnd();
    glFlush();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (i=0;i<n;++i){
            glVertex2f(52.5+10*cos(2*Pi/n*i),57.5+10*sin(2*Pi/n*i));
            glVertex2f(52.5+10.1*cos(2*Pi/n*i),57.5+10.1*sin(2*Pi/n*i));
            glVertex2f(52.5+10.2*cos(2*Pi/n*i),57.5+10.2*sin(2*Pi/n*i));
            glVertex2f(52.5+10.3*cos(2*Pi/n*i),57.5+10.3*sin(2*Pi/n*i));
            glVertex2f(52.5+10.4*cos(2*Pi/n*i),57.5+10.4*sin(2*Pi/n*i));
            glVertex2f(52.5+10.5*cos(2*Pi/n*i),57.5+10.5*sin(2*Pi/n*i));
        }
    glEnd();
    glFlush();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINE_LOOP);
        for (i=0;i<n;++i){
            glVertex2f(77.5+10*cos(2*Pi/n*i),57.5+10*sin(2*Pi/n*i));
            glVertex2f(77.5+10.1*cos(2*Pi/n*i),57.5+10.1*sin(2*Pi/n*i));
            glVertex2f(77.5+10.2*cos(2*Pi/n*i),57.5+10.2*sin(2*Pi/n*i));
            glVertex2f(77.5+10.3*cos(2*Pi/n*i),57.5+10.3*sin(2*Pi/n*i));
            glVertex2f(77.5+10.4*cos(2*Pi/n*i),57.5+10.4*sin(2*Pi/n*i));
            glVertex2f(77.5+10.5*cos(2*Pi/n*i),57.5+10.5*sin(2*Pi/n*i));
        }
    glEnd();
    glFlush();
}



int main (int argc, char** argv)
{    
glutInit (&argc, argv);                         // Initialize GLUT.    
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.    
glutInitWindowPosition (50, 100);   // Set top-left display-window position.   
glutInitWindowSize (600, 400);      // Set display-window width and height.    
glutCreateWindow ("CYLIN's OpenGL Program"); // Create display window.    
init ( );                            // Execute initialization procedure.    
glutDisplayFunc (lineSegment);       // Send graphics to display window.    
glutMainLoop ( );                    // Display everything and wait.
}
