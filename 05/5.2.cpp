#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ�������-1.���۰���ң�
int BinarySearch(int arr[], int k, int left, int right)
{
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] < k)
			left = mid + 1;
		else if (arr[mid] > k)
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, k = 7;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int ret = BinarySearch(arr, k, left, right);
	if (ret == -1)
		printf("δ�ҵ�\n");
	else
		printf("�ҵ��ˣ��±�Ϊ%d\n", ret);

	system("pause");
	return 0;
}

#endif
