#define __STDC_WANT_LIB_EXT1__ 1
#include "game.h"
void Iintboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void displayboard(char board[ROW][COL], int row, int col)
{
	int j = 0;
	int i = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j< col - 1)
				printf("|");
	    }
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
	}    printf("\n");
	}
}
void player(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");
	while(1)
	{
		printf("请输入坐标：\n");
		scanf_s("%d%d", &x,&y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else

			{
				printf("您已经下过这步\n");
			}
        }
		else {
			printf("请按照棋盘位置输入\n");
		}

		
		
	}
}
	
	void computer(char board[ROW][COL], int row, int col)
	{
		int x = 0;
		int y = 0;
		printf("电脑走:>\n");
		x = rand() % row;//rand()是电脑产生的随机数
		y = rand() % col;
		while (1)
		{
			if (board[x][y] == ' ')
			{
				board[x][y] = '#';
				break;
			}
		}
	}
	int isfull(char board[ROW][COL], int row, int col)
	{
		int j = 0;
		int i = 0;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				if (board[i][j] == ' ')
				{
					return 0;
				}
			}
			
		}
		return 1;//棋盘已经填满了

	}
	char iswin(char board[ROW][COL], int row, int col)
	{
		//判断行和列
		int i = 0;
		for (i = 0; i < row; i++)
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
				return board[i][2];

		}
		for (i = 0; i < row; i++)
		{
			if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
				return board[2][i];

		}
		//判断对角线
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
			return  board[1][1];
		if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] != ' ')
			return  board[1][1];
		//判断是否平局
		if (1 == isfull(board, ROW, COL))
		{
			return 'p';
		}
		return 'c';
	}