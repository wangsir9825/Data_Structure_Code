#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_

#include"Sysutil.h"

#define QueueElemType int

//顺序队列 --> 循环队列
#define QUEUE_DEFAULT_SIZE 8
typedef struct SeqQueue
{
	QueueElemType* base; // 指向数组空间的指针
	size_t         capacity; // 容量
	int            front; // 队头指针
	int            rear; // 队尾指针
}SeqQueue;

void SeqQueueInit(SeqQueue* pq, int sz); // 顺序队列初始化

void SeqQueueDestroy(SeqQueue* pq); // 销毁队列

void SeqQueueEn(SeqQueue* pq, QueueElemType x); // 入队
void SeqQueueDe(SeqQueue* pq); // 出队
QueueElemType SeqQueueBack(SeqQueue* pq); // 取队尾元素
QueueElemType SeqQueueFront(SeqQueue* pq); // 取队头元素
void SeqQueueShow(SeqQueue* pq); // 显示队列

void SeqQueueInit(SeqQueue* pq, int sz) // 顺序队列初始化
{
	assert(pq);
	pq->capacity = sz > QUEUE_DEFAULT_SIZE ? sz : QUEUE_DEFAULT_SIZE; // 队列的默认容量为8个元素
	pq->base = (QueueElemType*)malloc(sizeof(QueueElemType) * (pq->capacity + 1)); // pq->capacity + 1表示申请空间时，多给一个空间，用于区分满与空状态
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

void SeqQueueEn(SeqQueue* pq, QueueElemType x) // 入队（尾插）
{
	assert(pq);
	if ((pq->rear + 1) % (pq->capacity + 1) == pq->front) // 用取模运算实现循环队列
	{
		printf("队列已满, %d 不能入队.\n", x);
		return;
	}

	pq->base[pq->rear] = x; 
	pq->rear = (pq->rear + 1) % (pq->capacity + 1);
}
void SeqQueueDe(SeqQueue* pq) // 出队（头删）
{
	assert(pq);
	if (pq->front == pq->rear)
	{
		printf("队列已空，不能出队.\n");
		return;
	}
	pq->front = (pq->front + 1) % (pq->capacity + 1);
}
QueueElemType SeqQueueBack(SeqQueue* pq) // 取队尾元素（）
{
	assert(pq && (pq->front != pq->rear));
	return pq->base[(pq->rear - 1 + pq->capacity + 1) % (pq->capacity + 1)];
}
QueueElemType SeqQueueFront(SeqQueue* pq) // 取队头元素
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