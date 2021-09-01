#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_

#include"Sysutil.h"

#define QueueElemType int

//˳����� --> ѭ������
#define QUEUE_DEFAULT_SIZE 8
typedef struct SeqQueue
{
	QueueElemType* base; // ָ������ռ��ָ��
	size_t         capacity; // ����
	int            front; // ��ͷָ��
	int            rear; // ��βָ��
}SeqQueue;

void SeqQueueInit(SeqQueue* pq, int sz); // ˳����г�ʼ��

void SeqQueueDestroy(SeqQueue* pq); // ���ٶ���

void SeqQueueEn(SeqQueue* pq, QueueElemType x); // ���
void SeqQueueDe(SeqQueue* pq); // ����
QueueElemType SeqQueueBack(SeqQueue* pq); // ȡ��βԪ��
QueueElemType SeqQueueFront(SeqQueue* pq); // ȡ��ͷԪ��
void SeqQueueShow(SeqQueue* pq); // ��ʾ����

void SeqQueueInit(SeqQueue* pq, int sz) // ˳����г�ʼ��
{
	assert(pq);
	pq->capacity = sz > QUEUE_DEFAULT_SIZE ? sz : QUEUE_DEFAULT_SIZE; // ���е�Ĭ������Ϊ8��Ԫ��
	pq->base = (QueueElemType*)malloc(sizeof(QueueElemType) * (pq->capacity + 1)); // pq->capacity + 1��ʾ����ռ�ʱ�����һ���ռ䣬�������������״̬
	assert(pq->base != NULL);
	pq->front = pq->rear = 0;
}

void SeqQueueDestroy(SeqQueue* pq)
{
	assert(pq);
	free(pq->base);
	pq->base = NULL;
	pq->capacity = pq->front = pq->rear = 0;
}

void SeqQueueEn(SeqQueue* pq, QueueElemType x) // ��ӣ�β�壩
{
	assert(pq);
	if ((pq->rear + 1) % (pq->capacity + 1) == pq->front) // ��ȡģ����ʵ��ѭ������
	{
		printf("��������, %d �������.\n", x);
		return;
	}

	pq->base[pq->rear] = x; 
	pq->rear = (pq->rear + 1) % (pq->capacity + 1);
}
void SeqQueueDe(SeqQueue* pq) // ���ӣ�ͷɾ��
{
	assert(pq);
	if (pq->front == pq->rear)
	{
		printf("�����ѿգ����ܳ���.\n");
		return;
	}
	pq->front = (pq->front + 1) % (pq->capacity + 1);
}
QueueElemType SeqQueueBack(SeqQueue* pq) // ȡ��βԪ�أ���
{
	assert(pq && (pq->front != pq->rear));
	return pq->base[(pq->rear - 1 + pq->capacity + 1) % (pq->capacity + 1)];
}
QueueElemType SeqQueueFront(SeqQueue* pq) // ȡ��ͷԪ��
{
	assert(pq && (pq->front != pq->rear));
	return pq->base[pq->front];
}
void SeqQueueShow(SeqQueue* pq)
{
	assert(pq);
	for (int i = pq->front; i != pq->rear; )
	{
		printf("%d<--", pq->base[i]);
		i = (i + 1) % (pq->capacity + 1);
	}
	printf("Nil.\n");
}
#endif /* _SEQQUEUE_H_ */