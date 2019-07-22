//≤Â»Î°¢œ£∂˚°¢—°‘Ò°¢∂—≈≈°¢√∞≈›°¢πÈ≤¢°¢º∆ ˝°¢ª˘ ˝≈≈–Ú
#include<stdio.h>
#include<iostream>
#include<assert.h>
using namespace std;

//√∞≈›≈≈–Ú 
void BubbleSort(int *arr,int size)
{
  for(int i = 0;i < size - 1;++ i)
  {
  	for(int j = 1;j < size - i;++ j)
  	{
  		if(arr[j-1]>arr[j])
  		{
  			swap(arr[j-1],arr[j]);
		}
	  }
   }	
 } 
 
 //—°‘Ò≈≈–Ú
void SelectSort(int *arr,int size)
{
	for(int i = 0;i < size-1 ;++i)
  {
		int max = i;
	for(int j = i + 1;j < size;++j)
	{
		if(arr[j]>arr[max])
		{
			max = j;
		}
		if(max!=i)
		{
	     swap(arr[max],arr[i]);
	    }
	}
  } 
 } 
 
 //≤Â»Î≈≈–Ú
 void  InsertSort(int *arr,int size)
 {
 	for(int i = 0; i < size; i++)
 	{
 		int k = arr[i];
 		int j;
 		for(j = i-1;j >=0&&k < arr[j]; j--){
 			arr[j+1]=arr[j];
		 }
	 arr[j+1]=k;
	 }
  } 
  
//œ£∂˚≈≈–Ú
void gaper(int *arr,int gap,int size)
{
	gap = size;
	while(1){
		gap = gap / 3 + 1;
		gaper(arr,size,gap);
		if(gap==1)
		{
			break;
		}
	} 
} 
	
void  ShellSort(int *arr,int size)
 {
 	for(int i = 0; i < size; i++)
	{
		int gap;
		int k = arr[i];
 		int j;
 		for(j = i - gap;j >=0&&k < arr[j]; j-=gap){
 			arr[j+gap]=arr[j];
	}
arr[j+gap]=k;
    }
}

//∂—≈≈–Ú
void AdjustDown(int *arr, int root,int size)
{
	int parent = root;
	int left = 2 * parent+1;
	int right = left + 1;
	while (left <size)
	{
		int max = left;
		if (arr[max] < arr[right]&&right<size)
		{
			max = right;
		}
		if (arr[parent] < arr[max])
		{
			swap(arr[parent], arr[max]);
			parent = max;
			left = 2 * parent+1;
		    right = left + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int *arr, int size)
{
	for (int i = size / 2 - 1; i >= 0; --i)
	{
		AdjustDown(arr,i,size);
	}
	int end = size - 1;
	while (end > 0)
	{
		swap(arr[0], arr[end]);
		AdjustDown(arr,0,end);
		--end;
	}
}

// πÈ≤¢≈≈–Ú
void MergeData(int *arr,int left,int right,int *temp,int mid)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid;
	int end2 = right;
	int index = left;
	while (begin1 < end1 && begin2 < end2)
	{
		if (arr[begin1] <arr[begin2])
		{
			temp[index++] = arr[begin1++];
		}
		else
		{
			temp[index++] = arr[begin2++];
		}
	}
	while (begin1 < end1)
	{
		temp[index++] = arr[begin1++];
	}
	while (begin2 < end2)
	{
		temp[index++] = arr[begin2++];
	}
	memcpy(arr+left,temp+left,(right-left)*sizeof(int));
}

void MergeSort(int *arr,int left,int right,int *temp )
{
	int mid = (left + (right - left) >> 1);
	MergeSort(arr,temp,left,mid);
	MergeSort(arr,temp,mid,right);
	int *temp = (int*)malloc((right - left)*sizeof(arr[0]));
	if(temp == NULL)
	return;
	MergeData(arr,left,mid,right,temp);
	memcpy(arr+left,remp+right,(right-left)*sizeof(arr[0]));	
 } 
 
 //º∆ ˝≈≈–Ú
void CountSort(int *arr,int size)
{
	int max = arr[0];
	int min = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	int *temp = new int[max-min + 1];
	memset(temp,0,sizeof(int)*(max-min+1));
 
	for (int i = 0; i < size; ++i)
	{
		temp[arr[i] - min]++;
	}
}

//ª˘ ˝≈≈–Ú
void RadixSort(int* arr, int size)
{
	int maxBit = 2;
	int* count = new int[10]();
	int* bucket = new int[len]();
 
	int radix = 1;
	for (int bit = 1; bit <= maxBit; ++bit)
	{
		memset(count, 0, sizeof(int)* 10);
 
		for (int i = 0; i < size; ++i)
		{
			int k = (arr[i] / radix) % 10;
			count[k]++;
		}
 
	    for (int i = 1; i < size; ++i)
		{
			count[i] = count[i] + count[i - 1];
		}
 
		for (int i = size - 1; i >= 0; --i)
		{
			int k = (arr[i] / radix) % 10;
			bucket[--count[k]] = arr[i];
		}
 
		memcpy(bucket, arr, sizeof(int)*size);
 
		radix *= 10;
	}
}
 
void Printf(int *arr,int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

 int main()
{
	int arr[] = {5,3,9,6,7,1,2,8,4,10};
	int size = sizeof(arr) / sizeof(arr[0]);
	//BubbleSort(arr, size);
	//SelectSort(arr,size);
	//InsertSort(arr,size);
	//ShellSort(arr,size);
	//HeapSort(arr,size); 
	//MergeSort(arr,size); 
	//CountSort(arr,size);
	RadixSort(arr,size);
	Printf(arr,size);
	return 0;
}

