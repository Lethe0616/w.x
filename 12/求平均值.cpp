#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 0, b = 0, average = 0;
	printf("����������������\n");
	scanf("%d%d", &a, &b);
	average = (a + b) >> 1;
	printf("a��b��ƽ��ֵΪ��%d\n", average);
	system("pause");
	return 0;
}
