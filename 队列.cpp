#include<assert.h>
#include<stdio.h>
typedef struct Node
{
	QDataType data; 
	struct Node *next;
}Node;

typedef struct Queue 
{ 
QNode* _front; 
QNode* _rear; 
}Queue; 

// ��ʼ������ 
void QueueInit(Queue* q) 
{
	q->_front =q->_rear=null;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
Node* node=(Node*)malloc(sizeof(Node));
node->data=data;

if(q->_front=null){
	q->_front=node;
}
else
{
	q->_rear->next=node;
}

q->_rear=node;
}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q->_front!=NULL);
	
	Node *second=q->_front->next;
	int data=q->_front->data;
	free(q->_front);
	q->_front=second;
	
	if(q->_front=null)
	{
		q->_rear=null;
	}
	return data;
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q->_front!=NULL);
	
	return q->_front->data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q->_rear!=NULL);
	
	return q->_rear->data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q) 
{
	int size=0;
	Queue* cur=q->_front;
	while(cur)
	{
		size++;
		cur=cur->next;
	}
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front==NULL;
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	q->_front-=q->_rear=NULL;
}
