#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

   /*  Set initial display-window size. */
GLsizei winWidth = 600, winHeight = 600;  

   /*  Set range for world coordinates.  */
GLfloat xwcMin = 0.0, xwcMax = 225.0;
GLfloat ywcMin = 0.0, ywcMax = 225.0;

class wcPt2D {
    public:
    GLfloat x, y;
   };
   
typedef GLfloat Matrix4x4 [4][4];

   Matrix4x4 matComposite;

   const GLdouble pi = 3.14159;

   void init (void)
   {
      /*  Set color of display window to white.  */
      glClearColor (1.0, 1.0, 1.0, 0.0);
   }

/* Construct the 3 by 3 identity matrix. */
   void matrix4x4SetIdentity (Matrix4x4 matIdent4x4)
   {
      GLint row, col;

      for (row = 0; row < 4; row++)
         for (col = 0; col < 4; col++)
            matIdent4x4 [row][col] = (row == col);
   }

/* Premultiply matrix m1 times matrix m2, store result in m2. */
   void matrix4x4PreMultiply (Matrix4x4 m1, Matrix4x4 m2)
   {
      GLint row, col;
      Matrix4x4 matTemp;

      for (row = 0; row < 4; row++)
         for (col = 0; col < 4 ; col++)
            matTemp [row][col] = m1 [row][0] * m2 [0][col] + m1 [row][1] * m2 [1][col] + m1 [row][2] * m2 [2][col] + m1 [row][3] * m2 [3][col];

      for (row = 0; row < 4; row++)
         for (col = 0; col < 4; col++)
            m2 [row][col] = matTemp [row][col];
   }

void translate2D (GLfloat tx, GLfloat ty)
   {
      Matrix4x4 matTransl;

      /*  Initialize translation matrix to identity.  */
      matrix4x4SetIdentity (matTransl);  

      matTransl [0][2] = tx;
      matTransl [1][2] = ty;

      /*  Concatenate matTransl with the composite matrix.  */
      matrix4x4PreMultiply (matTransl, matComposite);
   }

void rotate2D (wcPt2D pivotPt, GLfloat theta)
   {
      Matrix4x4 matRot;

      /*  Initialize rotation matrix to identity.  */
      matrix4x4SetIdentity (matRot);    

      matRot [0][0] = cos (theta);
      matRot [0][1] = -sin (theta);
      matRot [0][2] = pivotPt.x * (1 - cos (theta)) + pivotPt.y  * sin (theta);
      
	  matRot [1][0] = sin (theta);
      matRot [1][1] = cos (theta);
      matRot [1][2] = pivotPt.y * (1 - cos (theta)) - pivotPt.x  * sin (theta);

      /*  Concatenate matRot with the composite matrix.  */
      matrix4x4PreMultiply (matRot, matComposite);
   }

void scale2D (GLfloat sx, GLfloat sy, wcPt2D fixedPt)
   {
      Matrix4x4 matScale;

      /*  Initialize scaling matrix to identity.  */
      matrix4x4SetIdentity (matScale);    

      matScale [0][0] = sx;
      matScale [0][2] = (1 - sx) * fixedPt.x;
      matScale [1][1] = sy;
      matScale [1][2] = (1 - sy) * fixedPt.y;

      /*  Concatenate matScale with the composite matrix.  */
      matrix4x4PreMultiply (matScale, matComposite);
   }

/* Using the composite matrix, calculate transformed coordinates. */
   void transformVerts2D (GLint nVerts, wcPt2D * verts)
   {
      GLint k;
      GLfloat temp;

      for (k = 0; k < nVerts; k++) {
         temp = matComposite [0][0] * verts [k].x + matComposite [0][1] *verts [k].y + matComposite [0][2];
         verts [k].y = matComposite [1][0] * verts [k].x + matComposite [1][1] *verts [k].y + matComposite [1][2];
         verts [k].x = temp;
      }
   }

void square (wcPt2D *verts)
   {
       GLint k;

       glBegin (GL_QUADS);
          for (k = 0; k < 4; k++)
             glVertex2f (verts [k].x, verts [k].y);
       glEnd ( );
   }

   void displayFcn (void)
   {
      /*  Define initial position for triangle.  */
      GLint nVerts = 4;
      wcPt2D verts [4] = { {0.0, 0.0}, {50.0, 0.0}, {50.0, 50.0} ,{0.0,50.0}};

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

      glColor3f (0.0, 0.0, 1.0);      //  Set initial fill color to blue.
      square (verts);               //  Display blue triangle.

      /*  Initialize composite matrix to identity.  */
      matrix4x4SetIdentity (matComposite);

      /*  Construct composite matrix for transformation sequence.  */
      scale2D (0.5, 0.5, fixedPt);   //  First transformation: Scale.
      rotate2D (pivPt, theta/2);     //  Second transformation: Rotate
      translate2D (50, 100);        //  Final transformation: Translate.

      /*  Apply composite matrix to triangle vertices.  */
      transformVerts2D (nVerts, verts);
      glColor3f (1.0, 0.0, 0.0);  // Set color for transformed triangle.
      square (verts);           // Display red transformed triangle.

      glFlush ( );
   }

void winReshapeFcn (GLint newWidth, GLint newHeight)
   {
      glMatrixMode (GL_PROJECTION);
      glLoadIdentity ( );
      gluOrtho2D (xwcMin, xwcMax, ywcMin, ywcMax);

      glClear (GL_COLOR_BUFFER_BIT);
   }
int main (int argc, char ** argv)
   {
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



