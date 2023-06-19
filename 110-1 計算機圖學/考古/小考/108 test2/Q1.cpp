#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

void init (void)
 {
      glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.
     glMatrixMode (GL_PROJECTION);       // Set projection parameters.
     gluOrtho2D ( 0.0, 4000.0, 0.0, 4000.0);//�����j�p
      glPointSize(3.0); 
 }


//�����ܼ� 
int n=1;
GLfloat vertices[3][2] = {{200,200},{600,200},{400,400}};
GLfloat temp[3][2] = {{0,0},{0,0},{0,0}};
GLfloat cx,cy;

//�䤤���I 
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

//����
void translate(GLfloat tx,GLfloat ty)
{
  for(int i=0 ; i<n ; i++)
  {
    vertices[i][0] = vertices[i][0]+tx;
    vertices[i][1] = vertices[i][1]+ty;
  }
}

//�Y�� 
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

//����
void rotate(GLfloat angle,GLfloat fixed_x,GLfloat fixed_y)
{
  //�����੷�� 
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
       
       //STEP1
       glColor3f(1.0,0.0,0.0);  //RED
       glBegin(GL_POINTS);
         for(i=0 ; i<360 ; i++)
         {
           x=vertices[0][0]+100*cos(i*3.1415926/180);
           y=vertices[0][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
       glEnd();
       glColor3f(0.0,0.0,1.0); //BLUE
       glBegin(GL_POINTS);
         for(i=0 ; i<360 ; i++)
         {
           x=vertices[1][0]+100*cos(i*3.1415926/180);
           y=vertices[1][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
       glEnd();
       glColor3f(0.0,1.0,0.0); //GREEN
        glBegin(GL_POINTS);
         for(i=0 ; i<360 ; i++)
         {
           x=vertices[2][0]+100*cos(i*3.1415926/180);
           y=vertices[2][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
	
       glEnd();
       
       	findcxcy();//STEP2
		
		//STEP3
	    glColor3f(1.0,0.0,0.0);  //RED
       glBegin(GL_POINTS);
         for(i=0 ; i<360 ; i++)
         {
           x=vertices[0][0]+100*cos(i*3.1415926/180);
           y=vertices[0][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
       glEnd();
       rotate(-45.0,cx,cy);
	   
	   //STEP4
       glColor3f(0.0,0.0,1.0); //BLUE
       glBegin(GL_POINTS);
         for(i=0 ; i<360 ; i++)
         {
           x=vertices[1][0]+100*cos(i*3.1415926/180);
           y=vertices[1][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
	   glEnd();
	   rotate(45.0,cx,cy);
       
       //STEP5
        glColor3f(1.0,0.0,0.0);  //RED
       glBegin(GL_POINTS);
         for(i=0 ; i<360 ; i++)
         {
           x=vertices[0][0]+100*cos(i*3.1415926/180);
           y=vertices[0][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
       glEnd();
       rotate(-45.0,cx,cy);
       findcxcy();
       
       //STEP6
       glColor3f(0.0,0.0,1.0); //BLUE
       glBegin(GL_POINTS);
         for(i=0 ; i<360 ; i++)
         {
           x=vertices[1][0]+100*cos(i*3.1415926/180);
           y=vertices[1][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
	   glEnd();
	   scale(3,3,cx,cy);
	   
       //STEP7
       findcxcy();
      
       //STEP8
       glColor3f(1.0,0.0,0.0);  //RED
       glBegin(GL_POINTS);
         for(i=0 ; i<360 ; i++)
         {
           x=vertices[0][0]+100*cos(i*3.1415926/180);
           y=vertices[0][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
       glEnd();
       rotate(-180.0,cx,cy);
      
      //step9
       glColor3f(1.0,0.0,0.0);  //RED
       glBegin(GL_POINTS);
         for(i=0 ; i<360 ; i++)
         {
           x=vertices[0][0]+100*cos(i*3.1415926/180);
           y=vertices[0][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
       glEnd();
       glColor3f(0.0,0.0,1.0); //BLUE
       glBegin(GL_POINTS);
         for(i=0 ; i<360 ; i++)
         {
           x=vertices[1][0]+100*cos(i*3.1415926/180);
           y=vertices[1][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
       glEnd();
       glColor3f(0.0,1.0,0.0); //GREEN
        glBegin(GL_POINTS);
         for(i=0 ; i<360 ; i++)
         {
           x=vertices[2][0]+100*cos(i*3.1415926/180);
           y=vertices[2][1]+100*sin(i*3.1415926/180);
           glVertex2f(x,y);
         }
       glEnd();
	   

       
       glFlush ( );     // Process all OpenGL routines as quickly as possible.
 }
 int main (int argc, char** argv)
 {    
       glutInit (&argc, argv);                         // Initialize GLUT.    
       glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.    
       glutInitWindowPosition (50, 50);               // ���W������`�������I    
       glutInitWindowSize (600, 600);                  // �`�����j�p
       glutCreateWindow ("B0629025-Q1");   //�����W��
       init ( );                                       // Execute initialization procedure.    
       glutDisplayFunc (lineSegment);                  // Send graphics to display window. 
       glutMainLoop ( );  
 
 }
