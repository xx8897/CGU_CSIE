#include <GL/glut.h>
#include <stdlib.h>


void init(void)
{
    //����ϥ�����
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };  //�譱�Ϯg�Ѽ� 
    GLfloat mat_shininess[] = { 50.0 };               //�������� 
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };   //
    GLfloat Light_Model_Ambient[] = { 0.2, 0.2, 0.2, 1.0 }; //���ҥ��Ѽ� 

    glClearColor(0.0, 0.0, 0.0, 0.0);  //�I����
    glShadeModel(GL_FLAT);           //�h�ܩʶ�R�Ҧ�

    //�����ݩ�
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    //�O���]�m
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);   //���g���ݩ�
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);  //�譱�Ϯg��
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Light_Model_Ambient);  //���ҥ��Ѽ� 

    glEnable(GL_LIGHTING);   //�}��:�ϥΥ�
    glEnable(GL_LIGHT0);     //���}0���O
    glEnable(GL_DEPTH_TEST); //���}�`��
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

    //�]�m��v�Ѽ� 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //�����v
    if (w <= h)
        glOrtho(-1.5, 1.5, -1.5*(GLfloat)h / (GLfloat)w, 1.5*(GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-1.5*(GLfloat)w / (GLfloat)h, 1.5*(GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);

    //�]�m�ҫ� 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("����");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
