#define GLUT_DISABLE_ATEXIT_HACK
#include<windows.h>
#include<stdlib.h>
#include<gl/gl.h> 
#include<gl/glut.h>
#include<math.h>
#include<time.h>
#define PI 3.1415926535898
GLfloat color[6][3]={{1.0, 0.0, 0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,0.0},{1.0,0.0,1.0},{0.0,1.0,1.0}};

void init(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D (0.0, 800.0, 0.0, 800.0);
}
	
void display(void)
{
	srand(time(NULL));
	glClear (GL_COLOR_BUFFER_BIT);
	int n=360,r,i,j;
	
	glLineWidth(3.5f);
   
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i (200,200);
        glVertex2i (600,200);
        glVertex2i (600,600);
        glVertex2i (200,600);
    glEnd();
		
		
	for(int j=0;j<20;j++){
	
		int x = rand()%400+200;
		int y = rand()%400+200;
		int r = rand()%50+15;
		int a = rand()%6;
		
		int b = x-200;
		int c = 600-x;
		int d = y-200;
		int e = 600-y;
		glColor3fv(color[a]);
		
		if(b>r&&c>r&&d>r&&e>r){
			glBegin(GL_POLYGON);
			for(int i=0; i<500; ++i)
				glVertex2f(x + r*cos(2*PI/500*i),y + r*sin(2*PI/500*i));
			glEnd();
		}else{
			j--;
		}
	}
	glFlush();	

}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(100,100);
	glutCreateWindow("B0629049's -1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}


