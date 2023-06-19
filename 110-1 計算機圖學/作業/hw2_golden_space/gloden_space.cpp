#include<Windows.h>
#include<GL\glut.h>
#include<cstdlib>
#include<ctime>
//�Ӷ��B�a�y�M��G
//���]�C�Ӥ볣�O30��
//�@�~12�Ӥ�A�@�O360��
static int day = 200; // day���ܤ�:�q0��359
float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;
float distinceX = 0.0,distinceY=0.0,distinceZ=0.0;
float light_position[] = {-20, 20, 0, 0};  //��������m -20 20 0
int trigger=0;
int old_rot_x = 0;                       //����U�ƹ��ɪ������y��
int old_rot_y = 0;

int rot_x = 0;                           //�즲�᪺�۹�y�СA�γo�M�w�n����X��
int rot_y = 0;

int record_x = 0;                        //�����W�@�����઺����
int record_y = 0;
//void glTranslatef(GLfloat x,GLfloat y,GLfloat z);
//��ƥ\��G�uX�b����V����x�ӳ��(x�O���Ÿ���)
//  �uY�b����V����y�ӳ��(y�O���Ÿ���)
//  �uZ�b����V����z�ӳ��(z�O���Ÿ���)
//void glRotatef(GLfloat angle,GLfloat x,GLfloat y,GLfloat z);
//�������@�U�����V�A��(0,0,0)��(x,y,z)���V�q�A�Υk�ⴤ��o���V�q�A�j������V�V�q������V�A�|����¶����V�N�O���઺��V�F
//��ƥ\��G�H�I(0,0,0)���I(x,y,z)���b�A����angle���סF

void star(int i) {
    int var=0;
    var=rand()%199;
    glTranslatef( -var-2*i, var-i, var/2);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere (1, 20, 50);
    glTranslatef( var-8*var/12, var-100, var);
    glutSolidSphere (1, 20, 50);
}

void block() {
//  glTranslatef( 0+distinceX, 0+distinceY, distinceZ);
    int point=100;
    glRotatef( (float)rot_y + (float)record_y, 1.0, 0.0, 0.0);   //�Hx�b�����b
    glRotatef( (float)rot_x + (float)record_x, 0.0, 1.0, 0.0);   //�Hy�b�����b
    glPushMatrix ();
    glBegin(GL_QUADS);
    //����        //�T�wz�b x�e�� y�e��|�I���@�ӭ�
    glNormal3f(0,0,1);        //�]�w�k�V�q
    glVertex3f(-point, point, point);
    glVertex3f(-point,-point, point);
    glVertex3f( point,-point, point);
    glVertex3f( point, point, point);
    //�I��
    glNormal3f(0,0,-1);
    glVertex3f(-point, point,-point);
    glVertex3f( point, point,-point);
    glVertex3f( point,-point,-point);
    glVertex3f(-point,-point,-point);
    //�k����
    glNormal3f(1,0,0);
    glVertex3f( point,  point, point);
    glVertex3f( point, -point, point);
    glVertex3f( point, -point,-point);
    glVertex3f( point,  point,-point);
    //������
    glNormal3f(-1,0,0);
    glVertex3f(-point, point,-point);
    glVertex3f(-point,-point,-point);
    glVertex3f(-point,-point, point);
    glVertex3f(-point, point, point);
    //�W��
    glNormal3f(0,1,0);
    glVertex3f(-point, point,-point);
    glVertex3f(-point, point, point);
    glVertex3f( point, point, point);
    glVertex3f( point, point,-point);
    //�U��
    glNormal3f(0,-1,0);
    glVertex3f(-point, -point, point);
    glVertex3f(-point, -point,-point);
    glVertex3f( point, -point,-point);
    glVertex3f( point, -point, point);
    glEnd();
    glPopMatrix ();
}

void sun() {
    glColor3f(0.85,0.64,0.12);
    glPushMatrix ();
    glTranslatef( 0+distinceX, 0+distinceY, distinceZ);   //�Ӷ��_�l��m
//  glRotatef       (60.0, 1,0,0);
    glRotatef       (zRotated*2.0, 0,0,1);   // ����.
    glutSolidSphere (69.6, 20 , 150);
    glPopMatrix ();
}

void earth() {
    glColor3f(0.87,0.93,0.93);
    glRotatef(day / 360.0*360.0, 0.0f, 0.0f, -1.0f);//�a�y����
    glTranslatef(150, 0.0f, 0.0f); //�a�y��l��m
    glPushMatrix ();
    glTranslatef( 0+distinceX, 0+distinceY, distinceZ);
    glRotatef       (60.0, 1,0,0);
    glRotatef       (zRotated*2.0, 0,0,1);   // ����.
    glutSolidSphere (20, 30, 100);
    glPopMatrix ();
}

