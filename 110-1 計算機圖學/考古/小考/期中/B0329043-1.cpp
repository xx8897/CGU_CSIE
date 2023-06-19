#include <GL/glut.h>
#include <stdlib.h>
#include <cmath>
GLfloat color[5][3]={{1.0, 0.0, 0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,0.0},{0.0,1.0,1.0}};
void init (void){
     glClearColor (1.0, 1.0, 1.0, 0.0);  
     glMatrixMode (GL_PROJECTION);
     gluOrtho2D (0.0, 100.0, 0.0, 100.0);
}       

void square (void)
{
	int n=360,R=20,i,j;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
	glBegin (GL_POLYGON);
   	for(int j=0;j<n;++j) 
    glVertex2f(50 +R*sin(2*M_PI/n*j), 50 +R*cos(2*M_PI/n*j));
    glEnd ( );
    glColor3f(1.0, 1.0, 1.0);
	glBegin (GL_POLYGON);
   	for(int j=1;j<180;++j) 
    glVertex2f(50 +R*sin(2*M_PI/n*j), 50 +R*cos(2*M_PI/n*j));
    glEnd ( );
    glBegin (GL_POLYGON);
    for(int j=0;j<360;++j) 
    glVertex2f(50 +R/2*sin(2*M_PI/n*j), 40 +R/2*cos(2*M_PI/n*j));
    glEnd ( );
    glColor3f(0.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
    for(int j=0;j<360;++j) 
    glVertex2f(50 +R/2*sin(2*M_PI/n*j), 60 +R/2*cos(2*M_PI/n*j));
    glEnd ( );
    glBegin (GL_POLYGON);
    for(int j=0;j<360;++j) 
    glVertex2f(50 +2*sin(2*M_PI/n*j), 40 +2*cos(2*M_PI/n*j));
    glEnd ( );
    glColor3f(1.0, 1.0, 1.0);
    glBegin (GL_POLYGON);
    for(int j=0;j<360;++j) 
    glVertex2f(50 +2*sin(2*M_PI/n*j), 60 +2*cos(2*M_PI/n*j));
    glEnd ( );
    glColor3f(0.0, 0.0, 0.0);
	glBegin (GL_LINE_LOOP);
   	for(int j=0;j<n;++j) 
    glVertex2f(50 +R*sin(2*M_PI/n*j), 50 +R*cos(2*M_PI/n*j));
    glEnd ( );
    glFlush ( );     
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("B0329043-1");
    init ();  
    glutDisplayFunc(square);                          
    glutMainLoop ( );                    
    
}
