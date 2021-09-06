#ifndef _LINKSTACK_H_  // ��ջ
#define _LINKSTACK_H_

#include"Sysutil.h"
struct BinTreeNode;
#define StackElemType struct BinTreeNode* // ջ��Ԫ������

#define SEQSTACK_DEFAULT_SIZE 8 // ջ��Ĭ�ϴ�С

//��ջ�����ݽṹ��������ʵ��ջ��
typedef struct LinkStackNode // ��ջ�ڵ�
{
	StackElemType data;
	struct LinkStackNode* next;
}LinkStackNode;
typedef struct LinkStack
{
	LinkStackNode* head; // ��ջͷ�ڵ�
}LinkStack;

void LinkStackInit(LinkStack* pst); // ��ʼ����ջ
void LinkStackDestroy(LinkStack* pst);
void LinkStackPush(LinkStack* pst, StackElemType x); // ��ջ
void LinkStackPop(LinkStack* pst); // ��ջ
StackElemType LinkStackTop(LinkStack* pst); // ȡջ��Ԫ��
void LinkStackShow(LinkStack* pst); // ��ʾջ

bool LinkStackEmpty(LinkStack* pst) // �п�
{
	return pst->head == NULL;
}

void LinkStackInit(LinkStack* pst) // ��ʼ����ջ
{
	assert(pst);
	pst->head = NULL;
}

void LinkStackPush(LinkStack* pst, StackElemType x) // ��ջ��ͷ�壩
{
	assert(pst);
	LinkStackNode* s = (LinkStackNode*)malloc(sizeof(LinkStackNode)); // ����ڵ�
	assert(s != NULL);
	s->data = x; // �������

	s->next = pst->head;
	pst->head = s;
}

void LinkStackPop(LinkStack* pst) // ��ջ��ͷɾ��
{
	assert(pst);
	if (pst->head != NULL) // ������ǿ�ջ����Գ�ջ
	{
		LinkStackNode* p = pst->head;
		pst->head = p->next;
		free(p);
	}
}

StackElemType LinkStackTop(LinkStack* pst) // ȡջ��Ԫ��
{
	assert(pst && pst->head != NULL);
	return pst->head->data;
}

void LinkStackShow(LinkStack* pst) // ��ʾջ
{
	assert(pst);
	LinkStackNode* p = pst->head;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

void LinkStackDestroy(LinkStack* pst) // �ݻ�ջ
{
	assert(pst);
	while (pst->head != NULL)
	{
		LinkStackNode* p = pst->head;
		pst->head = p->next;
		free(p);
	}
}

#endif /* _LINKSTACK_H_ */