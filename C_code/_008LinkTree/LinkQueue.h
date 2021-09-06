#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include"Sysutil.h"

struct BinTreeNode;
#define QueueElemType struct BinTreeNode*

// ������
typedef struct LinkQueueNode // �����нڵ�
{
	QueueElemType data;
	struct LinkQueueNode* next;
}LinkQueueNode;

typedef struct LinkQueue // ������ṹ������
{
	LinkQueueNode* head; // ָ���ͷ
	LinkQueueNode* tail; //ָ���β�ڵ�
}LinkQueue;

void LinkQueueInit(LinkQueue* pq); // ��ʼ��������
void LinkQueueDestroy(LinkQueue* pq);
void LinkQueueEn(LinkQueue* pq, QueueElemType x); // ���
void LinkQueueDe(LinkQueue* pq); // ����
void LinkQueueShow(LinkQueue* pq); // ��ʾ����
QueueElemType LinkQueueBack(LinkQueue* pq); // ȡ��βԪ��
QueueElemType LinkQueueFront(LinkQueue* pq); // ȡ��ͷԪ��

bool LinkQueueEmpty(LinkQueue* pq) // �п�
{
	return pq->head == NULL;
}

void LinkQueueInit(LinkQueue* pq) // ��ʼ��������
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void LinkQueueEn(LinkQueue* pq, QueueElemType x) // ���(β��)
{
	assert(pq);
	LinkQueueNode* s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	if (pq->head == NULL) // �������Ϊ��
		pq->head = pq->tail = s;
	else
	{
		pq->tail->next = s;
		pq->tail = s; // βָ��ָ�����һ���ڵ�
	}
}

void LinkQueueDe(LinkQueue* pq) // ���ӣ�ͷɾ��
{
	assert(pq);
	if (pq->head != NULL)
	{
		LinkQueueNode* p = pq->head;
		pq->head = p->next;
		if (pq->head == NULL) // ���Ԫ���Ѿ���ȫ����
			pq->tail = NULL;
		free(p);
	}
}

void LinkQueueShow(LinkQueue* pq) // ��ʾ����
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

QueueElemType LinkQueueBack(LinkQueue* pq) // ȡ��βԪ��
{
	assert(pq && pq->head);
	return pq->tail->data;
}
QueueElemType LinkQueueFront(LinkQueue* pq) // ȡ��ͷԪ��
{
	assert(pq && pq->head);
	return pq->head->data;
}

void LinkQueueDestroy(LinkQueue* pq) // �ݻٶ���
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