
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

#define PI 3.14159265f

//色彩全局常量
GLfloat WHITE[] = { 1, 1, 1 };    //白色
GLfloat RED[] = { 1, 0, 0 };    //紅色
GLfloat GREEN[] = { 0, 1, 0 };    //綠色
GLfloat MAGENTA[] = { 1, 0, 1 };  //洋紅

//攝像機類：水平移動半徑為10，按上下鍵則垂直移動
class Camera {
public:
    double theta;      //確定x和z的位置
    double y;          //y位置
    double dTheta;     //角度增量
    double dy;         //上下y增量
public:
    //類構造函數—默認初始化用法
    Camera() : theta(0), y(3), dTheta(0.04), dy(0.2) {}
    //類方法
    double getX() { return 10 * cos(theta); }
    double getY() { return y; }
    double getZ() { return 10 * sin(theta); }
    void moveRight() { theta += dTheta; }
    void moveLeft() { theta -= dTheta; }
    void moveUp() { y += dy; }
    void moveDown() { if (y > dy) y -= dy; }
};

//球類定義
//半徑、顏色、最大高度
//x和z固定
//用lame bouncing algorithm
//每幀上下移動0.05單位
class Ball {
    //類的屬性
    double radius;
    GLfloat* color;
    double maximumHeight;
    double x;
    double y;
    double z;
    int direction;   //方向
public:
    //構造函數
    Ball(double r, GLfloat* c, double h, double x, double z) :
        radius(r), color(c), maximumHeight(h), direction(-1),
        y(h), x(x), z(z) {
    }

    //更新和繪制方法
    void update() {
        //正反運動
        y += direction * 0.05;
        if (y > maximumHeight) {
            y = maximumHeight;
            direction = -1;
        }
        else if (y < radius) {
            y = radius;
            direction = 1;
        }
        glPushMatrix();
        //單獨設置每個球的材質參數
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
        glTranslated(x, y, z);
        //創建球
        glutSolidSphere(radius, 30, 30);
        glPopMatrix();//
    }
};

//棋盤格：沿x和z平面分布
//點光源位置設置為(4, 3, 7).
class Checkerboard {
    int displayListId;
    int width;
    int depth;
public:
    //構造函數
    Checkerboard(int width, int depth) : width(width), depth(depth) {}
    //中心X
    double centerx() { return width / 2; }
    //中心Y
    double centerz() { return depth / 2; }
    //創建方法
    void create() {
        displayListId = glGenLists(1);     //每個顯示列表對應1個編號——關聯起來
        //新建操作表
        glNewList(displayListId, GL_COMPILE);   //把下述命令裝入顯示列表但不顯示
        //光源位置參數
        GLfloat lightPosition[] = { 4, 3, 7, 1 };
        //設置光源位置
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        //開始繪制四邊形
        glBegin(GL_QUADS);
        //法向量方向
        glNormal3d(0, 1, 0);
        for (int x = 0; x < width - 1; x++) {
            for (int z = 0; z < depth - 1; z++) {
                //設置每個格子的材質屬性
                glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,
                    (x + z) % 2 == 0 ? RED : WHITE);
                //四邊形的4個點坐標
                glVertex3d(x, 0, z);
                glVertex3d(x + 1, 0, z);
                glVertex3d(x + 1, 0, z + 1);
                glVertex3d(x, 0, z + 1);
            }
        }
        glEnd();
        glEndList();
    }
    //按列表編號繪制棋盤格
    void draw() {
    glCallList(displayListId);
    }
};

//全局變量：棋盤格、相機和3個球的數組
Checkerboard checkerboard(8, 8);
Camera camera;
//創建3個小球的數組
Ball balls[] = {
    Ball(1, GREEN, 7, 6, 1),
    Ball(1.5, MAGENTA, 6, 3, 4),
    Ball(0.4, WHITE, 5, 1, 7)
};

//自定義初始化方法
void init() {
    //允許深度測試
    glEnable(GL_DEPTH_TEST);
    //設置散射和鏡像反射為白光
    glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
    glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
    //設置前表面的高光鏡像反射為白光
    glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE);
    //設置前表面散射光反光系數
    glMaterialf(GL_FRONT, GL_SHININESS, 30);
    //允許燈光
    glEnable(GL_LIGHTING);
    //打開0#燈
    glEnable(GL_LIGHT0);
    //創建棋盤格
    checkerboard.create();
}

//自定義繪制函數
//通過類繪制各對象，display函數代碼得以簡化
void display() {
    //清除前一幀繪圖結果
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //裝入單位陣
    glLoadIdentity();
    //設置視角——攝像機參數
    gluLookAt(camera.getX(), camera.getY(), camera.getZ(),    //攝像機位置
        checkerboard.centerx(), 0.0, checkerboard.centerz(),   //焦點坐標
        0.0, 1.0, 0.0);   //攝像機機頂方向矢量
    //繪制棋盤
    checkerboard.draw();
    //繪制小球
    for (int i = 0; i < sizeof balls / sizeof(Ball); i++) {
        //更新位置並繪圖
        balls[i].update();
    }
    //glFlush();
    glutSwapBuffers();
}

//窗口調整大小時調用的函數
void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, GLfloat(w) / GLfloat(h), 1.0, 150.0);
    glMatrixMode(GL_MODELVIEW);
}
//自定義計時器函數
void timer(int v) {
    //當計時器喚醒時所調用的函數
    glutPostRedisplay();
    //設置下一次計時器的參數
    glutTimerFunc(1000 / 60, timer, v);//timer:函數名
}

//鍵盤處理函數
void onKey(int key, int, int) {
    //按鍵：上下左右
    switch (key) {
    case GLUT_KEY_LEFT: camera.moveLeft(); break;
    case GLUT_KEY_RIGHT: camera.moveRight(); break;
    case GLUT_KEY_UP: camera.moveUp(); break;
    case GLUT_KEY_DOWN: camera.moveDown(); break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("跳躍的球");
    glutDisplayFunc(display);   //設置顯示函數
    glutReshapeFunc(reshape);   //設置窗口調整大小的函數
    glutSpecialFunc(onKey);   //設置按鍵處理函數
    glutTimerFunc(100, timer, 0);  //設置計時器函數--每100ms被調用1次
    init();//自定義初始化函數
    glutMainLoop();//進入opengl主循環
    
    return 0;
}

