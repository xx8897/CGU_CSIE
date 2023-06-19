#include<Windows.h>
#include<GL\glut.h>
#include<cstdlib>
#include<ctime>
//太陽、地球和月亮
//假設每個月都是30天
//一年12個月，共是360天
static int day = 200; // day的變化:從0到359
float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;
float distinceX = 0.0,distinceY=0.0,distinceZ=0.0;
float light_position[] = {-20, 20, 0, 0};  //光源的位置 -20 20 0
int trigger=0;
int old_rot_x = 0;                       //剛按下滑鼠時的視窗座標
int old_rot_y = 0;

int rot_x = 0;                           //拖曳後的相對座標，用這決定要旋轉幾度
int rot_y = 0;

int record_x = 0;                        //紀錄上一次旋轉的角度
int record_y = 0;
//void glTranslatef(GLfloat x,GLfloat y,GLfloat z);
//函數功能：沿X軸正方向平移x個單位(x是有符號數)
//  沿Y軸正方向平移y個單位(y是有符號數)
//  沿Z軸正方向平移z個單位(z是有符號數)
//void glRotatef(GLfloat angle,GLfloat x,GLfloat y,GLfloat z);
//先解釋一下旋轉方向，做(0,0,0)到(x,y,z)的向量，用右手握住這條向量，大拇指指向向量的正方向，四指環繞的方向就是旋轉的方向；
//函數功能：以點(0,0,0)到點(x,y,z)為軸，旋轉angle角度；

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
    glRotatef( (float)rot_y + (float)record_y, 1.0, 0.0, 0.0);   //以x軸當旋轉軸
    glRotatef( (float)rot_x + (float)record_x, 0.0, 1.0, 0.0);   //以y軸當旋轉軸
    glPushMatrix ();
    glBegin(GL_QUADS);
    //正面        //固定z軸 x前後 y前後四點成一個面
    glNormal3f(0,0,1);        //設定法向量
    glVertex3f(-point, point, point);
    glVertex3f(-point,-point, point);
    glVertex3f( point,-point, point);
    glVertex3f( point, point, point);
    //背面
    glNormal3f(0,0,-1);
    glVertex3f(-point, point,-point);
    glVertex3f( point, point,-point);
    glVertex3f( point,-point,-point);
    glVertex3f(-point,-point,-point);
    //右側面
    glNormal3f(1,0,0);
    glVertex3f( point,  point, point);
    glVertex3f( point, -point, point);
    glVertex3f( point, -point,-point);
    glVertex3f( point,  point,-point);
    //左側面
    glNormal3f(-1,0,0);
    glVertex3f(-point, point,-point);
    glVertex3f(-point,-point,-point);
    glVertex3f(-point,-point, point);
    glVertex3f(-point, point, point);
    //上面
    glNormal3f(0,1,0);
    glVertex3f(-point, point,-point);
    glVertex3f(-point, point, point);
    glVertex3f( point, point, point);
    glVertex3f( point, point,-point);
    //下面
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
    glTranslatef( 0+distinceX, 0+distinceY, distinceZ);   //太陽起始位置
//  glRotatef       (60.0, 1,0,0);
    glRotatef       (zRotated*2.0, 0,0,1);   // 自轉.
    glutSolidSphere (69.6, 20 , 150);
    glPopMatrix ();
}

void earth() {
    glColor3f(0.87,0.93,0.93);
    glRotatef(day / 360.0*360.0, 0.0f, 0.0f, -1.0f);//地球公轉
    glTranslatef(150, 0.0f, 0.0f); //地球初始位置
    glPushMatrix ();
    glTranslatef( 0+distinceX, 0+distinceY, distinceZ);
    glRotatef       (60.0, 1,0,0);
    glRotatef       (zRotated*2.0, 0,0,1);   // 自轉.
    glutSolidSphere (20, 30, 100);
    glPopMatrix ();
}

void moon() {
    glColor3f(0.93,0.8,0.67);
    glRotatef(day / 30.0*360.0 - day / 360.0*360.0, 0.0f, 0.0f, -1.0f);//月球公轉再多除以360因為一天
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

void reshapeFunc (int x, int y) { //改變視窗重新繪製
    //glEnable(GL_DEPTH_TEST); //3d模式要開啟
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, 1, 1, 2000);
//  glTranslatef    (0.0, 0.0, -15.0); //turn to 3d
    //沿著z軸平移
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200, 200, 0, 0, 0, 0, 0, 1);

//繪製金色的"太陽"
    sun();
//繪製銀色的"地球"
    earth();
//繪製銅色的"月亮"
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
    glutPostRedisplay();            //令視窗重繪
}

void myDisplay(void) {
    glEnable(GL_DEPTH_TEST); //3d模式要開啟
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION); //投影模式
    glLoadIdentity();
    gluPerspective(75, 1, 1, 2000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200, 200, 0, 0, 0, 0, 0, 1);

//繪製紅色的"太陽"
    sun();
    block();
//繪製藍色的"地球"
    earth();
//繪製黃色的"月亮"
    moon();
    

    if(trigger%2==0) {  //每2tick變化一次
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

    glEnable(GL_LIGHTING);                                 //開燈

    // 設定發光體的光源的特性
    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);      //環境光(Ambient Light)
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);      //散射光(Diffuse Light)
    glLightfv( GL_LIGHT0, GL_SPECULAR,light_specular);     //反射光(Specular Light)

    glLightfv( GL_LIGHT0, GL_POSITION,light_position);     //光的座標

    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_DEPTH_TEST);                               //啟動深度測試
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
     
      rot_x = 0;   //沒有歸零會有不理想的結果
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

