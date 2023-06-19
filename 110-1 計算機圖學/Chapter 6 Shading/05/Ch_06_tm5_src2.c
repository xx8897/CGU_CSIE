#include <GL/glut.h>
#include <stdlib.h>


void init(void)
{
    //材質反光測試
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };  //鏡面反射參數 
    GLfloat mat_shininess[] = { 50.0 };               //高光指數 
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };   //
    GLfloat Light_Model_Ambient[] = { 0.2, 0.2, 0.2, 1.0 }; //環境光參數 

    glClearColor(0.0, 0.0, 0.0, 0.0);  //背景色
    glShadeModel(GL_FLAT);           //多變性填充模式

    //材質屬性
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    //燈光設置
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);   //散射光屬性
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);  //鏡面反射光
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Light_Model_Ambient);  //環境光參數 

    glEnable(GL_LIGHTING);   //開關:使用光
    glEnable(GL_LIGHT0);     //打開0號燈
    glEnable(GL_DEPTH_TEST); //打開深度
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.5);
    glFlush();   //glSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    //設置投影參數 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //正交投影
    if (w <= h)
        glOrtho(-1.5, 1.5, -1.5*(GLfloat)h / (GLfloat)w, 1.5*(GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-1.5*(GLfloat)w / (GLfloat)h, 1.5*(GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);

    //設置模型 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("茶壺");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
