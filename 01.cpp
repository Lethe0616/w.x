#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//��ӡ100~200֮������� 	
	int i = 0, prime = 0, j = 0, year = 0;
	for (i = 100; i <= 200; i++){
		for (prime = 2; prime < i; prime++)
			if (i % prime == 0) break;
		if (i == prime)
			printf("%d ", i);
	}
	printf("\n\n");
	//����˷��ھ��� 
	for (i = 1; i <= 10; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%d*%d=%d ", i, j, i*j);
		printf("\n");
	}
	printf("\n\n");
	//�ж�1000��---2000��֮������� 
	printf("��������ݣ�\n");
	scanf("%d", &year);
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
	{
		printf("�����ꡣ\n");
	}
	else{
		printf("�������ꡣ\n");
	}

	system("pause");
	return 0;
}
