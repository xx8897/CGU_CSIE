#include <cstdio>
#include <cstdlib>
#include <GL/glut.h>
#include <cmath>
#include <ctime>
#include <iostream>

#include<stdlib.h>
#include<stdio.h>
using namespace std;

float g_fWidth = 700;
float g_fHeight = 700;
float g_fDepth = 100;
float g_fAngle = .0;

int square_width=60;    //九宮格每一格的長寬
int border=30;
int window_y=700;  //視窗的高度
int window_x=700;   //視窗的寬度

int second=-1;   //紀錄過了幾秒
int rand_x; //遮罩的x軸(範圍在9x9宮格內)
int rand_y; //遮罩的y軸(範圍在9x9宮格內)
int rand_row; //遮罩的row
int rand_col; //遮罩的col

int start=0;
int X=40;
int Y=10;
int height=40;
int width=20;
int main_w,w1;

int present_col_choose=-1; //上次選的col
int present_row_choose=-1; //上次選的row

int color9x9[9][9];//存使用者選的答案
int color9x9_display[9][9];//存要顯示給使用者看的9x9宮格
int sudoku_question[9][9];//數獨的題目
int sudoku_answer[9][9];//數獨的正確解答
int score;

bool i=true;														//if i==true 則主選單就會顯示出來 
bool hard_button = false;
bool middle_button = false;
bool easy_button = false;
bool introduction_button = false;
bool timer = false;
bool check_answer = false; 

void createNum(int num,int x,int y)
{
    switch(num)
    {
        case 0:
            glBegin(GL_LINES);
                glVertex2f(x,y+height);
                glVertex2f(x,y);
                glVertex2f(x,y+height);
                glVertex2f(x+width,y+height);
                glVertex2f(x+width,y);
                glVertex2f(x+width,y+height);
                glVertex2f(x+width,y);
                glVertex2f(x,y);
            glEnd();
            break;
        case 1:
            glBegin(GL_LINES);
                glVertex2f(x+width,y);
                glVertex2f(x+width,y+height);
            glEnd();
            break;
        case 2:
            glBegin(GL_LINES);
                glVertex2f(x,y+height);
                glVertex2f(x+width,y+height);
                glVertex2f(x+width,y+height/2);
                glVertex2f(x+width,y+height);
                glVertex2f(x+width,y+height/2);
                glVertex2f(x,y+height/2);
                glVertex2f(x,y+height/2);
                glVertex2f(x,y);
                glVertex2f(x+width,y);
                glVertex2f(x,y);
            glEnd();
            break;
        case 3:
            glBegin(GL_LINES);
                glVertex2f(x,y+height);
                glVertex2f(x+width,y+height);
                glVertex2f(x+width,y);
                glVertex2f(x+width,y+height);
                glVertex2f(x+width,y+height/2);
                glVertex2f(x,y+height/2);
                glVertex2f(x+width,y);
                glVertex2f(x,y);
            glEnd();
            break;
        case 4:
            glBegin(GL_LINES);
                glVertex2f(x,y+height);
                glVertex2f(x,y+height/2);
                glVertex2f(x+width,y);
                glVertex2f(x+width,y+height);
                glVertex2f(x+width,y+height/2);
                glVertex2f(x,y+height/2);
            glEnd();
            break;
        case 5:
            glBegin(GL_LINES);
                glVertex2f(x,y+height);
                glVertex2f(x+width,y+height);
                glVertex2f(x,y+height);
                glVertex2f(x,y+height/2);
                glVertex2f(x+width,y);
                glVertex2f(x+width,y+height/2);
                glVertex2f(x+width,y+height/2);
                glVertex2f(x,y+height/2);
                glVertex2f(x+width,y);
                glVertex2f(x,y);
            glEnd();
            break;
        case 6:
            glBegin(GL_LINES);
                glVertex2f(x,y+height);
                glVertex2f(x+width,y+height);
                glVertex2f(x,y+height);
                glVertex2f(x,y);
                glVertex2f(x+width,y);
                glVertex2f(x+width,y+height/2);
                glVertex2f(x+width,y+height/2);
                glVertex2f(x,y+height/2);
                glVertex2f(x+width,y);
                glVertex2f(x,y);
            glEnd();
            break;
        case 7:
            glBegin(GL_LINES);
                glVertex2f(x,y+height);
                glVertex2f(x,y+height/2);
                glVertex2f(x,y+height);
                glVertex2f(x+width,y+height);
                glVertex2f(x+width,y);
                glVertex2f(x+width,y+height);
            glEnd();
            break;
        case 8:
            glBegin(GL_LINES);
                glVertex2f(x,y+height);
                glVertex2f(x,y);
                glVertex2f(x,y+height);
                glVertex2f(x+width,y+height);
                glVertex2f(x+width,y+height/2);
                glVertex2f(x,y+height/2);
                glVertex2f(x+width,y);
                glVertex2f(x+width,y+height);
                glVertex2f(x+width,y);
                glVertex2f(x,y);
            glEnd();
            break;
        case 9:
            glBegin(GL_LINES);
                glVertex2f(x,y+height);
                glVertex2f(x+width,y+height);
                glVertex2f(x,y+height);
                glVertex2f(x,y+height/2);
                glVertex2f(x+width,y);
                glVertex2f(x+width,y+height);
                glVertex2f(x+width,y+height/2);
                glVertex2f(x,y+height/2);
                glVertex2f(x+width,y);
                glVertex2f(x,y);
            glEnd();
            break;
    }
}

void arra_initial()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(sudoku_question[i][j]!=-1)
                color9x9[i][j]=sudoku_question[i][j];
            else
                color9x9[i][j]=9;
            color9x9_display[i][j]=color9x9[i][j];
        }
    }
}

void question ()    //存題目在三維陣列
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if( (i==0&&j==0) || (i==0&&j==2) || (i==0&&j==4) || (i==0&&j==6) || (i==0&&j==8) || (i==1&&j==1) || (i==1&&j==2) || (i==1&&j==4) || (i==1&&j==6) || (i==1&&j==7) || (i==1&&j==8) || (i==1&&j==6) || (i==2&&j==0) || (i==2&&j==1) || (i==2&&j==3) || (i==2&&j==5) || (i==2&&j==7) || (i==3&&j==0) || (i==3&&j==2) || (i==3&&j==3) || (i==3&&j==4) || (i==3&&j==6) || (i==3&&j==7) || (i==4&&j==1) || (i==4&&j==2) || (i==4&&j==4) || (i==4&&j==5) || (i==4&&j==7) || (i==5&&j==0) || (i==5&&j==1) || (i==5&&j==3) || (i==5&&j==4) || (i==5&&j==6) || (i==5&&j==8) || (i==6&&j==2) || (i==6&&j==3) || (i==6&&j==5) || (i==6&&j==7) || (i==6&&j==8) || (i==7&&j==0)|| (i==7&&j==1) || (i==7&&j==4) || (i==7&&j==6) || (i==7&&j==8) || (i==8&&j==0) || (i==8&&j==2) || (i==8&&j==3) || (i==8&&j==5) || (i==8&&j==6) || (i==8&&j==7))
            //if( (i==0&&j==0) || (i==0&&j==1) ||(i==0&&j==2) || (i==0&&j==3) ||(i==0&&j==4) || (i==0&&j==5) ||(i==0&&j==6) || (i==0&&j==7) ||(i==0&&j==8) || (i==1&&j==0) ||(i==1&&j==1) || (i==1&&j==2) || (i==1&&j==3) ||(i==1&&j==4) ||(i==1&&j==5) || (i==1&&j==6) || (i==1&&j==7) || (i==1&&j==8)|| (i==2&&j==0) || (i==2&&j==1) || (i==2&&j==2) ||(i==2&&j==3) || (i==2&&j==4) ||(i==2&&j==5) ||(i==2&&j==6) || (i==2&&j==7) ||(i==2&&j==8) || (i==3&&j==0) || (i==3&&j==1) || (i==3&&j==2) || (i==3&&j==3) || (i==3&&j==4) ||(i==3&&j==5) ||  (i==3&&j==6) || (i==3&&j==7) || (i==3&&j==8) || (i==4&&j==0) ||(i==4&&j==1) || (i==4&&j==2) || (i==4&&j==3) ||(i==4&&j==4) || (i==4&&j==5) || (i==4&&j==6) ||(i==4&&j==7) || (i==4&&j==8) ||(i==5&&j==0) || (i==5&&j==1) ||(i==5&&j==2) ||  (i==5&&j==3) || (i==5&&j==4) || (i==5&&j==5) || (i==5&&j==6) || (i==5&&j==7) || (i==5&&j==8) ||(i==6&&j==0) ||(i==6&&j==1) || (i==6&&j==2) || (i==6&&j==3) ||(i==6&&j==4) || (i==6&&j==5) || (i==6&&j==6) ||(i==6&&j==7) || (i==6&&j==8) || (i==7&&j==0)|| (i==7&&j==1) || (i==7&&j==2)|| (i==7&&j==3)|| (i==7&&j==4) || (i==7&&j==5)|| (i==7&&j==6) || (i==7&&j==7) || (i==7&&j==8) || (i==8&&j==0) || (i==8&&j==2) || (i==8&&j==0) ||(i==8&&j==1) ||(i==8&&j==2) || (i==8&&j==3) || (i==8&&j==4) || (i==8&&j==5))

				sudoku_question[i][j]=sudoku_answer[i][j];
            else
                sudoku_question[i][j]=-1;
        }
    }
}

