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

float height ; /* size of window in complex plane */
float width ;
float cx; /* center of window in complex plane */
float cy;
int max; /* number of iterations per point */

int n=N;
int m=M;

/* use unsigned bytes for image */

GLubyte image[N][M];

/* complex data type and complex add, mult, and magnitude functions
   probably not worth overhead */

typedef float complex[2];

void add(complex a, complex b, complex 	p)
{
    p[0]=a[0]+b[0];	//x1y1+y1y2+c  
    p[1]=a[1]+b[1]; //x1y2+x2y1+c
}

void mult(complex a, complex b, complex p)
{
    p[0]=a[0]*b[0]-a[1]*b[1];//d[0]=x1x2-y1y2   �곡 
    p[1]=a[0]*b[1]+a[1]*b[0];//d[1]=x1y2+x2y1   �곡 
}

float mag2(complex a){
    return(a[0]*a[0]+a[1]*a[1]);//]z]^2=x^2+y^2
}

void form(float a, float b, complex p)
{
    p[0]=a;
    p[1]=b;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(n,m,GL_COLOR_INDEX, GL_UNSIGNED_BYTE, image);
	glFlush();
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    gluOrtho2D(0.0, 0.0, (GLfloat) n, (GLfloat) m* (GLfloat) h /(GLfloat) w);	//�վ�ø�s�j�p
	//ex:n=w=500,m=h=1000�A1000*(1000/500)����ҡC 
    else
    gluOrtho2D(0.0, 0.0, (GLfloat) n * (GLfloat) w / (GLfloat) h,
                         (GLfloat) m);
    glMatrixMode(GL_MODELVIEW);
}

void myinit()
{
    float redmap[256], greenmap[256],bluemap[256];	//mapping RGB color
    int i;

    glClearColor (1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0.0, 0.0, (GLfloat) n, (GLfloat) m);//�G����l�� 

/* define pseudocolor maps, ramps for red and blue,
   random for green */


    for(i=0;i<256;i++)	//random color
    {
         redmap[i]=i/255.;
         greenmap[i]=rand()%255;
         bluemap[i]=1.0-i/255.;	
    }

    glPixelMapfv(GL_PIXEL_MAP_I_TO_R, 256, redmap);
    glPixelMapfv(GL_PIXEL_MAP_I_TO_G, 256, greenmap);
    glPixelMapfv(GL_PIXEL_MAP_I_TO_B, 256, bluemap);
}


main(int argc, char *argv[])
{
    int i, j, k;
    float x, y, v;
    complex c0, c, d;

/* uncomment to define your own parameters */
	printf("center x:");
    scanf("%f", &cx); /* center x */
    printf("center y:");
	scanf("%f", &cy); /* center y */
    printf("Complex plane rectangle width:");
	scanf("%f", &width); /* rectangle width */
    height=width; /* rectangle height */
    printf("maxinum iterations:");
	scanf("%d",&max); /* maximum iterations */

    for (i=0; i<n; i++) 
		for(j=0; j<m; j++){
		/* starting point */
	    x= i *(width/(n-1)) + cx -width/2;
	    y= j *(height/(m-1)) + cy -height/2;

	    form(0,0,c);	
	    form(y,x,c0);	

		/* complex iteration */
		
    	for(k=0; k<max; k++){
	        mult(c,c,d);
	        add(d,c0,c);
	        v=mag2(c);
	    	if(v>4.0) break; /* assume not in set if mag > 4 */
        }
		
		/* assign gray level to point based on its magnitude */
        if(v>1.0) v=1.0; /* clamp if > 1 256(0-255) types gray level*/ 
        image[i][j]=255*v;
    }

		//x=�C�@�ӵ�������*(�Ƽƥ�������e�j�p/�`�����j�p = 1�ӵ�����ҧe�{���Ƽƥ������榳�h�ּe��)+�Ƽƥ�������x-�Ƽƥ�������j�p/2=�`����) 

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(N, M);
    glutCreateWindow("mandlebrot");
    myinit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);

    glutMainLoop();


}
