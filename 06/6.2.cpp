#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//ʹ�ú���ʵ���������Ľ���
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int main()
{
	int a = 10, b = 20;
	printf("����ǰa=%d,b=%d\n", a, b);
	swap(&a, &b);
	printf("������a=%d,b=%d\n", a, b);

	system("pause");
	return 0;
}

#endif
