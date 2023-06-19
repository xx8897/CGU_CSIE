#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <GL/glut.h>
#include <math.h> 

#define Pi 3.1415926

void init(void)
{
     glClearColor(1.0,1.0,1.0,0.0);
     glMatrixMode(GL_PROJECTION);
     gluOrtho2D(0.0,400.0,0.0,400.0);
}

class wcPt2D
{
      public:
         float x, y;
};

wcPt2D square_1[4];
wcPt2D square_2[4];
wcPt2D center;

void init_array(void)
{
	 square_1[0].x=0;
	 square_1[0].y=0;
  	 square_1[1].x=100;
	 square_1[1].y=0;
	 square_1[2].x=100;
	 square_1[2].y=100;
	 square_1[3].x=0;
	 square_1[3].y=100;
}

void set_center(void)
{
	center.x=0;
	center.y=0;
	for(int i=0; i<4; i++){
		center.x=center.x+square_1[i].x;
		center.y=center.y+square_1[i].y;
	}
	center.x=center.x/4;
	center.y=center.y/4;
}
	 
void drow(void)
{
	
     glClear(GL_COLOR_BUFFER_BIT);
     
     glColor3f(0.0,0.0,1.0);
     glBegin(GL_POLYGON);
     for(int i=0; i<4; i++)
	 {
		glVertex2f(square_1[i].x, square_1[i].y);
 	 }
     glEnd();
	 
	 set_center();
     GLfloat sx=0.5,sy=0.5;            //scale
     for(int j=0; j<4; j++)
     {
     		square_2[j].x=square_1[j].x*sx+center.x*(1-sx);
			square_2[j].y=square_1[j].y*sy+center.y*(1-sy);
			square_1[j].x=square_2[j].x;
			square_1[j].y=square_2[j].y;
     }
     
     set_center();
     GLfloat pivPt=45;
     pivPt=pivPt*Pi/180;
     for(int k=0; k<4; k++)            //rotate
     {
             square_2[k].x=center.x+(square_1[k].x-center.x)*cos(pivPt)-(square_1[k].y-center.y)*sin(pivPt);
             square_2[k].y=center.y+(square_1[k].x-center.x)*sin(pivPt)+(square_1[k].y-center.y)*cos(pivPt); 
             square_1[k].x=square_2[k].x;
		 	 square_1[k].y=square_2[k].y;
     }
     
     set_center();
     GLfloat tx=50,ty=100;             //translate
     for(int l=0; l<4; l++)            
     {
             square_2[l].x=square_1[l].x+tx;
             square_2[l].y=square_1[l].y+ty;
     }
     
     
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_POLYGON);
     for(int m=0; m<4; m++)
	 {
		glVertex2f(square_2[m].x, square_2[m].y);
 	 }
     glEnd();
     
     glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("B0329044's-1");
    init();
    init_array();
    glutDisplayFunc(drow);
    glutMainLoop();
}
