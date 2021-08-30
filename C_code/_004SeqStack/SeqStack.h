#ifndef _SEQSTACK_H_ // ˳��ջ
#define _SEQSTACK_H_

#include"Sysutil.h"

#define StackElemType int // ջ��Ԫ������
#define SEQSTACK_DEFAULT_SIZE 8 // ջ��Ĭ�ϴ�С

//˳��ջ�����ݽṹ
typedef struct SeqStack
{
	StackElemType* base; // ջ�ռ�ָ��
	size_t         capacity; // ջ�ռ�
	int            top; // ջ��ָ��
}SeqStack;


void SeqStackInit(SeqStack* pst, int sz); // ˳��ջ�ĳ�ʼ��
void SeqStackPush(SeqStack* pst, StackElemType x); // ������ջ
void SeqStackPop(SeqStack* pst); // ��ջ
StackElemType SeqStackTop(SeqStack* pst); // �鿴ջ��Ԫ��
void SeqStackShow(SeqStack* pst); // ��ӡջ
void SeqStackDestroy(SeqStack* pst); // ջ�Ĵݻ�

bool IsFull(SeqStack* pst) // ����
{
	return pst->top >= pst->capacity;
}
bool IsEmpty(SeqStack* pst) // �п�
{
	return pst->top == 0;
}

void SeqStackInit(SeqStack* pst, int sz) // ��ʼ��˳��ջʱ������ָ��ջ�Ĵ�С
{
	assert(pst);
	pst->capacity = sz > SEQSTACK_DEFAULT_SIZE ? sz : SEQSTACK_DEFAULT_SIZE;  // ջ�Ŀռ�����Ϊ8��Ԫ�صĴ�С
	pst->base = (StackElemType*)malloc(sizeof(StackElemType) * pst->capacity); // ����ջ�ռ�
	assert(pst->base != NULL);
	pst->top = 0; // ջ��Ĭ�ϴ�0��ʼ����ȻҲ���Դ�-1��ʼ��
}

void SeqStackPush(SeqStack* pst, StackElemType x) // ������ջ
{
	assert(pst); // �ж�ջ��ַ�Ƿ�Ϸ�
	if (IsFull(pst))
	{
		printf("ջ�ռ�������%d������ջ\n", x);
		return;
	}
	pst->base[pst->top++] = x; // ��ջ
}

void SeqStackPop(SeqStack* pst) // ��ջ
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("ջ�ѿգ����ܳ�ջ.\n");
		return;
	}
	pst->top--;
}

StackElemType SeqStackTop(SeqStack* pst) // �鿴ջ��Ԫ��
{
	assert(pst && !IsEmpty(pst)); // ջ��Ч��ջ��Ϊ�ղ��ܲ鿴ջ��Ԫ��
	return pst->base[pst->top - 1];
}

void SeqStackShow(SeqStack* pst) // ��ӡջ
{
	assert(pst);
	for (int i = pst->top - 1; i >= 0; --i)
		printf("%d\n", pst->base[i]);
}

void SeqStackDestroy(SeqStack* pst)// ջ�Ĵݻ�
{
	assert(pst);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}

#endif /* _SEQSTACK_H_ */