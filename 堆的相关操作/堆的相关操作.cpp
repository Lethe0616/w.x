#include "Heap.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
 
void Swap(int *m,int *n)
{
	int tmp=*m;
	*m=*n;
	*n=tmp;
}

void AdjustUp(Heap* hp,DataType child)
{
	int parent=(child-1)>>1;
	if(hp==NULL)
		return;
	while(child)
	{
		if(hp->_data(hp->_array[child],hp->_array[parent]))
		{
			Swap(&hp->_array[parent],&hp->_array[child]);
			child=parent;
			parent=(child-1)>>1;
		}
		else
			break;
	}
 
}
 
void AdjustDown(Heap* hp,DataType parent)
{
	int child=parent*2+1;
	if(hp==NULL)
		return;
 
	while(child<hp->_size)
	{
		if(hp->_com(hp->_array[child+1],hp->_array[child])&& child+1<hp->_size )
		{
			child=child+1;
		}
 
		if(hp->_com(hp->_array[child],hp->_array[parent]))
		{
			Swap(&hp->_array[child],&hp->_array[parent]);
			parent=child;
			child=parent*2+1;
		}
		else
			break;
	}
}

//������ 
void CreateHeap(Heap* hp, int* array, int size)
{
	int i=0;
	int root=0;
	assert(hp);
 
	hp->_array =(int*)malloc(sizeof(int)*MAX_SIZE);
	if(hp->_array ==NULL)
		printf("����ռ�ʧ��\n");
	hp->_capacity =MAX_SIZE;
	hp->_size =0;
 
	for(;i<size;++i)
	{
		hp->_array[i]=array[i];
		hp->_size++;
	}
	hp->_size =size;
 

	root=(size-2)>>1;  
	for(;root>=0;root--)
		AdjustDown(hp,root);
}
 
 
// �ڶ��в���ֵΪdata��Ԫ�� 
void InsertHeap(Heap* hp, DataType data)
{
	if(hp==NULL)
		return;
	//����Ԫ�أ���Ԫ�ط������һ��Ԫ��֮��
	hp->_array[hp->_size]=data;
	hp->_size++;
	
	//����Ԫ��
	if(hp->_size >1)
		AdjustUp(hp,hp->_size -1);
}
 
// ��ȡ�Ѷ�Ԫ�� 
DataType TopHeap(Heap* hp)
{
	if(hp==NULL)
		return -1;
	return hp->_array[0];
}
 
// ���һ�����Ƿ�Ϊ�ն� 
int EmptyHeap(Heap* hp)
{
	if(hp==NULL)
		return 1;
	return 0;
}
 
// ��ȡ����Ԫ�صĸ��� 
int SizeHeap(Heap* hp)
{
	if(hp==NULL)
		return 0;
	return hp->_size ;
}
 
// ɾ���Ѷ�Ԫ�� 
void DeleteHeap(Heap* hp)
{
	if(hp==NULL)
		return;
	//1.�Ѷ�Ԫ�ػ������һ��Ԫ��
	Swap(&hp->_array[0],&hp->_array[hp->_size-1]);
	hp->_size--;
	//2.���µ���
	AdjustDown(hp,0);
}
 
// ���ٶ� 
void DestroyHeap(Heap* hp)
{
	assert(hp);
	if(EmptyHeap(hp))
		return;
	hp->_size =0;
	hp->_com =NULL;
}
