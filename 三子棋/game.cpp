#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	int choice = 0;
	int row = ROW, col = COL;
	char board[ROW][COL] = { 0 };
	char ret = 0;
	srand((unsigned int)time(NULL));
	InitBoard(board, row, col);
	DisplatBoard(board, row, col);
	do
	{
		printf("������1������֣���2�������ֽ���ѡ��");
		scanf("%d", &choice);
		if (choice == 1 || choice == 2)
			break;
		else
			printf("�������������ѡ��\n");
	} while (1);
	while (choice == 1)
	{
		PlayMove(board, row, col);
		DisplatBoard(board, row, col);
		ret = IsWin(board, row, col);
		if (ret != 'C')
			break;
		//ComputerMove(board, row, col);
		ComputerMovePlus(board, row, col);
		DisplatBoard(board, row, col);
		ret = IsWin(board, row, col);
		if (ret != 'C')
			break;
	}
	while (choice == 2)
	{
		ComputerMovePlus(board, row, col);
		DisplatBoard(board, row, col);
		ret = IsWin(board, row, col);
		if (ret != 'C')
			break;
		PlayMove(board, row, col);
		DisplatBoard(board, row, col);
		ret = IsWin(board, row, col);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("��ϲ���ʤ����\n");
	else if (ret == '#')
		printf("����ʤ����\n");
	else
		printf("ƽ�֣�\n");
}

void InitBoard(char board[ROW][COL], int row, int col)
{
	//int i = 0, j = 0;
	//for (i = 0; i < row; i++)
	//{
	//	for (j = 0; j < col; j++)
	//	{
	//		board[i][j] = ' ';
	//	}
	//}
	memset(board, ' ', col*row);  //�����̳�ʼ��Ϊ�� ���ո���ţ�Ч�ʸ���
}

void DisplatBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c \n", board[i][j]);
		}
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf("---|", board[i][j]);
			else
				printf("---\n", board[i][j]);
		}
	}
}

void PlayMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("������壺\n");
	while (1)
	{
		printf("�����������λ�ã�");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else 
				printf("�����ѱ�ռ�ã����������롣\n");
		}
		else 
			printf("����Ƿ������������롣\n");
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("�������壺\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//���֣����м䣬��������߱��м�λ�ã��������ڽ����Է����ӵĽ�λ�á��Է��ض����㣬Ȼ����������ڸղ��Լ���λ�����ӵ��Աߣ���Ӯ��
//      ����Է�Ҳ���棬�ͻ��������ڽ�λ�ã����������Ǻ��塣
//���֣��Է��м䣬����ڽ�λ�ã�Ȼ��¶Է����У����Ǻ��塣
//����Ƕ��ѭ��ʱ����������֮��ֱ��goto��������ѭ������ֹ�������Ӳ�ֹһ��
void ComputerMovePlus(char board[ROW][COL], int row, int col)  //���Ժ��־��������
{
	int i = 0, j = 0;
	char win = 0;
	printf("�������壺\n");
	while (1)
	{
		//�����������ռ�����ĵ�
		if (board[1][1] == ' ')
		{
			board[1][1] = '#';
			break;
		}
		//��������λ���ж���#�Ƿ���Ӯ����Ӯ����
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = '#';
					win = IsWin(board, row, col);
					if (win != '#')
						board[i][j] = ' ';
					else
						goto end;
				}
			}
		}
		//��������λ���ж���*����Ƿ���Ӯ�������ס��λ��
		if (win != '#')
		{
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
				{
					if (board[i][j] == ' ')
					{
						board[i][j] = '*';
						win = IsWin(board, row, col);
						if (win != '*')
							board[i][j] = ' ';
						else
						{
							board[i][j] = '#';
							goto end;
						}
					}
				}
			}
		}
		//�����Ͼ����ﵽ�����������ڽ�λ�ã���һ�ζ���ռ������������һ���ǣ�
		if (board[0][0] == ' ')
		{
			board[0][0] = '#';
			break;
		}
		else if (board[0][3] == ' ')
		{
			board[0][3] = '#';
			break;
		}
		else if (board[3][0] == ' ')
		{
			board[3][0] = '#';
			break;
		}
		else if (board[3][3] == ' ')
		{
			board[3][3] = '#';
			break;
		}
		//���ϳ��������Ѱ��λ��
		while (1)
		{
			i = rand() % row;
			j = rand() % col;
			if (board[i][j] == ' ')
			{
				board[i][j] = '#';
				goto end;
			}
		}
	}
    end:
	    ;
}

static int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	/*
	int i;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	else if (IsFull(board, row, col))
		return 'Q';
	return 'C';
	*/

	int i = 0, j = 0;
	int flag = 0;
	//һ�����
	for (i = 0; i < row; i++)
	{
		flag = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == '*')
				;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			return '*';
	}

	for (i = 0; i < row; i++)
	{
		flag = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == '#')
				;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			return '#';
	}
	
	//һ�����
	for (i = 0; i < row; i++)
	{
		flag = 0;
		for (j = 0; j < col; j++)
		{
			if (board[j][i] == '*')
				;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			return '*';
	}

	for (i = 0; i < row; i++)
	{
		flag = 0;
		for (j = 0; j < col; j++)
		{
			if (board[j][i] == '#')
				;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			return '#';
	}
	
	//���Խ������
	flag = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][i] == '*')
			;
		else
		{
			flag = 1;
			break;
		}
		
	}
	if (flag != 1)
		return '*';

	flag = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][i] == '#')
			;
		else
		{
			flag = 1;
			break;
		}

	}
	if (flag != 1)
		return '#';

	//���Խ������
	flag = 0;
	for (i = 0, j = col - 1; i < row, j >= 0; i++, j--)
	{
		if (board[i][j] == '*')
			;
		else
		{
			flag = 1;
			break;
		}

	}
	if (flag != 1)
		return '*';

	flag = 0;
	for (i = 0, j = col - 1; i < row, j >= 0; i++, j--)
	{
		if (board[i][j] == '#')
			;
		else
		{
			flag = 1;
			break;
		}

	}
	if (flag != 1)
		return '#';

	//�������
	if (flag)
	{
		if (IsFull(board, row, col))
			return 'Q';
		else
			return 'C';
	}

	//����������пؼ�·��������ֵ�ľ���
	else
	{
		return 'C';
	}
}
