#include<stdlib.h>
#include<stdio.h>
#include <GL/glut.h>
#include <math.h>

void init (void)
{   
       glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.    
       glMatrixMode (GL_PROJECTION);       // Set projection parameters.  
       gluOrtho2D (0.0, 150,0.0, 150);      
}

void myDisplay()
{
     glClear(GL_COLOR_BUFFER_BIT);
     
    
     glEnable(GL_BLEND);
     glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
     glEnable( GL_LINE_SMOOTH );
     glEnable( GL_POLYGON_SMOOTH );
     glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
     glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );
     
     const int n = 360;
     GLfloat R = 29;
     const GLfloat Pi = 3.1415926536f;

     glColor3f (0,0.0,0.0);
     glLineWidth(3);       
     glBegin(GL_LINE_LOOP);
     for(int Q=0; Q<n; ++Q)
         glVertex2f(75+R*cos(2*Pi/n*Q),85+ R*sin(2*Pi/n*Q));
     glEnd(); 
     
     glColor3f (0.0, 0.0, 0.0);
     glTranslatef(160,15,0.0);
     glRotatef(90,0,0,1);       
     glBegin(GL_TRIANGLE_FAN);
     
     for(int i=0;i<0+n;i+=120)
     {            
         glVertex2f(75+0.8*R*cos(2*Pi/n*i),85+0.2*R*sin(2*Pi/n*i));
         
     }
     glTranslatef(-160,-15,0.0);
     glEnd(); 
     
     //glTranslatef(-160,-15,0.0);
     glColor3f (0.0, 0.0, 0.0);
     glTranslatef(170,50,0.0);
     glRotatef(110,0,0,1);       
     glBegin(GL_TRIANGLE_FAN);
     
     for(int i=0;i<0+n;i+=120)
     {            
         glVertex2f(75+0.8*R*cos(2*Pi/n*i),85+0.2*R*sin(2*Pi/n*i));
         
     }
     
     glEnd(); 
     
     glColor3f (0.0, 0.0, 0.0);
     glTranslatef(175,70,0.0);
     glRotatef(120,0,0,1);       
     glBegin(GL_TRIANGLE_FAN);
     
     for(int i=0;i<0+n;i+=120)
     {            
         glVertex2f(75+0.8*R*cos(2*Pi/n*i),85+0.2*R*sin(2*Pi/n*i));
         
     }
     
     glEnd(); 
  glFlush();
  
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tiffany's circle");
    init ( ); 
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
