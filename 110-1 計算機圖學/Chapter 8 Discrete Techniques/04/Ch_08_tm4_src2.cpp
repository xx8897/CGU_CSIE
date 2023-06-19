#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <GL/glut.h>

/* default data*/
/* can enter other values via command line arguments */

#define CENTERX -0.5
#define CENTERY 0.5
#define HEIGHT 0.5
#define WIDTH 0.5
#define MAX_ITER 100

/* N x M array to be generated */

#define N 500
#define M 500

float height = HEIGHT; /* size of window in complex plane */
float width = WIDTH;
float cx = CENTERX; /* center of window in complex plane */
float cy = CENTERY;
int max = MAX_ITER; /* number of interations per point */

int n=N;
int m=M;

/* use unsigned bytes for image */

GLubyte image[N][M];

/* complex data type and complex add, mult, and magnitude functions
   probably not worth overhead */

typedef float complex[2];  //declare type of complex 

void add(complex a, complex b, complex p) //two complex add
{
    p[0]=a[0]+b[0];
    p[1]=a[1]+b[1];
}

void mult(complex a, complex b, complex p) //two complex mult
{
    p[0]=a[0]*b[0]-a[1]*b[1];
    p[1]=a[0]*b[1]+a[1]*b[0];
}

float mag2(complex a)
{
    return(a[0]*a[0]+a[1]*a[1]);
}

void form(float a, float b, complex p) //put data into a complex
{
    p[0]=a;
    p[1]=b;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); //clear the buffer of color
    glDrawPixels(n,m,GL_COLOR_INDEX, GL_UNSIGNED_BYTE, image); //draw a 
 glFlush();
}


void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);  //�w�q�����x�Ϊ��j�p��m 
    glMatrixMode(GL_PROJECTION); //�N��e�x�}���w����v�x�} 
    glLoadIdentity();    //�ثe���x�}���N���ѧO�x�}
    if (w <= h)      //�e�񰪪� 
    gluOrtho2D(0.0, 0.0, (GLfloat) n, (GLfloat) m* (GLfloat) h /  //�q�L�����v��ҫ�����1:1�����ø���ŵ����W  �Ѽ�:(���A�k�A�W�A�U) 
                         (GLfloat) w);
    else
    gluOrtho2D(0.0, 0.0, (GLfloat) n * (GLfloat) w / (GLfloat) h,
                         (GLfloat) m);
    glMatrixMode(GL_MODELVIEW);  //�e�@�Ӫ���A(�ݰ_�ӬO3D��) 
}

void myinit()
{
    float redmap[256], greenmap[256],bluemap[256];
    int i;

    glClearColor (1.0, 1.0, 1.0, 1.0);  //�����C��I�� (����B���B�Ŧ�BAlpha)
    gluOrtho2D(0.0, 0.0, (GLfloat) n, (GLfloat) m);  //�q�L�����v��ҫ�����1:1�����ø���ŵ����W  �Ѽ�:(���A�k�A�W�A�U)

/* define pseudocolor maps, ramps for red and blue,
   random for green */


    for(i=0;i<256;i++)   //�ϥΤ����h�w�qredmap�Pbluemap �A�ζüƥh�w�qgreenmap 
    {
         redmap[i]=i/255.;
         greenmap[i]=rand()%255;
         bluemap[i]=1.0-i/255.;
    }

    glPixelMapfv(GL_PIXEL_MAP_I_TO_R, 256, redmap);  //�����洫�� map�C����ި������q 
    glPixelMapfv(GL_PIXEL_MAP_I_TO_G, 256, greenmap); //������q 
    glPixelMapfv(GL_PIXEL_MAP_I_TO_B, 256, bluemap); //���Ŧ���q 
}


main(int argc, char *argv[])
{
    int i, j, k;  //declare variable
    float x, y, v;
    complex c0, c, d;

/* uncomment to define your own parameters */

/*    scanf("%f", &cx); /* center x */
/*    scanf("%f", &cy); /* center y */
 /*   scanf("%f", &width); /* rectangle width */
 /*   height=width; /* rectangle height */
/*    scanf("%d",&max); /* maximum iterations */

    for (i=0; i<n; i++) for(j=0; j<m; j++)   
    {

/* starting point */

    x= i *(width/(n-1)) + cx - width / 2;    //produce the point of complex c0 
    y= j *(height/(m-1)) + cy - height / 2;

    form(0,0,c);        //form(a,b,complex)
    form(x,y,c0);		//form(a,b,complex)


    for(k=0; k<max; k++)       //�Ƽƪ��p��P���Ncomplex calculate and iteration
    {
        mult(c,c,d);
        add(d,c0,c);
        v=mag2(c);
        if(v>4.0) break; /* assume not in set if mag > 4 */
    }

/* assign gray level to point based on its magnitude */
        if(v>1.0) v=1.0; /* clamp if > 1 */
        image[i][j]=255*v;       //�z�L���N�Ӻ�Ximage���Upixel���� 
    }


    glutInit(&argc, argv);       //initialize glut lib
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB ); //define mode
    glutInitWindowSize(N, M);      //define window
    glutCreateWindow("mandlebrot");
    myinit();
    glutReshapeFunc(myReshape);      //���f�ؤo���ܮɡA�ϧΤ�Ҥ��o���ܤ�
    glutDisplayFunc(display);      //���f�ҭn���а�����ӵ{�� 

    glutMainLoop();         //�i�J�j�� 


}
