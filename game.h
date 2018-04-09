#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
void PlayerMov(char board[ROW][COL],int row,int col);
void ComputerMov(char board[ROW][COL],int row,int col);
char IsWin(char board[ROW][COL],int row,int col);

#endif //__GAME_H__