void answer()   //產生數獨的答案
{
    int error=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            sudoku_answer[i][j]=9;
        }
    }
    
    for(int j=0;j<9;j++)
    {
        int p=0;
        for(int k=0;k<9;k++)
        {
            error=0;
            int num=rand()%9;
            int ID=0;
            for(int a=0;a<3;a++)
            {
                for(int b=0;b<3;b++)
                {
                    if(sudoku_answer[ID][k]==num||sudoku_answer[j][ID]==num||sudoku_answer[(j/3)*3+a][(k/3)*3+b]==num)
                    {
                        error=1;
                        break;
                    }
                    ID++;
                    if(error==1)
                    {
                        break;
                    }
                }
                if(error==1)
                {
                    break;
                }
            }
            if(error==1)
            {
                if(p>20000)
                {
                    answer();
                    return;
                }
                p++;
                k--;
                continue;
            }
            else
            sudoku_answer[j][k]=num;
        }
    }
    
    for(int i=0;i<9;i++)
    {
    	for(int j=0;j<9;j++)
    	{
    		cout<<sudoku_answer[i][j]<<"  ";
		}
		cout<<endl;
	}
}

void drawText(const char *text , int length , int x , int y)
{
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[200];
	glGetDoublev(GL_PROJECTION_MATRIX,matrix);
	glLoadIdentity();
	glOrtho(0,700,0,700,0,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x,y);
	for(int i=0;i<length;i++)
	{
		if(introduction_button == true || hard_button == true || middle_button == true || easy_button == true)
		{
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15 ,(int)text[i]);
		}
		else
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,(int)text[i]);
		}
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void final_score()
{
	cout<<endl<<"score:  "<<score<<endl;
	
	int min=second/60;
	int sec=second%60;
	
	std::string text;
	std::string text1;
	
	text  = "GET POINT !";
	glColor3f(0,0,0);
	drawText(text.data(),text.size(),270,380);
	
	text1  = "USE   TIME !";
	drawText(text1.data(),text1.size(),270, 240);
	
	glColor3f(0,0,0); 
	if(score == 100)
	{
		createNum(1,270,310);
		createNum(0,320,310);
		createNum(0,370,310);
	}
	else
	{
		createNum(0,270,310);
		createNum(score/10,320,310);
		createNum(score%10,370,310);
	}
	
	createNum(min/10,270,180);
    createNum(min%10,300,180);
    glPointSize(8);
    glBegin(GL_POINTS);
        glVertex2f(335,210);
        glVertex2f(335,190);
    glEnd();
    
    createNum(sec/10,350,180);
    createNum(sec%10,380,180);
    
    glColor3f(0.5,0.6,0); 
    glBegin(GL_POLYGON);
        glVertex2f(285,140);
        glVertex2f(285,100);
        glVertex2f(385,100);
        glVertex2f(385,140);
    glEnd();
    
    glColor3f(0,0,0); 
    text1  = "Back";
	drawText(text1.data(),text1.size(),310, 115);
    
    
}

void check_ans()    //檢查使用者輸入的答案
{
    int check_ans=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(color9x9[i][j]==sudoku_answer[i][j])
            {
                check_ans++;
            }
        }
    }
    
    if(check_ans==81)   //使用者全部答對
    {
    	hard_button = false;
    	middle_button = false;
    	easy_button = false;
    	timer = false;
    	check_answer = true;
    	glClear (GL_COLOR_BUFFER_BIT);
    	final_score();
    }
}

float R,G,B;
void color(int which)
{
    switch (which)
    {
        case 0: //紫
            R=145.00;
            G=44.00;
            B=238.00;
            break;
        case 1: //靛
            R=85.00;
            G=26.00;
            B=139.00;
            break;
        case 2: //深藍
            R=0;
            G=0;
            B=205;
            break;
        case 3: //藍
            R=58.00;
            G=95.00;
            B=205.00;
            break;
        case 4: //深綠
            R=34.00;
            G=139.00;
            B=34.00;
            break;
        case 5: //綠
            R=50.00;
            G=205.00;
            B=50.00;
            break;
        case 6: //黃
            R=255.00;
            G=215.00;
            B=0;
            break;
        case 7: //橙
            R=255.00;
            G=127.00;
            B=0;
            break;
        case 8: //紅
            R=255.00;
            G=0;
            B=0;
            break;
        case 9: //白(清除)
            R=255.00;
            G=255.00;
            B=255.00;
            break;
        case 10: //灰色
            R=192.00;
            G=192.00;
            B=192.00;
            break;
        case 11: //黑色
            R=0;
            G=0;
            B=0;
            break;
    }
}

