#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��д����ģ��������������ĳ���������������������룬������ȷ����ʾ����¼�ɹ���,�������
//�����������룬����������Ρ����ξ�������ʾ�˳�����
int main()
{
	char c[] = "123456";
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		printf("���������룺");
		scanf("%s", c);
		if (strcmp(c, "123456") == 0)
			break;
		else
			printf("�����������������\n");
	}
	if (i == 3)
		printf("����������󣬳����˳�\n");
	else
		printf("��½�ɹ�\n");

	system("pause");
	return 0;
}

#endif
