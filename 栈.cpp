#include<assert.h>
typedef int SDataType; 
typedef struct Stack 
{ 
int array[100]; 
int _capacity; 
int _top; // 标记栈顶位置 
}Stack; 

// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_top=0;
}
// 入栈 
void StackPush(Stack* ps, SDataType data) 
{
	ps->array[ps->_top++]; 
}

// 出栈 
int StackPop(Stack* ps)
{
	assert(ps->_top>0);
	return ps->array[--ps->_top];
}
// 获取栈顶元素 
SDataType StackTop(Stack* ps)
{
	assert(ps->_top>0);
	return ps->array[ps->_top-1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps) 
{
	return ps->_top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return ps->_top==0?1:0;
}
// 销毁栈 
void StackDestroy(Stack* ps)
{
	ps->_top=NULL;
	ps->_capacity=NULL;
}
