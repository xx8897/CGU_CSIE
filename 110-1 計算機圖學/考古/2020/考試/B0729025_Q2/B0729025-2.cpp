#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>

using namespace std;

void init (void){
	glClearColor (0.7, 0.5, 0.5, 0.0);  // Set display-window color to white.
	glMatrixMode (GL_PROJECTION);       // Set projection parameters.
	gluOrtho2D (0.0,600.0,0.0,600.0);
}

const int n = 3600;
const GLfloat pi = 3.1415926536f;
const GLfloat R = 8; //圓形半徑 


void lineSegment (void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f (0.0, 0.0, 0.0);
	glBegin (GL_LINES);////////////GL_LINES
	for(int i=0;i<19;i++){
		glVertex2i (30,30+30*i);
		glVertex2i (570,30+30*i);
	}
	glEnd();
	glBegin (GL_LINES);////////////GL_LINES
	for(int i=0;i<19;i++){
		glVertex2i (30+30*i,30);
		glVertex2i (30+30*i,570);
	}
	glEnd();
	//圍棋 
	srand(time(0));
	int arr[19][19]={{0},{0}};//row column
	for(int num=0;num<150;num++){
		int x=rand()%19+1;
		int y=rand()%19+1;
		int h=rand()%19+1;
		int w=rand()%19+1;
		//黑色 
		if(arr[x][y]==0)
		    arr[x][y]=1;
		else{
			num--;
			continue;
		}
		if(arr[h][w]==0)
		    arr[h][w]=1;
		else{
			num--;
			arr[x][y]=0;
			continue;
		}  
	    //黑色 
		glBegin(GL_POLYGON);
			glColor3f(0.0,0.0,0.0); 
			for (int i=1;i<=n;i++){
				glVertex2f(30*x+R*cos(2*pi/n*i),30*y+R*sin(2*pi/n*i));
			}
		glEnd();
		//白色 
		glBegin(GL_POLYGON);
			glColor3f(1.0,1.0,1.0); 
			for (int i=1;i<=n;i++){
				glVertex2f(30*h+R*cos(2*pi/n*i),30*w+R*sin(2*pi/n*i));
			}
		glEnd();
	}
	
    glFlush();
}
   

int main (int argc, char** argv){
	glutInit (&argc, argv); // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
	glutInitWindowPosition (100,50);   // Set top-left display-window position.
	glutInitWindowSize (600, 600);// Set display-window width and height.
	glutCreateWindow ("B0729025_2"); // Create display window.
	init ( );
	glutDisplayFunc (lineSegment); // Send graphics to display window.
	glutMainLoop ( );  // Display everything and wait.
}
