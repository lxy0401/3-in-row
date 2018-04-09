#include "game.h"
void menu()
{
    printf("***********************************\n");
    printf("*********1.play********0.exit******\n");
    printf("***********************************\n");
}

char game()
{
    char board[ROW][COL]={0};
    char ret;
    InitBoard(board,ROW,COL);
    DisplayBoard(board,ROW,COL);
    while(1)
    {
        PlayerMov(board,ROW,COL);
        DisplayBoard(board,ROW,COL);
        ret=IsWin(board,ROW,COL);
        if(ret!=' ')
        {
            break;
        }
        ComputerMov(board,ROW,COL);
        DisplayBoard(board,ROW,COL);
        ret=IsWin(board,ROW,COL);
        if(ret!=' ')
        {
            break;
        }
    }
    if(ret == 'X')
    {
        printf("玩家获胜！！\n");
    }
    else if(ret == '0')
    {
        printf("电脑获胜！！\n");
    }
    else if(ret == 'q')
    {
        printf("平局！！\n");
    }
}

void Test()
{
    int input=0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择：>");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出\n");
                break;
            default:
                printf("输入错误\n");
                break;
        }
    }
    while(input);
}

int main()
{
    Test();
    return 0;
}
