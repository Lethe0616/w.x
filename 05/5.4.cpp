#define _CRT_SECURE_NO_WARNINGS 1
#if 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//��дһ�����򣬿���һֱ���ռ����ַ��������Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ�����������ֲ������
int main()
{
	int ch;
	printf("�������ַ���\n");
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
			//			printf("%c\n", ch-32);
			printf("%c\n", toupper(ch));
		else if (ch >= 'A'&&ch <= 'Z')
			//			printf("%c\n", ch+32);
			printf("%c\n", tolower(ch));
	}

	system("pause");
	return 0;
}

#endif
