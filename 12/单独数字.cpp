#include <stdio.h>
#include <stdlib.h>

int main()
{
	int one = 0, i = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };
	one = arr[0];
	for (i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		one = one ^ arr[i]; //�������齫Ԫ��������µ�һ����
	}
	printf("%d\n", one);
	system("pause");
	return 0;
}