void drawSquare (int x, int y)  //畫9x9宮格
{
    //-1表示沒有值
    int col_choose=-1;    //座標落在9x9宮格的第幾個col
    int row_choose=-1;    //座標落在9x9宮格的第幾個row
    int color_choose=-1;   //選的顏色
    
    if(x>=border && x<=border+9*square_width && y>=border && y<=border+9*square_width )  //如果按的地方在9x9宮格內
    {
        col_choose=(x-border)/square_width;
        row_choose=(y-border)/square_width;
        
        if(sudoku_question[row_choose][col_choose]==-1 && color9x9_display[row_choose][col_choose]!=11)    //按的是可以改顏色的地方(填空)
        {
            present_col_choose=col_choose;
            present_row_choose=row_choose;
        }
        else    //如果按的是不可以改的地方(題目)
        {
            present_col_choose=-1;
            present_row_choose=-1;
        }
    }
    else if(x>=window_x-border-square_width && x<=window_x-border && y>=border && y<=border+10*square_width)   //如果按的地方在選顏色區塊內
    {
        color_choose=(y-border)/square_width;
        if(present_row_choose!=-1 && present_col_choose!=-1)    //如果上次選的是9x9的格子
        {
            color9x9[present_row_choose][present_col_choose]=color_choose;  //把該格顏色存進去陣列
            color9x9_display[present_row_choose][present_col_choose]=color_choose;  //把該格顏色存進去陣列
        }
    }
    else
    {
        if(x>=border+8*square_width && x<=border+9*square_width && border+9.2*square_width && border+10*square_width)   //如果按的地方是返回 
        {
        	cout<<"back"<<endl;
        	second = -1;
            i= true;
            hard_button = false;
            easy_button = false;
            middle_button = false;
            
	        answer();
	        question();
	        arra_initial();
        }
    }

    for(int i=0; i<9; i++)  //畫九宮格的格子
        for(int j=0; j<9; j++)
        {
            if(col_choose!=-1 && row_choose!=-1 && col_choose==j && row_choose==i && sudoku_question[i][j]==-1 && color9x9_display[i][j]!=11)
            {
                color(10);  //畫灰色格子
            }
            else
                color(color9x9_display[i][j]);
            glColor3f(R/225.00, G/225.00, B/225.00);
            glBegin(GL_POLYGON);
                glVertex2f(border+square_width*j, border+square_width*i);
                glVertex2f(border+square_width+square_width*j, border+square_width*i);
                glVertex2f(border+square_width+square_width*j, border+square_width+square_width*i);
                glVertex2f(border+square_width*j, border+square_width+square_width*i);
            glEnd();
        }
    
    for(int j=0; j<=9; j++) //畫九宮格的線
    {
        int line_width;
        if(j%3==0)
            line_width=3;
        else
            line_width=1;
        glColor3f(0.0, 0.0, 0.0);   //黑色
        
        glLineWidth(line_width);
        glBegin(GL_LINES);
            glVertex2f(border+square_width*j, border);
            glVertex2f(border+square_width*j, border+square_width*9);
        glEnd();
        glBegin(GL_LINES);
            glVertex2f(border, border+square_width*j);
            glVertex2f(border+square_width*9, border+square_width*j);
        glEnd();
    }
    
    for(int j=0; j<=9; j++)  //畫右邊那排9個顏色
    {
        color(j);
        glColor3f(R/255.00, G/255.00, B/255.00);
        glBegin(GL_POLYGON);
            glVertex2f(window_x-border-square_width, border+square_width*j);
            glVertex2f(window_x-border, border+square_width*j);
            glVertex2f(window_x-border, border+square_width+square_width*j);
            glVertex2f(window_x-border-square_width, border+square_width+square_width*j);
        glEnd();
        if(j==9)
        {
            glColor3f(0, 0, 0);
            glLineWidth(2);
            glBegin(GL_LINES);
                glVertex2f(window_x-border-square_width, border+square_width*j);//左下角
                glVertex2f(window_x-border, border+square_width*j); //右下角
                glVertex2f(window_x-border, border+square_width*j); //右下角
                glVertex2f(window_x-border, border+square_width+square_width*j);//右上角
                glVertex2f(window_x-border, border+square_width+square_width*j);//右上角
                glVertex2f(window_x-border-square_width, border+square_width+square_width*j);//左上角
                glVertex2f(window_x-border-square_width, border+square_width+square_width*j);//左上角
                glVertex2f(window_x-border-square_width, border+square_width*j);//左下角
                
                glVertex2f(window_x-border, border+square_width+square_width*j);//右上角
                glVertex2f(window_x-border-square_width, border+square_width*j);//左下角
                glVertex2f(window_x-border-square_width, border+square_width+square_width*j);//左上角
                glVertex2f(window_x-border, border+square_width*j); //右下角
            glEnd();
        }
    }
    
    
	//畫完成按鈕
    glColor3f(0.5,0.25,0);
    glBegin(GL_POLYGON);
        glVertex2f(border+8*square_width, border+9.2*square_width);
        glVertex2f(border+9*square_width, border+9.2*square_width);
        glVertex2f(border+9*square_width, border+10*square_width);
        glVertex2f(border+8*square_width, border+10*square_width);
    glEnd();
    
    std :: string text;
    text  = "BACK";
	glColor3f(1,1,1);
	drawText(text.data(),text.size(),border+8*square_width+13,border+9.2*square_width+15);
    
    glFlush();
}

void introduction()
{
	i=false;
	cout<<"introduction"<<endl;
	cout<<introduction_button<<endl;
	std::string text;
	std::string text1;
	std::string text1_1;
	std::string text1_2;
	std::string text2;
	std::string text2_1;
	std::string text2_2;
	std::string text3;
	std::string text3_1;
	std::string text3_2;
	std::string text4;
	
	text  = "introduction";
	text1 = "Easy : ";
	text1_1 = "Ruler : Simple";
	text1_2 = "Score : After 3 minutes , 5 points will be deducted every 2 minutes ";
	
	text2 = "Middle: ";
	text2_1 = "Ruler : After 3 minutes , the color will be disappeared";
	text2_2 = "Score : After 6 minutes , 5 points will be deducted every 2 minutes ";
	
	text3 = "Hard: ";
	text3_1 = "Ruler : After 2 minutes , the color will be covered";
	text3_2 = "Score : After 9 minutes , 5 points will be deducted every 2 minutes ";
	
	glColor3f(0,0,0);
	drawText(text.data(),text.size(),40,410);
	drawText(text1.data(),text1.size(),40,380);
	drawText(text1_1.data(),text1_1.size(),40,360);
	drawText(text1_2.data(),text1_2.size(),40,340);
	drawText(text2.data(),text2.size(),40,310);
	drawText(text2_1.data(),text2_1.size(),40,290);
	drawText(text2_2.data(),text2_2.size(),40,270);
	drawText(text3.data(),text3.size(),40,240);
	drawText(text3_1.data(),text3_1.size(),40,220);
	drawText(text3_2.data(),text3_2.size(),40,200);
	
	glColor3f(0.5,0.5,0.5);		//introduction 裡面的返回鍵 
	glBegin(GL_POLYGON);
		glVertex2i(550,160);
		glVertex2i(650,160);
		glVertex2i(650,130);
		glVertex2i(550,130);
	glEnd();
	
	glColor3f(1,1,1);
	text4 = "B a c k";
	drawText(text4.data(),text4.size(),570,140);
	
}

struct Hard_Button{
	float Hard_posX;
	float Hard_posY;
	float m_fWidth;
	float m_fHeight;

	bool m_bPressed;
	
	void Render()
	{
		if(i==true)
		{
			glPushMatrix();
			{
				glTranslatef(Hard_posX+m_fWidth/2, Hard_posY+m_fHeight/2, -2.0);
				if( m_bPressed ){
					glScalef(0.9, 0.9, 1.0);
				}
				glScalef (m_fWidth, m_fHeight, 5.0);      
				glutSolidCube(1.0);
			}
			glColor3f(0,0,0);
			std::string text;
			text = "Hard";
			drawText(text.data(),text.size(),Hard_posX+125,Hard_posY+20);
		}
	}
	
	bool OnMouseDown(int mousex, int mousey)
	{
		if(i==true)
		{
			mousey = g_fHeight-mousey;
			if( mousex > Hard_posX && mousex < Hard_posX + m_fWidth && mousey > Hard_posY && mousey < Hard_posY + m_fHeight )
			{
				m_bPressed = true;
				hard_button = true;				//open hard button
				i=false;
				timer = true;
				return true;
			}
			return false;
		}
	}
	void OnMouseUp()
	{
		if(i==true)
		{
			m_bPressed = false;
		}
	}
	
};

struct Middle_Button{
	float Middle_posX;
	float Middle_posY;
	float m_fWidth;
	float m_fHeight;

	bool m_bPressed;
	void Render1()
	{
		if(i==true)
		{
			glPushMatrix();
			{
				glTranslatef(Middle_posX+m_fWidth/2, Middle_posY+m_fHeight/2, -2.0);
				if( m_bPressed ){
					glScalef(0.9, 0.9, 1.0);
				}
				glScalef (m_fWidth, m_fHeight, 5.0);      
				glutSolidCube(1.0);
			}
			glColor3f(0,0,0);
			std::string text;
			text = "Middle";
			drawText(text.data(),text.size(),Middle_posX+115,Middle_posY+20);
		}
	}
	bool OnMouseDown1(int mousex, int mousey){
		mousey = g_fHeight-mousey;
		if( mousex > Middle_posX && mousex < Middle_posX+m_fWidth && mousey > Middle_posY && mousey < Middle_posY+m_fHeight )
		{
			m_bPressed = true;		
			i=false;
			middle_button = true;
			timer = true;
			return true;
		}
		return false;
	}
	void OnMouseUp(){
		m_bPressed = false;
	}
};

struct Easy_Button{
	float Easy_posX;
	float Easy_posY;
	float m_fWidth;
	float m_fHeight;

