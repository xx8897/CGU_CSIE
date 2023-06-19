#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

void init (void)
 {
      glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.
     glMatrixMode (GL_PROJECTION);       // Set projection parameters.
     gluOrtho2D ( -100.0,600.0, -300.0, 400.0);//視窗大小
      glPointSize(3.0); 
 }


//全域變數 
int n=1;
GLfloat vertices[1][2] = {{100,100}};
GLfloat temp[1][2] = {0,0};
GLfloat cx,cy;

//找中心點 
void findcxcy()
{
  cx=0;
  cy=0;
  for(int i=0 ; i<n ; i++)
  {
    cx = vertices[i][0] + cx;
    cy = vertices[i][1] + cy;
  }
  cx = cx/n;
  cy = cy/n;
}

//移動
void translate(GLfloat tx,GLfloat ty)
{
  for(int i=0 ; i<n ; i++)
  {
    vertices[i][0] = vertices[i][0]+tx;
    vertices[i][1] = vertices[i][1]+ty;
  }
}

//縮放 
void scale(GLfloat sx,GLfloat sy,GLfloat fixed_x,GLfloat fixed_y)
{
  translate((-1)*fixed_x,(-1)*fixed_y);
  for(int i=0 ; i<n ; i++)
  {
    vertices[i][0] *= sx;
    vertices[i][1] *= sy;
  }
  translate(fixed_x,fixed_y);
}

//旋轉
void rotate(GLfloat angle,GLfloat fixed_x,GLfloat fixed_y)
{
  //角度轉弧度 
  angle=angle*3.1415926/180;
  
  translate((-1)*fixed_x,(-1)*fixed_y);
  for(int i=0 ; i<n ; i++)
  {
    temp[i][0] = vertices[i][0]*cos(angle) - vertices[i][1]*sin(angle);
    temp[i][1] = vertices[i][0]*sin(angle) + vertices[i][1]*cos(angle);
  }
  for(int i=0 ; i<n ; i++)
  {
    vertices[i][0] = temp[i][0];
    vertices[i][1] = temp[i][1];
  }
  translate(fixed_x,fixed_y);
}
 
 void lineSegment (void)
 {    
       glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.
       
       GLfloat x,y;
       GLint i;
       //step1
       glColor3f(1.0,0.0,0.0);
       glBegin(GL_POLYGON);
         for(i=60 ; i<240 ; i++)
         {
           x=vertices[0][0]+100*cos(i*3.1415926/180);
           y=vertices[0][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
       glEnd();
        
       glColor3f(0.0,1.0,0.0);
        glBegin(GL_POINTS);
         for(i=240 ; i<360 ; i++)
         {
           x=vertices[0][0]+100*cos(i*3.1415926/180);
           y=vertices[0][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
       glEnd();
        
       //step2
	   rotate(-45.0,0.0,0.0); 
      
       //step3
       translate(-200,200);
       
       //step4
       findcxcy();
       
       //step5
       scale(3,3,cx,cy);
       
       //step6
       rotate(-180,100,100);
       
       //step7
       glColor3f(1.0,0.0,0.0);
       glBegin(GL_POINTS);
         for(i=60 ; i<240 ; i++)
         {
           x=vertices[0][0]+100*cos(i*3.1415926/180);
           y=vertices[0][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
       glEnd();
        
       glColor3f(0.0,1.0,0.0);
        glBegin(GL_POINTS);
         for(i=240 ; i<420 ; i++)
         {
           x=vertices[0][0]+100*cos(i*3.1415926/180);
           y=vertices[0][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
       glEnd();
       
       glFlush ( );     // Process all OpenGL routines as quickly as possible.
 }
 int main (int argc, char** argv)
 {    
       glutInit (&argc, argv);                         // Initialize GLUT.    
       glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.    
       glutInitWindowPosition (50, 50);               // 左上角位於總視窗原點    
       glutInitWindowSize (400, 400);                  // 總視窗大小
       glutCreateWindow ("B0629025-Q2");   //視窗名稱
       init ( );                                       // Execute initialization procedure.    
       glutDisplayFunc (lineSegment);                  // Send graphics to display window. 
       glutMainLoop ( );  
 
 }
