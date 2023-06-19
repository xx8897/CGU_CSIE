
/* Rotating cube with viewer movement from Chapter 5 */
/* Cube definition and display similar to rotating--cube program */

/* We use the Lookat function in the display callback to point
the viewer, whose position can be altered by the x,X,y,Y,z, and Z keys.
The perspective view is set in the reshape callback */

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <GL/glut.h>
#include <math.h>
#include <cmath>


	GLfloat vertices[][3] = {{0.0,0.0,0.0},{2.0,0.0,0.0},
	{2.0,2.0,0.0}, {0.0,2.0,0.0}, {0.0,0.0,2.0}, 
	{2.0,0.0,2.0}, {2.0,2.0,2.0}, {0.0,2.0,2.0}};

	GLfloat normals[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
	{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0}, 
	{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};

	GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},
	{1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0}, 
	{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};
	
	GLfloat GroundVertics[][3]{{-1,0,3},{-1,0,-1},{3,0,-1},{3,0,3}};

void polygon(int a, int b, int c , int d)
{
	glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
		glNormal3fv(normals[a]);
		glVertex3fv(vertices[a]);
		glColor3fv(colors[b]);
		glNormal3fv(normals[b]);
		glVertex3fv(vertices[b]);
		glColor3fv(colors[c]);
		glNormal3fv(normals[c]);
		glVertex3fv(vertices[c]);
		glColor3fv(colors[d]);
		glNormal3fv(normals[d]);
		glVertex3fv(vertices[d]);
	glEnd();
	}

// draw the ground
void ground(int a, int b, int c , int d)
{
	glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
		glNormal3fv(normals[a]);
		glVertex3fv(GroundVertics[a]);
		glColor3fv(colors[b]);
		glNormal3fv(normals[b]);
		glVertex3fv(GroundVertics[b]);
		glColor3fv(colors[c]);
		glNormal3fv(normals[c]);
		glVertex3fv(GroundVertics[c]);
		glColor3fv(colors[d]);
		glNormal3fv(normals[d]);
		glVertex3fv(GroundVertics[d]);
	glEnd();
}

void colorcube()
{
	polygon(0,3,2,1);
	polygon(2,3,7,6);
	polygon(0,4,7,3);
	polygon(1,2,6,5);
	polygon(4,5,6,7);
	polygon(0,1,5,4);
	ground(0,1,2,3);
}

class Camera {
public:  
    double theta;      //position of x and z
    double y;          //y
    double dTheta;     //angle change
    double dy;         //y change
public:
    //init
    Camera() : theta(0), y(3), dTheta(0.04), dy(0.2) {}
   
    double getX() { return 1+5 * cos(theta); }
    double getY() { return y; }
    double getZ() { return 1+5 * sin(theta); }
    void moveRight() { theta += dTheta; }
    void moveLeft() { theta -= dTheta; }
    void moveUp() { y += dy; }
    void moveDown() { y -= dy; }
};

Camera camera;



void display(void)
{

 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

/* Update viewer position in modelview matrix */

	glLoadIdentity();
	gluLookAt(camera.getX(), camera.getY(), camera.getZ(), 1.0, 1.0, 1.0, 0.0, 1.0, 0.0);
   
    colorcube();
    
 glFlush();
	glutSwapBuffers();
}


void onKey(int key, int , int )
{

/* Use x, X, y, Y, z, and Z keys to move viewer */

   switch (key) {
    case GLUT_KEY_LEFT: camera.moveLeft(); break;
    case GLUT_KEY_RIGHT: camera.moveRight(); break;
    case GLUT_KEY_UP: camera.moveUp(); break;
    case GLUT_KEY_DOWN: camera.moveDown(); break;
    }
   display();
}

void myReshape(int w, int h)
{
 glViewport(0, 0, w, h);

/* Use a perspective view */

 glMatrixMode(GL_PROJECTION); 
 glLoadIdentity();
	if(w<=h) glFrustum(-2.0, 2.0, -2.0 * (GLfloat) h/ (GLfloat) w, 
       2.0* (GLfloat) h / (GLfloat) w, 2.0, 20.0);
	else glFrustum(-2.0, 2.0, -2.0 * (GLfloat) w/ (GLfloat) h, 
       2.0* (GLfloat) w / (GLfloat) h, 2.0, 20.0);

/* Or we can use gluPerspective */

 /* gluPerspective(45.0, w/h, -10.0, 10.0); */

 glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize(500, 500);
 glutCreateWindow("colorcube");
 glutReshapeFunc(myReshape);
 glutDisplayFunc(display);
 glutSpecialFunc(onKey);

	glEnable(GL_DEPTH_TEST);

 glutMainLoop();
}
