#define __STDC_WANT_LIB_EXT1__ 1
#include "game.h"
#include "game.cpp"

void menu()
{
	printf("******游戏说明******\n");
	printf("输入1就play  \n输入0就exit \n");
	printf("********************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = {'a'};
	Iintboard(board,ROW,COL);//棋盘初始化
	displayboard(board,ROW,COL);//打印棋盘
	while (1)
	{
 		player(board, ROW, COL);//玩家落子
		displayboard(board, ROW, COL);
		ret=iswin(board, ROW, COL);
		if (ret != 'c')//如果这里判断等于'c'那么游戏继续
		{
			break;
		}
		computer(board, ROW, COL);//电脑落子
		displayboard(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("你赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	

}
void test()
{
	int imput = 0;
	srand((unsigned int)time(NULL));//设置时间戳给rand
	do {
		menu();
		printf("请选择:>");
		scanf_s("%d", &imput);
		switch(imput)
		{
			case 1:
				printf("三子棋\n");
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误,重新输入\n");
				break;

		}
	} while (imput);
}
int main()
{
	test();
	return 0;
}