#include <GL/glew.h>
#include "Textfile.h"
#include <GL/freeglut.h>
#include <iostream>
 
#pragma comment(lib,"glew32.lib")  
 
using namespace std;
 
GLuint vShader, fShader;//??/���q?�⾹?�H  
GLuint vaoHandle;// VAO?�H
 
//??��m??  
float positionData[] = {
						-0.5f,-0.5f,0.0f,1.0f,
						0.5f,-0.5f,0.0f,1.0f,
						0.5f,0.5f,0.0f,1.0f,
						-0.5f,0.5f,0.0f,1.0f
};
//???��??  
float colorData[] = {
					 1.0f, 0.0f, 0.0f,1.0f,
					 0.0f, 1.0f, 0.0f,1.0f,
					 0.0f, 0.0f, 1.0f,1.0f,
					 1.0f,1.0f,0.0f,1.0f
};
 
void initShader(const char *VShaderFile, const char *FShaderFile)
{
	//1�B�d��?�d�BGLSL�MOpenGL���H��  
	const GLubyte *vendor = glGetString(GL_VENDOR);
	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *version = glGetString(GL_VERSION);
	const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
	cout << "?�d��?��   : " << vendor << endl;
	cout << "?�d��?     : " << renderer << endl;
	cout << "OpenGL����   : " << version << endl;
	cout << "GLSL����     : " << glslVersion << endl;
 
	//2�B???�⾹  
	//?��?�⾹?�H�G???�⾹  
	vShader = glCreateShader(GL_VERTEX_SHADER);
	//????  
	if (0 == vShader)
	{
		cerr << "ERROR : Create vertex shader failed" << endl;
		exit(1);
	}
 
	//��?�⾹���N?�M?�⾹?�H��??  
	const GLchar *vShaderCode = textFileRead(VShaderFile);
	const GLchar *vCodeArray[1] = { vShaderCode };
 
	//?�r��???�w��??��?�⾹?�H�W
	glShaderSource(vShader, 1, vCodeArray, NULL);
 
	//???�⾹?�H  
	glCompileShader(vShader);
 
	//?�d??�O�_���\  
	GLint compileResult;
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &compileResult);
	if (GL_FALSE == compileResult)
	{
		GLint logLen;
		//�o��??���?��  
		glGetShaderiv(vShader, GL_INFO_LOG_LENGTH, &logLen);
		if (logLen > 0)
		{
			char *log = (char *)malloc(logLen);
			GLsizei written;
			//�o���ӫH���}?�X  
			glGetShaderInfoLog(vShader, logLen, &written, log);
			cerr << "vertex shader compile log : " << endl;
			cerr << log << endl;
			free(log);//?���?  
		}
	}
 
	//?��?�⾹?�H�G��??�⾹  
	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	//????  
	if (0 == fShader)
	{
		cerr << "ERROR : Create fragment shader failed" << endl;
		exit(1);
	}
 
	//��?�⾹���N?�M?�⾹?�H��??  
	const GLchar *fShaderCode = textFileRead(FShaderFile);
	const GLchar *fCodeArray[1] = { fShaderCode };
	glShaderSource(fShader, 1, fCodeArray, NULL);
 
	//???�⾹?�H  
	glCompileShader(fShader);
 
	//?�d??�O�_���\  
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &compileResult);
	if (GL_FALSE == compileResult)
	{
		GLint logLen;
		//�o��??���?��  
		glGetShaderiv(fShader, GL_INFO_LOG_LENGTH, &logLen);
		if (logLen > 0)
		{
			char *log = (char *)malloc(logLen);
			GLsizei written;
			//�o���ӫH���}?�X  
			glGetShaderInfoLog(fShader, logLen, &written, log);
			cerr << "fragment shader compile log : " << endl;
			cerr << log << endl;
			free(log);//?���?  
		}
	}
 
	//3�B?��?�⾹?�H  
	//?��?�⾹�{��  
	GLuint programHandle = glCreateProgram();
	if (!programHandle)
	{
		cerr << "ERROR : create program failed" << endl;
		exit(1);
	}
	//??�⾹�{��?�����?�ت��{�Ǥ�  
	glAttachShader(programHandle, vShader);
	glAttachShader(programHandle, fShader);
	//??��?�H?�����@?�i?��{��  
	glLinkProgram(programHandle);
	//�d??����?�G  
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
	else//?�����\�A�bOpenGL��?���ϥδ�V�{��  
	{
		glUseProgram(programHandle);
	}
}
 
void initVBO()
{
	//?�wVAO
	glGenVertexArrays(1, &vaoHandle);
	glBindVertexArray(vaoHandle);
 
	// Create and populate the buffer objects  
	GLuint vboHandles[2];
	glGenBuffers(2, vboHandles);
	GLuint positionBufferHandle = vboHandles[0];
	GLuint colorBufferHandle = vboHandles[1];
 
	//?�wVBO�H�Ѩϥ�  
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	//�[??�u��VBO  
	glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float),
		positionData, GL_STATIC_DRAW);
 
	//?�wVBO�H�Ѩϥ�  
	glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
	//�[??�u��VBO  
	glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float),
		colorData, GL_STATIC_DRAW);
 
	glEnableVertexAttribArray(0);//??��?  
	glEnableVertexAttribArray(1);//???��  
 
		//?��glVertexAttribPointer���e�ݭn?��?�w�ާ@  
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);
	glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);
}
 
void init()
{
	//��l��glew?�i?  
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		cout << "Error initializing GLEW: " << glewGetErrorString(err) << endl;
	}
	//�[???�M���q?�⾹?�H�}?����@?�{��?�H�W
	initShader("VertexShader.vert","FragmentShader.frag");
	//?�w�}�[?VAO�AVBO
	initVBO();
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
 
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//�ϥ�VAO�BVBO?��  
	glBindVertexArray(vaoHandle);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glBindVertexArray(0);
	glutSwapBuffers();
}
 
//ESC?�Τ_�h�X�ϥ�?�⾹
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		glDeleteShader(vShader);
		glUseProgram(0);
		glutPostRedisplay(); //��s?��
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

