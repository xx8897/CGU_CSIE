/* recursive subdivision of triangle to form Sierpinski gasket */
/* number of recursive steps given on command line */

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <GL/glut.h>

/* initial triangle */

//原始三角形的頂點由陣列給出 GLfloat v[3][2]
GLfloat v[3][2]={{-1.0, -0.58}, {1.0, -0.58}, {0.0, 1.15}};

int n;

void triangle( GLfloat *a, GLfloat *b, GLfloat *c)

/* specify one triangle */
{
       glVertex2fv(a);
       glVertex2fv(b);
       glVertex2fv(c);
}
//邊的中點由m陣列提供 
void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m)
{

/* triangle subdivision using vertex numbers */

    GLfloat v0[2], v1[2], v2[2];
    int j;
    if(m>0)
    {
        for(j=0; j<2; j++) v0[j]=(a[j]+b[j])/2;
        for(j=0; j<2; j++) v1[j]=(a[j]+c[j])/2;
        for(j=0; j<2; j++) v2[j]=(b[j]+c[j])/2;
        divide_triangle(a, v0, v1, m-1);
        divide_triangle(c, v1, v2, m-1);
        divide_triangle(b, v2, v0, m-1);
    }
    else triangle(a,b,c); /* draw triangle at end of recursion */
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT); /*clear the window */
    glBegin(GL_TRIANGLES);
    divide_triangle(v[0], v[1], v[2], n);
    glEnd();
    glFlush();
}
/* set attributes */
void myinit()
{
/* set up viewing */
/* 500 x 500 window with origin lower left */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    
    glClearColor (1.0, 1.0, 1.0, 1.0); /* white background */
    glColor3f(0.0,0.0,0.0); /* draw in black */
}

int main(int argc, char **argv)
{
    n=5; /* or set number of subdivision steps here */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); /* default, not needed */
    glutInitWindowSize(500, 500); /* 500 x 500 pixel window */
    glutCreateWindow("Sierpinski Gasket"); /* window title */ 
    glutDisplayFunc(display); /* display callback invoked when window opened */
    myinit(); /* set attributes */
    glutMainLoop(); /* enter event loop */
}
