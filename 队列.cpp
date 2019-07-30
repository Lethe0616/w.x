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

// 初始化队列 
void QueueInit(Queue* q) 
{
	q->_front =q->_rear=null;
}
// 队尾入队列 
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
// 队头出队列 
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
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q->_front!=NULL);
	
	return q->_front->data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q->_rear!=NULL);
	
	return q->_rear->data;
}
// 获取队列中有效元素个数 
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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front==NULL;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	q->_front-=q->_rear=NULL;
}
