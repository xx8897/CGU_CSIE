#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>      // (or others, depending on the system in use)
#include<math.h>
void init (void)
 {
      glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.
     glMatrixMode (GL_PROJECTION);       // Set projection parameters.
     gluOrtho2D (0.0, 400.0, 0.0, 400.0);//�����j�p 
 }
 void lineSegment (void)
 {    
       glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.
       
       GLfloat pi,x,y,a,b;
       GLint i;
       
       
       
       //1.(c)
       //�T���� 
       glColor3f(1.0,0.0,0.0);
       glBegin(GL_POLYGON);
           x=300+100*cos(1.57);//����(300,100) //100����j�p //()������ 
           y=100+100*sin(1.57);
           glVertex2f(x,y);
           x=300+100*cos(3.66);
           y=100+100*sin(3.66);
           glVertex2f(x,y);
           x=300+100*cos(5.75);
           y=100+100*sin(5.75);
           glVertex2f(x,y);
       glEnd();
       //�զ�T���� 
       glColor3f(1.0,1.0,1.0);
       glBegin(GL_POLYGON);
           x=300+80*cos(1.57);
           y=100+80*sin(1.57);
           glVertex2f(x,y);
           x=300+80*cos(3.66);
           y=100+80*sin(3.66);
           glVertex2f(x,y);
           x=300+80*cos(5.75);
           y=100+80*sin(5.75);
           glVertex2f(x,y);
       glEnd();
       
       //�¦�T���� 
       glColor3f(0.0,0.0,0.0);
       glBegin(GL_POLYGON);
           x=300+80*cos(1.1);
           y=50+80*sin(1.1);
           glVertex2f(x,y);
           x=300+80*cos(3.66);
           y=100+80*sin(3.66);
           glVertex2f(x,y);
           x=300+80*cos(5.75);
           y=100+80*sin(5.75);
           glVertex2f(x,y);
       glEnd();
       
       //�b�Y�u 
       glLineWidth(10);
       glColor3f (0.0, 0.0, 0.0);      // Set line segment color to red.    
      glBegin (GL_LINES);        
      glVertex2i (280, 100);
      glVertex2i (320, 125);  
       glEnd();
      
      //�b�Y 
       glColor3f(0.0,0.0,0.0);
       glBegin(GL_POLYGON);
           x=300+8*cos(1.7)-20;
           y=150+8*sin(1.7)-50;
           glVertex2f(x,y);
           x=300+8*cos(3.7)-20;
           y=150+8*sin(3.7)-50;
           glVertex2f(x,y);
           x=300+8*cos(5.4)-20;
           y=150+8*sin(5.4)-50;
           glVertex2f(x,y);
           
       
       glEnd();
       
      
       
       glFlush ( );     // Process all OpenGL routines as quickly as possible.
 }
 int main (int argc, char** argv)
 {    
       glutInit (&argc, argv);                         // Initialize GLUT.    
       glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.    
       glutInitWindowPosition (50, 50);               // ���W������`�������I    
       glutInitWindowSize (600, 600);                  // �`�����j�p
       glutCreateWindow ("2.0");                      //�����W��
       init ( );                                       // Execute initialization procedure.    
       glutDisplayFunc (lineSegment);                  // Send graphics to display window.    
       glutMainLoop ( );                               // Display everything and wait.
 }
