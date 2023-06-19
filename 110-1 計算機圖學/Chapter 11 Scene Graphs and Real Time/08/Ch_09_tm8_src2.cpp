
#include <stdlib.h>
#include <GL/glut.h>


static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;

    GLuint tex;

void display(void)
{

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindTexture(GL_TEXTURE_CUBE_MAP, tex);

	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);

	glutSolidTeapot(1.0);


	glutSwapBuffers();
}

void spinCube()
{


	theta[axis] += 2.0;
	if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
	glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y)
{

	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
            2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
            2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void key(char k, int x, int y)
{
	if(k == '1') glutIdleFunc(spinCube);
	if(k == '2') glutIdleFunc(NULL);
        if(k == 'q') exit(0);
}

void init()
{

    GLubyte red[3] = {255, 0, 0};
    GLubyte green[3] = {0, 255, 0};
    GLubyte blue[3] = {0, 0, 255};
    GLubyte cyan[3] = {0, 255, 255};
    GLubyte magenta[3] = {255, 0, 255};
    GLubyte yellow[3] = {255, 255, 0};

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glEnable(GL_TEXTURE_GEN_R);
    glEnable(GL_TEXTURE_CUBE_MAP);

   glGenTextures(1, &tex);
   glBindTexture(GL_TEXTURE_CUBE_MAP, tex);

   glTexGeni(GL_S, GL_TEXTURE_GEN_MODE,GL_REFLECTION_MAP);
   glTexGeni(GL_T, GL_TEXTURE_GEN_MODE,GL_REFLECTION_MAP);
   glTexGeni(GL_R, GL_TEXTURE_GEN_MODE,GL_REFLECTION_MAP);
   glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X ,0,3,1,1,0,GL_RGB,GL_UNSIGNED_BYTE, red);
   glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X ,0,3,1,1,0,GL_RGB,GL_UNSIGNED_BYTE, green);
   glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y ,0,3,1,1,0,GL_RGB,GL_UNSIGNED_BYTE, blue);
   glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y ,0,3,1,1,0,GL_RGB,GL_UNSIGNED_BYTE, cyan);
   glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z ,0,3,1,1,0,GL_RGB,GL_UNSIGNED_BYTE, magenta);
   glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z ,0,3,1,1,0,GL_RGB,GL_UNSIGNED_BYTE, yellow);
   glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_S,GL_REPEAT);
   glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_T,GL_REPEAT);
   glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_R,GL_REPEAT);
   glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MIN_FILTER,GL_NEAREST); 

   glClearColor(1.0,1.0,1.0,1.0);
}

void
main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("colorcube");

    init();

    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutIdleFunc(spinCube);
    glutIdleFunc(NULL);
    glutMouseFunc(mouse);

    glutKeyboardFunc(key);
    glutMainLoop();
}
#include <GL/glew.h>
#include "Textfile.h"
#include <GL/freeglut.h>
#include <iostream>
 
#pragma comment(lib,"glew32.lib")  
 
using namespace std;
 
GLuint vShader, fShader;//??/片段?色器?象  
GLuint vaoHandle;// VAO?象
 
//??位置??  
float positionData[] = {
						-0.5f,-0.5f,0.0f,1.0f,
						0.5f,-0.5f,0.0f,1.0f,
						0.5f,0.5f,0.0f,1.0f,
						-0.5f,0.5f,0.0f,1.0f
};
//???色??  
float colorData[] = {
					 1.0f, 0.0f, 0.0f,1.0f,
					 0.0f, 1.0f, 0.0f,1.0f,
					 0.0f, 0.0f, 1.0f,1.0f,
					 1.0f,1.0f,0.0f,1.0f
};
 
