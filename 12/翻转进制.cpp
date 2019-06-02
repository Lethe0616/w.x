#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int reverse_bit(unsigned int value)
{
	int arr[32] = { 0 };
	unsigned int sum = 0;
	for (int i = 0; i < 32; i++)
	{
		arr[i] = value & 1;
		value = value >> 1;
	}
	for (int i = 0; i < 32; i++)
	{
		sum = sum + arr[i] * pow(2, 32 - 1 - i);
	}
	return sum;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	unsigned int ret = reverse_bit(n);
	printf("翻转二进制后的值为：\n");
	printf("%u\n", ret);  
	system("pause");
	return 0;
}

