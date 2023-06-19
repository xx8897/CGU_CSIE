#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

/*  Set initial display-window size. */
GLsizei winWidth = 600, winHeight = 600;

/*  Set range for world coordinates.  */
GLfloat xwcMin = 0.0, xwcMax = 4000.0;
GLfloat ywcMin = 0.0, ywcMax = 4000.0;

class wcPt2D {
	public:
		GLfloat x, y;
};

typedef GLfloat Matrix3x3 [3][3];

Matrix3x3 matComposite;

const GLdouble pi = 3.14159;
	
void init (void) {
	/*  Set color of display window to white.  */
	glClearColor (1.0, 1.0, 1.0, 0.0);
}

/* Construct the 3 by 3 identity matrix. */
void matrix3x3SetIdentity (Matrix3x3 matIdent3x3) {
	GLint row, col;
	
	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			matIdent3x3 [row][col] = (row == col);
}

/* Premultiply matrix m1 times matrix m2, store result in m2. */
void matrix3x3PreMultiply (Matrix3x3 m1, Matrix3x3 m2) {
	GLint row, col;
	Matrix3x3 matTemp;
	
	for (row = 0; row < 3; row++)
		for (col = 0; col < 3 ; col++)
			matTemp [row][col] = m1 [row][0] * m2 [0][col] + m1 [row][1] * m2 [1][col] + m1 [row][2] * m2 [2][col];
	
	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			m2 [row][col] = matTemp [row][col];
}

void translate2D (GLfloat tx, GLfloat ty) {
	Matrix3x3 matTransl;
	
	/*  Initialize translation matrix to identity.  */
	matrix3x3SetIdentity (matTransl);  
	
	matTransl [0][2] = tx;
	matTransl [1][2] = ty;
	
	/*  Concatenate matTransl with the composite matrix.  */
	matrix3x3PreMultiply (matTransl, matComposite);
}

void rotate2D (wcPt2D pivotPt, GLfloat theta) {
	Matrix3x3 matRot;
	
	/*  Initialize rotation matrix to identity.  */
	matrix3x3SetIdentity (matRot);    
	
	matRot [0][0] = cos (theta);
	matRot [0][1] = -sin (theta);
	matRot [0][2] = pivotPt.x * (1 - cos (theta)) + pivotPt.y * sin (theta);
	matRot [1][0] = sin (theta);
	matRot [1][1] = cos (theta);
	matRot [1][2] = pivotPt.y * (1 - cos (theta)) - pivotPt.x * sin (theta);
	
	/*  Concatenate matRot with the composite matrix.  */
	matrix3x3PreMultiply (matRot, matComposite);
}

void scale2D (GLfloat sx, GLfloat sy, wcPt2D fixedPt) {
	Matrix3x3 matScale;
	
	/*  Initialize scaling matrix to identity.  */
	matrix3x3SetIdentity (matScale);    
	
	matScale [0][0] = sx;
	matScale [0][2] = (1 - sx) * fixedPt.x;
	matScale [1][1] = sy;
	matScale [1][2] = (1 - sy) * fixedPt.y;
	
	/*  Concatenate matScale with the composite matrix.  */
	matrix3x3PreMultiply (matScale, matComposite);
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
	//glColor3f (1.0, 0.0, 0.0); 
		for (k = 0; k < 360; k++)
			glVertex2f (verts [k].x, verts [k].y);
	//glEnd ( );
	/*glBegin (GL_LINE_LOOP);
	glColor3f (1.0, 1.0, 0.0); 
		for (k = 89; k < 360; k++)
			glVertex2f (verts [k].x, verts [k].y);*/
	glEnd ( );
}

