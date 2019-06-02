#include <stdio.h>
#include <stdlib.h>
#include <assert.h>  

void reverse(char *start, char *end)  //翻转字符串
{
	assert(start);
	assert(end);
	while (start < end)
	{
		char t = *start;
		*start = *end;
		*end = t;
		start++;
		end--;
	}
}
void reverse_str(char *str, int sz)
{
	assert(str);
	char *str1 = str;
	char *left = str;
	char *right = str + sz - 1;
	reverse(left, right);  //整体字符串反转
	while (*str1)  //将单词逐个反转
	{
		left = str1;
		while ((*str1 != '\0') && (*str1 != ' '))  
		{
			str1++;
		}
		right = str1 - 1; 
		reverse(left, right);  
		if (*str1 == ' ')  
		{
			str1++;
		}
	}
}
int main()
{
	char arr[] = "student a am i";
	int sz = strlen(arr);
	printf("原来的字符串为：%s\n", arr);
	reverse_str(arr, sz);
	printf("反转后的字符串为：%s", arr);
	system("pause");
	return 0;
}
