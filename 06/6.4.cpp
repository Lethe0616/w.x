#define _CRT_SECURE_NO_WARNINGS 1
#if 1
#include <stdio.h>
#include <stdlib.h>

//����һ�����飬ʵ�ֺ���init������ʼ�����顢ʵ��empty����������顢ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
void init(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
		arr[i] = 1;
}
void empty(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
		arr[i] = 0;
}
void reverse(int arr[], int sz)
{
	int i = 0, t = 0;
	for (i = 0; i < sz / 2; i++)
	{
		t = arr[i];
		arr[i] = arr[sz-1-i];
		arr[sz-1-i] = t;
	}
}
int main()
{
	int arr[10] = { 0 };
	int i = 0, sz = 0;
	sz = sizeof(arr)/sizeof(arr[0]);
	printf("��ʼ������ȫΪ1��\n");
	init(arr, sz);
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("�������ȫΪ0��\n");
	empty(arr, sz);
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("���������飺\n");
	for (i = 0; i < sz; i++)
		scanf("%d", &arr[i]);
	reverse(arr, sz);
	printf("�������ú�\n");
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	printf("\n");

	system("pause");
	return 0;
}

#endif
