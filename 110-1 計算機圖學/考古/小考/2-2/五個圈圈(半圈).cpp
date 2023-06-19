#include<stdlib.h>
#include<stdio.h>
#include <GL/glut.h>
#include <math.h>

void init (void)
{   
       glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.    
       glMatrixMode (GL_PROJECTION);       // Set projection parameters.  
       gluOrtho2D (-0.7, 0.5,-0.8, 0.9);      
}



const int n = 1000;
GLfloat R = 0.1f;
const GLfloat Pi = 3.1415926536f;

void DrawCircle()
{
     glEnable( GL_LINE_SMOOTH );
     glEnable( GL_POLYGON_SMOOTH );
     glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
     glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );
     
     
     //藍色圓 (左) 
     glColor3f (0.0, 0.0, 1.0);
     glLineWidth(5);    
     int i;
     glBegin(GL_POLYGON);
     for(i=0; i<n; ++i)
         glVertex2f(-0.39+R*cos(2*Pi/n*i),0.5+ R*sin(2*Pi/n*i));
     glEnd(); 
     
     //白色半圓 (左上斜) 
     GLfloat R1=0.08;
     glColor3f (1.0, 1.0, 1.0);
     glLineWidth(1);    
     int a;
     glBegin(GL_POLYGON);
     for(a=360; a<360+n; ++a)
         glVertex2f(-0.39+R1*cos(1*Pi/n*a),0.5+ R1*sin(1*Pi/n*a));
     glEnd(); 
     
     //紅色圓(上) 
     glColor3f (1.0, 0.0, 0.0);
     glLineWidth(5);    
     int j;
     glBegin(GL_POLYGON);
     for(j=0; j<n; ++j)
         glVertex2f(-0.24+R*cos(2*Pi/n*j), 0.65+R*sin(2*Pi/n*j));
     glEnd();
     
     //白色半圓 (上) 
      GLfloat R2=0.08;
     glColor3f (1.0, 1.0, 1.0);
     glLineWidth(1);    
     int b;
     glBegin(GL_POLYGON);
     for(b=0; b<n; ++b)
         glVertex2f(-0.24+R2*cos(1*Pi/n*b),0.65+ R2*sin(1*Pi/n*b));
     glEnd(); 
     
     //綠色圓(右) 
     glColor3f (0.0, 1.0, 0.0);
     glLineWidth(5);    
     int k;
     glBegin(GL_POLYGON);
     for(k=0; k<n; ++k)
         glVertex2f(-0.09+R*cos(2*Pi/n*k), 0.5+R*sin(2*Pi/n*k));
     glEnd();
     
     //白色半圓 (右上斜) 
     GLfloat R3=0.08;
     glColor3f (1.0, 1.0, 1.0);
     glLineWidth(1);    
     int c;
     glBegin(GL_POLYGON);
     for(c=1700; c<1700+n; ++c)
         glVertex2f(-0.09+R3*cos(1*Pi/n*c), 0.5+ R3*sin(1*Pi/n*c));
     glEnd(); 
     
     //黑色圓(左下) 
     glColor3f (0.0, 0.0, 0.0);
     glLineWidth(5);    
     int m;
     glBegin(GL_POLYGON);
     for(m=0; m<n; ++m)
         glVertex2f(-0.34+R*cos(2*Pi/n*m), 0.3+R*sin(2*Pi/n*m));
     glEnd();
     
     //白色半圓 (左下斜) 
     GLfloat R4=0.08;
     glColor3f (1.0, 1.0, 1.0);
     glLineWidth(1);    
     int d;
     glBegin(GL_POLYGON);
     for(d=700; d<700+n; ++d)
         glVertex2f(-0.34+R4*cos(1*Pi/n*d), 0.3+ R4*sin(1*Pi/n*d));
     glEnd(); 
     
     //紅色圓(右下) 
      glColor3f (1.0, 0.0, 0.0);
     glLineWidth(5);    
     int ov;
     glBegin(GL_POLYGON);
     for(ov=0; ov<n; ++ov)
         glVertex2f(-0.14+R*cos(2*Pi/n*ov), 0.3+R*sin(2*Pi/n*ov));
     glEnd();
     
     //白色半圓 (右下斜) 
     /*GLfloat R5=0.08;
     glColor3f (1.0, 1.0, 1.0);
     glLineWidth(1);    
     int ca;
     glBegin(GL_POLYGON);
     for(ca=1200; ca<1200+n; ++ca)
         glVertex2f(-0.14+R5*cos(1*Pi/n*ca), 0.3+ R5*sin(1*Pi/n*ca));
     glEnd();*/ 


     glFlush();
}
void myDisplay()
{
  glClear(GL_COLOR_BUFFER_BIT);
  DrawCircle();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 0);
    glutInitWindowSize(600, 800);
    glutCreateWindow("Tiffany's circle");
    init ( ); 
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