	bool m_bPressed;
	void Render2()
	{
		if(i==true)
		{
			glPushMatrix();
			{
				glTranslatef(Easy_posX+m_fWidth/2, Easy_posY+m_fHeight/2, -2.0);
				if( m_bPressed ){
					glScalef(0.9, 0.9, 1.0);
				}
				glScalef (m_fWidth, m_fHeight, 5.0);      
				glutSolidCube(1.0);
			}
			glColor3f(0,0,0);
			std::string text;
			text = "Easy";
			drawText(text.data(),text.size(),Easy_posX+125,Easy_posY+20);
		}
	}
	bool OnMouseDown2(int mousex, int mousey)
	{
		mousey = g_fHeight-mousey;
		if( mousex > Easy_posX && mousex < Easy_posX+m_fWidth && mousey > Easy_posY && mousey < Easy_posY+m_fHeight )
		{
			m_bPressed = true;
			i=false;
			easy_button = true;
			timer = true;
			return true;
		}
		return false;
	}
	void OnMouseUp(){
		m_bPressed = false;
	}
};

struct Introduction_Button{
	float Intro_posX;
	float Intro_posY;
	float m_fWidth;
	float m_fHeight;

	bool m_bPressed;
	void Render3()
	{
		if(i==true)
		{
			glPushMatrix();
			{
				glTranslatef(Intro_posX+m_fWidth/2, Intro_posY+m_fHeight/2, -2.0);
				if( m_bPressed ){
					glScalef(0.9, 0.9, 1.0);
				}
				glScalef (m_fWidth, m_fHeight, 5.0);      
				glutSolidCube(1.0);
			}
			glColor3f(0,0,0);
			std::string text;
			text = "Introduction";
			drawText(text.data(),text.size(),Intro_posX+90,Intro_posY+20);
		}
	}
	bool OnMouseDown3(int mousex, int mousey){
		mousey = g_fHeight-mousey;
		if( mousex > Intro_posX && mousex < Intro_posX+m_fWidth && mousey > Intro_posY && mousey < Intro_posY+m_fHeight )
		{
			m_bPressed = true;
			introduction_button = true;
			timer = true;
			introduction();
			return true;
		}
		return false;
	}
	void OnMouseUp(){
		m_bPressed = false;
	}
};

Hard_Button* pBtn;
Middle_Button* pBtn1;
Easy_Button* pBtn2;
Introduction_Button* pBtn3;
const GLfloat pi=3.1415926536f;
const int n=3600;
const float DEG2RAD = 3.14159/180;

int mouse_x;
int mouse_y;

