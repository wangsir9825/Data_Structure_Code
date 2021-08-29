#ifndef _DCLIST_H_
#define _DCLIST_H_

#include"Sysutil.h"

#define ElemType int

//带头结点双向循环链表（double cycle）
typedef struct DCListNode
{
	ElemType data;//数据域
	struct DCListNode* prev;//前驱节点指针
	struct DCListNode* next;//后继节点
}DCListNode;

typedef struct DCList//方便管理
{
	DCListNode* first;//指向链表的首节点
	DCListNode* last;//指向链表的尾节点
	size_t      size;//元素节点的个数
}DCList;
DCListNode* _BuyDCListNode(ElemType x)
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));//申请一个结点
	assert(s != NULL);
	s->next = s->prev = NULL;
	s->data = x;
	return s;
}


void DCListInit(DCList* plist);//初始化
void DCListPushBack(DCList* plist, ElemType x);	//尾插 1
void DCListPushFront(DCList* plist, ElemType x);// 头插 2
void DCListShow(DCList* plist);//显示链表 3
void DCListPopBack(DCList* plist);//从尾部删除 4
void DCListPopFront(DCList* plist);//从头部删除 5
size_t DCListLength(DCList* plist);//查看表长 6
void DCListInsertByVal(DCList* plist, ElemType x);//按值插入 8
void DCListDeleteByVal(DCList* plist, ElemType key);//按值删除 10
DCListNode* DCListFind(DCList* plist, ElemType key);//查找元素 12
void DCListReverse(DCList* plist); //位置翻转 14
void DCListClear(DCList* plist);//清除 （清除所有元素）16
void DCListDestroy(DCList* plist);//摧毁（把数据表直接释放） 17



void DCListInit(DCList* plist)//初始化
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(0);//头节点
	plist->first = plist->last = s;// 因为只有一个节点，所以首尾节点指向相同
	//结点循环起来
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size = 0;
}

void DCListPushBack(DCList* plist, ElemType x)//尾插 1
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(x);
	s->prev = plist->last;//新节点链接尾节点
	plist->last->next = s;//尾节点变成次尾节点（即倒数第二个节点），s成为尾节点
	plist->last = s;//last更新为尾节点

	plist->last->next = plist->first;//尾节点连接到首节点
	plist->first->prev = plist->last;//首节点连接到尾节点
	plist->size++;//节点数加1
}

void DCListPushFront(DCList* plist, ElemType x)// 头插 2
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(x);
	//以下操作顺序不可乱
	s->next = plist->first->next;//新节点连接到次首节点
	plist->first->next->prev = s;//次首节点连接上新节点
	plist->first->next = s;//首节点连接到新节点
	s->prev = plist->first;//新节点连接到次首节点

	if (plist->last == plist->first)//如果链表只有一个头节点，则需要修改last的指向
		plist->last = s;

	plist->size++;
}

void DCListShow(DCList* plist)//显示链表 3
{
	DCListNode* p = plist->first->next;
	while (p != plist->first)//当p循环到头节点就停止
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void DCListPopBack(DCList* plist)//从尾部删除 4
{
	assert(plist);
	DCListNode* p = plist->last;//暂存尾节点
	if (p != plist->first)//如果不是空表
	{
		plist->last = p->prev;//次尾节点变成尾节点
		plist->last->next = plist->first;//尾节点连接到首节点
		plist->first->prev = plist->last;//首节点连接到尾节点

		free(p);
		plist->size--;
	}
}

void DCListPopFront(DCList* plist)//从头部删除 5
{
	assert(plist);

	DCListNode* p;
	if (plist->size == 0)//如果是空链表，直接返回
		return;

	p = plist->first->next;

	p->prev->next = p->next;
	p->next->prev = p->prev;

	free(p);
	plist->size--;
	if (plist->size == 0)//如果删除的结点是最后一个节点则修改last的指向
		plist->last = plist->first;

}

size_t DCListLength(DCList* plist)//查看表长 6
{
	return plist->size;
}

void DCListInsertByVal(DCList* plist, ElemType x)//按值插入 8 （前提链表要进行升序排序）
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(x);
	DCListNode* p = plist->first->next;
	while (p != plist->first && x > p->data)
		p = p->next;
	if (p == plist->first)//插入的元素，排在最后一个位置
		plist->last = s;

	s->next = p;//s的后继改为p
	s->prev = p->prev;//s的前驱改为p
	s->prev->next = s;//s前驱节点的后继改为s
	s->next->prev = s;//后继节点的前驱改为s
}

void DCListDeleteByVal(DCList* plist, ElemType key)//按值删除 10
{
	assert(plist);
	DCListNode* p = DCListFind(plist, key);
	if (p != NULL)
	{
		if (p == plist->last) //需要判断是否是最后一个节点
			plist->last = p->prev;

		p->prev->next = p->next;
		p->next->prev = p->prev;

		free(p);
		plist->size--;
	}
}

DCListNode* DCListFind(DCList* plist, ElemType key)//查找元素 12
{
	assert(plist);
	DCListNode* p = plist->first->next;
	while (p != plist->first && p->data != key)
		p = p->next;
	if (p == plist->first)
		return NULL;
	return p;
}
void DCListReverse(DCList* plist)//位置翻转 14
{
	assert(plist);
	DCListNode* p, * q;
	if (plist->size <= 1)//如果是空表或者只有一个数据节点
		return;

	p = plist->first->next;//次首节点赋值给P
	q = p->next;
	plist->last = p;//尾节点转为p
	plist->last->next = plist->first;//尾连接到首
	plist->first->prev = plist->last;//首连接到尾

	while (q != plist->first)//将剩余的结点进行头插
	{
		p = q;
		q = q->next;

		p->next = plist->first->next;//p结点连接到次首节点
		p->next->prev = p;//次首节点连接到p
		p->prev = plist->first;////p结点连接到首节点
		p->prev->next = p;//首节点连接到p
	}
}
void DCListClear(DCList* plist)//清除 （清除所有元素，保存头节点）16
{
	assert(plist);
	DCListNode* p = plist->first->next;
	if (plist->size == 0)
		return;
	while (p != plist->first)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = plist->first->next;
	}
	plist->size = 0;
	plist->last = plist->first;
}
void DCListDestroy(DCList* plist)//摧毁（把数据表直接释放） 17
{
	DCListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
	plist->size = 0;
}

#endif


