#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<GL/glut.h>      // (or others, depending on the system in use)
void init (void)
{    
	glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.    
	glMatrixMode (GL_PROJECTION);       // Set projection parameters.    
	gluOrtho2D (0.0, 600.0, 0.0, 600.0);
}
void show (void)
{   
	glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.
	glColor3f (0.0, 0.0, 0.0);
	//A PICTURE
	int i=0;
    int n=3;
    float pi=3.14159265359;
    float x[200],y[200];
    glBegin (GL_POLYGON);
    for(i=0;i<n;i++)  
	{  
		x[i]=100+50*cos(2*pi-2*i*pi/n-pi/6);  
		y[i]=500+50*sin(2*pi-2*i*pi/n-pi/6);
		glVertex2f(x[i],y[i]);  
	}
	glEnd ( );
	glColor3f (1.0, 1.0, 1.0);
	glBegin (GL_POLYGON);
	i=0;
    for(i=0;i<n;i++)  
	{  
		x[i]=100+25*cos(2*pi-2*i*pi/n+pi/6);  
		y[i]=500+25*sin(2*pi-2*i*pi/n+pi/6);
		glVertex2f(x[i],y[i]);
	}
	glEnd ( );
	float a[200],b[200];
	//有正方形的
	n=4;i=0;
	
	for(i=0;i<n;i++)  
	{  
		x[i]=500+25*cos(2*pi-2*i*pi/n-2*pi*45/360);  
		y[i]=500+25*sin(2*pi-2*i*pi/n-2*pi*45/360);
		a[i]=500+12.5*(sqrt(2)+2)*cos(2*pi-2*i*pi/n);  
		b[i]=500+12.5*(sqrt(2)+2)*sin(2*pi-2*i*pi/n);
	}
	glColor3f (0.0, 0.0, 0.0);
	glBegin (GL_POLYGON);
	i=0;
    for(i=0;i<n;i++)  
	{
		glVertex2f(a[i],b[i]);
	}
	glEnd ( );
	glColor3f (1.0, 1.0, 1.0);
	glBegin (GL_POLYGON);
	i=0;
    for(i=0;i<n;i++)  
	{
		glVertex2f(x[i],y[i]);
	}
	glEnd ( );
	glColor3f (1.0, 1.0, 1.0);
	i=0;
	int t;
    for(i=0;i<n;i++)  
	{
		glBegin (GL_POLYGON);
		t=(i+1)%4;
		glVertex2f(x[i],y[i]);
		glVertex2f(a[t],b[t]);
		glVertex2f(a[i],b[i]);
		glEnd ( );
	}
	//五角形
	glColor3f (0.0, 0.0, 0.0);
	n=5;i=0;
	glBegin (GL_POLYGON);
	for(i=0;i<n;i++)  
	{  
		x[i]=100+25*cos(2*pi-2*i*pi/n-2*pi*18/360);  
		y[i]=100+25*sin(2*pi-2*i*pi/n-2*pi*18/360);
		/*glVertex2f(x[i],y[i]);*/ 
		a[i]=100+12.5*(sqrt(2)+2)*cos(2*pi-2*i*pi/n+2*pi*18/360);  
		b[i]=100+12.5*(sqrt(2)+2)*sin(2*pi-2*i*pi/n+2*pi*18/360);
		//glVertex2f(a[i],b[i]);
	}
	glEnd ( );
	glColor3f (0.0, 0.0, 0.0);
	glBegin (GL_POLYGON);
	i=0;
    for(i=0;i<n;i++)  
	{
		glVertex2f(a[i],b[i]);
	}
	glEnd ( );
	glColor3f (1.0, 1.0, 1.0);
	glBegin (GL_POLYGON);
	i=0;
    for(i=0;i<n;i++)  
	{
		glVertex2f(x[i],y[i]);
	}
	glEnd ( );
	glColor3f (1.0, 1.0, 1.0);
	for(i=0;i<n;i++)  
	{
		glBegin (GL_POLYGON);
		t=(i+1)%5;
		glVertex2f(x[i],y[i]);
		glVertex2f(a[t],b[t]);
		glVertex2f(a[i],b[i]);
		glEnd ( );
	}
	//六角形
	glColor3f (0.0, 0.0, 0.0);
	n=6;i=0;
	glBegin (GL_POLYGON);
	for(i=0;i<n;i++)  
	{  
		x[i]=500+25*cos(2*pi-2*i*pi/n);  
		y[i]=100+25*sin(2*pi-2*i*pi/n);
		/*glVertex2f(x[i],y[i]);*/ 
		a[i]=500+12.5*(sqrt(2)+2)*cos(2*pi-2*i*pi/n+2*pi*30/360);  
		b[i]=100+12.5*(sqrt(2)+2)*sin(2*pi-2*i*pi/n+2*pi*30/360);
		//glVertex2f(a[i],b[i]);
	}
	glEnd ( );
	glColor3f (0.0, 0.0, 0.0);
	glBegin (GL_POLYGON);
	i=0;
    for(i=0;i<n;i++)  
	{
		glVertex2f(a[i],b[i]);
	}
	glEnd ( );
	glColor3f (1.0, 1.0, 1.0);
	glBegin (GL_POLYGON);
	i=0;
    for(i=0;i<n;i++)  
	{
		glVertex2f(x[i],y[i]);
	}
	glEnd ( );
	glColor3f (1.0, 1.0, 1.0);
	for(i=0;i<n;i++)  
	{
		glBegin (GL_POLYGON);
		t=(i+1)%6;
		glVertex2f(x[i],y[i]);
		glVertex2f(a[t],b[t]);
		glVertex2f(a[i],b[i]);
		glEnd ( );
	}
    glFlush ( );
    
	
}
int main (int argc, char** argv)
{    
	glutInit (&argc, argv);                         // Initialize GLUT.    
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.    
	glutInitWindowPosition (10, 10);   // Set top-left display-window position.    
	glutInitWindowSize (600, 600);      // Set display-window width and height.    
	glutCreateWindow ("b0429008"); // Create display window.    
	init ( );                            // Execute initialization procedure.    
	glutDisplayFunc (show);       // Send graphics to display window.    
	glutMainLoop ( );                    // Display everything and wait.
} 
