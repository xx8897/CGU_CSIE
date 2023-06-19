#include <GL/glut.h>
#include <stdlib.h>
#include <cmath>
GLfloat color[8][3]={{1.0, 1.0, 0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.7,0.0,0.7},{0.8,0.0,0.8},{1.0, 0.0, 0.7},{1.0,0.0,0.0},{0.8,0.0,0.0}};
void init (void){
     glClearColor (1.0, 1.0, 1.0, 0.0);  
     glMatrixMode (GL_PROJECTION);
     gluOrtho2D (0.0, 100.0, 0.0, 100.0);
}       

void square (void)
{
	int n=360,R=20,i=0,j;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
	glBegin (GL_LINE_LOOP);
   	for(int j=0;j<n;j+=45) 
    glVertex2f(50 +R*sin(2*M_PI/n*j-2*M_PI/16), 50 +R*cos(2*M_PI/n*j-2*M_PI/16));
    glEnd ( );
    glColor3f(1.0, 1.0, 1.0);
	glBegin (GL_POLYGON);
   	for(int j=0;j<n;j+=45) 
    glVertex2f(50 +12*sin(2*M_PI/n*j-2*M_PI/32), 50 +12*cos(2*M_PI/n*j-2*M_PI/32));
    glEnd ( );
	glBegin (GL_TRIANGLES);
   	for(int j=0;j<n;j+=45)
    { 
        glColor3fv(color[i]);
        glVertex2f(50 +R*sin(2*M_PI/n*(j+45)-2*M_PI/16), 50 +R*cos(2*M_PI/n*(j+45)-2*M_PI/16));
        glVertex2f(50 +R*sin(2*M_PI/n*(j+90)-2*M_PI/16), 50 +R*cos(2*M_PI/n*(j+90)-2*M_PI/16));
        glVertex2f(50 +12*sin(2*M_PI/n*j-2*M_PI/32), 50 +12*cos(2*M_PI/n*j-2*M_PI/32));
        i++;
    }
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
