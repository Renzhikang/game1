#define __STDC_WANT_LIB_EXT1__ 1
#define ROW 3
#define COL 3
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void Iintboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL], int row, int col);
void player(char board[ROW][COL], int row, int col);
void computer(char board[ROW][COL], int row, int col);
char iswin(char board[ROW][COL], int row, int col);