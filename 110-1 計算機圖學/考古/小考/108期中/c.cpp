#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>


const int n = 100000;
const GLfloat R = 10;
float pi = 3.1415926536f;
//GLfloat R = 0.1f;
//const GLfloat Pi = 3.1415926536f;

void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
    
}

void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
 
	glBegin(GL_POLYGON); // RIGHT EAR
	glColor3f(1.0, 1.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(66+2*cos(0.38+2 * pi / n*i), 70+5*sin(0.38+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(5);
	glBegin(GL_LINE_LOOP); // EAR
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(66+2*cos(0.38+2 * pi / n*i), 70+5*sin(0.38+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glBegin(GL_POLYGON); // LEFT EAR
	glColor3f(1.0, 1.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(34+2*cos(0.38+2 * pi / n*i), 70+5*sin(0.38+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(5);
	glBegin(GL_LINE_LOOP); // EAR
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(34+2*cos(0.38+2 * pi / n*i), 70+5*sin(0.38+2* pi / n*i));
	glEnd();
	glFlush(); 
 
	glLineWidth(15);
    glColor3f(0.0,0.0,0.0);  
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<10000;i++)
        	glVertex2f(50+15*cos(2*pi/100*i),70+15*sin(2*pi/100*i));
    glEnd(); 
	glFlush();
	
	glLineWidth(15);
    glColor3f(1.0,0.0,0.0);  
    glBegin(GL_POLYGON);
        for(int i=0;i<10000;i++)
        	glVertex2f(50+15*cos(2*pi/100*i),70+15*sin(2*pi/100*i));
    glEnd(); 
	glFlush();
	
	glBegin(GL_POLYGON); // HAND 
	glColor3f(1.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(45.5+5*cos(2+2 * pi / n*i), 50+6*sin(2+2* pi / n*i));
	glEnd();
	glFlush();
	
	glLineWidth(5);
	glBegin(GL_LINE_LOOP); // HAND 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(45.5+5*cos(2+2 * pi / n*i), 50+6*sin(2+2* pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // HAND 
	glColor3f(1.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(54.5+5*cos(2+2 * pi / n*i), 50+6*sin(2+2* pi / n*i));
	glEnd();
	glFlush();
	
	glLineWidth(5);
	glBegin(GL_LINE_LOOP); // HAND 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(54.5+5*cos(2+2 * pi / n*i), 50+6*sin(2+2* pi / n*i));
	glEnd();
	glFlush();
	
	glLineWidth(5);
	glBegin(GL_POLYGON); // FOOT 
	glColor3f(1.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(47.5+4*cos(3.1+2 * pi / n*i), 45+6*sin(3.1+2* pi / n*i));
	glEnd();
	glFlush();

	glLineWidth(5);
	glBegin(GL_POLYGON); // FOOT 
	glColor3f(1.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(52.5+4*cos(3.1+2 * pi / n*i), 45+6*sin(3.1+2* pi / n*i));
	glEnd();
	glFlush();
	
	glLineWidth(5);
	glBegin(GL_LINE_LOOP); // FOOT 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(47.5+4*cos(3.1+2 * pi / n*i), 45+6*sin(3.1+2* pi / n*i));
	glEnd();
	glFlush();

	glLineWidth(5);
	glBegin(GL_LINE_LOOP); // FOOT 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(52.5+4*cos(3.1+2 * pi / n*i), 45+6*sin(3.1+2* pi / n*i));
	glEnd();
	glFlush();
			
	glBegin(GL_POLYGON); // BODY
	glColor3f(1.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(50+8*cos(3.1+2 * pi / n*i), 50+10*sin(3.1+2* pi / n*i));
	glEnd();
	glFlush();
	
	glLineWidth(5);
	glBegin(GL_LINE_LOOP); // BODY
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(50+8*cos(3.1+1* pi / n*i), 50+10*sin(3.1+1* pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // BODY
	glColor3f(1.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(50+8*cos(3.1+2 * pi / n*i), 50+10*sin(3.1+2* pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // ¥ª²´ 
	glColor3f(1.0, 1.0, 1.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(42.5+5*cos(2.78+1 * pi / n*i), 70+5*sin(2.78+1* pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // ¥k²´ 
	glColor3f(1.0, 1.0, 1.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(57.5+5*cos(3.5+1 * pi / n*i), 70+5*sin(3.5+1* pi / n*i));
	glEnd();
	glFlush();
	
	glLineWidth(5);
	glBegin(GL_LINE_LOOP); // ¥ª²´ 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(42.5+5*cos(2.78+1 * pi / n*i), 70+5*sin(2.78+1* pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_LINE_LOOP); // ¥k²´ 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(57.5+5*cos(3.5+1 * pi / n*i), 70+5*sin(3.5+1* pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // ¼L¤Ú 
	glColor3f(1.0, 0.6, 0.6); 
	for (int i = 0; i < n; i++)
		glVertex2f(50+13*cos(3.1+1 * pi / n*i), 62.5+8*sin(3.1+1* pi / n*i));
	glEnd();
	glFlush();
	
	glLineWidth(5);
	glBegin(GL_LINE_LOOP); // ¼L¤Ú 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(50+13*cos(3.1+1 * pi / n*i), 62.5+8*sin(3.1+1* pi / n*i));
	glEnd();
	glFlush();
	
	glLineWidth(5);
	glBegin(GL_POLYGON); // ¼L¤Ú 
	glColor3f(1.0, 1.0, 1.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(50+3*cos(2 * pi / n*i), 47.5+3*sin(2* pi / n*i));
	glEnd();
	glFlush();
	
	glLineWidth(3);
	glBegin(GL_LINE_LOOP); // ¼L¤Ú 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(50+3*cos(2 * pi / n*i), 47.5+3*sin(2* pi / n*i));
	glEnd();
	glFlush();
	
	glLineWidth(3);
	glColor3f(1.0, 1.0, 0.0);//PANT
	glBegin(GL_TRIANGLES);
	glVertex2i(50,40);
	glVertex2i(44,42.5);
	glVertex2i(56,42.5);
	glEnd ( );
	glFlush();
	
	glLineWidth(3);
	glColor3f(0.0, 0.0, 0.0);//PANT
	glBegin(GL_LINE_LOOP);
	glVertex2i(50,40);
	glVertex2i(44,42.5);
	glVertex2i(56,42.5);
	glEnd ( );
	glFlush();
	
	/*glLineWidth(3);
	glColor3f(1.0, 1.0, 0.0);//PANT
	glBegin(GL_QUADS);
	glVertex2i(50,50);
	glVertex2i(44,47.5);
	glVertex2i(56,42.5);
	glVertex2i(50,50);
	glEnd ( );
	glFlush();*/
	
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("My Program");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
    return 0;
}
