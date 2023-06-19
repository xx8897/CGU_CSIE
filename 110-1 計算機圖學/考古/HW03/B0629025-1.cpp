#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>
#include<math.h>

void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,500.0,0.0,500.0);
}
const int n =500;
float Pi = 3.1415926536f;
void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLineWidth(3.5f);
   
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i (50,450);
        glVertex2i (450,450);
        glVertex2i (450,50);
        glVertex2i (50,50);
    glEnd();
    
    for(int i=0;i<20;i++) //20¶ê 
    {
        int rand();
        int color=rand()%6;
        switch(color)
        {
            case 0:
                glColor3f(1.0,0.0,0.0);
                break;
            case 1:
                glColor3f(0.0,1.0,0.0);
                break;
            case 2:
                glColor3f(0.0,0.0,1.0);
                break;
            case 3:
                glColor3f(1.0,1.0,0.0);
                break;
            case 4:
                glColor3f(1.0,0.0,1.0);
                break;
            case 5:
                glColor3f(0.0,1.0,1.0);
                break;
        }
        
        glBegin(GL_POLYGON);
        int X = rand() % 400+50;
        int Y = rand() % 400+50;
        int R = rand() % 100+1;
        if((X-R)>50&&(X+R)<450&&(Y-R)>50&&(Y+R)<450)
        {
            for (int j=0;j<n;++j)
            {
                glVertex2f(X+R*cos(2*Pi/n*j),Y+R*sin(2*Pi/n*j)); //CIRCLE
            }
        }
        else
        {
            i--; 
        }
        glEnd();
        glFlush();

    }
}

int main(int argc,char** argv)
{
    srand( time(NULL) );
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("HW03-1");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
    return 0;
}
