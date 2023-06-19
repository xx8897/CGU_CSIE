/*

	Copyright 2010 Etay Meiri

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Tutorial 01 - Create a window
*/

// modified by Jyh-Da Wei, 2021.10.16

#include <GL/freeglut.h>

static void RenderSceneCB()
{
   GLfloat i; // instead of "float i;" thus we allow the "portability"
   
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
    
    for(i=0;i<=1;i+=0.0002){ 
	  glClearColor(i, i, 0.7f, 0.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      glutSwapBuffers();
    }
    
    glClearColor(0.7f, 0.7f, 0.7f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(512, 384);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Tutorial 01 B");

    InitializeGlutCallbacks();

    glClearColor(0.9f, 0.7f, 0.9f, 0.5f);

    glutMainLoop();
    
    return 0;
}