void init(void) {
	srand(0);	
	glClearColor (1.0,1.0,1.0,0.0);//set color of background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,500.0,0.0,500.0);//(coordinate=> left x,right x,buttom y,top y)
    
	glShadeModel (GL_SMOOTH);

	
//buttom hard & position
	pBtn = new Hard_Button;
	pBtn->m_bPressed = false;
	
	pBtn->Hard_posX = 200;
	pBtn->Hard_posY = 180;
	pBtn->m_fWidth  = 300;
	pBtn->m_fHeight = 60;
	
//buttom middle & position
	pBtn1 = new Middle_Button;
	pBtn1->m_bPressed = false;
	
	pBtn1->Middle_posX  = 200;
	pBtn1->Middle_posY  = 265;
	pBtn1->m_fWidth     = 300;
	pBtn1->m_fHeight    = 60;

//buttom easy & position
	pBtn2 = new Easy_Button;
	pBtn2-> m_bPressed = false;

	pBtn2->Easy_posX   = 200;
	pBtn2->Easy_posY   = 350;
	pBtn2->m_fWidth    = 300;
	pBtn2->m_fHeight   = 60;

//buttom introduction & position
	pBtn3 = new Introduction_Button;
	pBtn3-> m_bPressed = false;

	pBtn3->Intro_posX  = 200;
	pBtn3->Intro_posY  = 95;
	pBtn3->m_fWidth    = 300;
	pBtn3->m_fHeight   = 60;
	
	answer();
    question ();
    arra_initial();

}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	
	if(i == true || introduction_button == true)
	{
		//background
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (0,0);
			glVertex2i (0,700);
			glVertex2i (700,700);
		glEnd();	
		
		glColor3f (0.96, 0.96, 0.45);
		glBegin (GL_POLYGON);
			glVertex2i (0,0);
			glVertex2i (700,700);
			glVertex2i (700,0);
		glEnd();
			
		//buttom1
		glColor3f (0.5, 0.5, 0.5);//color of buttom
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, g_fWidth, 0, g_fHeight, 0, g_fDepth);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		pBtn->Render();
		//buttom2
		glColor3f (0.5, 0.5, 0.5);//color of buttom
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, g_fWidth, 0, g_fHeight, 0, g_fDepth);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		pBtn1->Render1();
		//buttom3
		glColor3f (0.5, 0.5, 0.5);//color of buttom
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, g_fWidth, 0, g_fHeight, 0, g_fDepth);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		pBtn2->Render2();
		//buttom introduction
		glColor3f (0.5, 0.5, 0.5);//color of buttom
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, g_fWidth, 0, g_fHeight, 0, g_fDepth);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		pBtn3->Render3();	
	
	//s
		float xradius=44;
		float yradius=55;
	    glBegin(GL_POLYGON);
	    glColor3f(1.0,0.0,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(87+cos(degInRad)*xradius,520+sin(degInRad)*yradius);
		}
		glEnd();
		//squire
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (85,525);
			glVertex2i (132,525);
			glVertex2i (132,543);
			glVertex2i (85,543);
		glEnd();
		
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (85,495);
			glVertex2i (43,495);
			glVertex2i (43,510);
			glVertex2i (85,510);
		glEnd();
		
		glBegin (GL_POLYGON);
			glVertex2i (40,515);
			glVertex2i (85,515);
			glVertex2i (85,510);
			glVertex2i (40,510);
		glEnd();
		//triangel
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (85,525);
			glVertex2i (133,525);
			glVertex2i (133,510);
		glEnd();
		
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (85,515);
			glVertex2i (40,530);
			glVertex2i (40,515);
		glEnd();
		//circle
		float xsradius=4;
		float ysradius=4;
	    glBegin(GL_POLYGON);
	   glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(48+cos(degInRad)*xsradius,553+sin(degInRad)*ysradius);
			glVertex2f(54+cos(degInRad)*xsradius,532+sin(degInRad)*ysradius);
			glVertex2f(54+cos(degInRad)*xsradius,534+sin(degInRad)*ysradius);
			glVertex2f(54+cos(degInRad)*xsradius,536+sin(degInRad)*ysradius);
			glVertex2f(56+cos(degInRad)*xsradius,530+sin(degInRad)*ysradius);
			glVertex2f(44+cos(degInRad)*xsradius,530+sin(degInRad)*ysradius);
			glVertex2f(44+cos(degInRad)*xsradius,538+sin(degInRad)*ysradius);
			glVertex2f(48+cos(degInRad)*xsradius,543+sin(degInRad)*ysradius);
		}
		glEnd();
		
		glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(51+cos(degInRad)*xsradius,555+sin(degInRad)*ysradius);
			glVertex2f(50+cos(degInRad)*xsradius,553+sin(degInRad)*ysradius);
			glVertex2f(48+cos(degInRad)*xsradius,543+sin(degInRad)*ysradius);
			glVertex2f(52+cos(degInRad)*xsradius,525+sin(degInRad)*ysradius);
		}
		glEnd();
		
		glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(127+cos(degInRad)*xsradius,508+sin(degInRad)*ysradius);
			glVertex2f(127+cos(degInRad)*xsradius,507+sin(degInRad)*ysradius);
		}
		glEnd();
		
		float xs1radius=25;
		float ys1radius=24;
	    glBegin(GL_POLYGON);
	    glColor3f(1.0,0.0,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(75+cos(degInRad)*xs1radius,542+sin(degInRad)*ys1radius);
		}
		glEnd();
		    
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(102+cos(degInRad)*xs1radius,500+sin(degInRad)*ys1radius);
		}
		glEnd();
		
		//upCircle
		float xupradius=20;
		float yupradius=20;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(87+cos(degInRad)*xupradius,544+sin(degInRad)*yupradius);
		}
		glEnd();
		//downCircle
		float xdoradius=20;
		float ydoradius=20;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(87+cos(degInRad)*xdoradius,497+sin(degInRad)*ydoradius);
		}
		glEnd();
		
	//u
		//big circle
		float x1radius=42;
		float y1radius=50;
	    glBegin(GL_POLYGON);
	    glColor3f(1.0,0.5,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(178+cos(degInRad)*x1radius,522+sin(degInRad)*y1radius);
		}
		glEnd();
		//squire
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (134,498);
			glVertex2i (226,498);
			glVertex2i (226,573);
			glVertex2i (134,573);
		glEnd();
		
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (216,500);
			glVertex2i (206,478);
			glVertex2i (206,535);
			glVertex2i (216,575);
		glEnd();
		//small circle
		float xu1radius=18;
		float yu1radius=25;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(178+cos(degInRad)*xu1radius,510+sin(degInRad)*yu1radius);
		}
		glEnd();
		
		glColor3f (1.0, 0.5, 0.0);
		glBegin (GL_POLYGON);
			glVertex2i (142,492);
			glVertex2i (161,492);
			glVertex2i (161,540);
			glVertex2i (142,540);
		glEnd();
		
		glColor3f (1.0, 0.5, 0.0);
		glBegin (GL_POLYGON);
			glVertex2i (196,470);
			glVertex2i (216,470);
			glVertex2i (216,540);
			glVertex2i (196,540);
		glEnd();
		//sscircle
		float x41radius=3;
		float y41radius=3;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(141+cos(degInRad)*x41radius,491+sin(degInRad)*y41radius);
		}
		glEnd();
	//d
		float x2radius=31;
		float y2radius=35;
	    glBegin(GL_POLYGON);
	    glColor3f(1.0,0.8,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(263+cos(degInRad)*x2radius,505+sin(degInRad)*y2radius);
		}
		glEnd();
		//
		float xdradius=16;
		float ydradius=21;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(266+cos(degInRad)*xdradius,505+sin(degInRad)*ydradius);
		}
		glEnd();
		//
		glColor3f (1.0, 0.8, 0.0);
		glBegin (GL_POLYGON);
			glVertex2i (286,470);
			glVertex2i (306,470);
			glVertex2i (306,575);
			glVertex2i (286,575);
		glEnd();	
	//o
		float x3radius=40;
		float y3radius=40;
	    glBegin(GL_POLYGON);
	    glColor3f(0.2,0.8,0.2);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(362+cos(degInRad)*x3radius,505+sin(degInRad)*y3radius);
		}
		glEnd();	
		float xcradius=21;
		float ycradius=25;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(362+cos(degInRad)*xcradius,505+sin(degInRad)*ycradius);
		}
		glEnd();
	//k
		glColor3f (0.2, 0.4, 0.8);
		glBegin (GL_POLYGON);
			glVertex2i (418,470);
			glVertex2i (438,470);
			glVertex2i (438,575);
			glVertex2i (418,575);
		glEnd();
		
		glBegin (GL_POLYGON);
			glVertex2i (488,540);
			glVertex2i (438,497);
			glVertex2i (438,520);
			glVertex2i (463,540);
		glEnd();
		
		glBegin (GL_POLYGON);
			glVertex2i (460,470);
			glVertex2i (483,470);
			glVertex2i (458,520);
			glVertex2i (443,510);
		glEnd();
	//u
		//big circle
		float x5radius=42;
		float y5radius=50;
	    glBegin(GL_POLYGON);
	    glColor3f(0.0,0.0,0.6);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(537+cos(degInRad)*x5radius,522+sin(degInRad)*y5radius);
		}
		glEnd();
		//squire
		glColor3f (0.96, 0.96, 0.45);
		glBegin (GL_POLYGON);
			glVertex2i (493,498);
			glVertex2i (585,498);
			glVertex2i (585,573);
			glVertex2i (493,573);
		glEnd();	
		
		glColor3f (0.96, 0.96, 0.45);
		glBegin (GL_POLYGON);
			glVertex2i (555,498);
			glVertex2i (585,498);
			glVertex2i (585,525);
		glEnd();
		
		glColor3f (0.96, 0.96, 0.45);
		glBegin (GL_POLYGON);
			glVertex2i (575,500);
			glVertex2i (565,478);
			glVertex2i (565,535);
			glVertex2i (575,575);
		glEnd();
		//small circle
		float xuradius=18;
		float yuradius=25;
	    glBegin(GL_POLYGON);
	    glColor3f (0.96, 0.96, 0.45);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(537+cos(degInRad)*xuradius,510+sin(degInRad)*yuradius);
		}
		glEnd();
		
		//squire
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (493,498);
			glVertex2i (496,498);
			glVertex2i (572,573);
			glVertex2i (493,573);
		glEnd();
		
		glColor3f (0.0, 0.0, 0.6);
		glBegin (GL_POLYGON);
			glVertex2i (501,492);
			glVertex2i (520,492);
			glVertex2i (520,540);
			glVertex2i (501,540);
		glEnd();
		
		glColor3f (0.0, 0.0, 0.6);
		glBegin (GL_POLYGON);
			glVertex2i (555,470);
			glVertex2i (575,470);
			glVertex2i (575,540);
			glVertex2i (555,540);
		glEnd();
		//sscircle
		float x4radius=3;
		float y4radius=3;
	    glBegin(GL_POLYGON);
	    glColor3f (0.96, 0.96, 0.45);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(500+cos(degInRad)*x4radius,491+sin(degInRad)*y4radius);
		}
		glEnd();
	
	//!
		glColor3f (0.57, 0.17, 0.93);
		glBegin (GL_POLYGON);
			glVertex2i (593,575);
			glVertex2i (596,495);
			glVertex2i (613,495);
			glVertex2i (616,575);
		glEnd();	
		
		glColor3f (0.57, 0.17, 0.93);
		glBegin (GL_POLYGON);
			glVertex2i (596,470);
			glVertex2i (596,488);
			glVertex2i (613,488);
			glVertex2i (613,470);
		glEnd();	
		glFlush();
		glutSwapBuffers();
	
	}
	

	
	if(introduction_button == true)
	{
		introduction();
	}
	
	else if(hard_button==true || middle_button==true || easy_button==true)
	{
		drawSquare(mouse_x, mouse_y);
	}
	
	else if(check_answer == true)
	{
		//background
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (0,0);
			glVertex2i (0,700);
			glVertex2i (700,700);
		glEnd();	
		
		glColor3f (0.96, 0.96, 0.45);
		glBegin (GL_POLYGON);
			glVertex2i (0,0);
			glVertex2i (700,700);
			glVertex2i (700,0);
		glEnd();
		
		//s
		float xradius=44;
		float yradius=55;
	    glBegin(GL_POLYGON);
	    glColor3f(1.0,0.0,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(87+cos(degInRad)*xradius,520+sin(degInRad)*yradius);
		}
		glEnd();
		//squire
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (85,525);
			glVertex2i (132,525);
			glVertex2i (132,543);
			glVertex2i (85,543);
		glEnd();
		
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (85,495);
			glVertex2i (43,495);
			glVertex2i (43,510);
			glVertex2i (85,510);
		glEnd();
		
		glBegin (GL_POLYGON);
			glVertex2i (40,515);
			glVertex2i (85,515);
			glVertex2i (85,510);
			glVertex2i (40,510);
		glEnd();
		//triangel
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (85,525);
			glVertex2i (133,525);
			glVertex2i (133,510);
		glEnd();
		
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (85,515);
			glVertex2i (40,530);
			glVertex2i (40,515);
		glEnd();
		//circle
		float xsradius=4;
		float ysradius=4;
	    glBegin(GL_POLYGON);
	   glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(48+cos(degInRad)*xsradius,553+sin(degInRad)*ysradius);
			glVertex2f(54+cos(degInRad)*xsradius,532+sin(degInRad)*ysradius);
			glVertex2f(54+cos(degInRad)*xsradius,534+sin(degInRad)*ysradius);
			glVertex2f(54+cos(degInRad)*xsradius,536+sin(degInRad)*ysradius);
			glVertex2f(56+cos(degInRad)*xsradius,530+sin(degInRad)*ysradius);
			glVertex2f(44+cos(degInRad)*xsradius,530+sin(degInRad)*ysradius);
			glVertex2f(44+cos(degInRad)*xsradius,538+sin(degInRad)*ysradius);
			glVertex2f(48+cos(degInRad)*xsradius,543+sin(degInRad)*ysradius);
		}
		glEnd();
		
		glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(51+cos(degInRad)*xsradius,555+sin(degInRad)*ysradius);
			glVertex2f(50+cos(degInRad)*xsradius,553+sin(degInRad)*ysradius);
			glVertex2f(48+cos(degInRad)*xsradius,543+sin(degInRad)*ysradius);
			glVertex2f(52+cos(degInRad)*xsradius,525+sin(degInRad)*ysradius);
		}
		glEnd();
		
		glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(127+cos(degInRad)*xsradius,508+sin(degInRad)*ysradius);
			glVertex2f(127+cos(degInRad)*xsradius,507+sin(degInRad)*ysradius);
		}
		glEnd();
		
		float xs1radius=25;
		float ys1radius=24;
	    glBegin(GL_POLYGON);
	    glColor3f(1.0,0.0,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(75+cos(degInRad)*xs1radius,542+sin(degInRad)*ys1radius);
		}
		glEnd();
		    
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(102+cos(degInRad)*xs1radius,500+sin(degInRad)*ys1radius);
		}
		glEnd();
		
		//upCircle
		float xupradius=20;
		float yupradius=20;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(87+cos(degInRad)*xupradius,544+sin(degInRad)*yupradius);
		}
		glEnd();
		//downCircle
		float xdoradius=20;
		float ydoradius=20;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(87+cos(degInRad)*xdoradius,497+sin(degInRad)*ydoradius);
		}
		glEnd();
		
	//u
		//big circle
		float x1radius=42;
		float y1radius=50;
	    glBegin(GL_POLYGON);
	    glColor3f(1.0,0.5,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(178+cos(degInRad)*x1radius,522+sin(degInRad)*y1radius);
		}
		glEnd();
		//squire
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (134,498);
			glVertex2i (226,498);
			glVertex2i (226,573);
			glVertex2i (134,573);
		glEnd();
		
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (216,500);
			glVertex2i (206,478);
			glVertex2i (206,535);
			glVertex2i (216,575);
		glEnd();
		//small circle
		float xu1radius=18;
		float yu1radius=25;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(178+cos(degInRad)*xu1radius,510+sin(degInRad)*yu1radius);
		}
		glEnd();
		
		glColor3f (1.0, 0.5, 0.0);
		glBegin (GL_POLYGON);
			glVertex2i (142,492);
			glVertex2i (161,492);
			glVertex2i (161,540);
			glVertex2i (142,540);
		glEnd();
		
		glColor3f (1.0, 0.5, 0.0);
		glBegin (GL_POLYGON);
			glVertex2i (196,470);
			glVertex2i (216,470);
			glVertex2i (216,540);
			glVertex2i (196,540);
		glEnd();
		//sscircle
		float x41radius=3;
		float y41radius=3;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(141+cos(degInRad)*x41radius,491+sin(degInRad)*y41radius);
		}
		glEnd();
	//d
		float x2radius=31;
		float y2radius=35;
	    glBegin(GL_POLYGON);
	    glColor3f(1.0,0.8,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(263+cos(degInRad)*x2radius,505+sin(degInRad)*y2radius);
		}
		glEnd();
		//
		float xdradius=16;
		float ydradius=21;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(266+cos(degInRad)*xdradius,505+sin(degInRad)*ydradius);
		}
		glEnd();
		//
		glColor3f (1.0, 0.8, 0.0);
		glBegin (GL_POLYGON);
			glVertex2i (286,470);
			glVertex2i (306,470);
			glVertex2i (306,575);
			glVertex2i (286,575);
		glEnd();	
	//o
		float x3radius=40;
		float y3radius=40;
	    glBegin(GL_POLYGON);
	    glColor3f(0.2,0.8,0.2);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(362+cos(degInRad)*x3radius,505+sin(degInRad)*y3radius);
		}
		glEnd();	
		float xcradius=21;
		float ycradius=25;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(362+cos(degInRad)*xcradius,505+sin(degInRad)*ycradius);
		}
		glEnd();
	//k
		glColor3f (0.2, 0.4, 0.8);
		glBegin (GL_POLYGON);
			glVertex2i (418,470);
			glVertex2i (438,470);
			glVertex2i (438,575);
			glVertex2i (418,575);
		glEnd();
		
		glBegin (GL_POLYGON);
			glVertex2i (488,540);
			glVertex2i (438,497);
			glVertex2i (438,520);
			glVertex2i (463,540);
		glEnd();
		
		glBegin (GL_POLYGON);
			glVertex2i (460,470);
			glVertex2i (483,470);
			glVertex2i (458,520);
			glVertex2i (443,510);
		glEnd();
	//u
		//big circle
		float x5radius=42;
		float y5radius=50;
	    glBegin(GL_POLYGON);
	    glColor3f(0.0,0.0,0.6);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(537+cos(degInRad)*x5radius,522+sin(degInRad)*y5radius);
		}
		glEnd();
		//squire
		glColor3f (0.96, 0.96, 0.45);
		glBegin (GL_POLYGON);
			glVertex2i (493,498);
			glVertex2i (585,498);
			glVertex2i (585,573);
			glVertex2i (493,573);
		glEnd();	
		
		glColor3f (0.96, 0.96, 0.45);
		glBegin (GL_POLYGON);
			glVertex2i (555,498);
			glVertex2i (585,498);
			glVertex2i (585,525);
		glEnd();
		
		glColor3f (0.96, 0.96, 0.45);
		glBegin (GL_POLYGON);
			glVertex2i (575,500);
			glVertex2i (565,478);
			glVertex2i (565,535);
			glVertex2i (575,575);
		glEnd();
		//small circle
		float xuradius=18;
		float yuradius=25;
	    glBegin(GL_POLYGON);
	    glColor3f (0.96, 0.96, 0.45);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(537+cos(degInRad)*xuradius,510+sin(degInRad)*yuradius);
		}
		glEnd();
		
		//squire
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (493,498);
			glVertex2i (496,498);
			glVertex2i (572,573);
			glVertex2i (493,573);
		glEnd();
		
		glColor3f (0.0, 0.0, 0.6);
		glBegin (GL_POLYGON);
			glVertex2i (501,492);
			glVertex2i (520,492);
			glVertex2i (520,540);
			glVertex2i (501,540);
		glEnd();
		
		glColor3f (0.0, 0.0, 0.6);
		glBegin (GL_POLYGON);
			glVertex2i (555,470);
			glVertex2i (575,470);
			glVertex2i (575,540);
			glVertex2i (555,540);
		glEnd();
		//sscircle
		float x4radius=3;
		float y4radius=3;
	    glBegin(GL_POLYGON);
	    glColor3f (0.96, 0.96, 0.45);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(500+cos(degInRad)*x4radius,491+sin(degInRad)*y4radius);
		}
		glEnd();
	
	//!
		glColor3f (0.57, 0.17, 0.93);
		glBegin (GL_POLYGON);
			glVertex2i (593,575);
			glVertex2i (596,495);
			glVertex2i (613,495);
			glVertex2i (616,575);
		glEnd();	
		
		glColor3f (0.57, 0.17, 0.93);
		glBegin (GL_POLYGON);
			glVertex2i (596,470);
			glVertex2i (596,488);
			glVertex2i (613,488);
			glVertex2i (613,470);
		glEnd();	
		
		final_score();
	}
	
	glFlush();
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
	int struct_y;
	struct_y = y;
	y = window_y-y;
	
	if(i == true)
	{
		if(button==GLUT_LEFT_BUTTON)
		{
			switch(state)
			{
				case GLUT_DOWN:
					cout<<"mouse  x: "<<x<<" y: "<<y<<endl;
					printf("\n");
					if( pBtn->OnMouseDown(x, struct_y) )
						g_fAngle += 2.0;
					else if( pBtn1->OnMouseDown1(x, struct_y) )
						g_fAngle += 2.0;
					else if( pBtn2->OnMouseDown2(x, struct_y) )
						g_fAngle += 2.0;
					else if( pBtn3->OnMouseDown3(x, struct_y) )
						g_fAngle += 2.0;
					break;
		
				case GLUT_UP:
					pBtn->OnMouseUp();
					pBtn1->OnMouseUp();
					pBtn2->OnMouseUp();
					pBtn3->OnMouseUp();
					break;
			}
		}
	}
	
	if(i==false && introduction_button == false)
	{
	    mouse_x=x;
	    mouse_y=y;
	    if(button==GLUT_LEFT_BUTTON && state== GLUT_DOWN)
	    {
	        drawSquare(x, y);
	    }
	}
	
	if(introduction_button == true)							//進入到introduction 則introduction_button == true && i == false 
	{
		if(button==GLUT_LEFT_BUTTON)
		{
			if(state == GLUT_DOWN)
			{
				if(x>=550 && x<=650 && y>=130 && y<=160) 
				{
						cout<<"back click!"<<endl;
						i = true;
						introduction_button = false;
				}  
			} 
		}
	}
	
	if(check_answer == true)
	{
		if(button==GLUT_LEFT_BUTTON)
		{
			if(state == GLUT_DOWN)
			{
				if(x>=285 && x<=385 && y>=100 && y<=140) 
				{
						i=true;
						easy_button = false;
						middle_button = false;
						hard_button = false;
						check_answer = false;
						timer = false;
						introduction_button = false;
						
						for(int i=0;i<9;i++)
						{
							for(int j=0;j<9;j++)
							{
								color9x9[i][j]=0;
							}
						}
						
						answer();
				        question();
				        arra_initial();
				}  
			} 
		}
	}
	
	glutPostRedisplay();
}

