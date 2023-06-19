#include <GL/glut.h>
GLfloat color[5][3]={{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,1.0,0.0},{1,0.0,1},{0.0,1,1}}; //  ��,��,��,��,������,�C�� 

void init (void)

{

    glClearColor (1.0, 1.0, 1.0, 0.0);

    glMatrixMode (GL_PROJECTION);

    gluOrtho2D (0.0,5.0,-5.0, 0.0); 

    glMatrixMode (GL_MODELVIEW);

}

double drawSquare(double i) 

{

   glBegin (GL_POLYGON); 

   glVertex2f (-i,-i);//���U 

   glVertex2f (i,-i);//�k�U

   glVertex2f (i, i);//�k�W

   glVertex2f (-i,i);//���W

   glEnd ( );

}

void myDraw1 (void)

{
    
   const float e=0.7071f;//�ڸ�2 
         float e1=0.7071f;
   glClear (GL_COLOR_BUFFER_BIT); //�M��

   glLoadIdentity(); 

   glColor3f (1.0, 0.0, 0.0);
   drawSquare(5); 

   for(int i=0;i<5;i++)
   {
           glRotatef(45,0.0,0.0,1.0);//����45�� 
           glColor3fv(color[i]);//�C��]�w 
           drawSquare(5*e1);//���=2�� 
           e1=e1*e;//�@�����ڸ�2 (�]�����)
    }
/*
glRotatef(45,0.0,0.0,1.0);
glColor3f (0.0, 0.0, 1.0);
drawSquare(5*0.7*0.7); 

glRotatef(45,0.0,0.0,1.0);
glColor3f (1.0, 1.0, 0.0);
drawSquare(5*0.7*0.7*0.7); 

glRotatef(45,0.0,0.0,1.0);
glColor3f (1.0, 0.0, 1.0);
drawSquare(5*0.7*0.7*0.7*0.7); 


glRotatef(45,0.0,0.0,1.0);
glColor3f (0.0, 1.0, 1.0);
drawSquare(5*0.7*0.7*0.7*0.7*0.7);*/
glFlush ( );

}

int main (int argc, char** argv)

{

glutInit (&argc, argv);

glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

glutInitWindowPosition (0, 0);

glutInitWindowSize (600, 600);

glutCreateWindow ("Rotate");

init();

glutDisplayFunc (myDraw1);

glutMainLoop ( );

}
