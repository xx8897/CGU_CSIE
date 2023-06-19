#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<GL/glut.h>      // (or others, depending on the system in use)
#include<math.h>

void init (void)
{    
	glClearColor (0.8F, 0.6F,0.4F, 0.0);  // Set display-window color to white.    
	glMatrixMode (GL_PROJECTION);       // Set projection parameters.    
	gluOrtho2D (-200.0, 200.0, -200.0, 200.0);
}

const int n = 1000;
const GLfloat Pi = 3.14;

void lineSegment (void)
{    
	glClear(GL_COLOR_BUFFER_BIT); //清除顏色緩衝和深度緩衝
	
	glBegin(GL_POLYGON); // 池塘 
	glColor3f(0.0, 0.6, 1.0); //設置顏色，3f代表參數為三個浮點數
	for (int i = 0; i < n; i++)
		glVertex2f(200+400*cos(2 * Pi / n*i), -200+100*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	//glLineWidth(4.0f);  //池塘邊緣線 
	glColor3f(0.0, 0.8, 1.0);
    glBegin(GL_LINE_LOOP);
      for (int i=0;i<n;++i){
        glVertex2f(30*cos(2 * Pi / n*i), -150+10*sin(2 * Pi / n*i));
        }
    glEnd();
    glFlush();
    
    //glLineWidth(4.0f);  //池塘邊緣線 
	glColor3f(0.0, 0.8, 1.0);
    glBegin(GL_LINE_LOOP);
      for (int i=0;i<n;++i){
        glVertex2f(35*cos(2 * Pi / n*i), -150+12*sin(2 * Pi / n*i));
        }
    glEnd();
    glFlush();
    
     //glLineWidth(4.0f);  //池塘邊緣線 
	glColor3f(0.0, 0.8, 1.0);
    glBegin(GL_LINE_LOOP);
      for (int i=0;i<n;++i){
        glVertex2f(40*cos(2 * Pi / n*i), -150+14*sin(2 * Pi / n*i));
        }
    glEnd();
    glFlush();
    
     //glLineWidth(4.0f);  //池塘邊緣線 
	glColor3f(0.0, 0.8, 1.0);
    glBegin(GL_LINE_LOOP);
      for (int i=0;i<n;++i){
        glVertex2f(45*cos(2 * Pi / n*i), -150+16*sin(2 * Pi / n*i));
        }
    glEnd();
    glFlush();
	
	//glLineWidth(4.0f);  //池塘邊緣線 
	glColor3f(0.0, 0.8, 1.0);
    glBegin(GL_LINE_LOOP);
      for (int i=0;i<n;++i){
        glVertex2f(50*cos(2 * Pi / n*i), -150+18*sin(2 * Pi / n*i));
        }
    glEnd();
    glFlush();
    
	glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.3, 0.3, 0.3); 
	for (int i = 0; i < n; i++)
		glVertex2f(200+30*cos(2 * Pi / n*i), -100+20*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.2, 0.2, 0.2); 
	for (int i = 0; i < n; i++)
		glVertex2f(150+24*cos(2 * Pi / n*i), -100+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.25, 0.25, 0.25); 
	for (int i = 0; i < n; i++)
		glVertex2f(123+24*cos(2 * Pi / n*i), -100+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.355, 0.355, 0.355); 
	for (int i = 0; i < n; i++)
		glVertex2f(100+24*cos(2 * Pi / n*i), -105+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
		glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.255, 0.355, 0.355); 
	for (int i = 0; i < n; i++)
		glVertex2f(80+24*cos(2 * Pi / n*i), -110+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
		glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.355, 0.355, 0.355); 
	for (int i = 0; i < n; i++)
		glVertex2f(60+24*cos(2 * Pi / n*i), -105+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
		glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.355, 0.355, 0.355); 
	for (int i = 0; i < n; i++)
		glVertex2f(40+24*cos(2 * Pi / n*i), -105+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.355, 0.355, 0.355); 
	for (int i = 0; i < n; i++)
		glVertex2f(-40+24*cos(2 * Pi / n*i), -110+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.255, 0.355, 0.255); 
	for (int i = 0; i < n; i++)
		glVertex2f(-60+24*cos(2 * Pi / n*i), -120+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.355, 0.355, 0.355); 
	for (int i = 0; i < n; i++)
		glVertex2f(-100+24*cos(2 * Pi / n*i), -125+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.355, 0.355, 0.355); 
	for (int i = 0; i < n; i++)
		glVertex2f(-120+24*cos(2 * Pi / n*i), -130+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.3, 0.3, 0.3); 
	for (int i = 0; i < n; i++)
		glVertex2f(-120+24*cos(2 * Pi / n*i), -140+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.2, 0.2, 0.2); 
	for (int i = 0; i < n; i++)
		glVertex2f(-140+24*cos(2 * Pi / n*i), -150+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.355, 0.355, 0.355); 
	for (int i = 0; i < n; i++)
		glVertex2f(-160+24*cos(2 * Pi / n*i), -170+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.2, 0.2, 0.355); 
	for (int i = 0; i < n; i++)
		glVertex2f(-180+24*cos(2 * Pi / n*i), -185+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // 石頭 
	glColor3f(0.4, 0.4, 0.355); 
	for (int i = 0; i < n; i++)
		glVertex2f(-200+24*cos(2 * Pi / n*i), -190+15*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glColor3f(1.0, 1.0, 1.0);  //天空 
	glBegin(GL_QUADS);
	glVertex2i(200,200);
	glVertex2i(200,-55);
	glVertex2i(-200,-55);
	glVertex2i(-200,200);
	glEnd ( );
	glFlush();
	
	glBegin(GL_POLYGON); //繪製方式 雲 
	glColor3f(0.0, 0.7, 0.9); 
	for (int i = 0; i < n; i++)
		glVertex2f(70+40*cos(2* Pi / n*i), 160+20*sin(2* Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); //繪製方式 雲 
	glColor3f(0.0, 0.7, 0.9); 
	for (int i = 0; i < n; i++)
		glVertex2f(90+40*cos(2* Pi / n*i), 150+20*sin(2* Pi / n*i));
	glEnd();
	glFlush();

	glBegin(GL_POLYGON); //繪製方式 雲 
	glColor3f(0.0, 0.7, 0.9); 
	for (int i = 0; i < n; i++)
		glVertex2f(-100+40*cos(2* Pi / n*i), 170+20*sin(2* Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); //繪製方式 雲 
	glColor3f(0.0, 0.7, 0.9); 
	for (int i = 0; i < n; i++)
		glVertex2f(-140+40*cos(2* Pi / n*i), 150+20*sin(2* Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); //繪製方式 雲 
	glColor3f(0.0, 0.7, 0.9); 
	for (int i = 0; i < n; i++)
		glVertex2f(-140+40*cos(2* Pi / n*i), 70+20*sin(2* Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); //繪製方式 雲 
	glColor3f(0.0, 0.7, 0.9); 
	for (int i = 0; i < n; i++)
		glVertex2f(-170+30*cos(2* Pi / n*i), 60+20*sin(2* Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); // 太陽 
	glColor3f(1.0, 1.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(-180+70*cos(2 * Pi / n*i), 180+70*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	
	glBegin(GL_POLYGON); //  鞋子 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(10+5*cos(2 * Pi / n*i), -150+5*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glColor3f(0.5, 1.4, 0.4); //FOOT 
	glBegin(GL_QUAD_STRIP);
	glVertex2i(5,-150);
	glVertex2i(5,-90);
	glVertex2i(15,-150);
	glVertex2i(15,-90);
	
	glEnd ( );
	glFlush();
	
	glBegin(GL_POLYGON); // 鞋子 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(-5+5*cos(2 * Pi / n*i), -150+5*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	
	glColor3f(0.5, 1.4, 0.4); //FOOT
	glBegin(GL_QUAD_STRIP);
	glVertex2i(-10,-150);
	glVertex2i(-10,-90);
	glVertex2i(0,-150);
	glVertex2i(0,-90);
	glEnd ( );
	glFlush();
	
	glColor3f(0.5, 1.4, 0.4);  //HAND
	glBegin(GL_QUADS);
	glVertex2i(-70,-40);
	glVertex2i(-10,-50);
	glVertex2i(-10,-60);
	glVertex2i(-70,-50);
	glEnd ( );
	glFlush();
	
	glColor3f(0.5, 1.4, 0.4);  //HAND
	glBegin(GL_QUADS);
	glVertex2i(70,-40);
	glVertex2i(10,-50);
	glVertex2i(10,-60);
	glVertex2i(70,-50);
	glEnd ( );
	glFlush();
	
	glColor3f(1.5, 1.4, 0.4);//身體 
	glBegin(GL_TRIANGLES);
	glVertex2i(0,50);
	glVertex2i(-40,-120);
	glVertex2i(40,-120);
	glEnd ( );
	glFlush();
	
	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.0, 0.5); 
	for (int i = 0; i < n; i++)
		glVertex2f(30*cos(2 * Pi / n*i), 15+70*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.0, 0.5); 
	for (int i = 0; i < n; i++)
		glVertex2f(10*cos(2 * Pi / n*i), -10+40*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glLineWidth(4.0f);  //邊緣線 
	glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
      for (int i=0;i<n;++i){
        glVertex2f(30*cos(2 * Pi / n*i), 15+70*sin(2 * Pi / n*i));
        }
    glEnd();
    glFlush();
    
    glLineWidth(4.0f);  //邊緣線  領帶 
	glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
      glVertex2i(7,-51);
      glVertex2i(-7,-51);
      glVertex2i(-7,-65);
      glVertex2i(0,-70);
      glVertex2i(7,-65);
    glEnd();
    glFlush();
	
	glBegin(GL_POLYGON); //大頭 
	glColor3f(0.5, 1.4, 0.4); 
	for (int i = 0; i < n; i++)
		glVertex2f(100*cos(2* Pi / n*i), 60+100*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	
	glColor3f(0.5, 1.4, 0.4);
	glBegin(GL_TRIANGLES);
	glVertex2i(-40,-120);
	glVertex2i(40,-120);
	glEnd ( );
	glFlush();
	

	glBegin(GL_POLYGON); //繪製方式        小手手(右手) 
	glColor3f(0.5, 1.4, 0.4); 
	for (int i = 0; i < n; i++)
		glVertex2f(70+5*cos(2 * Pi / n*i), -45+5*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	
	
	glBegin(GL_POLYGON); //繪製方式        小手手(左手) 
	glColor3f(0.5, 1.4, 0.4);
	for (int i = 0; i < n; i++)
		glVertex2f(-70+5*cos(2 * Pi / n*i), -45+5*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2i(75,-20);
	glVertex2i(70,-50);
	glVertex2i(80,-45);
	glEnd ( );
	glFlush();
	
	glBegin(GL_POLYGON); //眼睛 
	glColor3f(0.5f, 0.5f, 0.5f); 
	for (int i = 0; i < n; i++)
		glVertex2f(-70+25*cos(2 * Pi / n*i), 100+25*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); //眼睛
	glColor3f(0.5f, 0.5f, 0.5f);
	for (int i = 0; i < n; i++)
		glVertex2f(70+25*cos(2* Pi / n*i), 100+25*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); //帽子 
	glColor3f(0.8, 0.8, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(100*cos(2 * Pi / n*i), 130+10*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glColor3f(0.8, 0.8, 0.0);
    glBegin(GL_LINE_STRIP);
	  glVertex2i(-70,140);
	  glVertex2i(-66,140);
      glVertex2i(-52,140);
	  glVertex2i(-50,140);
      glVertex2i(-44,139);
      glVertex2i(-44,140);
      glVertex2i(50,135);
      glVertex2i(70,140);
      glVertex2i(66,130);
      glVertex2i(44,140);
      
    glEnd();
    glFlush();
	
	glBegin(GL_POLYGON); //空空眼睛 
	glColor3f(1.0, 1.0, 1.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(70+17*cos(2* Pi / n*i), 84+10*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); //黑眼球
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(70+12*cos(2* Pi / n*i), 84+12*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); //空空眼睛 
	glColor3f(1.0, 1.0, 1.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(-70+17*cos(2* Pi / n*i), 84+10*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
		glBegin(GL_POLYGON); //黑眼球 
	glColor3f(0.0, 0.0, 0.0); 
	for (int i = 0; i < n; i++)
		glVertex2f(-70+12*cos(2* Pi / n*i), 84+12*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); //繪製方式
	glColor3f(0.8f, 0.6f, 0.2f); 
	for (int i = 0; i < n; i++)
		glVertex2f(80*cos(2 * Pi / n*i), 40+20*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
	glLineWidth(3);  
	glColor3f (0.5, 0.6, 0.8);      // Set line segment color to red.   
	glBegin(GL_LINES);      
	glVertex2i (-80,40);       // Specify line-segment geometry.
	glVertex2i (80,40);
	glEnd ( );
	glFlush();
    
    glColor3f(0.0,0.0,0.5);  //領帶      
	
	/*glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
      for (int i=0;i<n;++i){
        glVertex2f(30*cos(2 * Pi / n*i), 15+70*sin(2 * Pi / n*i));//計算坐標
        }
    glEnd();
    glFlush();*/
    
    
    glBegin(GL_TRIANGLE_FAN);  //領帶 
      glVertex2i(7,-40);
      glVertex2i(-7,-40);
      glVertex2i(-7,-65);
      glVertex2i(0,-70);
      glVertex2i(7,-65);
	  glEnd();
	  glFlush();

	glLineWidth(2);  
	glColor3f (1.0, 1.0, 1.0);      // Set line segment color to red.   
	glBegin(GL_LINES);      
	glVertex2i (-7,-52);       // Specify line-segment geometry.
	glVertex2i (7,-55);
	glEnd ( );
	glFlush();
	
	glLineWidth(2);  
	glColor3f (1.0, 1.0, 1.0);      // Set line segment color to red.   
	glBegin(GL_LINES);      
	glVertex2i (-7,-55);       // Specify line-segment geometry.
	glVertex2i (7,-58);
	glEnd ( );
	glFlush();
	
	glLineWidth(2);  
	glColor3f (1.0, 1.0, 1.0);      // Set line segment color to red.   
	glBegin(GL_LINES);      
	glVertex2i (-7,-58);       // Specify line-segment geometry.
	glVertex2i (7,-61);
	glEnd ( );
	glFlush();
	
	glLineWidth(2);  
	glColor3f (1.0, 1.0, 1.0);      // Set line segment color to red.   
	glBegin(GL_LINES);      
	glVertex2i (-7,-61);       // Specify line-segment geometry.
	glVertex2i (7,-64);
	glEnd ( );
	glFlush();
	
	glLineWidth(2);  
	glColor3f (1.0, 1.0, 1.0);      // Set line segment color to red.   
	glBegin(GL_LINES);      
	glVertex2i (-7,-64);       // Specify line-segment geometry.
	glVertex2i (7,-67);
	glEnd ( );
	glFlush();
	
	glColor3f(0.4F, 0.6F,0.8F);
    glBegin(GL_LINE_STRIP);
      glVertex2i(-70,-40);
      glVertex2i(-75,-60);
      glVertex2i(-73,-70);
      glVertex2i(-67,-65);
      glVertex2i(-60,-52);
    glEnd();
    glFlush();
				
	glBegin(GL_POLYGON); //繪製方式 (右腮紅) 
	glColor3f(0.4, 0.9, 0.8); 
	for (int i = 0; i < n; i++)
		glVertex2f(-75+5*cos(2* Pi / n*i), -73+5*sin(2* Pi / n*i));
	glEnd();
	glFlush();
		  
	glBegin(GL_POLYGON); //繪製方式 (右腮紅) 
	glColor3f(1.4, 0.5, 0.2); 
	for (int i = 0; i < n; i++)
		glVertex2f(70+5*cos(2* Pi / n*i), 65+2.5*sin(2* Pi / n*i));
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON); //繪製方式 (腮紅) 
	glColor3f(1.4, 0.5, 0.2); 
	for (int i = 0; i < n; i++)
		glVertex2f(-70+5*cos(2* Pi / n*i), 65+2.5*sin(2 * Pi / n*i));
	glEnd();
	glFlush();
		
	glPointSize(6);
	glBegin(GL_POINTS);
	glColor3f(1.3,0.6,0.3); 
		glVertex2i(5,-100);
		glVertex2i(20,-70);
		glVertex2i(-10,-80);
		glVertex2i(-14,-65);
		//glVertex2i(7,-60);
		glVertex2i(-13,-63);
		glVertex2i(-20,-59);
		glVertex2i(18,-54);
		glVertex2i(31,-96);
		glVertex2i(-26,-96);
		glVertex2i(-24,-103);
		glVertex2i(30,-90);
		glVertex2i(15,-76);
		glVertex2i(16,-73);
		glVertex2i(-19,-67);
	glEnd();
	glFlush();
	
	
}

int main (int argc, char** argv)
{    
	glutInit (&argc, argv);                         // Initialize GLUT.    
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   ////顯示方式    
	glutInitWindowPosition (100, 100);   // 窗口位置   
	glutInitWindowSize (500, 500);      // 窗口大小  
	glutCreateWindow ("HOMEWORK"); // Create display window.    
	init ( );                            // Execute initialization procedure.    
	glutDisplayFunc (lineSegment);       // //調用顯示函數    
	glutMainLoop ( );                    // Display everything and wait.
}