void make_mask()    //做黑色遮罩遮住題目			//大師 
{
	int sub_score=540;
	//int sub_score=5;
	if(second>=sub_score)
	{
		if(second==sub_score)
		{
			score=100-5;						//分數  (終極版)
		}
		else
		{
			score=95-((second-sub_score)/120)*5;
		}
			
		cout<<score;
	}
	else
	{
		score=100;
		cout<<score;
	}
	
    if(second%5==0 && second >0)
    {
        int qus_num=0;//算題目還有幾格能遮
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
            {
                if(sudoku_question[i][j]!=-1 && color9x9_display[i][j]!=11) //題目不為空的地方&&顯示不為黑色的地方
                    qus_num++;
            }
        if(qus_num>0)  //如果使用者有回答至少一個
        {
            while(1)
            {
                rand_row=rand()%(8-0+1)+0;
                rand_col=rand()%(8-0+1)+0;
                
                if(sudoku_question[rand_row][rand_col]==-1 || color9x9_display[rand_row][rand_col]==11)   //如果選出來的格子不是題目格子||那格顯示為黑色
                    continue;
                else
                {
                    color9x9_display[rand_row][rand_col]=11;  //把該格顏色改成黑色
                    break;
                }
            }
            drawSquare(present_col_choose*square_width+border, present_row_choose*square_width+border);
            //drawSquare(mouse_x, mouse_y);
        }
    }
}

