#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.
	glMatrixMode (GL_PROJECTION);       // Set projection parameters.
	gluOrtho2D (-100.0, 100.0, -100.0, 100.0);
}

const GLfloat pi=3.1415926536f;
const int n=3600;
const float DEG2RAD = 3.14159/180;

void lineSegment (void){
	glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.
	//杯墊底 
	const GLfloat R=60; //圓形半徑 
	glBegin(GL_POLYGON);
		glColor3f(0.3,0.0,1.0);
		for (int i=1;i<=n;i++){
			glVertex2f(R*cos(2*pi/n*i),R*sin(2*pi/n*i));
		}
    glEnd();
    //白色臉 
    const GLfloat r=48;
    glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		for (int i=1;i<=n;i++){
			glVertex2f(r*cos(2*pi/n*i),-7+r*sin(2*pi/n*i));
		}
    glEnd();
    glBegin(GL_LINE_STRIP);
		glColor3f(0.0,0.0,0.0);
		for (int i=1;i<=n;i++){
			glVertex2f(r*cos(2*pi/n*i),-7+r*sin(2*pi/n*i));
		}
    glEnd();
    //嘴巴
	float x2radius=40;
	float y2radius=30;
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*x2radius,-5+sin(degInRad)*y2radius);
	}
	glEnd(); 
	////////////////////////////////白色 
	const GLfloat rw=25;
    glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		for (int i=1;i<=n;i++){
			glVertex2f(13+rw*cos(2*pi/n*i),12+rw*sin(2*pi/n*i));
		}
    glEnd();
        glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		for (int i=1;i<=n;i++){
			glVertex2f(-13+rw*cos(2*pi/n*i),12+rw*sin(2*pi/n*i));
		}
    glEnd();
    //左眼 
    float xradius=13;
	float yradius=15;
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-13+cos(degInRad)*xradius,35+sin(degInRad)*yradius);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-13+cos(degInRad)*xradius,35+sin(degInRad)*yradius);
	}
	glEnd();
	//右眼 
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(13+cos(degInRad)*xradius,35+sin(degInRad)*yradius);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(13+cos(degInRad)*xradius,35+sin(degInRad)*yradius);
	}
	glEnd();
	//左眼球
	float x1radius=4;
	float y1radius=5;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-6+cos(degInRad)*x1radius,33+sin(degInRad)*y1radius);
	}
	glEnd();
	//右眼球
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(6+cos(degInRad)*x1radius,33+sin(degInRad)*y1radius);
	}
	glEnd();
	//鼻子
	const GLfloat r1=8;
    glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		for (int i=1;i<=n;i++){
			glVertex2f(r1*cos(2*pi/n*i),17+r1*sin(2*pi/n*i));
		}
    glEnd();
    glBegin(GL_LINE_STRIP);
		glColor3f(0.0,0.0,0.0);
		for (int i=1;i<=n;i++){
			glVertex2f(r1*cos(2*pi/n*i),17+r1*sin(2*pi/n*i));
		}
    glEnd();
	//左鬍鬚
	glColor3f (0.0, 0.0, 0.0);
	glBegin (GL_LINES);
		glVertex2i (-20,8);
		glVertex2i (-52,18);
	glEnd ( );	
	glBegin (GL_LINES);
		glVertex2i (-20,0);
		glVertex2i (-55,0);
	glEnd ( );
	glBegin (GL_LINES);
		glVertex2i (-20,-8);
		glVertex2i (-52,-18);
	glEnd ( );
	//右鬍鬚 
    glColor3f (0.0, 0.0, 0.0);
	glBegin (GL_LINES);
		glVertex2i (20,8);
		glVertex2i (52,18);
	glEnd ( );	
	glBegin (GL_LINES);
		glVertex2i (20,0);
		glVertex2i (55,0);
	glEnd ( );
	glBegin (GL_LINES);
		glVertex2i (20,-8);
		glVertex2i (52,-18);
	glEnd ( );
    //人中
    glColor3f (0.0, 0.0, 0.0);
	glBegin (GL_LINES);
		glVertex2i (0,-35);
		glVertex2i (0,9);
	glEnd ( );
    glFlush();
}

int main (int argc, char** argv){
	glutInit (&argc, argv); // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
	glutInitWindowPosition (100,50);   // Set top-left display-window position.
	glutInitWindowSize (500, 500);// Set display-window width and height.
	glutCreateWindow ("B0729025_HW1_Extra"); // Create display window.
	init ( );
	glutDisplayFunc (lineSegment); // Send graphics to display window.
	glutMainLoop ( );  // Display everything and wait.
}
