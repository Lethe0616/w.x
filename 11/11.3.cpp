#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//����Ļ�ϴ�ӡ������ǡ� 
//1 
//1 1 
//1 2 1 
//1 3 3 1 
int main()
{
	int i = 0, j = 0, n = 0;
	int a[100][100] = { 0 };
	printf("�������ӡ������");
	scanf("%d", &n);
	for (i = 0; i < n; i++)  //ÿ���������˵�1
	{
		a[i][0] = a[i][i] = 1;
	}
	//��i����i��Ԫ��
	for (i = 2; i < n; i++)  //�������ӵ����п�ʼ��
	{
		for (j = 1; j < i; j++)  //ÿ�и������ӵڶ��п�ʼ��
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");

	system("pause");
	return 0;
}

#endif
