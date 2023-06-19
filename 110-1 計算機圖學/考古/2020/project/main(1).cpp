#define GL_SILENCE_DEPRECATION

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include <GL/glut.h>
#define PI 3.14159
using namespace std;

int square_width=60;    //九宮格每一格的長寬
int border=30;
int window_y=700;  //視窗的高度
int window_x=700;   //視窗的寬度

int second=0;   //紀錄過了幾秒
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

int color9x9[9][9];//存使用者選的答案
int color9x9_display[9][9];//存要顯示給使用者看的9x9宮格
int sudoku_question[9][9];//數獨的題目
int sudoku_answer[9][9];//數獨的正確解答

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
        
    }
    
}

void init (void)
{
    srand(time(0));

    glClearColor (1.0,1.0,1.0,0.0);     //設定視窗背景顏色
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,window_x,0.0,window_y);//(左x座標,右x座標,下y座標,上y座標)

    answer();
    question ();
    arra_initial();
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

int present_col_choose=-1; //上次選的col
int present_row_choose=-1; //上次選的row

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
        if(x>=border+8*square_width && x<=border+9*square_width && border+9.2*square_width && border+10*square_width)   //如果按的地方是完成按鈕
        {
            check_ans();
            return;
        }
        present_col_choose=-1;
        present_row_choose=-1;
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
    /*color(11);
    glColor3f(R/255.00, G/255.00, B/255.00);
    glBegin(GL_POLYGON);
        glVertex2f(border+8*square_width, border+9.2*square_width);
        glVertex2f(border+9*square_width, border+9.2*square_width);
        glVertex2f(border+9*square_width, border+10*square_width);
        glVertex2f(border+8*square_width, border+10*square_width);
    glEnd();*/
    
    
    glFlush();
}

int mouse_x;
int mouse_y;

void myMouse(int btn, int state, int x, int y)  //(x,y)是游標點的座標
{
    y=window_y-y;    //因為window座標的y是反過來的
    mouse_x=x;
    mouse_y=y;
    if(btn==GLUT_LEFT_BUTTON && state== GLUT_DOWN)
    {
        drawSquare(x, y);
    }
}

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
    int min=second/60;
    int sec=second%60;
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2);
    
    DrawMin(min);
    DrawSec(sec);
    
    start++;
    glFlush();
}

void make_mask()    //做黑色遮罩遮住題目
{
	int score;
	int sub_score=540;
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
	
    if(second%5==0)
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

void make_delete()    //把使用者答的答案刪掉
{
	int score;
	int sub_score=360;
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
	
    if(second%5==0)
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
            //drawSquare(present_col_choose*square_width+border, present_row_choose*square_width+border);
            drawSquare(mouse_x, mouse_y);
        }
    }
}

void timerProc(int id)
{
    second++;
    
    glutTimerFunc(1000,timerProc,1);
    
    glutSetWindow(main_w);
    make_delete();
    check_ans();
    
    glutSetWindow(w1);
    DrawTimer();
}

void reshape(GLsizei w,GLsizei h)
{
    gluOrtho2D(0,w,0,h);
}

int run_num=0;
void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    run_num++;
	drawSquare(mouse_x, mouse_y);
    glFlush ();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);    //視窗位置
    glutInitWindowSize(window_x,window_y);       //視窗大小
    main_w=glutCreateWindow("sudoku!");       //設定視窗顯示的名稱
    init();
    glutMouseFunc (myMouse);
    glutDisplayFunc(display);

    w1=glutCreateSubWindow(main_w, 0, 0, window_x-200, window_y-600);   //§lμ¯μ° 1
    glutTimerFunc(1000,timerProc,1);
    //glutIdleFunc(&myIdle);
    glutReshapeFunc(reshape);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(DrawTimer);

    glutMainLoop();   //讓main一直跑,寫在這條指令下面的指令永遠不會被執行(目的:讓結果一直顯示在銀幕上)
}

