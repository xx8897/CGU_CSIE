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

position verts[360];
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
gluOrtho2D (-100.0, 600.0, -300.0, 400.0);
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
    theta=theta/180*PI;
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
void transformVerts2D(){
    GLfloat tmp;
    for(int i=0;i<360;i++){
        tmp=matComposite[0][0]*verts[i].x+matComposite[0][1]*verts[i].y+matComposite[0][2];
        verts[i].y=matComposite[1][0]*verts[i].x+matComposite[1][1]*verts[i].y+matComposite[1][2];
       	verts[i].x=tmp;
    }
    matrix3x3SetIdentity(matComposite);
}


//畫 
void polygon(){   
glClear (GL_COLOR_BUFFER_BIT); 
glLineWidth(3);
glColor3f(0,0,1);
transformVerts2D();
for(int i=0; i<360; i++){
	verts[i] = {100+100*cos(i*2*M_PI/360), 100+100*sin(i*2*M_PI/360)};
	//cout << verts[i].x << "，" << verts[i].y << endl; 
} 

//畫圓 
glColor3f(0,1,0);
glBegin(GL_LINE_STRIP);
for(int i=45;i<225;i++){
        glVertex2f(verts[i].x,verts[i].y);
    }
glEnd();

glColor3f(1,0,0);
glBegin(GL_LINE_STRIP);
for(int i=225;i<360;i++){
        glVertex2f(verts[i].x,verts[i].y);
    }
for(int i=0;i<45;i++){
        glVertex2f(verts[i].x,verts[i].y);
    }
glEnd();
cout << "original centroid point: {" << (verts[0].x + verts[180].x)/2.0 << "，" << (verts[0].y + verts[180].y)/2.0 << "}" << endl;


//控制變化 

//Step2
rotate2D(0.0,0.0,-45);
transformVerts2D();
cout << "original centroid point: {" << (verts[0].x + verts[180].x)/2.0 << "，" << (verts[0].y + verts[180].y)/2.0 << "}" << endl;

//Step3
translate2D(-200,200);
transformVerts2D();
cout << "original centroid point: {" << (verts[0].x + verts[180].x)/2.0 << "，" << (verts[0].y + verts[180].y)/2.0 << "}" << endl;

//Step5
scale2D(3,3,(verts[0].x + verts[180].x)/2.0,(verts[0].y + verts[180].y)/2.0);
transformVerts2D();
cout << "original centroid point: {" << (verts[0].x + verts[180].x)/2.0 << "，" << (verts[0].y + verts[180].y)/2.0 << "}" << endl;

//Step6
rotate2D(100.0,100.0,-180);
transformVerts2D();
cout << "original centroid point: {" << (verts[0].x + verts[180].x)/2.0 << "，" << (verts[0].y + verts[180].y)/2.0 << "}" << endl;

//畫圓 
glColor3f(0,1,0);
glBegin(GL_LINE_STRIP);
for(int i=45;i<225;i++){
        glVertex2f(verts[i].x,verts[i].y);
    }
glEnd();

glColor3f(1,0,0);
glBegin(GL_LINE_STRIP);
for(int i=225;i<360;i++){
        glVertex2f(verts[i].x,verts[i].y);
    }
for(int i=0;i<45;i++){
        glVertex2f(verts[i].x,verts[i].y);
    }
glEnd();
glFlush ( );
  
}



int main (int argc, char** argv){    
glutInit (&argc, argv);                         // Initialize GLUT.    
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.    
glutInitWindowPosition (100, 100);   // Set top-left display-window position.    
glutInitWindowSize (400, 400);      // Set display-window width and height.    
glutCreateWindow ("Training_5_1"); // Create display window.    
init ( );                          // Execute initialization procedure.   
glutDisplayFunc (polygon);     // Send graphics to display window.    
glutMainLoop ( );                    // Display everything and wait.

}
