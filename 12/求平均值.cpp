#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 0, b = 0, average = 0;
	printf("请输入两个整数：\n");
	scanf("%d%d", &a, &b);
	average = (a + b) >> 1;
	printf("a、b的平均值为：%d\n", average);
	system("pause");
	return 0;
}
