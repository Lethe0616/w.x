#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	float arr2[3];
	int i = 0;
	int arr[10] = { 0 };
	//�����������α�����ֵ��������ֵ�����ݽ��н��� 
	int a = 10;
	int b = 20;
	int c = 0;
	printf("����ǰa=%d,b=%d\n", a, b);
	c = a;
	a = b;
	b = a;
	printf("������a=%d,b=%d\n\n", a, b);
	//����������ʱ���������������������ݣ������⣩
	printf("����ǰa=%d,b=%d\n", a, b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("������a=%d,b=%d\n\n", a, b);
	//��10�����������ֵ 
	printf("������10������: ");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > c)
			c = arr[i];
	}
	printf("���ֵΪ: %d\n\n", c);
	//�����������Ӵ�С��� 
	printf("������������: ");
	scanf("%d%d%d", &a, &b, &c);
	if (a < b)
	{
		i = a;
		a = b;
		b = i;
	}
	if (a < c)
	{
		i = a;
		a = c;
		c = i;
	}
	if (b < c)
	{
		i = b;
		b = c;
		c = i;
	}
	printf("�Ӵ�С��˳����: %d %d %d\n\n", a, b, c);
	//�������������Լ�� 
	printf("������������: ");
	scanf("%d%d", &a, &b);
	while (b != 0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	printf("���Լ��Ϊ: %d\n", a);

	system("pause");
	return 0;
}