void moon() {
    glColor3f(0.93,0.8,0.67);
    glRotatef(day / 30.0*360.0 - day / 360.0*360.0, 0.0f, 0.0f, -1.0f);//��y����A�h���H360�]���@��
//  glRotatef(day / 30.0*360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(38, 0.0f, 0.0f);
    glPushMatrix ();
    glTranslatef( 0+distinceX, 0+distinceY, distinceZ);
    glRotatef       (60.0, 1,0,0);
    glRotatef       (zRotated, 0,0,1);
    glutSolidSphere (10, 30, 100);
    glPopMatrix ();
    glColor3f(1, 0, 0);
}

void reshapeFunc (int x, int y) { //���ܵ������sø�s
    //glEnable(GL_DEPTH_TEST); //3d�Ҧ��n�}��
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, 1, 1, 2000);
//  glTranslatef    (0.0, 0.0, -15.0); //turn to 3d
    //�u��z�b����
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200, 200, 0, 0, 0, 0, 0, 1);

//ø�s���⪺"�Ӷ�"
    sun();
//ø�s�Ȧ⪺"�a�y"
    earth();
//ø�s�ɦ⪺"��G"
    moon();

    glFlush();
    glutSwapBuffers();
}
void Keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            distinceZ+=1;
            break;
        case 's':
            distinceZ-=1;
            break;
        case 'a':
            distinceX-=1;
            break;
        case 'd':
            distinceX+=1;
            break;
        case 'o':
            distinceY+=1;
            break;
        case 'p':
            distinceY-=1;
            break;
        case 'q':
            glDisable(GL_LIGHT0);
            glDisable(GL_LIGHTING);
            glDisable(GL_DEPTH_TEST);
//          glutDestroyWindow(WinNumber);
            exit(0);
            break;
    }
    glutPostRedisplay();            //�O������ø
}

void myDisplay(void) {
    glEnable(GL_DEPTH_TEST); //3d�Ҧ��n�}��
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION); //��v�Ҧ�
    glLoadIdentity();
    gluPerspective(75, 1, 1, 2000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200, 200, 0, 0, 0, 0, 0, 1);

//ø�s���⪺"�Ӷ�"
    sun();
    block();
//ø�s�Ŧ⪺"�a�y"
    earth();
//ø�s���⪺"��G"
    moon();
    

    if(trigger%2==0) {  //�C2tick�ܤƤ@��
        for(int i=0; i<60/4; i++) {
            glPushMatrix ();
            star(i);
            glPopMatrix ();
        }
    }
    trigger++;

    glFlush();
    glutSwapBuffers();
}

void myIdle(void) {
    Sleep(50);
    ++day;
    if (day >= 360)
        day = 0;
    zRotated += 0.3;
    glutPostRedisplay();
    myDisplay();
}
void SetLightSource() {
    float light_ambient[]  = { 0.1,0.1,0.1,1};
    float light_diffuse[]  = { 0.8, 0.8, 0.8, 1.0};
    float light_specular[] = { 0.9,0.9,0.9,1};

    glEnable(GL_LIGHTING);                                 //�}�O

    // �]�w�o���骺�������S��
    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);      //���ҥ�(Ambient Light)
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);      //���g��(Diffuse Light)
    glLightfv( GL_LIGHT0, GL_SPECULAR,light_specular);     //�Ϯg��(Specular Light)

    glLightfv( GL_LIGHT0, GL_POSITION,light_position);     //�����y��

    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_DEPTH_TEST);                               //�Ұʲ`�״���
}

void SetMaterial() {
    float material_ambient[]  = { 0.2, 0.2, 0.2, 1.0};
    float material_diffuse[]  = { 0.3, 0.3, 0.3, 1.0};
    float material_specular[] = { 0.2, 0.2, 0.2, 1.0};

    glMaterialfv( GL_FRONT, GL_AMBIENT,  material_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE,  material_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular);
}
void Mouse(int button, int state, int x, int y){
   if(state){
      record_x += x - old_rot_x;
      record_y += y - old_rot_y;
     
      rot_x = 0;   //�S���k�s�|�����z�Q�����G
      rot_y = 0;
   }else{
      old_rot_x = x;
      old_rot_y = y;
   }
}
void MotionMouse(int x, int y){
   rot_x = x - old_rot_x;
   rot_y = y - old_rot_y;
   glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    srand(time(0));

    glutInit(&argc, argv);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("new space");
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //change view in order to 3d performance
    glutDisplayFunc(&myDisplay);

    SetLightSource();
    SetMaterial();

    glutKeyboardFunc( Keyboard);
    glutMouseFunc   ( Mouse );
    glutMotionFunc  ( MotionMouse );
    glutReshapeFunc (reshapeFunc);
    glutIdleFunc(&myIdle);
    
//glutIdleFunc(&idleFunc);
    glutMainLoop();
    return 0;
}

