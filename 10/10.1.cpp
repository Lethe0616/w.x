#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//дһ���������ز����������� 1 �ĸ��� 
//���磺 15 0000 1111 4 �� 1
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
//	// ���� 1��λ�� 
//}
int count_one_bits(unsigned int value)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)  //32λƽ̨
	{
		if ((value & 1) == 1)  //==������&
		{
			count++;
		}
		value = value >> 1;
	}
	return count;
}

int main()
{
	unsigned int value = 0;
	scanf("%d", &value);
	printf("%d\n", count_one_bits(value));

	system("pause");
	return 0;
}

#endif
