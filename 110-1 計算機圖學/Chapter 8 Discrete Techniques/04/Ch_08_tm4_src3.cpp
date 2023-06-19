#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <GL/glut.h>

GLfloat planes[]= {-1.0, 0.0, 1.0, 0.0};
GLfloat planet[]= {0.0, -1.0,  0.0, 1.0};
GLfloat vertices[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
    {1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
    {1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};
GLfloat colors[][4] = {{0.0,0.0,0.0,0.5},{1.0,0.0,0.0,0.5},
    {1.0,1.0,0.0,0.5}, {0.0,1.0,0.0,0.5}, {0.0,0.0,1.0,0.5},
    {1.0,0.0,1.0,0.5}, {1.0,1.0,1.0,0.5}, {0.0,1.0,1.0,0.5}};

void polygon(int a, int b, int c, int d)
{
    glBegin(GL_POLYGON);  //ø�s�@�Ӧh��� 
    glColor4fv(colors[a]);  //�]�w�C��4�ӰѼ�(����B���B�Ŧ�Balpha��) 
    glTexCoord2f(0.0,0.0);  //�t�m���z����
    glVertex3fv(vertices[a]); //�t�m�ϧΧ��СA����Ө禡�i�H�N�ϧ����p�ܤ@�Ӧh��ΤW�A�e�{�u���ı�ĪG 
    glColor4fv(colors[b]);  //�A�]�w�C�� 
    glTexCoord2f(0.0,1.0);
    glVertex3fv(vertices[b]);
    glColor4fv(colors[c]);
    glTexCoord2f(1.0,1.0);
    glVertex3fv(vertices[c]);
    glColor4fv(colors[d]);
    glTexCoord2f(1.0,0.0);
    glVertex3fv(vertices[d]);
    glEnd();
}

void colorcube()   //�s�y�h��� 
{

/* map vertices to faces */

    polygon(0,3,2,1);
    polygon(2,3,7,6);
    polygon(0,4,7,3);
    polygon(1,2,6,5);
    polygon(4,5,6,7);
    polygon(0,1,5,4);
}

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //�M���ثe�w�ҥΦ�m�P�`�׼g�J���w�İ�
    glLoadIdentity();          //�ثe���x�}���N���ѧO�x�}�A�߱󤧫e���x�} 
    glRotatef(theta[0], 1.0, 0.0, 0.0);      //¶ x �b���� 
    glRotatef(theta[1], 0.0, 1.0, 0.0);      //¶ y �b���� 
    glRotatef(theta[2], 0.0, 0.0, 1.0);      //¶ z �b���� 
    colorcube();
    glutSwapBuffers();          //�N��x���w�İϸ�e�x�洫 
}

void spinCube()   //������઺���� 
{
    theta[axis] += 2.0;
    if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
    glutPostRedisplay(); //�C��loop�`���ɡA��e�����ݭn���sø�s 
}

void mouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;  //����k��ɡAcube��V�Haxis 0���� 
    if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;  //�������ɡAcude��V�|�Haxis 1���� 
    if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;  //����U�u����Acude�|�Haxis 2��V���� 
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);     //�w�q�����x�Ϊ��j�p��m 
    glMatrixMode(GL_PROJECTION);    //�N��e�x�}���w����v�x�}
    glLoadIdentity();      //�ثe���x�}���N���ѧO�x�}
    if (w <= h)       //�e�񰪵���θ��� 
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,   //�q�L�����v��ҫ�����1:1�����ø���ŵ����W  �Ѽ�:(���A�k�A�W�A�U)
            2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
            2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);     
}

void key(unsigned char k, int x, int y)
{
    if(k == '1') glutIdleFunc(spinCube);   //���U"1"�� ����cube 
    if(k == '2') glutIdleFunc(NULL);    //���U"2"�� �Ȱ�cube 
    if(k == 'q') exit(0);     //���U"q"�� ���X�{�� 
}

int main(int argc, char **argv)
{
   GLubyte image[64][64][3];     //�ŧi�����ƭ� 
   int i, j,  c;
   for(i=0;i<64;i++)
   {
     for(j=0;j<64;j++)                     //�N image�}�C�̭����Ҧ��ȵe�� 8*8���ѽL(�C�Ӥ�ӥ� 8*8�ӹ��I�զ�) 
     {
       c = ((((i&0x8)==0)^((j&0x8))==0))*255;
       image[i][j][0]= (GLubyte) c;
       image[i][j][1]= (GLubyte) c;
       image[i][j][2]= (GLubyte) c;
     }
   }
    glutInit(&argc, argv);      
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //�Ыص��f���w��ܼҦ�������(���w�ġB�C��Ҧ��B�`�׼Ҧ�) 
    glutInitWindowSize(500, 500);    //���⪺���e 
    glutCreateWindow("colorcube");    //���f�W�� 
    glutReshapeFunc(myReshape);     //���f�ؤo���ܮɡA�ϧΤ�Ҥ��o���ܤ�
    glutDisplayFunc(display);     
    glutIdleFunc(spinCube);     //�]�m���_�ե���ܨ��
    glutMouseFunc(mouse);     //�ϥηƹ�click����� mouse 
    glEnable(GL_DEPTH_TEST);     //�ҥβ`�� 
    glEnable(GL_TEXTURE_2D);     //�ҥ� 2�����z 
    glTexImage2D(GL_TEXTURE_2D,0,3,64,64,0,GL_RGB,GL_UNSIGNED_BYTE, image); //���w���Ѽƥͦ��@��2D���zRGB 64*64���j�p
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);   //�]�m���z�����Ѽ�(2���B�Hx�b�����B���Ư��z)
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);   //(2���B�Hy�b�����B���Ư��z)
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);  //(2���B�]�m�̤j�L�o�B�̱��񪺤@�ӹ������C��@��ø�s�������C��)
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);  //(2���B�]�m�̤p�L�o�B�̱��񪺤@�ӹ������C��@��ø�s�������C��)
    glutKeyboardFunc(key);     //�ϥ���L����� mouse 
    glClearColor(1.0,1.0,1.0,1.0);    //�M���ثe�w�ҥΦ�m�P�`�׼g�J���w�İ�
    glutMainLoop();      //�i�J�j��
}
