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
    glBegin(GL_POLYGON);  //繪製一個多邊形 
    glColor4fv(colors[a]);  //設定顏色4個參數(紅色、綠色、藍色、alpha值) 
    glTexCoord2f(0.0,0.0);  //配置紋理坐標
    glVertex3fv(vertices[a]); //配置圖形坐標，此兩個函式可以將圖形關聯至一個多邊形上，呈現真實視覺效果 
    glColor4fv(colors[b]);  //再設定顏色 
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

void colorcube()   //製造多邊形 
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //清除目前已啟用色彩與深度寫入的緩衝區
    glLoadIdentity();          //目前的矩陣取代為識別矩陣，拋棄之前的矩陣 
    glRotatef(theta[0], 1.0, 0.0, 0.0);      //繞 x 軸旋轉 
    glRotatef(theta[1], 0.0, 1.0, 0.0);      //繞 y 軸旋轉 
    glRotatef(theta[2], 0.0, 0.0, 1.0);      //繞 z 軸旋轉 
    colorcube();
    glutSwapBuffers();          //將後台的緩衝區跟前台交換 
}

void spinCube()   //物體旋轉的公式 
{
    theta[axis] += 2.0;
    if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
    glutPostRedisplay(); //每次loop循環時，當前視窗需要重新繪製 
}

void mouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;  //當按右鍵時，cube方向以axis 0改變 
    if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;  //當按左鍵時，cude方向會以axis 1改變 
    if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;  //當按下滾輪鍵，cude會以axis 2方向改變 
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);     //定義視窗矩形的大小位置 
    glMatrixMode(GL_PROJECTION);    //將當前矩陣指定為投影矩陣
    glLoadIdentity();      //目前的矩陣取代為識別矩陣
    if (w <= h)       //寬比高等於或較長 
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,   //通過正交投影把模型按照1:1的比例繪制到剪裁面上  參數:(左，右，上，下)
            2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
            2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);     
}

void key(unsigned char k, int x, int y)
{
    if(k == '1') glutIdleFunc(spinCube);   //按下"1"時 旋轉cube 
    if(k == '2') glutIdleFunc(NULL);    //按下"2"時 暫停cube 
    if(k == 'q') exit(0);     //按下"q"時 跳出程式 
}

int main(int argc, char **argv)
{
   GLubyte image[64][64][3];     //宣告相關數值 
   int i, j,  c;
   for(i=0;i<64;i++)
   {
     for(j=0;j<64;j++)                     //將 image陣列裡面的所有值畫成 8*8方格棋盤(每個方個由 8*8個像點組成) 
     {
       c = ((((i&0x8)==0)^((j&0x8))==0))*255;
       image[i][j][0]= (GLubyte) c;
       image[i][j][1]= (GLubyte) c;
       image[i][j][2]= (GLubyte) c;
     }
   }
    glutInit(&argc, argv);      
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //創建窗口指定顯示模式的類型(雙緩衝、顏色模式、深度模式) 
    glutInitWindowSize(500, 500);    //窗手的長寬 
    glutCreateWindow("colorcube");    //窗口名稱 
    glutReshapeFunc(myReshape);     //當窗口尺寸改變時，圖形比例不發生變化
    glutDisplayFunc(display);     
    glutIdleFunc(spinCube);     //設置不斷調用顯示函數
    glutMouseFunc(mouse);     //使用滑鼠click的函數 mouse 
    glEnable(GL_DEPTH_TEST);     //啟用深度 
    glEnable(GL_TEXTURE_2D);     //啟用 2維紋理 
    glTexImage2D(GL_TEXTURE_2D,0,3,64,64,0,GL_RGB,GL_UNSIGNED_BYTE, image); //指定的參數生成一個2D紋理RGB 64*64的大小
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);   //設置紋理相關參數(2維、以x軸延伸、重複紋理)
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);   //(2維、以y軸延伸、重複紋理)
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);  //(2維、設置最大過濾、最接近的一個像素的顏色作為繪製像素的顏色)
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);  //(2維、設置最小過濾、最接近的一個像素的顏色作為繪製像素的顏色)
    glutKeyboardFunc(key);     //使用鍵盤的函數 mouse 
    glClearColor(1.0,1.0,1.0,1.0);    //清除目前已啟用色彩與深度寫入的緩衝區
    glutMainLoop();      //進入迴圈
}
