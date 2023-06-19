#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>      // (or others, depending on the system in use)
#include<math.h>

void init (void)
{    
	glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.     
	glMatrixMode (GL_PROJECTION);       // Set projection parameters.    
	gluOrtho2D (0.0, 100.0, 0.0, 100.0);
}

float pi = 3.1415926536f;

void polygon (void)
{   
	
	glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.    
	glColor3f (1.0, 0.0, 0.0);      // Set line segment color to red.
	float x[5] = {0};
	float y[5] = {0};
		
    
        for(int i=0;i<5;i++)
        {
        	x[i] = 50+10*cos(0.3+2*pi/5*i);
        	y[i] = 50+10*sin(0.3+2*pi/5*i);
    		//glVertex2f(50+10*cos(0.3+2*pi/5*i),50+10*sin(0.3+2*pi/5*i));
    	}
    	
    glEnd();
    glFlush();
    
    
    glColor3f(1.0,0.0,0.0);  //red
    glBegin(GL_POLYGON);
        for(int i=0;i<100000;i++)
        	glVertex2f(x[2]+10*cos(2*pi/100*i),y[2]+10*sin(2*pi/100*i));
    glEnd(); 
	glFlush();  
			
	glColor3f(0.0,1.0,0.0); //green
    glBegin(GL_POLYGON);
        for(int i=0;i<100;i++)
        	glVertex2f(x[1]+10*cos(2*pi/100*i),y[1]+10*sin(2*pi/100*i));
    glEnd(); 
	glFlush();  
	
	glColor3f(0.0,0.0,1.0);  //blue
    glBegin(GL_POLYGON);
        for(int i=0;i<100;i++)
        	glVertex2f(x[0]+10*cos(2*pi/100*i),y[0]+10*sin(2*pi/100*i));
    glEnd(); 
	glFlush();
	
	glColor3f(1.0,1.0,0.0);  //yellow
    glBegin(GL_POLYGON);
        for(int i=0;i<100;i++)
        	glVertex2f(x[4]+10*cos(2*pi/100*i),y[4]+10*sin(2*pi/100*i));
    glEnd(); 
	glFlush(); 
	
	glColor3f(0.0,1.0,1.0);  //dark blue
    glBegin(GL_POLYGON);
        for(int i=0;i<100;i++)
        	glVertex2f(x[3]+10*cos(2*pi/100*i),y[3]+10*sin(2*pi/100*i));
    glEnd(); 
	glFlush(); 
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<5;i++)
        {
        	x[i] = 50+10*cos(0.3+2*pi/5*i);
        	y[i] = 50+10*sin(0.3+2*pi/5*i);
        	glVertex2f(x[i],y[i]);
    		//glVertex2f(50+10*cos(0.3+2*pi/5*i),50+10*sin(0.3+2*pi/5*i));
    	}
		
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