void make_delete()    //把使用者答的答案刪掉		//困難 
{
	int sub_score=360;
	//int sub_score=5;
	if(second>=sub_score)
	{
		if(second==sub_score)
		{
			score=100-5;						//分數  (困難版)
		}
		else
		{
			score=95-((second-sub_score)/120)*5;
		}
			
		cout<<score;
	}
	else
	{
		score=100;
		cout<<score;
	}
	
    if(second%5==0 && second >0)
    {
        int ans_num=0;//算使用者看到的總共有幾格有顏色
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
            {
                if(sudoku_question[i][j]==-1 && color9x9_display[i][j]!=9)
                    ans_num++;
            }
        if(ans_num>0)  //如果使用者有回答至少一個
        {
            while(1)
            {
                rand_row=rand()%(8-0+1)+0;
                rand_col=rand()%(8-0+1)+0;
                
                if(sudoku_question[rand_row][rand_col]!=-1)   //如果選出來的格子是題目格子
                    continue;
                else if(color9x9_display[rand_row][rand_col]==9)   //如果選出來的格子選出的格子是空的
                    continue;
                else
                {
                    color9x9[rand_row][rand_col]=9;  //把該格顏色改成白色
                    color9x9_display[rand_row][rand_col]=9;  //把該格顏色改成白色
					break;
                }
            }
            drawSquare(present_col_choose*square_width+border, present_row_choose*square_width+border);
            //drawSquare(mouse_x, mouse_y);

        }
    }
}

void DrawMin(int min)
{
    createNum(min/10,X,Y);
    createNum(min%10,X+width*5/4,Y);
    glPointSize(8);
    glBegin(GL_POINTS);
        glVertex2f(X+width*3,Y+height/4);
        glVertex2f(X+width*3,Y+3*height/4);
    glEnd();
}

void DrawSec(int sec)
{
    createNum(sec/10,X+width*15/4,Y);
    createNum(sec%10,X+width*5,Y);
}
    
void DrawTimer (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    if(i==false && introduction_button == false && timer == true)
    {
	    int min=second/60;
	    int sec=second%60;
	    glColor3f(0.0,0.0,0.0);
	    glLineWidth(2);
    	DrawMin(min);
	    DrawSec(sec);
	    start++;	
	}
    
    glFlush();
}

