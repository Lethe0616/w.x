#define _CRT_SECURE_NO_WARNINGS 1
#if 1
#include <stdio.h>
#include <stdlib.h>

//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣� 
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
void reverse_string(char * string)
{
	if (*(++string) != '\0')   //this is a bug 
		reverse_string(string);
	printf("%c", *(--string));
}
int main()
{
	char s[] = "abcdefg";
	reverse_string(s);

	system("pause");
	return 0;
}

#endif