void initShader(const char *VShaderFile, const char *FShaderFile)
{
	//1、查看?卡、GLSL和OpenGL的信息  
	const GLubyte *vendor = glGetString(GL_VENDOR);
	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *version = glGetString(GL_VERSION);
	const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
	cout << "?卡供?商   : " << vendor << endl;
	cout << "?卡型?     : " << renderer << endl;
	cout << "OpenGL版本   : " << version << endl;
	cout << "GLSL版本     : " << glslVersion << endl;
 
	//2、???色器  
	//?建?色器?象：???色器  
	vShader = glCreateShader(GL_VERTEX_SHADER);
	//????  
	if (0 == vShader)
	{
		cerr << "ERROR : Create vertex shader failed" << endl;
		exit(1);
	}
 
	//把?色器源代?和?色器?象相??  
	const GLchar *vShaderCode = textFileRead(VShaderFile);
	const GLchar *vCodeArray[1] = { vShaderCode };
 
	//?字符???定到??的?色器?象上
	glShaderSource(vShader, 1, vCodeArray, NULL);
 
	//???色器?象  
	glCompileShader(vShader);
 
	//?查??是否成功  
	GLint compileResult;
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &compileResult);
	if (GL_FALSE == compileResult)
	{
		GLint logLen;
		//得到??日志?度  
		glGetShaderiv(vShader, GL_INFO_LOG_LENGTH, &logLen);
		if (logLen > 0)
		{
			char *log = (char *)malloc(logLen);
			GLsizei written;
			//得到日志信息并?出  
			glGetShaderInfoLog(vShader, logLen, &written, log);
			cerr << "vertex shader compile log : " << endl;
			cerr << log << endl;
			free(log);//?放空?  
		}
	}
 
	//?建?色器?象：片??色器  
	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	//????  
	if (0 == fShader)
	{
		cerr << "ERROR : Create fragment shader failed" << endl;
		exit(1);
	}
 
	//把?色器源代?和?色器?象相??  
	const GLchar *fShaderCode = textFileRead(FShaderFile);
	const GLchar *fCodeArray[1] = { fShaderCode };
	glShaderSource(fShader, 1, fCodeArray, NULL);
 
	//???色器?象  
	glCompileShader(fShader);
 
	//?查??是否成功  
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &compileResult);
	if (GL_FALSE == compileResult)
	{
		GLint logLen;
		//得到??日志?度  
		glGetShaderiv(fShader, GL_INFO_LOG_LENGTH, &logLen);
		if (logLen > 0)
		{
			char *log = (char *)malloc(logLen);
			GLsizei written;
			//得到日志信息并?出  
			glGetShaderInfoLog(fShader, logLen, &written, log);
			cerr << "fragment shader compile log : " << endl;
			cerr << log << endl;
			free(log);//?放空?  
		}
	}
 
	//3、?接?色器?象  
	//?建?色器程序  
	GLuint programHandle = glCreateProgram();
	if (!programHandle)
	{
		cerr << "ERROR : create program failed" << endl;
		exit(1);
	}
	//??色器程序?接到所?建的程序中  
	glAttachShader(programHandle, vShader);
	glAttachShader(programHandle, fShader);
	//??些?象?接成一?可?行程序  
	glLinkProgram(programHandle);
	//查??接的?果  
	GLint linkStatus;
	glGetProgramiv(programHandle, GL_LINK_STATUS, &linkStatus);
	if (GL_FALSE == linkStatus)
	{
		cerr << "ERROR : link shader program failed" << endl;
		GLint logLen;
		glGetProgramiv(programHandle, GL_INFO_LOG_LENGTH,
			&logLen);
		if (logLen > 0)
		{
			char *log = (char *)malloc(logLen);
			GLsizei written;
			glGetProgramInfoLog(programHandle, logLen,
				&written, log);
			cerr << "Program log : " << endl;
			cerr << log << endl;
		}
	}
	else//?接成功，在OpenGL管?中使用渲染程序  
	{
		glUseProgram(programHandle);
	}
}
 
void initVBO()
{
	//?定VAO
	glGenVertexArrays(1, &vaoHandle);
	glBindVertexArray(vaoHandle);
 
	// Create and populate the buffer objects  
	GLuint vboHandles[2];
	glGenBuffers(2, vboHandles);
	GLuint positionBufferHandle = vboHandles[0];
	GLuint colorBufferHandle = vboHandles[1];
 
	//?定VBO以供使用  
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	//加??据到VBO  
	glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float),
		positionData, GL_STATIC_DRAW);
 
	//?定VBO以供使用  
	glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
	//加??据到VBO  
	glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float),
		colorData, GL_STATIC_DRAW);
 
	glEnableVertexAttribArray(0);//??坐?  
	glEnableVertexAttribArray(1);//???色  
 
		//?用glVertexAttribPointer之前需要?行?定操作  
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);
	glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);
}
 
void init()
{
	//初始化glew?展?  
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		cout << "Error initializing GLEW: " << glewGetErrorString(err) << endl;
	}
	//加???和片段?色器?象并?接到一?程序?象上
	initShader("VertexShader.vert","FragmentShader.frag");
	//?定并加?VAO，VBO
	initVBO();
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
 
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//使用VAO、VBO?制  
	glBindVertexArray(vaoHandle);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glBindVertexArray(0);
	glutSwapBuffers();
}
 
//ESC?用于退出使用?色器
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		glDeleteShader(vShader);
		glUseProgram(0);
		glutPostRedisplay(); //刷新?示
		break;
	}
}
 
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello GLSL");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

