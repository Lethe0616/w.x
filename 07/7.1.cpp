#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
int fib1(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib1(n - 1) + fib1(n - 2);
}
int fib2(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("�ݹ鷽ʽ��õ�%d��쳲�������Ϊ��%d\n", n, fib1(n));
	printf("�ǵݹ鷽ʽ��õ�%d��쳲�������Ϊ��%d\n", n, fib2(n));

	system("pause");
	return 0;
}

#endif
