#define _CRT_SECURE_NO_WARNINGS 1
#if 1

#include <stdio.h>
#include <stdlib.h>

//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
//��������: 
//1999 2299 
//�������:7	
int main()
{
	int a = 0, b = 0;
	int c = 0;
	int count = 0;
	int i = 0;
	scanf("%d%d", &a, &b);
	c = a^b;
	for (i = 0; i < 32; i++)  //��1�ĸ���
	{
		if (((c >> i) & 1) == 1)
		{
			count++;
		}
	}
	printf("%d\n", count);

	system("pause");
	return 0;
}

#endif
