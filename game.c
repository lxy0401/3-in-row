#include "game.h"
void InitBoard(char board[ROW][COL],int row,int col)
{
    memset(board,' ',row*col*sizeof(board[0][0]));
}

void DisplayBoard(char board[ROW][COL],int row,int col)
{
    int i=0;
    for(i=0;i<row;i++)
    {
        printf("%c|%c|%c\n",board[i][0],board[i][1],board[i][2]);
        if(i<row-1)
        {
            printf("---|---|---\n");
        }
    }
}

void PlayerMov(char board[ROW][COL],int row,int col)
{
    int x=0;
    int y=0;
    while(1)
    {
        printf("玩家走：>");
        scanf("%d %d",&x,&y);
        if(((x>=0)&&(x<=row))&&((y>=0)&&(y<=col)))
        {
            if(board[x-1][y-1]==' ')
            {
                board[x-1][y-1]='X';
                break;
            }
            else
            {
                printf("坐标已被占用\n");
            }
        }
        else
        {
            printf("非法坐标\n");
        }
    }
}

void ComputerMov(char board[ROW][COL],int row,int col)
{
    printf("电脑走：>");
    while(1)
    {
        int x=rand()%row;
        int y=rand()%col;
        if(board[x][y]==' ')
        {
            board[x][y]='0';
            break;
        }
    }
}

static int IsFul(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    for(;i<row;i++)
    {
        for(;j<col;j++)
        {
            if(board[i][j]==' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

char IsWin(char board[ROW][COL],int row,int col)
{
    int i=0;
    for(i=0;i<row;i++)
    {
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=' ')
        {
            return board[i][0];
        }
    }
    for(;i<col;i++)
    {
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[0][i]!=' ')
        {
            return board[0][i];
        }
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]!=' ')
    {
        return board[1][1];
    }
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]!=' ')
    {
        return board[1][1];
    }
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]!=' ')
    {
        return board[1][1];
    }
    if(IsFul(board,row,col))
    {
        return 'q';
    }
    return ' ';
}

