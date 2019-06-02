#include <stdio.h>
#include <stdlib.h>
#define ROW 3


int find(int arr[ROW][ROW], int row, int k)
{
	int left = 0;
	int right = row - 1;
	while ((left < row) && (right >= 0))
	{
		if (arr[left][right] < k)
		{
			left++;
		}
		if (arr[left][right] > k)
		{
			right--;
		}
		if (arr[left][right] == k)
		{
			return 1;
		}
	}
	return 0;
}
//�ݹ�д�������Ͻ�
#define N 3
int find_r(int a[][N], int row, int col, int x, int y, int key)
{
	//��ֹ
	if (x >= row || y < 0)
		return 0;
	if (a[x][y] == key)
		return 1;
	else if (key > a[x][y])
		return find_r(a, row, col, x + 1, y, key);
	else
		return find_r(a, row, col, x, y - 1, key);
}

int main()
{
	int arr[ROW][ROW] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int k = 0, ret = 0;
	printf("��������Ҫ���ҵ����֣�");
	scanf("%d", &k);
	ret = find(arr, ROW, k);
	if (ret == 1)
		printf("�ҵ���\n");
	else
		printf("δ�ҵ�\n");
	system("pause");
	return 0;
}
