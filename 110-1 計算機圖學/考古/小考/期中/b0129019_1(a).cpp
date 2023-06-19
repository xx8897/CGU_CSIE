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
     
     const int n = 360;
     GLfloat R = 29;
     const GLfloat Pi = 3.1415926536f;
     
     glColor3f (0.623, 0.611, 0.607);
    // glTranslatef(160,15,0.0);
     //glRotatef(90,0,0,1);       
     glBegin(GL_TRIANGLE_FAN);
     
     for(int i=0;i<0+n;i+=90)
     {            
         glVertex2f(75+0.4*R*cos(2*Pi/n*i),85+0.8*R*sin(2*Pi/n*i));
         
     }
     
     glEnd(); 
     glTranslatef(30,-25,0.0);
      glRotatef(25,0,0,1);     
     glColor3f (0.623, 0.611, 0.607);
    // glTranslatef(160,15,0.0);
    // glRotatef(90,0,0,1);       
     glBegin(GL_TRIANGLE_FAN);
     
     for(int i=90;i<90+n;i+=90)
     {            
         glVertex2f(55+0.8*R*cos(2*Pi/n*i),60+0.4*R*sin(2*Pi/n*i));
         
     }
     
     glEnd(); 
     
     glTranslatef(175,38,0.0);
      glRotatef(130,0,0,1);     
     glColor3f (0.623, 0.611, 0.607);
    // glTranslatef(160,15,0.0);
    // glRotatef(90,0,0,1);       
     glBegin(GL_TRIANGLE_FAN);
     
     for(int i=90;i<90+n;i+=90)
     {            
         glVertex2f(55+0.8*R*cos(2*Pi/n*i),60+0.4*R*sin(2*Pi/n*i));
         
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