void timerProc(int id)
{
	if(i==false && introduction_button == false && check_answer == false)
	{
		second++;	
	}

    glutSetWindow(main_w);
    
    if(middle_button == true)
    {
    	make_delete();
	}
    
    else if(hard_button == true)
    {
    	make_mask();
	}
	
	else
	{
		int sub_score=180;
		//int sub_score=5;
		if(second>=sub_score)
		{
			if(second==sub_score)
			{
				score=100-5;						//分數  (困難版)
			}
			else
			{
				score=95-((second-sub_score)/120)*5;
			}
				
			cout<<score;
			}
			else
			{
				score=100;
				cout<<score;
			}
	}
	
	check_ans();
	if(check_answer == true && i == false)
	{
		//background
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (0,0);
			glVertex2i (0,700);
			glVertex2i (700,700);
		glEnd();	
		
		glColor3f (0.96, 0.96, 0.45);
		glBegin (GL_POLYGON);
			glVertex2i (0,0);
			glVertex2i (700,700);
			glVertex2i (700,0);
		glEnd();
		
		//s
		float xradius=44;
		float yradius=55;
	    glBegin(GL_POLYGON);
	    glColor3f(1.0,0.0,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(87+cos(degInRad)*xradius,520+sin(degInRad)*yradius);
		}
		glEnd();
		//squire
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (85,525);
			glVertex2i (132,525);
			glVertex2i (132,543);
			glVertex2i (85,543);
		glEnd();
		
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (85,495);
			glVertex2i (43,495);
			glVertex2i (43,510);
			glVertex2i (85,510);
		glEnd();
		
		glBegin (GL_POLYGON);
			glVertex2i (40,515);
			glVertex2i (85,515);
			glVertex2i (85,510);
			glVertex2i (40,510);
		glEnd();
		//triangel
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (85,525);
			glVertex2i (133,525);
			glVertex2i (133,510);
		glEnd();
		
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (85,515);
			glVertex2i (40,530);
			glVertex2i (40,515);
		glEnd();
		//circle
		float xsradius=4;
		float ysradius=4;
	    glBegin(GL_POLYGON);
	   glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(48+cos(degInRad)*xsradius,553+sin(degInRad)*ysradius);
			glVertex2f(54+cos(degInRad)*xsradius,532+sin(degInRad)*ysradius);
			glVertex2f(54+cos(degInRad)*xsradius,534+sin(degInRad)*ysradius);
			glVertex2f(54+cos(degInRad)*xsradius,536+sin(degInRad)*ysradius);
			glVertex2f(56+cos(degInRad)*xsradius,530+sin(degInRad)*ysradius);
			glVertex2f(44+cos(degInRad)*xsradius,530+sin(degInRad)*ysradius);
			glVertex2f(44+cos(degInRad)*xsradius,538+sin(degInRad)*ysradius);
			glVertex2f(48+cos(degInRad)*xsradius,543+sin(degInRad)*ysradius);
		}
		glEnd();
		
		glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(51+cos(degInRad)*xsradius,555+sin(degInRad)*ysradius);
			glVertex2f(50+cos(degInRad)*xsradius,553+sin(degInRad)*ysradius);
			glVertex2f(48+cos(degInRad)*xsradius,543+sin(degInRad)*ysradius);
			glVertex2f(52+cos(degInRad)*xsradius,525+sin(degInRad)*ysradius);
		}
		glEnd();
		
		glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(127+cos(degInRad)*xsradius,508+sin(degInRad)*ysradius);
			glVertex2f(127+cos(degInRad)*xsradius,507+sin(degInRad)*ysradius);
		}
		glEnd();
		
		float xs1radius=25;
		float ys1radius=24;
	    glBegin(GL_POLYGON);
	    glColor3f(1.0,0.0,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(75+cos(degInRad)*xs1radius,542+sin(degInRad)*ys1radius);
		}
		glEnd();
		    
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(102+cos(degInRad)*xs1radius,500+sin(degInRad)*ys1radius);
		}
		glEnd();
		
		//upCircle
		float xupradius=20;
		float yupradius=20;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(87+cos(degInRad)*xupradius,544+sin(degInRad)*yupradius);
		}
		glEnd();
		//downCircle
		float xdoradius=20;
		float ydoradius=20;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(87+cos(degInRad)*xdoradius,497+sin(degInRad)*ydoradius);
		}
		glEnd();
		
	//u
		//big circle
		float x1radius=42;
		float y1radius=50;
	    glBegin(GL_POLYGON);
	    glColor3f(1.0,0.5,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(178+cos(degInRad)*x1radius,522+sin(degInRad)*y1radius);
		}
		glEnd();
		//squire
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (134,498);
			glVertex2i (226,498);
			glVertex2i (226,573);
			glVertex2i (134,573);
		glEnd();
		
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (216,500);
			glVertex2i (206,478);
			glVertex2i (206,535);
			glVertex2i (216,575);
		glEnd();
		//small circle
		float xu1radius=18;
		float yu1radius=25;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(178+cos(degInRad)*xu1radius,510+sin(degInRad)*yu1radius);
		}
		glEnd();
		
		glColor3f (1.0, 0.5, 0.0);
		glBegin (GL_POLYGON);
			glVertex2i (142,492);
			glVertex2i (161,492);
			glVertex2i (161,540);
			glVertex2i (142,540);
		glEnd();
		
		glColor3f (1.0, 0.5, 0.0);
		glBegin (GL_POLYGON);
			glVertex2i (196,470);
			glVertex2i (216,470);
			glVertex2i (216,540);
			glVertex2i (196,540);
		glEnd();
		//sscircle
		float x41radius=3;
		float y41radius=3;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(141+cos(degInRad)*x41radius,491+sin(degInRad)*y41radius);
		}
		glEnd();
	//d
		float x2radius=31;
		float y2radius=35;
	    glBegin(GL_POLYGON);
	    glColor3f(1.0,0.8,0.0);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(263+cos(degInRad)*x2radius,505+sin(degInRad)*y2radius);
		}
		glEnd();
		//
		float xdradius=16;
		float ydradius=21;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(266+cos(degInRad)*xdradius,505+sin(degInRad)*ydradius);
		}
		glEnd();
		//
		glColor3f (1.0, 0.8, 0.0);
		glBegin (GL_POLYGON);
			glVertex2i (286,470);
			glVertex2i (306,470);
			glVertex2i (306,575);
			glVertex2i (286,575);
		glEnd();	
	//o
		float x3radius=40;
		float y3radius=40;
	    glBegin(GL_POLYGON);
	    glColor3f(0.2,0.8,0.2);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(362+cos(degInRad)*x3radius,505+sin(degInRad)*y3radius);
		}
		glEnd();	
		float xcradius=21;
		float ycradius=25;
	    glBegin(GL_POLYGON);
	    glColor3f (0.45, 0.82, 0.96);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(362+cos(degInRad)*xcradius,505+sin(degInRad)*ycradius);
		}
		glEnd();
	//k
		glColor3f (0.2, 0.4, 0.8);
		glBegin (GL_POLYGON);
			glVertex2i (418,470);
			glVertex2i (438,470);
			glVertex2i (438,575);
			glVertex2i (418,575);
		glEnd();
		
		glBegin (GL_POLYGON);
			glVertex2i (488,540);
			glVertex2i (438,497);
			glVertex2i (438,520);
			glVertex2i (463,540);
		glEnd();
		
		glBegin (GL_POLYGON);
			glVertex2i (460,470);
			glVertex2i (483,470);
			glVertex2i (458,520);
			glVertex2i (443,510);
		glEnd();
	//u
		//big circle
		float x5radius=42;
		float y5radius=50;
	    glBegin(GL_POLYGON);
	    glColor3f(0.0,0.0,0.6);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(537+cos(degInRad)*x5radius,522+sin(degInRad)*y5radius);
		}
		glEnd();
		//squire
		glColor3f (0.96, 0.96, 0.45);
		glBegin (GL_POLYGON);
			glVertex2i (493,498);
			glVertex2i (585,498);
			glVertex2i (585,573);
			glVertex2i (493,573);
		glEnd();	
		
		glColor3f (0.96, 0.96, 0.45);
		glBegin (GL_POLYGON);
			glVertex2i (555,498);
			glVertex2i (585,498);
			glVertex2i (585,525);
		glEnd();
		
		glColor3f (0.96, 0.96, 0.45);
		glBegin (GL_POLYGON);
			glVertex2i (575,500);
			glVertex2i (565,478);
			glVertex2i (565,535);
			glVertex2i (575,575);
		glEnd();
		//small circle
		float xuradius=18;
		float yuradius=25;
	    glBegin(GL_POLYGON);
	    glColor3f (0.96, 0.96, 0.45);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(537+cos(degInRad)*xuradius,510+sin(degInRad)*yuradius);
		}
		glEnd();
		
		//squire
		glColor3f (0.45, 0.82, 0.96);
		glBegin (GL_POLYGON);
			glVertex2i (493,498);
			glVertex2i (496,498);
			glVertex2i (572,573);
			glVertex2i (493,573);
		glEnd();
		
		glColor3f (0.0, 0.0, 0.6);
		glBegin (GL_POLYGON);
			glVertex2i (501,492);
			glVertex2i (520,492);
			glVertex2i (520,540);
			glVertex2i (501,540);
		glEnd();
		
		glColor3f (0.0, 0.0, 0.6);
		glBegin (GL_POLYGON);
			glVertex2i (555,470);
			glVertex2i (575,470);
			glVertex2i (575,540);
			glVertex2i (555,540);
		glEnd();
		//sscircle
		float x4radius=3;
		float y4radius=3;
	    glBegin(GL_POLYGON);
	    glColor3f (0.96, 0.96, 0.45);
		for (int i=0; i < 360; i++){
			//convert degrees into radians
			float degInRad = i*DEG2RAD;
			glVertex2f(500+cos(degInRad)*x4radius,491+sin(degInRad)*y4radius);
		}
		glEnd();
	
	//!
		glColor3f (0.57, 0.17, 0.93);
		glBegin (GL_POLYGON);
			glVertex2i (593,575);
			glVertex2i (596,495);
			glVertex2i (613,495);
			glVertex2i (616,575);
		glEnd();	
		
		glColor3f (0.57, 0.17, 0.93);
		glBegin (GL_POLYGON);
			glVertex2i (596,470);
			glVertex2i (596,488);
			glVertex2i (613,488);
			glVertex2i (613,470);
		glEnd();	
		
		final_score();
	}
	 
    
    glutSetWindow(w1);
    if(check_answer == true||i==true||introduction_button==true)
    {
    	glClearColor(0.45, 0.82, 0.96, 0.0);
	}
	else
	{
		glClearColor(1.0, 1.0, 1.0, 0.0);
	}
	
    DrawTimer();
    
    glutTimerFunc(1000,timerProc,1);
}

void reshape(GLsizei w,GLsizei h)
{
    gluOrtho2D(0,w,0,h);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (window_x, window_y); 
	glutInitWindowPosition (50, 50);
	main_w=glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display); 
	glutMouseFunc( mouse );
	
	w1=glutCreateSubWindow(main_w, 0, 0, window_x-500, window_y-600);   //§lμ‾μ° 1
	glutTimerFunc(999,timerProc,1);
	//glutIdleFunc(&myIdle);
	glutReshapeFunc(reshape);
	glClearColor(0.45, 0.82, 0.96, 0.0);
	glutDisplayFunc(DrawTimer);
    
	glutMainLoop();
}

