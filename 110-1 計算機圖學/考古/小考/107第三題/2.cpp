#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <GL/glut.h>
#include <math.h>

const GLfloat Pi = 3.1415926536f;
const GLfloat N = 360;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 300.0, 0.0, 600.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	GLfloat color[6][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 1.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 1.0, 1.0}};
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		for(int i=0, j=0; i<=300, j<=600; i+=30, j+=30){
			glVertex2f(i, 600);
			glVertex2f(i, 0);
			glVertex2f(0, j);
			glVertex2f(300, j);
		}
	glEnd();
	glFlush();
	
	int n, c;
	int i = 15;
	srand(time(NULL));
	while(i<=285){
		int j = 585;
		while(j>=15){
			n = rand()%4+1;
			c = rand()%6;
			
			if(n == 1){
				glColor3f(color[c][0], color[c][1], color[c][2]);
				glBegin(GL_TRIANGLES);
					glVertex2f(i, j+10);
					glVertex2f(i-10, j-10);
					glVertex2f(i+10, j-10);
				glEnd();
				glFlush();
			} else if(n == 2){
				glColor3f(color[c][0], color[c][1], color[c][2]);
				glBegin(GL_QUADS);
					glVertex2f(i-10, j+10);
					glVertex2f(i-10, j-10);
					glVertex2f(i+10, j-10);
					glVertex2f(i+10, j+10);
				glEnd();
				glFlush();
			} else if(n == 3){
				glColor3f(color[c][0], color[c][1], color[c][2]);
				glBegin(GL_POLYGON);
					for(int k=0; k<N; k++) {
						glVertex2f(i+10*cos(2*Pi/N*k), j+10*sin(2*Pi/N*k));
					}
				glEnd();
				glFlush();
			} else{
				glColor3f(color[c][0], color[c][1], color[c][2]);
				glBegin(GL_POLYGON);
					glVertex2f(i-10, j+6);
					glVertex2f(i-3, j+10);
					glVertex2f(i+3, j+10);
					glVertex2f(i+10, j+6);
					glVertex2f(i, j-10);
				glEnd();
				glFlush();
			}
			j = j - 30;
		}
		i = i + 30;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(300, 600);
	glutCreateWindow("B0629002's OpenGL Program");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
