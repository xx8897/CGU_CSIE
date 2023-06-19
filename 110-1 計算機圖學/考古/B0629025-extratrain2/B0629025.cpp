#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>


const int n = 100000;
const GLfloat R = 10;
float pi = 3.1415926536f;
GLfloat vertices[1][2] = {{100,100}};
//GLfloat R = 0.1f;
//const GLfloat Pi = 3.1415926536f;

void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
    
}

//glColor3ub(255, 227, 132); 
#define face   1 

GLfloat points[360][2];
GLint i;
void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
 	glScalef(0.4, 0.4, 1);
 	
 	glNewList(face, GL_COMPILE);
	glBegin(GL_POLYGON); // FACE
	glColor3f(1.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(50+20*cos(2*pi/n*i),60+30*sin(2*pi/n*i));
	glEnd();
	glFlush();
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2i(29,60);
	glVertex2i(32,73);
	glVertex2i(32,47);
	glEnd ( );
	glFlush();
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2i(71,60);
	glVertex2i(68,73);
	glVertex2i(68,47);
	glEnd ( );
	glFlush(); 
	
	glBegin(GL_POLYGON); // ¥k²´white
	glColor3f(1.0, 1.0, 1.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(57.5+12*cos(3.84+1*pi/n*i),65+12*sin(3.8+1*pi/n*i));
	glEnd();
	glFlush();
	
		glBegin(GL_POLYGON); // ¥ª²´white 
	glColor3f(1.0, 1.0, 1.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(42.5+12*cos(2.4+1* pi/n*i),65+12*sin(2.5+1*pi/n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // ¥k²´ black
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(58+10*cos(3.8+1*pi/n*i),64+10*sin(3.8+1*pi/n*i));
	glEnd();

	glBegin(GL_POLYGON); // ¥k²´ 
	glColor3f(1.0, 1.0, 1.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(59+7*cos(3.8+1*pi/n*i),62+7*sin(3.8+1*pi/n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // ¥ª²´ black
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(42+10*cos(2.4+1*pi/n*i),64+10*sin(2.5+1*pi/n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // ¥ª²´ 
	glColor3f(1.0, 1.0, 1.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(41+7*cos(2.4+1*pi/n*i),62+7*sin(2.5+1*pi/n*i));
	glEnd();
	glFlush();
	
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2i(50,58);
	glVertex2i(47,61);
	glVertex2i(53,61);
	glEnd ( );
	glFlush(); 
	
	glLineWidth(5);
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(50,58);
	  glVertex2i(65,80);
    glEnd();
    glFlush();
    
   glLineWidth(5);
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(50,58);
	  glVertex2i(35,80);
    glEnd();
    glFlush();
    
    glLineWidth(5);
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(50,58);
	  glVertex2i(50,90);
    glEnd();
    glFlush();
    
    glLineWidth(5);
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(50,78);
	  glVertex2i(58,70);
    glEnd();
    glFlush();
    
    glLineWidth(5);;
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(50,78);
	  glVertex2i(42,70);
    glEnd();
    glFlush();

    glLineWidth(5);
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(50,85);
	  glVertex2i(38,75);
    glEnd();
    glFlush();
    
   	glLineWidth(5);
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(50,85);
	  glVertex2i(62,75);
    glEnd();
    glFlush();

	//Áy¤U¥b³¡ (left)
    glLineWidth(5);
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(50,58);
	  glVertex2i(47,48);
	  glVertex2i(47,48);
	  glVertex2i(40,43);
	  glVertex2i(36,38);
    glEnd();
    glFlush();
    //Áy¤U¥b³¡ (right) 
    glLineWidth(5);
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(50,58);
	  glVertex2i(53,48);
	  glVertex2i(53,48);
	  glVertex2i(60,43);
	  glVertex2i(64,38);
    glEnd();
    glFlush();   
    //Áyy(left) 
    glLineWidth(5);
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(40,43);
	  glVertex2i(50,38);
    glEnd();
    glFlush(); 
    //Áyy(right)
	glLineWidth(5);
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(60,43);
	  glVertex2i(50,38);
    glEnd();
    glFlush();  
	//Áyy(down) 
    glLineWidth(5);
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(50,38);
	  glVertex2i(50,30);
    glEnd();
    glFlush(); 
    //ÁyÀU(left) 
	glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
	  glVertex2i(29,58);
	  glVertex2i(31,50);
	  glVertex2i(33,44);
	  glVertex2i(34,41);
	  glVertex2i(37,48);
	  glVertex2i(35,52);
	  glVertex2i(32,53);
	  glVertex2i(29,58);
    glEnd();
    glFlush(); 
    
    //ÁyÀU(left) 
    glLineWidth(4);
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(29,58);
	  glVertex2i(31,50);
	  glVertex2i(33,44);
	  glVertex2i(34,41);
	  glVertex2i(37,48);
	  glVertex2i(35,52);
	  glVertex2i(33,53);
	  glVertex2i(30,58);
    glEnd();
    glFlush(); 
    
    //ÁyÀU(right) 
	glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
	  glVertex2i(70,56);
	  glVertex2i(69,50);
	  glVertex2i(67,44);
	  glVertex2i(66,41);
	  glVertex2i(64,46);
	  glVertex2i(65,50);
	  glVertex2i(66,51);
	  glVertex2i(70,56);
    glEnd();
    glFlush(); 
    
    //ÁyÀU(right) 
    glLineWidth(4);
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(70,56);
	  glVertex2i(69,50);
	  glVertex2i(67,44);
	  glVertex2i(66,41);
	  glVertex2i(64,46);
	  glVertex2i(65,50);
	  glVertex2i(66,51);
	  glVertex2i(70,56);
    glEnd();
    glFlush(); 
    
    
    glEndList();
    
    glCallList(face);
    
    //glTranslatef(0.0,100.0,0.0);
    //glCallList(face);
 
    glTranslatef(80.0,0.0,0.0);
    glCallList(face);
    
	glTranslatef(80.0,0.0,0.0);
    glCallList(face);
    
    glTranslatef(0.0,100.0,0.0);
    glCallList(face);
    
    glTranslatef(-80.0,0.0,0.0);
    glCallList(face);
    
    glTranslatef(-80.0,0.0,0.0);
    glCallList(face);
    
    //glRotatef(-80.0,10.0,1.0,0.0);
    //glCallList(face);
    
    glFlush();
}
    
    
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("My Program");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
    return 0;
}
