#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//�ݹ�ͷǵݹ�ֱ�ʵ��strlen
int my_strlen(char *str)
{
	if (*str == '\0') 
		return 0;
	else
		return 1 + my_strlen(str + 1);
}
int main()
{
	int i = 0, sum = 0;
	char s[] = "abcdefg";
	printf("���õݹ鷽ʽ����ַ�������Ϊ��%d\n", my_strlen(s));
	for (i = 0; s[i] != '\0'; i++)
		sum++;
	printf("����ѭ������ַ�������Ϊ��%d\n", sum);

	system("pause");
	return 0;
}

#endif
