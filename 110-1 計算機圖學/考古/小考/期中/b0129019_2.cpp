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
void three()//鬍鬚 
{
     glBegin(GL_LINES);
     glColor3f (0.0,0.0,0.0);
     glLineWidth(1);
     glVertex2i (55, 92);
     glVertex2i (68, 90);
     
     glVertex2i (55, 89);
     glVertex2i (68, 89);
     
     glVertex2i (55, 86);
     glVertex2i (68, 88);
     
     glVertex2i (81, 88);
     glVertex2i (94, 86);
     
     glVertex2i (81, 89);
     glVertex2i (94, 89);
     
     glVertex2i (81, 90);
     glVertex2i (94, 92);
     glEnd();
 }
   
double drawSQ(double i,double j) 

{

   glBegin (GL_QUADS); 

   glVertex2f (-i,-j);//左下 

   glVertex2f (i,-j);//右下

   glVertex2f (i, j);//右上

   glVertex2f (-i,j);//左上

   glEnd ( );

}

double drawSQ_LINE(double i,double j) 

{

   glBegin (GL_LINE_LOOP); 

   glVertex2f (-i,-j);//左下 

   glVertex2f (i,-j);//右下

   glVertex2f (i, j);//右上

   glVertex2f (-i,j);//左上

   glEnd ( );

}

void red()//紅色長方形領巾 
{
     glColor3f (1,0.0,0.0);
     glTranslatef(75,71,0.0);
     drawSQ(21,1.08);
     glColor3f (0,0.0,0.0);
     drawSQ_LINE(21,1.08);
       
}
    

