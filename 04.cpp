#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sum = 0, k = 0;
	int a = 0, b = 0, c = 0;
	//����Ļ���������ͼ�� 
	int i = 0, j = 0, n = 6;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
			printf(" ");
		for (j = 1; j <= 2 * i - 1; j++)
			printf("*");
		printf("\n");
	}
	for (i = n - 1; i > 0; i--)
	{
		for (j = n - i - 1; j >= 0; j--)
			printf(" ");
		for (j = 2 * i - 2; j >= 0; j--)
			printf("*");
		printf("\n");
	}

	/*���0��999֮������С�ˮ�ɻ������������
	��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ��������磻153��1��5��3?����153��һ����ˮ�ɻ�������
	�������У�ˮ�ɻ�����Narcissistic number��Ҳ��Ϊ������������������ķ˹׳����ķ˹��������Armstrong number����
	��ָһNλ�����������֮N�η��͵��ڸ�����
	����153��370��371��407������λ����ˮ�ɻ������������֮�����͵��ڸ�����
	153 = 1^3 + 5^3 + 3^3��
	370 = 3^3 + 7^3 + 0^3��
	371 = 3^3 + 7^3 + 1^3��
	407 = 4^3 + 0^3 + 7^3�� */
	for (a = 1; a <= 9; a++)
		for (b = 0; b <= 9; b++)
			for (c = 0; c <= 9; c++)
				if (100 * a + 10 * b + c == a*a*a + b*b*b + c*c*c)
					printf("%d%d%d\n", a, b, c);

	//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣����磺2+22+222+2222+22222 
	scanf("%d", &a);
	for (i = 0; i < 5; i++)
	{
		k = k * 10 + a;
		sum = sum + k;
	}
	printf("%d\n", sum);

	system("pause");
	return 0;
}
