#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ� 
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
int DigitSum(int n)
{
	int sum = 0;
	int m = 0;
	if (n != 0)
	{
		m = n % 10;
		sum = m + DigitSum(n / 10);
	}
	return sum;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", DigitSum(n));

	system("pause");
	return 0;
}

#endif