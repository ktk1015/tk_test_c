/*
	미로찾기
	참고: http://yk209.tistory.com/84
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define MAZE_BOARD_HEIGHT 10
#define MAZE_BOARD_WIDTH 6
#define POINT_X 4  //보드시작좌표x
#define POINT_Y 2  //보드시작좌표y

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

#define DELAY 100
#define EXIT 50


int maze[MAZE_BOARD_HEIGHT][MAZE_BOARD_WIDTH]={
        {'1','1','1','1','1','1'},
        {'e','0','0','0','0','1'},
        {'1','0','1','1','1','1'},
        {'1','0','0','0','1','1'},
        {'1','0','1','0','0','1'},
        {'1','0','0','1','0','1'},
        {'1','1','1','0','0','1'},
        {'1','0','1','0','1','1'},
        {'1','0','0','0','0','x'},
        {'1','1','1','1','1','1'}
};


void setCursor(int x,int y)
{
        COORD pos;
        pos.X=x;
        pos.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

COORD getCursor(void)
{
        COORD curPoint;
        CONSOLE_SCREEN_BUFFER_INFO pos;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&pos);
        curPoint.X=pos.dwCursorPosition.X;
        curPoint.Y=pos.dwCursorPosition.Y;
        return curPoint;
}

void removeCursor(void)
{
        CONSOLE_CURSOR_INFO cur;
        GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cur);
        cur.bVisible=0;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cur);
}

void showBoard(void)
{
        int x,y;
        COORD cur=getCursor();

        for(y=0; y<MAZE_BOARD_HEIGHT; y++)
        {
                for(x=0; x<MAZE_BOARD_WIDTH; x++)
                {
                        setCursor(cur.X+(x*2), cur.Y+y);
                        if(maze[y][x]=='1')
                                printf("■");
                        if(maze[y][x]=='x')
                                printf("→");
        
                }
        }
        setCursor(cur.X,cur.Y);
}
void showCharacter(void)
{
        COORD cur=getCursor();
        
        printf("◎");
        setCursor(cur.X, cur.Y);

}
int detect(int x,int y)
{
        int x1=0;
        int y1=0;

        // 커서위치얻기
        COORD cur=getCursor();

        // 미로내에서의위치계산
        x1=cur.X+x;
        y1=cur.Y+y;
        x1=x1/2-2;
        y1=y1-2;

        // 미로밖에있느냐
        if(!((x1 >=0 && x1 <MAZE_BOARD_WIDTH) && (y1 >=0 && y1 <MAZE_BOARD_HEIGHT)))
        {
                return 1;
        }

        //배열을넘어가지않는이유
        if(maze[y1][x1]=='1')
                return 1;
        //미션성공
        else if(maze[y1][x1]=='x')
                return EXIT;
        else
                return 0;
}
void RemoveCharacter_Set(int x, int y)
{
        int value=detect(x,y);
        
        if(value==0)
        {
                COORD cur=getCursor();
                
                printf("  ");
                setCursor(cur.X+x, cur.Y+y);    
        }
        else if(value==EXIT)
        {
                setCursor(10,15);
                printf("성공");
                system("pause");
                exit(1);
        }
}


void character_static(void)
{
        int kb;
        setCursor(4,3);  //케릭터시작위치
        while(1)
        {
                while(!_kbhit())
                {
                        showCharacter();
                        Sleep(DELAY);
                }
                kb=_getch();
                switch(kb)
                {
                        case UP:
                                RemoveCharacter_Set(0,-1);
                                break;
                        case DOWN:
                                RemoveCharacter_Set(0,1);
                                break;
                        case RIGHT:
                                RemoveCharacter_Set(2,0);
                                break;
                        case LEFT:
                                RemoveCharacter_Set(-2,0);
                                break;
                }
                
        }
}
                        
                
                
int maze_main()
{
	removeCursor(); //커서깜박이지우기
	setCursor(POINT_X, POINT_Y); //보드시작좌표
	showBoard(); //미로판보여주기

	character_static(); //케릭터움직이기
	getchar();

return 0;
}