void Mouth()//嘴巴 
{     
     const int n = 360;
     GLfloat R = 20;
     const GLfloat Pi = 3.1415926536f;    
     glLineWidth(2);       
     glBegin(GL_LINE_STRIP);
     for(int Q=220; Q<320; ++Q)
         glVertex2f(75+R*cos(2*Pi/n*Q),96+ R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
 
 void RING_L()//鈴鐺 
{     
     glTranslatef(-75,-71.8,0.0);
     const int n = 360;
     GLfloat R = 3;
     const GLfloat Pi = 3.1415926536f;    
     glLineWidth(3);       
     glBegin(GL_LINE_LOOP);
     for(int Q=0; Q<n; ++Q)
         glVertex2f(75+R*cos(2*Pi/n*Q),69+ R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
 
  void RING_P()
{     
     const int n = 360;
     GLfloat R = 3;
     const GLfloat Pi = 3.1415926536f;    
     glLineWidth(1);       
     glBegin(GL_POLYGON);
     for(int Q=0; Q<n; ++Q)
         glVertex2f(75+R*cos(2*Pi/n*Q),69+ R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
 
 void RING_BLACK()
{     
     const int n = 360;
     GLfloat R = 0.8;
     const GLfloat Pi = 3.1415926536f;    
     glLineWidth(1);       
     glBegin(GL_POLYGON);
     for(int Q=0; Q<n; ++Q)
         glVertex2f(75+R*cos(2*Pi/n*Q),68+ R*sin(2*Pi/n*Q));
     glEnd(); 
     
  
 }

void NOSE_L()
{     
     const int n = 360;
     GLfloat R = 3;
     const GLfloat Pi = 3.1415926536f;    
     glLineWidth(3);       
     glBegin(GL_LINE_LOOP);
     for(int Q=0; Q<n; ++Q)
         glVertex2f(75+R*cos(2*Pi/n*Q),95.5+ R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
 
 void NOSE_P()
{     
     const int n = 360;
     GLfloat R = 3;
     const GLfloat Pi = 3.1415926536f;    
     glLineWidth(3);       
     glBegin(GL_POLYGON);
     for(int Q=0; Q<n; ++Q)
         glVertex2f(75+R*cos(2*Pi/n*Q),95.5+ R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
 
void FACE_LINE()
{     
     const int n = 360;
     GLfloat R = 30;
     const GLfloat Pi = 3.1415926536f;    
     //glLineWidth(5);       
     glBegin(GL_LINE_LOOP);
     for(int Q=-50; Q<230; ++Q)
         glVertex2f(75+1.05*R*cos(2*Pi/n*Q),95+ R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
  void FACE_POLYGON()
{     
     const int n = 360;
     GLfloat R = 30;
     const GLfloat Pi = 3.1415926536f;    
     //glLineWidth(5);       
     glBegin(GL_POLYGON);
     for(int Q=-50; Q<230; ++Q)
         glVertex2f(75+1.05*R*cos(2*Pi/n*Q),95+ R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
 
 void FACE_L()
{     
     const int n = 360;
     GLfloat R = 20;
     const GLfloat Pi = 3.1415926536f;    
     //glLineWidth(5);       
     glBegin(GL_LINE_LOOP);
     for(int Q=-51; Q<231; ++Q)
         glVertex2f(75+1.2*R*cos(2*Pi/n*Q),87.8+ 1*R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
 void FACE_P()
{     
     const int n = 360;
     GLfloat R = 20;
     const GLfloat Pi = 3.1415926536f;    
     //glLineWidth(5);       
     glBegin(GL_POLYGON);
     for(int Q=-51; Q<231; ++Q)
         glVertex2f(75+1.2*R*cos(2*Pi/n*Q),87.8+1* R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
 

  void EYE_l()
{    
     const int n = 360;
     GLfloat R = 2;
     const GLfloat Pi = 3.1415926536f;

     glColor3f (0,0.0,0.0);
     //glLineWidth(5);       
     glBegin(GL_POLYGON);
     for(int Q=0; Q<n; ++Q)
         glVertex2f(70+R*cos(2*Pi/n*Q),102+ R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
 void EYE_r()
{    
     const int n = 360;
     GLfloat R = 2;
     const GLfloat Pi = 3.1415926536f;

     glColor3f (0,0.0,0.0);
     //glLineWidth(5);       
     glBegin(GL_POLYGON);
     for(int Q=0; Q<n; ++Q)
         glVertex2f(80+R*cos(2*Pi/n*Q),102+R*sin(2*Pi/n*Q));
     glEnd(); 
  
 } 
 
 
 void EYE_LEFT()
{    
     const int n = 360;
     GLfloat R = 8;
     const GLfloat Pi = 3.1415926536f;

     glColor3f (1,1.0,1.0);
     //glLineWidth(5);       
     glBegin(GL_POLYGON);
     for(int Q=0; Q<n; ++Q)
         glVertex2f(66+1.1*R*cos(2*Pi/n*Q),105+ 1.2*R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
 
  void EYE_LEFT_LINE()
{    
     const int n = 360;
     GLfloat R = 8;
     const GLfloat Pi = 3.1415926536f;

     glColor3f (0,0.0,0.0);
     glLineWidth(3);       
     glBegin(GL_LINE_LOOP);
     for(int Q=0; Q<n; ++Q)
         glVertex2f(66+1.1*R*cos(2*Pi/n*Q),105+ 1.2*R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
 
 void EYE_RIGHT()
{    
     const int n = 360;
     GLfloat R = 8;
     const GLfloat Pi = 3.1415926536f;

     glColor3f (1,1.0,1.0);
     glLineWidth(3);       
     glBegin(GL_POLYGON);
     for(int Q=0; Q<n; ++Q)
         glVertex2f(84+1.1*R*cos(2*Pi/n*Q),105+ 1.2*R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
 
  void EYE_RIGHT_LINE()
{    
     const int n = 360;
     GLfloat R = 8;
     const GLfloat Pi = 3.1415926536f;

     glColor3f (0.0,0.0,0.0);
     //glLineWidth(5);       
     glBegin(GL_LINE_LOOP);
     for(int Q=0; Q<n; ++Q)
         glVertex2f(84+1.1*R*cos(2*Pi/n*Q),105+ 1.2*R*sin(2*Pi/n*Q));
     glEnd(); 
  
 }
 


void myDisplay()
{
     glEnable( GL_LINE_SMOOTH );
     glEnable( GL_POLYGON_SMOOTH );
     glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
     glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );
  
     glClear(GL_COLOR_BUFFER_BIT);
     
     
     glColor3f (0.113,0.662,1.0);
     FACE_POLYGON();
    
     glColor3f (0,0.0,0.0);
     FACE_LINE();
     
    
     glColor3f (1.0,1.0,1.0);
     FACE_P();
      glColor3f (0,0.0,0.0);
     FACE_L();
     
   
     EYE_LEFT_LINE();
     EYE_RIGHT_LINE();
     
     EYE_LEFT();
     EYE_RIGHT();
     
     glColor3f (0.0,0.0,0.0);
     NOSE_L();
     glColor3f (1.0,0.0,0.0);
     NOSE_P();
     
     //直線 
     glBegin(GL_LINES);
     glColor3f (0.0,0.0,0.0);
     glVertex2i (75, 76);
     glVertex2i (75, 92);
     glEnd();
     
     Mouth();
      ///長方形 
    
     EYE_l();
     EYE_r();
     
     
     three();
     red();/////////////////////////////////////////////////////////////
     RING_L();
     glColor3f (1.0,1.0,0.0);
     RING_P();
     
     glTranslatef(75,70,0.0);
     glColor3f (0.0,0.0,0.0);
     drawSQ_LINE(3,0.5); 
     
     glTranslatef(-75,-70,0.0);
     RING_BLACK();
     
     glTranslatef(0,0,0.0);
     glColor3f(0,0,0);
     glBegin(GL_LINES);
     glVertex2f(75,68);
     glVertex2f (75,66);
     glEnd(); 
     

     glFlush();
  
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Tiffany's program");
    init ( ); 
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
