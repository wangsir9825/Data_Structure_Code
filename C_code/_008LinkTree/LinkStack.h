#ifndef _LINKSTACK_H_  // 链栈
#define _LINKSTACK_H_

#include"Sysutil.h"
struct BinTreeNode;
#define StackElemType struct BinTreeNode* // 栈的元素类型

#define SEQSTACK_DEFAULT_SIZE 8 // 栈的默认大小

//链栈的数据结构（单链表实现栈）
typedef struct LinkStackNode // 链栈节点
{
	StackElemType data;
	struct LinkStackNode* next;
}LinkStackNode;
typedef struct LinkStack
{
	LinkStackNode* head; // 链栈头节点
}LinkStack;

void LinkStackInit(LinkStack* pst); // 初始化链栈
void LinkStackDestroy(LinkStack* pst);
void LinkStackPush(LinkStack* pst, StackElemType x); // 入栈
void LinkStackPop(LinkStack* pst); // 出栈
StackElemType LinkStackTop(LinkStack* pst); // 取栈顶元素
void LinkStackShow(LinkStack* pst); // 显示栈

bool LinkStackEmpty(LinkStack* pst) // 判空
{
	return pst->head == NULL;
}

void LinkStackInit(LinkStack* pst) // 初始化链栈
{
	assert(pst);
	pst->head = NULL;
}

void LinkStackPush(LinkStack* pst, StackElemType x) // 入栈（头插）
{
	assert(pst);
	LinkStackNode* s = (LinkStackNode*)malloc(sizeof(LinkStackNode)); // 申请节点
	assert(s != NULL);
	s->data = x; // 填充数据

	s->next = pst->head;
	pst->head = s;
}

void LinkStackPop(LinkStack* pst) // 出栈（头删）
{
	assert(pst);
	if (pst->head != NULL) // 如果不是空栈则可以出栈
	{
		LinkStackNode* p = pst->head;
		pst->head = p->next;
		free(p);
	}
}

StackElemType LinkStackTop(LinkStack* pst) // 取栈顶元素
{
	assert(pst && pst->head != NULL);
	return pst->head->data;
}

void LinkStackShow(LinkStack* pst) // 显示栈
{
	assert(pst);
	LinkStackNode* p = pst->head;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

void LinkStackDestroy(LinkStack* pst) // 摧毁栈
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