void displayFcn (void) {
	/*  Define initial position for triangle.  */
	GLint nVerts = 360;
	wcPt2D verts [360];
	wcPt2D verts1 [360];
	wcPt2D verts2 [360];
	for (int j=0;j<360;++j)
            {
            	verts[j] = {200+100*cos(2*pi/360*j),200+100*sin(2*pi/360*j) };
                //glVertex2f(200+100*cos(2*pi/360*j),200+100*sin(2*pi/360*j)); //CIRCLE
            }
    for (int g=0;g<360;++g)
            {
            	verts1[g] = {400+100*cos(2*pi/360*g),400+100*sin(2*pi/360*g) };
                //glVertex2f(400+100*cos(2*pi/360*g),400+100*sin(2*pi/360*g)); //CIRCLE
            }
    for (int j=0;j<360;++j)
            {
            	verts2[j] = {600+100*cos(2*pi/360*j),200+100*sin(2*pi/360*j) };
                glVertex2f(600+100*cos(2*pi/360*j),200+100*sin(2*pi/360*j)); //CIRCLE
            }
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
	
	glColor3f (1.0, 0.0, 0.0);      //  Set initial fill color to blue.
	triangle (verts);               //  Display blue triangle.
	glColor3f (0.0, 1.0, 0.0);      //  Set initial fill color to blue.
	triangle (verts1);               //  Display blue triangle.
	glColor3f (0.0, 0.0, 1.0);      //  Set initial fill color to blue.
	triangle (verts2);               //  Display blue triangle.
	
	/*  Initialize composite matrix to identity.  */
	matrix3x3SetIdentity (matComposite);
	
	/*STEP2*/
	wcPt2D centroidPt1;
	
	GLint k1, xSum1 = 0, ySum1 = 0;
	for (k1 = 0; k1 < nVerts;  k1++) {
		xSum1 += verts1 [k1].x;
		ySum1 += verts1 [k1].y;
	}
	centroidPt1.x = GLfloat (xSum1) / GLfloat (nVerts);
	centroidPt1.y = GLfloat (ySum1) / GLfloat (nVerts);
	wcPt2D pivPt1;
	pivPt1 = centroidPt1;
	
	/*STEP3*/   
	matrix3x3SetIdentity (matComposite);
	rotate2D (pivPt1, -(theta/2));
	transformVerts2D (nVerts, verts);  
	//triangle (verts);   

	/*STEP4*/  
	matrix3x3SetIdentity (matComposite);
	rotate2D (pivPt1, (theta/2));
	transformVerts2D (nVerts, verts2); 
	//triangle (verts2); 
	
	/*STEP5*/
	matrix3x3SetIdentity (matComposite);
	wcPt2D centroidPt2;
	
	GLint k2, xSum2 = 0, ySum2 = 0;
	for (k2 = 0; k2 < nVerts;  k2++) {
		xSum2 += verts [k2].x;
		ySum2 += verts [k2].y;
	}
	centroidPt2.x = GLfloat (xSum2) / GLfloat (nVerts);
	centroidPt2.y = GLfloat (ySum2) / GLfloat (nVerts);
	wcPt2D fixedPt2;
	fixedPt2 = centroidPt2;
	
	/*STEP6*/
	matrix3x3SetIdentity (matComposite);
	scale2D (3.0, 3.0, fixedPt2);
	transformVerts2D (nVerts, verts2); 
	//triangle (verts2);
	
	/*STEP7*/
	matrix3x3SetIdentity (matComposite);
	wcPt2D centroidPt3;
	
	GLint k3, xSum3 = 0, ySum3 = 0;
	for (k3 = 0; k3 < nVerts;  k3++) {
		xSum3 += verts2 [k3].x;
		ySum3 += verts2 [k3].y;
	}
	centroidPt3.x = GLfloat (xSum3) / GLfloat (nVerts);
	centroidPt3.y = GLfloat (ySum3) / GLfloat (nVerts);
	wcPt2D pivPt3;
	pivPt3 = centroidPt3;  
	
	/*STEP8*/
	matrix3x3SetIdentity (matComposite);
	rotate2D (pivPt3, -(pi));
	transformVerts2D (nVerts, verts); 
	//triangle (verts);
	
	glColor3f (1.0, 0.0, 0.0);      //  Set initial fill color to blue.
	triangle (verts);               //  Display blue triangle.
	glColor3f (0.0, 1.0, 0.0);      //  Set initial fill color to blue.
	triangle (verts1);               //  Display blue triangle.
	glColor3f (0.0, 0.0, 1.0);      //  Set initial fill color to blue.
	triangle (verts2);               //  Display blue triangle.

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
