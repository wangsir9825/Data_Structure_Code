#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include"Sysutil.h"

struct BinTreeNode;
#define QueueElemType struct BinTreeNode*

// 链队列
typedef struct LinkQueueNode // 链队列节点
{
	QueueElemType data;
	struct LinkQueueNode* next;
}LinkQueueNode;

typedef struct LinkQueue // 单链表结构体类型
{
	LinkQueueNode* head; // 指向队头
	LinkQueueNode* tail; //指向队尾节点
}LinkQueue;

void LinkQueueInit(LinkQueue* pq); // 初始化链队列
void LinkQueueDestroy(LinkQueue* pq);
void LinkQueueEn(LinkQueue* pq, QueueElemType x); // 入队
void LinkQueueDe(LinkQueue* pq); // 出队
void LinkQueueShow(LinkQueue* pq); // 显示队列
QueueElemType LinkQueueBack(LinkQueue* pq); // 取队尾元素
QueueElemType LinkQueueFront(LinkQueue* pq); // 取队头元素

bool LinkQueueEmpty(LinkQueue* pq) // 判空
{
	return pq->head == NULL;
}

void LinkQueueInit(LinkQueue* pq) // 初始化链队列
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void LinkQueueEn(LinkQueue* pq, QueueElemType x) // 入队(尾插)
{
	assert(pq);
	LinkQueueNode* s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	if (pq->head == NULL) // 如果队列为空
		pq->head = pq->tail = s;
	else
	{
		pq->tail->next = s;
		pq->tail = s; // 尾指针指向最后一个节点
	}
}

void LinkQueueDe(LinkQueue* pq) // 出队（头删）
{
	assert(pq);
	if (pq->head != NULL)
	{
		LinkQueueNode* p = pq->head;
		pq->head = p->next;
		if (pq->head == NULL) // 如果元素已经完全出队
			pq->tail = NULL;
		free(p);
	}
}

void LinkQueueShow(LinkQueue* pq) // 显示队列
{
	assert(pq != NULL);
	LinkQueueNode* p = pq->head;
	while (p != NULL)
	{
		printf("%d<--", p->data);
		p = p->next;
	}
	printf("NULL.\n");
}

QueueElemType LinkQueueBack(LinkQueue* pq) // 取队尾元素
{
	assert(pq && pq->head);
	return pq->tail->data;
}
QueueElemType LinkQueueFront(LinkQueue* pq) // 取队头元素
{
	assert(pq && pq->head);
	return pq->head->data;
}

void LinkQueueDestroy(LinkQueue* pq) // 摧毁队列
{
	assert(pq);
	while (pq->head != NULL)
	{
		LinkQueueNode* p = pq->head;
		pq->head = p->next;
		free(p);
	}
	pq->head = pq->tail = NULL;
}
#endif /* _LINKQUEUE_H_ */