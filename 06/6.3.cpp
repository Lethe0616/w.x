#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//ʵ��һ�������ж�year�ǲ�������
int is_leap_year(int year)
{
	return ((year%400 == 0) || (year%4 == 0 && year%100 != 0));
}
int main()
{
	int year = 0;
	int ret = 0;
	printf("��������ݣ�\n");
	scanf("%d", &year);
	ret = is_leap_year(year);
	if (ret == 1)
		printf("������\n");
	else
		printf("��������\n");

	system("pause");
	return 0;
}

#endif
