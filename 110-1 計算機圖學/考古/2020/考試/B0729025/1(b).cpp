#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

void init (void){
	glClearColor (0.8, 0.8, 0.0, 0.0);  // Set display-window color to white.
	glMatrixMode (GL_PROJECTION);       // Set projection parameters.
	gluOrtho2D (-100.0, 100.0, -100.0, 100.0);
}

const GLfloat pi=3.1415926536f;
const int n=3600;
const float DEG2RAD = 3.14159/180;

void lineSegment (void){
	glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.
    //®≠≈È 
    float xradius=80;
	float yradius=70;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*xradius,-20+sin(degInRad)*yradius);
	}
	glEnd();
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*xradius,-20+sin(degInRad)*yradius);
	}
	glEnd();
	//•™¶’ 
	float x1radius=14;
	float y1radius=16;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-43+cos(degInRad)*x1radius,50+sin(degInRad)*y1radius);
	}
	glEnd();
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-43+cos(degInRad)*x1radius,50+sin(degInRad)*y1radius);
	}
	glEnd();
	float x3radius=10;
	float y3radius=10;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-40+cos(degInRad)*x3radius,42+sin(degInRad)*y3radius);
	}
	glEnd();
	
	float x17radius=8;
	float y17radius=8;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-43+cos(degInRad)*x17radius,50+sin(degInRad)*y17radius);
	}
	glEnd();
	//•k¶’ 
	float x2radius=14;
	float y2radius=16;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(20+cos(degInRad)*x2radius,55+sin(degInRad)*y2radius);
	}
	glEnd();
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(20+cos(degInRad)*x2radius,55+sin(degInRad)*y2radius);
	}
	glEnd();
	float x4radius=12;
	float y4radius=12;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(18+cos(degInRad)*x4radius,42+sin(degInRad)*y4radius);
	}
	glEnd();
	
	glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(21+cos(degInRad)*x17radius,56+sin(degInRad)*y17radius);
	}
	glEnd();
	//ºL§⁄
	float x5radius=40;
	float y5radius=22;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*x5radius,-43+sin(degInRad)*y5radius);
	}
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.0);
		glVertex2f(-50,-45);
		glVertex2f(50,-45);
		glVertex2f(50,-20);
		glVertex2f(-50,-20);
	glEnd();
	//§˙æ¶•™ 
	float x11radius=8;
	float y11radius=10;
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-20+cos(degInRad)*x11radius,-55+sin(degInRad)*y11radius);
	}
	glEnd();
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.3,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-20+cos(degInRad)*x11radius,-55+sin(degInRad)*y11radius);
	}
	glEnd();
	//§˙æ¶§§ 
	float x12radius=12;
	float y12radius=10;
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-2+cos(degInRad)*x11radius,-58+sin(degInRad)*y12radius);
	}
	glEnd();
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.3,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-2+cos(degInRad)*x11radius,-58+sin(degInRad)*y12radius);
	}
	glEnd();
	//§˙æ¶•k 
	float x13radius=8;
	float y13radius=10;
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(16+cos(degInRad)*x13radius,-56+sin(degInRad)*y13radius);
	}
	glEnd();
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.3,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(16+cos(degInRad)*x13radius,-56+sin(degInRad)*y13radius);
	}
	glEnd();
	//•™≤¥
	float x9radius=19;
	float y9radius=20;
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-45+cos(degInRad)*x9radius,-15+sin(degInRad)*y9radius);
	}
	glEnd();
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.3,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-45+cos(degInRad)*x9radius,-15+sin(degInRad)*y9radius);
	}
	glEnd();
	//•™≤¥≤y
	float x10radius=5;
	float y10radius=5;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-37+cos(degInRad)*x10radius,-16+sin(degInRad)*y10radius);
	}
	glEnd();
	//•k≤¥
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(55+cos(degInRad)*x9radius,-16+sin(degInRad)*y9radius);
	}
	glEnd();
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.3,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(55+cos(degInRad)*x9radius,-16+sin(degInRad)*y9radius);
	}
	glEnd();
	//•k≤¥≤y
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(48+cos(degInRad)*x10radius,-16+sin(degInRad)*y10radius);
	}
	glEnd();	
	//ªÛ§l
	float x6radius=35;
	float y6radius=27;
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.7,0.3);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*x6radius,-30+sin(degInRad)*y6radius);
	}
	glEnd();
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.5,0.0);
	for (int i=0; i < 360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*x6radius,-30+sin(degInRad)*y6radius);
	}
	glEnd();
	//•™ªÛ§’
	float x7radius=7;
	float y7radius=10;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-12+cos(degInRad)*x7radius,-30+sin(degInRad)*y7radius);
	}
	glEnd();
	//•kªÛ§’ 
	float x8radius=7;
	float y8radius=8;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(12+cos(degInRad)*x8radius,-30+sin(degInRad)*y8radius);
	}
	glEnd();
	//•™¨‹§Ú
	float x15radius=10;
	float y15radius=5;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.4,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-52+cos(degInRad)*x15radius,20+sin(degInRad)*y15radius);
	}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-52+cos(degInRad)*x15radius,16+sin(degInRad)*y15radius);
	}
	glEnd();
	//•k¨‹§Ú 
	float x16radius=10;
	float y16radius=5;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.4,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(52+cos(degInRad)*x15radius,20+sin(degInRad)*y15radius);
	}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(52+cos(degInRad)*x15radius,16+sin(degInRad)*y15radius);
	}
	glEnd();
	//•™≥∂¥≥ 
	float x14radius=3;
	float y14radius=2;
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-52+cos(degInRad)*x14radius,-38+sin(degInRad)*y14radius);
	}
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-48+cos(degInRad)*x14radius,-45+sin(degInRad)*y14radius);
	}
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(-41+cos(degInRad)*x14radius,-39+sin(degInRad)*y14radius);
	}
	glEnd();
	//•k≥∂¥≥ 
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(56+cos(degInRad)*x14radius,-47+sin(degInRad)*y14radius);
	}
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(48+cos(degInRad)*x14radius,-40+sin(degInRad)*y14radius);
	}
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,0.0);
	for (int i=0; i<360; i++){
		//convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(45+cos(degInRad)*x14radius,-47+sin(degInRad)*y14radius);
	}
	glEnd();
    glFlush();
}

int main (int argc, char** argv){
	glutInit (&argc, argv); // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
	glutInitWindowPosition (100,50);   // Set top-left display-window position.
	glutInitWindowSize (500, 500);// Set display-window width and height.
	glutCreateWindow ("1(b)"); // Create display window.
	init ( );
	glutDisplayFunc (lineSegment); // Send graphics to display window.
	glutMainLoop ( );  // Display everything and wait.
}
