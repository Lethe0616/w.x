#include<assert.h>
typedef int SDataType; 
typedef struct Stack 
{ 
int array[100]; 
int _capacity; 
int _top; // ���ջ��λ�� 
}Stack; 

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->_top=0;
}
// ��ջ 
void StackPush(Stack* ps, SDataType data) 
{
	ps->array[ps->_top++]; 
}

// ��ջ 
int StackPop(Stack* ps)
{
	assert(ps->_top>0);
	return ps->array[--ps->_top];
}
// ��ȡջ��Ԫ�� 
SDataType StackTop(Stack* ps)
{
	assert(ps->_top>0);
	return ps->array[ps->_top-1];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps) 
{
	return ps->_top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	return ps->_top==0?1:0;
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	ps->_top=NULL;
	ps->_capacity=NULL;
}
