#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�� 
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ� 
//A˵�������ҡ� 
//B˵����C�� 
//C˵����D�� 
//D˵��C�ں�˵ 
//��֪3����˵���滰��1����˵���Ǽٻ��� 
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡� 

void predict()
{
	int killer = 0;
	// a, b, c, d --> 1, 2, 3, 4
	for (killer = 1; killer <= 4; killer++)
	{
		if ((killer != 1) + (killer == 3) + (killer == 4) + (killer != 4) == 3)
		{
			printf("�����ǣ�%c\n", killer + 'A' - 1);
		}
	}
}
void predict2()
{
	char killer = 0;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
		{
			printf("�����ǣ�%c\n", killer);
		}
	}
}

int main()
{
	int murder = 0;
	for (murder = 'A'; murder <= 'D'; murder++)
	{
		if (((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D')) == 3)  //����һ�٣���if���ģ�������Ϊ����Ϊ1��Ҫ�Ǽٽ��Ϊ0�����if����  �������������ض�Ϊ����һ�٣����ض�����3.  
		{
			printf("Murder is %c\n", murder);
		}
	}

	system("pause");
	return 0;
}

#endif
