#ifndef _SEQSTACK_H_ // 顺序栈
#define _SEQSTACK_H_

#include"Sysutil.h"

#define StackElemType int // 栈的元素类型
#define SEQSTACK_DEFAULT_SIZE 8 // 栈的默认大小

//顺序栈的数据结构
typedef struct SeqStack
{
	StackElemType* base; // 栈空间指针
	size_t         capacity; // 栈空间
	int            top; // 栈顶指针
}SeqStack;


void SeqStackInit(SeqStack* pst, int sz); // 顺序栈的初始化
void SeqStackPush(SeqStack* pst, StackElemType x); // 数据入栈
void SeqStackPop(SeqStack* pst); // 出栈
StackElemType SeqStackTop(SeqStack* pst); // 查看栈顶元素
void SeqStackShow(SeqStack* pst); // 打印栈
void SeqStackDestroy(SeqStack* pst); // 栈的摧毁

bool IsFull(SeqStack* pst) // 判满
{
	return pst->top >= pst->capacity;
}
bool IsEmpty(SeqStack* pst) // 判空
{
	return pst->top == 0;
}

void SeqStackInit(SeqStack* pst, int sz) // 初始化顺序栈时，可以指定栈的大小
{
	assert(pst);
	pst->capacity = sz > SEQSTACK_DEFAULT_SIZE ? sz : SEQSTACK_DEFAULT_SIZE;  // 栈的空间至少为8个元素的大小
	pst->base = (StackElemType*)malloc(sizeof(StackElemType) * pst->capacity); // 申请栈空间
	assert(pst->base != NULL);
	pst->top = 0; // 栈顶默认从0开始（当然也可以从-1开始）
}

void SeqStackPush(SeqStack* pst, StackElemType x) // 数据入栈
{
	assert(pst); // 判断栈地址是否合法
	if (IsFull(pst))
	{
		printf("栈空间已满，%d不能入栈\n", x);
		return;
	}
	pst->base[pst->top++] = x; // 入栈
}

void SeqStackPop(SeqStack* pst) // 出栈
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("栈已空，不能出栈.\n");
		return;
	}
	pst->top--;
}

StackElemType SeqStackTop(SeqStack* pst) // 查看栈顶元素
{
	assert(pst && !IsEmpty(pst)); // 栈有效且栈不为空才能查看栈顶元素
	return pst->base[pst->top - 1];
}

void SeqStackShow(SeqStack* pst) // 打印栈
{
	assert(pst);
	for (int i = pst->top - 1; i >= 0; --i)
		printf("%d\n", pst->base[i]);
}

void SeqStackDestroy(SeqStack* pst)// 栈的摧毁
{
	assert(pst);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}

#endif /* _SEQSTACK_H_ */