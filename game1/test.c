#define __STDC_WANT_LIB_EXT1__ 1
#include "game.h"
#include "game.cpp"

void menu()
{
	printf("******��Ϸ˵��******\n");
	printf("����1��play  \n����0��exit \n");
	printf("********************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = {'a'};
	Iintboard(board,ROW,COL);//���̳�ʼ��
	displayboard(board,ROW,COL);//��ӡ����
	while (1)
	{
 		player(board, ROW, COL);//�������
		displayboard(board, ROW, COL);
		ret=iswin(board, ROW, COL);
		if (ret != 'c')//��������жϵ���'c'��ô��Ϸ����
		{
			break;
		}
		computer(board, ROW, COL);//��������
		displayboard(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	

}
void test()
{
	int imput = 0;
	srand((unsigned int)time(NULL));//����ʱ�����rand
	do {
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &imput);
		switch(imput)
		{
			case 1:
				printf("������\n");
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("�������,��������\n");
				break;

		}
	} while (imput);
}
int main()
{
	test();
	return 0;
}