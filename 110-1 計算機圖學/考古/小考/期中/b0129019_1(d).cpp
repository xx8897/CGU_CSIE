#include<stdlib.h>
#include<stdio.h>
#include <GL/glut.h>
#include <math.h>
#include<time.h>
void init (void)
{   
       glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.    
       glMatrixMode (GL_PROJECTION);       // Set projection parameters.  
       gluOrtho2D (0.0, 150,0.0, 150);      
}



const int n = 360;
GLfloat R = 25;
const GLfloat Pi = 3.1415926536f;

void DrawCircle()
{
     
      srand(time(0));
      glEnable( GL_LINE_SMOOTH );
      glEnable( GL_POLYGON_SMOOTH );
      glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
      glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );
      GLint c;
      GLfloat color[6][3]={{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,0.0},{1.0,0.0,1.0},{0.0,1.0,1.0}}; //ÁÙ¦³¶Â¦â 
     
        

     glColor3f (1.0, 1.0, 0.0);
     //glLineWidth(5);    
     int i;
     glBegin(GL_POLYGON);
     for(i=0; i<n; ++i)
         glVertex2f(50+R*cos(2*Pi/n*i),105+ R*sin(2*Pi/n*i));
     glEnd(); 
     
    
    
     
   
     glColor3f (1.0, 1.0, 0.0);
    // glLineWidth(5);    
     int k;
     glBegin(GL_POLYGON);
     for(k=0; k<n; ++k)
         glVertex2f(50+R*cos(2*Pi/n*k), 70+R*sin(2*Pi/n*k));
     glEnd();
     
    
     
  
     glColor3f (1.0, 1.0, 0.0);
     //glLineWidth(5);    
     int m;
     glBegin(GL_POLYGON);
     for(m=0; m<n; ++m)
         glVertex2f(85+R*cos(2*Pi/n*m),105+R*sin(2*Pi/n*m));
     glEnd();
     
     
     
     
      glColor3f (1.0, 1.0, 0.0);
     //glLineWidth(5);    
     int ov;
     glBegin(GL_POLYGON);
     for(ov=0; ov<n; ++ov)
         glVertex2f(85+R*cos(2*Pi/n*ov), 70+R*sin(2*Pi/n*ov));
     glEnd();
     

  
     int ii,jj;
  
     GLfloat R1 ; 
    
     for(int p;p<100;p++)
     {
              R1=rand()%30+1;
              c=rand()%7;
              glColor3fv(color[c]); 
              glBegin(GL_LINES);
              ii=rand()%360+1;
     
     for(int ov=ii; ov<ii+1; ++ov)
     {
         glVertex2f(67.5, 87.5);
         glVertex2f(67.5+R1*cos(2*Pi/n*ov), 87.5+R1*sin(2*Pi/n*ov));
     } 
     }
     glEnd();
     

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
    glutInitWindowSize(800, 800);
    glutCreateWindow("Tiffany's circle");
    init ( ); 
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
