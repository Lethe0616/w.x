#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳� 
int Factorial(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return n * Factorial(n - 1);
}
int main()
{
	int n = 0;
	int i = 0, product = 1;
	scanf("%d", &n);
	printf("���õݹ鷽ʽ���%d�Ľ׳�Ϊ��%d\n", n, Factorial(n));
	for (i = 1; i <= n; i++)
		product *= i;
	printf("����ѭ�����%d�Ľ׳�Ϊ��%d\n", n, product);

	system("pause");
	return 0;
}

#endif
