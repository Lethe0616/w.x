#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//ʵ��һ���������ж�һ�����ǲ���������
int is_prime(int x)
{
	int i = 0;
	for (i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return 0;
	return 1;
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = is_prime(n);
	if (ret == 1)
		printf("������\n");
	else
		printf("��������\n");

	system("pause");
	return 0;
}

#endif
