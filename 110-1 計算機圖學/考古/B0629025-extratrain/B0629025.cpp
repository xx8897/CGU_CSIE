#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

const int n = 10000;
const int j = 140;
const int k = 360;
float pi = 3.1415926536f;

GLfloat R = 25;


void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,300.0,0.0,300.0);
}

void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
	
    glLineWidth(3);
    glColor3f(0.8,0.8,0.8);  //外圍的圓 
    glBegin(GL_LINE_STRIP);
        for(int i=0;i<n;i++)
        	glVertex2f(150+140*cos(2*pi/n*i),150+140*sin(2*pi/n*i));
    glEnd(); 
	glFlush();
	
	glColor3f(0.8,0.8,1.0);  //外圍的圓 
    glBegin(GL_POLYGON);
        for(int i=0;i<n;i++)
        	glVertex2f(150+140*cos(2*pi/n*i),150+140*sin(2*pi/n*i));
    glEnd(); 
	glFlush();
	
	glColor3f(0.8,0.8,0.6);  //外圍的圓 
    glBegin(GL_POLYGON);
        for(int i=0;i<n;i++)
        	glVertex2f(150+130*cos(2*pi/n*i),150+130*sin(2*pi/n*i));
    glEnd(); 
	glFlush();
	
    glBegin(GL_POLYGON); // yellow
	glColor3f(0.7,0.5,0.5); 
	for (int i = 0; i < n; i++)
		for(int j=80; j<230;j++)
		glVertex2f(j+40*cos(2 * pi / n*i), 125+40*sin(2* pi / n*i));
	glEnd();
	glFlush(); 
    
    glBegin(GL_POLYGON); // yellow
	glColor3ub(255, 227, 132); 
	for (int i = 0; i < n; i++)
		glVertex2f(150+15*cos(0.6+2 * pi / n*i), 120+20*sin(0.38+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(2.5);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < k; i++)
		glVertex2f(150+15*cos(0.6+2 * pi / k*i), 120+20*sin(0.38+2* pi / k*i));
	glEnd();
	glFlush(); 
	
	glBegin(GL_POLYGON); // yellow
	glColor3ub(255, 227, 132); 
	for (int i = 0; i < n; i++)
		glVertex2f(140+15*cos(0.38+2 * pi / n*i), 120+20*sin(0.6+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(2.5);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 50; i < k; i++)
		glVertex2f(140+15*cos(0.38+2 * pi / k*i), 120+20*sin(0.6+2* pi / k*i));
	glEnd();
	glFlush(); 
	
	glBegin(GL_POLYGON); // yellow
	glColor3ub(255, 227, 132); 
	for (int i = 0; i < n; i++)
		glVertex2f(145+10*cos(0.8+2 * pi / n*i), 103+5*sin(0.8+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(4);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 200; i < 330; i++)
		glVertex2f(145+10*cos(2*pi/330*i), 103+5*sin(2*pi/330*i));
	glEnd();
	glFlush(); 
	
	glColor3ub(255, 227, 132); // face square
	glBegin(GL_QUADS);
	glVertex2i(149,105);
	glVertex2i(149,132);
	glVertex2i(158,132);
	glVertex2i(158,105);
	glEnd ( );
	glFlush();
	
	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(0.0,0.0,0.0); 
		glVertex2i(133,128);
		glVertex2i(152,128);
	glEnd ( );
	glFlush();

	glBegin(GL_POLYGON); // mouth color
	glColor3ub(237, 145, 33); 
	for (int i = 0; i < n; i++)
		glVertex2f(141+3*cos(2 * pi / n*i), 128+1*sin(2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(3);
	glBegin(GL_LINE_LOOP); // mouth
	glColor3ub(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(141+4*cos(2 * pi / n*i), 128+2*sin(2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glBegin(GL_POLYGON); // mouth color(down)
	glColor3ub(237, 145, 33); 
	for (int i = 0; i < n; i++)
		glVertex2f(141+3*cos(2 * pi / n*i), 124+1*sin(2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(3);
	glBegin(GL_LINE_LOOP); // mouth
	glColor3ub(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(141+4*cos(2 * pi / n*i), 124+2*sin(2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(133,100);
	  glVertex2i(131,95);
	glEnd();
	glFlush(); 
	
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(154,100);
	  glVertex2i(156,95);
	glEnd();
	glFlush(); 
	
	//egg_one
	
	
	glBegin(GL_POLYGON); // yellow
	glColor3ub(255, 227, 132); 
	for (int i = 0; i < n; i++)
		glVertex2f(200+10*cos(0.38+2 * pi / n*i), 120+15*sin(0.1+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(2.5);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < k; i++)
		glVertex2f(200+10*cos(0.38+2 * pi / k*i), 120+15*sin(0.1+2* pi / k*i));
	glEnd();
	glFlush(); 
	
	glBegin(GL_POLYGON); // yellow
	glColor3ub(255, 227, 132); 
	for (int i = 0; i < n; i++)
		glVertex2f(190+10*cos(0.1+2 * pi / n*i), 120+15*sin(0.38+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(2.5);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 50; i < k; i++)
		glVertex2f(190+10*cos(0.1+2 * pi / k*i), 120+15*sin(0.38+2* pi / k*i));
	glEnd();
	glFlush(); 
	
	
	
	glBegin(GL_POLYGON); // yellow
	glColor3ub(255, 227, 132); 
	for (int i = 0; i < n; i++)
		glVertex2f(195+10*cos(0.8+2 * pi / n*i), 107+5*sin(0.8+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(4);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 200; i < 330; i++)
		glVertex2f(195+10*cos(2*pi/330*i), 107+5*sin(2*pi/330*i));
	glEnd();
	glFlush(); 
	
	glColor3ub(255, 227, 132); // face square
	glBegin(GL_QUADS);
	glVertex2i(195,105);
	glVertex2i(195,132);
	glVertex2i(202,132);
	glVertex2i(202,105);
	glEnd ( );
	glFlush();
	
	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(0.0,0.0,0.0); 
		glVertex2i(185,125);
		glVertex2i(203,125);
	glEnd ( );
	glFlush();

	glBegin(GL_POLYGON); // mouth color
	glColor3ub(237, 145, 33); 
	for (int i = 0; i < n; i++)
		glVertex2f(193+3*cos(2 * pi / n*i), 125+1.5*sin(2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(3);
	glBegin(GL_LINE_LOOP); // mouth
	glColor3ub(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(193+4*cos(2 * pi / n*i), 125+2*sin(2* pi / n*i));
	glEnd();
	glFlush(); 
	
	/*glBegin(GL_POLYGON); // mouth color(down)
	glColor3ub(237, 145, 33); 
	for (int i = 0; i < n; i++)
		glVertex2f(193+3*cos(2 * pi / n*i), 122+1.5*sin(2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(3);
	glBegin(GL_LINE_LOOP); // mouth
	glColor3ub(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(193+4*cos(2 * pi / n*i), 122+2*sin(2* pi / n*i));
	glEnd();
	glFlush();*/ 
	
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(186,106);
	  glVertex2i(183,100);
	glEnd();
	glFlush(); 
	
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(203,106);
	  glVertex2i(206,100);
	glEnd();
	glFlush();
	
	//egg_two
	
	glBegin(GL_POLYGON); // yellow
	glColor3ub(255, 227, 132); 
	for (int i = 0; i < n; i++)
		glVertex2f(235+5*cos(2 * pi / n*i), 120+10*sin(-0.4+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(2.5);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < k; i++)
		glVertex2f(235+5*cos(0.38+2 * pi / k*i), 120+10*sin(0.1+2* pi / k*i));
	glEnd();
	glFlush(); 
	
	 glBegin(GL_POLYGON); // yellow
	glColor3ub(255, 227, 132); 
	for (int i = 0; i < n; i++)
		glVertex2f(230+5*cos(0.1+2 * pi / n*i), 120+10*sin(0.38+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(2.5);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 60; i < k; i++)
		glVertex2f(230+5*cos(0.1+2 * pi / k*i), 120+10*sin(0.38+2* pi / k*i));
	glEnd();
	glFlush(); 
	
	
	
	glBegin(GL_POLYGON); // yellow
	glColor3ub(255, 227, 132); 
	for (int i = 0; i < n; i++)
		glVertex2f(232+6*cos(0.8+2 * pi / n*i), 112+3*sin(0.8+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(2.5);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 180; i < 330; i++)
		glVertex2f(232+6*cos(0.8+2 * pi /330*i), 112+3*sin(0.8+2* pi / 330*i));
	glEnd();
	glFlush(); 
	 
	glColor3ub(255, 227, 132); // face square
	glBegin(GL_QUADS);
	glVertex2i(232,112);
	glVertex2i(232,124);
	glVertex2i(238,124);
	glVertex2i(238,112);
	glEnd ( );
	glFlush();
	
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(0.0,0.0,0.0); 
		glVertex2i(228,123);
		glVertex2i(236,123);
	glEnd ( );
	glFlush();
	
	glBegin(GL_POLYGON); // mouth color
	glColor3ub(237, 145, 33); 
	for (int i = 0; i < n; i++)
		glVertex2f(231.5+1.8*cos(2 * pi / n*i), 123+1*sin(2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(2);
	glBegin(GL_LINE_LOOP); // mouth
	glColor3ub(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(231.5+1.8*cos(2 * pi / n*i), 123+1*sin(2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(4);
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(230,110);
	  glVertex2i(226,106);
	glEnd();
	glFlush(); 
	
	//glLineWidth(10);
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(235,110);
	  glVertex2i(238,106);
	glEnd();
	glFlush();
	
	//egg_three
	
	glLineWidth(3);
	glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(85,105);
	  glVertex2i(75,103);
    glEnd();
    glFlush();
    
    glLineWidth(3);
	glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(75,103);
	  glVertex2i(75,99);
    glEnd();
    glFlush();
    
    glLineWidth(3);
	glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(75,99);
	  glVertex2i(72,99);
    glEnd();
    glFlush();
    
    glLineWidth(3);
	glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(90,110);
	  glVertex2i(92,95);
    glEnd();
    glFlush();
    
    glLineWidth(3);
	glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(92,95);
	  glVertex2i(90,95);
    glEnd();
    glFlush();
    
    glBegin(GL_POLYGON); // body
	glColor3ub(160, 82, 45); 
	for (int i = 0; i < n; i++)
		glVertex2f(86+6*cos(0.9+2*pi/n*i),115+12*sin(0.9+2*pi/n*i));
	glEnd();
	glFlush(); 
    
	glLineWidth(3);
	glBegin(GL_LINE_STRIP); // body
	glColor3f(0.0,0.0,0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(86+6*cos(0.9+2*pi/n*i),115+12*sin(0.9+2*pi/n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(2);
	glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(90,107);
	  glVertex2i(86,105);
    glEnd();
    glFlush();
	
	glLineWidth(2);
	glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(88,106);
	  glVertex2i(100,100);
    glEnd();
    glFlush();
	
	glBegin(GL_POLYGON); // yellow
	glColor3ub(255, 227, 132); 
	for (int i = 0; i < n; i++)
		glVertex2f(90+15*cos(0.6+2 * pi / n*i), 140+17*sin(0.38+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(2.5);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < k; i++)
		glVertex2f(90+15*cos(0.6+2 * pi / k*i), 140+17*sin(0.38+2* pi / k*i));
	glEnd();
	glFlush(); 
	
	glBegin(GL_POLYGON); // yellow
	glColor3ub(255, 227, 132); 
	for (int i = 0; i < n; i++)
		glVertex2f(80+15*cos(0.38+2 * pi / n*i), 140+17*sin(0.6+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(2.5);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 50; i < k; i++)
		glVertex2f(80+15*cos(0.38+2 * pi / k*i), 140+17*sin(0.6+2* pi / k*i));
	glEnd();
	glFlush(); 
	
	glBegin(GL_POLYGON); // yellow
	glColor3ub(255, 227, 132); 
	for (int i = 0; i < n; i++)
		glVertex2f(85+10*cos(0.8+2 * pi / n*i), 126+5*sin(0.8+2* pi / n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(4);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 200; i < 330; i++)
		glVertex2f(85+10*cos(2*pi/330*i), 126+5*sin(2*pi/330*i));
	glEnd();
	glFlush(); 
	
	glColor3ub(255, 227, 132); // face square
	glBegin(GL_QUADS);
	glVertex2i(89,125);
	glVertex2i(89,150);
	glVertex2i(97,150);
	glVertex2i(97,130);
	glEnd ( );
	glFlush();
	
	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(0.0,0.0,0.0); 
		glVertex2i(73,147);
		glVertex2i(92,147);
	glEnd ( );
	glFlush();
	
	glBegin(GL_POLYGON); // mouth color
	glColor3ub(237, 145, 33); 
	for (int i = 0; i < n; i++)
		glVertex2f(82+3.5*cos(2* pi/n*i),147+2*sin(2* pi/ n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(3);
	glBegin(GL_LINE_LOOP); // mouth
	glColor3ub(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(82+4*cos(2*pi/n*i),147+2*sin(2*pi/n*i));
	glEnd();
	glFlush(); 
	
	glBegin(GL_POLYGON); // mouth color
	glColor3ub(237, 145, 33); 
	for (int i = 0; i < n; i++)
		glVertex2f(82+3.5*cos(2* pi/n*i),143.5+2*sin(2* pi/ n*i));
	glEnd();
	glFlush(); 
	
	glLineWidth(3);
	glBegin(GL_LINE_LOOP); // mouth
	glColor3ub(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(82+4*cos(2*pi/n*i),143.5+2*sin(2*pi/n*i));
	glEnd();
	glFlush();
	
	glPointSize(0.5);
	glBegin(GL_LINES);
	glColor3ub(250,128,114); 
		glVertex2i(70,145);
		glVertex2i(69,141);
	glEnd ( );
	glFlush();
	
	glPointSize(0.5);
	glBegin(GL_LINES);
	glColor3ub(250,128,114); 
		glVertex2i(73,145);
		glVertex2i(73,141);
	glEnd ( );
	glFlush();
	
	glPointSize(0.5);
	glBegin(GL_LINES);
	glColor3ub(250,128,114); 
		glVertex2i(91,145);
		glVertex2i(90,141);
	glEnd ( );
	glFlush();
	
	glPointSize(0.5);
	glBegin(GL_LINES);
	glColor3ub(250,128,114); 
		glVertex2i(94,145);
		glVertex2i(94,141);
	glEnd ( );
	glFlush();
	
	glPointSize(0.5);
	glBegin(GL_LINES);
	glColor3ub(250,128,114); 
		glVertex2i(97,145);
		glVertex2i(98,141);
	glEnd ( );
	glFlush();
	
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("extra");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
    return 0;
}
