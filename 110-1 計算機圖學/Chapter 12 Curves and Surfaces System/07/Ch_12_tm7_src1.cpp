
/* Shaded teapot using Bezier surfaces */


#include <GL/glut.h>


typedef GLfloat point[3];// a point data type


point data[32][4][4];

/* 306 vertices */

#include "vertices.h"

/* 32 patches each defined by 16 vertices, arranged in a 4 x 4 array */
/* NOTE: numbering scheme for teapot has vertices labeled from 1 to 306 */
/* remnent of the days of FORTRAN */

#include "patches.h"

void display(void)
{
   int i, j, k;

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//表示要清除顏色緩衝以及深度緩衝
   glColor3f(1.0, 1.0, 1.0);


	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0); //沿Z軸正方向平移-10個單位
 	glRotatef(-35.26, 1.0, 0.0, 0.0);
	glRotatef(-45.0, 0.0, 1.0, 0.0);  

	/* gluLookAt(-1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); */

/* data aligned along z axis, rotate to align with y axis */

    glRotatef(-90.0, 1.0,0.0, 0.0); 
    for(k=0;k<32;k++) 
	{
       glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
           0, 1, 12, 4, &data[k][0][0][0]);//允許二維映射
           
        //生成2D網格坐標，以從控制點參數插值確定網格點所對應的點集所對應的坐標
       for (j = 0; j <= 8; j++) 
	   {
            glBegin(GL_LINE_STRIP);
            for (i = 0; i <= 30; i++)
               glEvalCoord2f((GLfloat)i/30.0, (GLfloat)j/8.0);//固定y坐標時x方向的網格坐標
            glEnd();
            glBegin(GL_LINE_STRIP);
            for (i = 0; i <= 30; i++)
               glEvalCoord2f((GLfloat)j/8.0, (GLfloat)i/30.0);//固定x坐標時y方向的網格坐標 
            glEnd();
        }
   }
   glFlush();
}
void
myReshape(int w, int h)//改變窗口大小時保持圖形比例
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);//將當前矩陣指定為投影矩陣
    glLoadIdentity();
    if (w <= h)
        glOrtho(-4.0, 4.0, -4.0 * (GLfloat) h / (GLfloat) w,
            4.0 * (GLfloat) h / (GLfloat) w, -20.0, 20.0);
    else
        glOrtho(-4.0 * (GLfloat) w / (GLfloat) h,
            4.0 * (GLfloat) w / (GLfloat) h, -4.0, 4.0, -20.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    display();
}

void myinit()
{
   glEnable(GL_MAP2_VERTEX_3);
   glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0); 
   glEnable(GL_DEPTH_TEST);

}

main(int argc, char *argv[])
{
int i,j, k, m, n;



    for(i=0;i<32;i++) for(j=0;j<4;j++) for(k=0;k<4;k++) for(n=0;n<3;n++)
    {

/* put teapot data into single array for subdivision */

        m=indices[i][j][k];
        for(n=0;n<3;n++) data[i][j][k][n]=vertices[m-1][n];
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("teapot");
    myinit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);

    glutMainLoop();

}

