#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

/*  Set initial display-window size. */
GLsizei winWidth = 400, winHeight = 400;

/*  Set range for world coordinates.  */
GLfloat xwcMin = 0.0, xwcMax = 400.0;
GLfloat ywcMin = 0.0, ywcMax = 400.0;

class wcPt2D {
	public:
		GLfloat x, y;
};

typedef GLfloat Matrix5x5 [5][5];

Matrix5x5 matComposite;

const GLdouble pi = 3.14159;
	
void init (void) {
	/*  Set color of display window to white.  */
	glClearColor (1.0, 1.0, 1.0, 0.0);
}

/* Construct the 3 by 3 identity matrix. */
void matrix5x5SetIdentity (Matrix5x5 matIdent5x5) {
	GLint row, col;
	
	for (row = 0; row < 5; row++)
		for (col = 0; col < 5; col++)
			matIdent5x5 [row][col] = (row == col);
}

/* Premultiply matrix m1 times matrix m2, store result in m2. */
void matrix5x5PreMultiply (Matrix5x5 m1, Matrix5x5 m2) {
	GLint row, col;
	Matrix5x5 matTemp;
	
	for (row = 0; row < 5; row++)
		for (col = 0; col < 5 ; col++)
			matTemp [row][col] = m1 [row][0] * m2 [0][col] + m1 [row][1] * m2 [1][col] + m1 [row][2] * m2 [2][col]+ m1 [row][3] * m2 [3][col]+ m1 [row][4] * m2 [4][col];
	
	for (row = 0; row < 5; row++)
		for (col = 0; col < 5; col++)
			m2 [row][col] = matTemp [row][col];
}

void translate2D (GLfloat tx, GLfloat ty) {
	Matrix5x5 matTransl;
	
	/*  Initialize translation matrix to identity.  */
	matrix5x5SetIdentity (matTransl);  
	
	matTransl [0][2] = tx;
	matTransl [1][2] = ty;
	
	/*  Concatenate matTransl with the composite matrix.  */
	matrix5x5PreMultiply (matTransl, matComposite);
}

void rotate2D (wcPt2D pivotPt, GLfloat theta) {
	Matrix5x5 matRot;
	
	/*  Initialize rotation matrix to identity.  */
	matrix5x5SetIdentity (matRot);    
	
	matRot [0][0] = cos (theta);
	matRot [0][1] = -sin (theta);
	matRot [0][2] = pivotPt.x * (1 - cos (theta)) + pivotPt.y * sin (theta);
	matRot [1][0] = sin (theta);
	matRot [1][1] = cos (theta);
	matRot [1][2] = pivotPt.y * (1 - cos (theta)) - pivotPt.x * sin (theta);
	
	/*  Concatenate matRot with the composite matrix.  */
	matrix5x5PreMultiply (matRot, matComposite);
}

void scale2D (GLfloat sx, GLfloat sy, wcPt2D fixedPt) {
	Matrix5x5 matScale;
	
	/*  Initialize scaling matrix to identity.  */
	matrix5x5SetIdentity (matScale);    
	
	matScale [0][0] = sx;
	matScale [0][2] = (1 - sx) * fixedPt.x;
	matScale [1][1] = sy;
	matScale [1][2] = (1 - sy) * fixedPt.y;
	
	/*  Concatenate matScale with the composite matrix.  */
	matrix5x5PreMultiply (matScale, matComposite);
}

/* Using the composite matrix, calculate transformed coordinates. */
void transformVerts2D (GLint nVerts, wcPt2D * verts) {
	GLint k;
	GLfloat temp;
	
	for (k = 0; k < nVerts; k++) {
		temp = matComposite [0][0] * verts [k].x + matComposite [0][1] * verts [k].y + matComposite [0][2];
		verts [k].y = matComposite [1][0] * verts [k].x + matComposite [1][1] * verts [k].y + matComposite [1][2];
		verts [k].x = temp;
	}
}

void triangle (wcPt2D *verts) {
	GLint k;
	
	glBegin (GL_LINE_LOOP);
		for (k = 0; k < 5; k++)
			glVertex2f (verts [k].x, verts [k].y);
	glEnd ( );
}

