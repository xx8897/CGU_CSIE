#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h> 
#include<math.h>
#include<gl/glut.h>
#include<iostream>
#include<cmath>
#define PI 3.1415
#define n 360

using namespace std;

typedef GLfloat Matrix3x3[3][3];
Matrix3x3 matComposite;//複合矩陣

struct position{
    float x;
    float y;
};

position verts_RED[361];
position verts_GREEN[361];
position verts_BLUE[361];
//矩陣相乘
void matrixpreMultiply(Matrix3x3 m1,Matrix3x3 m2){
    GLint row,col;
    Matrix3x3 tmp;
    for(row=0;row<3;row++){
        for(col=0;col<3;col++){
            tmp[row][col]=m1[row][0]*m2[0][col]+m1[row][1]*
                m2[1][col]+m1[row][2]*m2[2][col];
        }
    }
    for(row=0;row<3;row++){
        for(col=0;col<3;col++){
            m2[row][col]=tmp[row][col];
        }
    }
}

void matrix3x3SetIdentity(Matrix3x3 mat){
    GLint row,col;
    for(row=0;row<3;row++){
        for(col=0;col<3;col++)
            mat[row][col]=(row==col);
    }
}

void init (void){    
glClearColor (1.0, 1.0, 1.0, 0.0);    
glMatrixMode (GL_PROJECTION);        
gluOrtho2D (0.0, 4000.0, 0.0, 4000.0);
matrix3x3SetIdentity(matComposite);
}

//平移
void translate2D(GLfloat tx,GLfloat ty){
    Matrix3x3 matTransl;
    matrix3x3SetIdentity(matTransl);//設定為單位矩陣
    matTransl[0][2]=tx;
    matTransl[1][2]=ty;
    matrixpreMultiply(matTransl,matComposite);
 
}

//旋轉
void rotate2D(int x,int y,float theta){
    theta=theta/180*M_PI;
    Matrix3x3 matRot;
    matrix3x3SetIdentity(matRot);
    matRot[0][0]=cos(theta);
    matRot[0][1]=-sin(theta);
    matRot[0][2]=x*(1-cos(theta))+y*sin(theta);
    matRot[1][0]=sin(theta);
    matRot[1][1]=cos(theta);
    matRot[1][2]=y*(1-cos(theta))-x*sin(theta);
    matrixpreMultiply(matRot,matComposite);
}

//縮放
void scale2D(GLfloat sx,GLfloat sy,int x,int y){
    Matrix3x3 matScale;
    matrix3x3SetIdentity(matScale);
    matScale[0][0]=sx;
    matScale[0][2]=(1-sx)*x;
    matScale[1][1]=sy;
    matScale[1][2]=(1-sy)*y;
    matrixpreMultiply(matScale,matComposite);
}

//複合矩陣
void transformVerts2D(position *vertex){
    GLfloat tmp;
    for(int i=0;i<361;i++){
        tmp=matComposite[0][0]*vertex[i].x+matComposite[0][1]*vertex[i].y+matComposite[0][2];
        vertex[i].y=matComposite[1][0]*vertex[i].x+matComposite[1][1]*vertex[i].y+matComposite[1][2];
       	vertex[i].x=tmp;
    }
    matrix3x3SetIdentity(matComposite);
}


//畫 
void polygon(){   
glClear (GL_COLOR_BUFFER_BIT); 
for(int i=0; i<360; i++){
	verts_RED[i] = {200+100*cos(i*2*M_PI/360), 200+100*sin(i*2*M_PI/360)};
	verts_BLUE[i] = {600+100*cos(i*2*M_PI/360), 200+100*sin(i*2*M_PI/360)};
	verts_GREEN[i] = {400+100*cos(i*2*M_PI/360), 400+100*sin(i*2*M_PI/360)};
		//cout << verts[i].x << "，" << verts[i].y << endl; 
} 
//PA,PB
verts_RED[360] = {200,200};//PB
verts_BLUE[360] = {600,200};//PC
verts_GREEN[360] = {400,400};//PA


cout << "PA.x: " << verts_GREEN[360].x << "  PA.y: " << verts_GREEN[360].y << endl;
cout << "PB.x: " << verts_RED[360].x << "  PB.y: " << verts_RED[360].y << endl;
cout << "PC.x: " << verts_BLUE[360].x << "  PC.y: " << verts_BLUE[360].y << endl << endl;
//畫圓 
glColor3f(1,0,0);
glBegin(GL_LINE_STRIP);
for(int i=0;i<360;i++){
        glVertex2f(verts_RED[i].x,verts_RED[i].y);
    }
glEnd();

glColor3f(0,1,0);
glBegin(GL_LINE_STRIP);
for(int i=0;i<360;i++){
        glVertex2f(verts_GREEN[i].x,verts_GREEN[i].y);
    }
glEnd();

glColor3f(0,0,1);
glBegin(GL_LINE_STRIP);
for(int i=0;i<360;i++){
        glVertex2f(verts_BLUE[i].x,verts_BLUE[i].y);
    }
glEnd();


//依據verts為重心轉verts_GREEN
//Step 3
rotate2D(verts_GREEN[360].x,verts_GREEN[360].y,-45);
transformVerts2D(verts_RED);


cout << "PB.x: " << verts_RED[360].x << "  PB.y: " << verts_RED[360].y << endl;


//Step4
rotate2D(verts_GREEN[360].x,verts_GREEN[360].y,45);
transformVerts2D(verts_BLUE);

cout << "PC.x: " << verts_BLUE[360].x << "  PC.y: " << verts_BLUE[360].y << endl << endl;

//Step6
scale2D(3,3,verts_RED[360].x,verts_RED[360].y);
transformVerts2D(verts_BLUE);
cout << "PC.x: " << verts_BLUE[360].x << "  PC.y: " << verts_BLUE[360].y << endl << endl;

//Step8
rotate2D(verts_BLUE[360].x,verts_BLUE[360].y,-180);
transformVerts2D(verts_RED);

cout << "PB.x: " << verts_RED[360].x << "  PB.y: " << verts_RED[360].y << endl;
//最後圖 
glColor3f(1,0,0);
glBegin(GL_LINE_STRIP);
for(int i=0;i<360;i++){
        glVertex2f(verts_RED[i].x,verts_RED[i].y);
    }
glEnd();

glColor3f(0,0,1);
glBegin(GL_LINE_STRIP);
for(int i=0;i<360;i++){
        glVertex2f(verts_BLUE[i].x,verts_BLUE[i].y);
    }
glEnd();

glColor3f(0,1,0);
glBegin(GL_LINE_STRIP);
for(int i=0;i<360;i++){
        glVertex2f(verts_GREEN[i].x,verts_GREEN[i].y);
    }
glEnd();

glFlush ( );
  
}



int main (int argc, char** argv){    
glutInit (&argc, argv);                         // Initialize GLUT.    
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.    
glutInitWindowPosition (100, 100);   // Set top-left display-window position.    
glutInitWindowSize (600, 600);      // Set display-window width and height.    
glutCreateWindow ("QUIZ2_1"); // Create display window.    
init ( );                          // Execute initialization procedure.   
glutDisplayFunc (polygon);     // Send graphics to display window.    
glutMainLoop ( );                    // Display everything and wait.

}
