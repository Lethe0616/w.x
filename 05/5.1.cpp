#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//��ɲ�������Ϸ
void menu()
{
	printf("_________________________________\n");
	printf("__________   1. play    _________\n");
	printf("__________   0. exit    _________\n");
	printf("_________________________________\n");
}
void game()
{
	int num = rand() % 100 + 1;
	int a = 0;
	while (1)
	{
		printf("������µ�����->");
		scanf("%d", &a);
		if (a > num)
			printf("�´���\n");
		else if (a < num)
			printf("��С��\n");
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
}
int main()
{
	int a = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("���������ѡ��");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ����������������\n");
			break;
		}
	} while (a);

	system("pause");
	return 0;
}

#endif