void displayFcn (void) {
	/*  Define initial position for triangle.  */
	GLint nVerts = 5;
	wcPt2D verts [5] = { {50.0, 300.0},{150.0, 300.0},{200.0, 350.0},{100.0,400.0},{0.0,350.0} };
	/*  Calculate position of triangle centroid.  */
	wcPt2D centroidPt;
	
	GLint k, xSum = 0, ySum = 0;
	for (k = 0; k < nVerts;  k++) {
		xSum += verts [k].x;
		ySum += verts [k].y;
	}
	centroidPt.x = GLfloat (xSum) / GLfloat (nVerts);
	centroidPt.y = GLfloat (ySum) / GLfloat (nVerts);
	/*  Set geometric transformation parameters.  */
	
	wcPt2D pivPt, fixedPt;
	pivPt = centroidPt;
	fixedPt = centroidPt;
	GLfloat tx = 0.0, ty = 100.0;
	GLfloat sx = 0.5, sy = 0.5;
	GLdouble theta = pi/2.0;
	glClear (GL_COLOR_BUFFER_BIT);   //  Clear display window.
	
	glColor3f (0.0, 1.0, 0.0);      //  Set initial fill color to blue.
	triangle (verts);               //  Display blue triangle.
	
	/*step1*/
	matrix5x5SetIdentity (matComposite);
	
	/*step2,3*/
	scale2D (1.5, 1.5, fixedPt);   
	transformVerts2D (nVerts, verts);
	glColor3f (1.0, 0.0, 0.0);  
	//triangle (verts);           
	
	/*step4*/
	matrix5x5SetIdentity (matComposite);
	rotate2D (pivPt, -(pi));     
	transformVerts2D (nVerts, verts);
	glColor3f (1.0, 0.0, 0.0);  
	//triangle (verts);           
	
	/*step5*/
	matrix5x5SetIdentity (matComposite);
	translate2D (150, -100);        
	transformVerts2D (nVerts, verts);
	glColor3f (1.0, 0.0, 0.0);  
	//triangle (verts);           
	wcPt2D centroidPt1;
	GLint k1, xSum1 = 0, ySum1 = 0;
	for (k1 = 0; k1 < nVerts;  k1++) {
		xSum1 += verts [k1].x;
		ySum1 += verts [k1].y;
	}
	centroidPt1.x = GLfloat (xSum1) / GLfloat (nVerts);
	centroidPt1.y = GLfloat (ySum1) / GLfloat (nVerts);
	wcPt2D pivPt1, fixedPt1;
	pivPt1 = centroidPt1;
	fixedPt1 = centroidPt1;
	
	/*step6*/
	matrix5x5SetIdentity (matComposite);
	rotate2D (pivPt1, theta);     //  Second transformation: Rotate
	transformVerts2D (nVerts, verts);
	glColor3f (1.0, 0.0, 0.0);  // Set color for transformed triangle.
	//triangle (verts);           // Display red transformed triangle.
	
	matrix5x5SetIdentity (matComposite);
	scale2D (0.5, 0.5, fixedPt1);   //  First transformation: Scale.
	transformVerts2D (nVerts, verts);
	glColor3f (1.0, 0.0, 0.0);  // Set color for transformed triangle.
	//triangle (verts);           // Display red transformed triangle.
	
	matrix5x5SetIdentity (matComposite);
	translate2D (100, -100);        //  Final transformation: Translate.
	transformVerts2D (nVerts, verts);
	glColor3f (1.0, 0.0, 0.0);  // Set color for transformed triangle.
	triangle (verts);           // Display red transformed triangle.
	
	glFlush ( );
}

void winReshapeFcn (GLint newWidth, GLint newHeight) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ( );
	gluOrtho2D (xwcMin, xwcMax, ywcMin, ywcMax);
	
	glClear (GL_COLOR_BUFFER_BIT);
}

int main (int argc, char ** argv) {
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (50, 50);
	glutInitWindowSize (winWidth, winHeight);
	glutCreateWindow ("Geometric Transformation Sequence");
	
	init ( );
	glutDisplayFunc (displayFcn);
	glutReshapeFunc (winReshapeFcn);
	
	glutMainLoop ( );
}
