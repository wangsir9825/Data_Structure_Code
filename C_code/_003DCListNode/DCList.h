#ifndef _DCLIST_H_
#define _DCLIST_H_

#include"Sysutil.h"

#define ElemType int

//��ͷ���˫��ѭ������double cycle��
typedef struct DCListNode
{
	ElemType data;//������
	struct DCListNode* prev;//ǰ���ڵ�ָ��
	struct DCListNode* next;//��̽ڵ�
}DCListNode;

typedef struct DCList//�������
{
	DCListNode* first;//ָ��������׽ڵ�
	DCListNode* last;//ָ�������β�ڵ�
	size_t      size;//Ԫ�ؽڵ�ĸ���
}DCList;
DCListNode* _BuyDCListNode(ElemType x)
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));//����һ�����
	assert(s != NULL);
	s->next = s->prev = NULL;
	s->data = x;
	return s;
}


void DCListInit(DCList* plist);//��ʼ��
void DCListPushBack(DCList* plist, ElemType x);	//β�� 1
void DCListPushFront(DCList* plist, ElemType x);// ͷ�� 2
void DCListShow(DCList* plist);//��ʾ���� 3
void DCListPopBack(DCList* plist);//��β��ɾ�� 4
void DCListPopFront(DCList* plist);//��ͷ��ɾ�� 5
size_t DCListLength(DCList* plist);//�鿴�� 6
void DCListInsertByVal(DCList* plist, ElemType x);//��ֵ���� 8
void DCListDeleteByVal(DCList* plist, ElemType key);//��ֵɾ�� 10
DCListNode* DCListFind(DCList* plist, ElemType key);//����Ԫ�� 12
void DCListReverse(DCList* plist); //λ�÷�ת 14
void DCListClear(DCList* plist);//��� ���������Ԫ�أ�16
void DCListDestroy(DCList* plist);//�ݻ٣������ݱ�ֱ���ͷţ� 17



void DCListInit(DCList* plist)//��ʼ��
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(0);//ͷ�ڵ�
	plist->first = plist->last = s;// ��Ϊֻ��һ���ڵ㣬������β�ڵ�ָ����ͬ
	//���ѭ������
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size = 0;
}

void DCListPushBack(DCList* plist, ElemType x)//β�� 1
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(x);
	s->prev = plist->last;//�½ڵ�����β�ڵ�
	plist->last->next = s;//β�ڵ��ɴ�β�ڵ㣨�������ڶ����ڵ㣩��s��Ϊβ�ڵ�
	plist->last = s;//last����Ϊβ�ڵ�

	plist->last->next = plist->first;//β�ڵ����ӵ��׽ڵ�
	plist->first->prev = plist->last;//�׽ڵ����ӵ�β�ڵ�
	plist->size++;//�ڵ�����1
}

void DCListPushFront(DCList* plist, ElemType x)// ͷ�� 2
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(x);
	//���²���˳�򲻿���
	s->next = plist->first->next;//�½ڵ����ӵ����׽ڵ�
	plist->first->next->prev = s;//���׽ڵ��������½ڵ�
	plist->first->next = s;//�׽ڵ����ӵ��½ڵ�
	s->prev = plist->first;//�½ڵ����ӵ����׽ڵ�

	if (plist->last == plist->first)//�������ֻ��һ��ͷ�ڵ㣬����Ҫ�޸�last��ָ��
		plist->last = s;

	plist->size++;
}

void DCListShow(DCList* plist)//��ʾ���� 3
{
	DCListNode* p = plist->first->next;
	while (p != plist->first)//��pѭ����ͷ�ڵ��ֹͣ
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void DCListPopBack(DCList* plist)//��β��ɾ�� 4
{
	assert(plist);
	DCListNode* p = plist->last;//�ݴ�β�ڵ�
	if (p != plist->first)//������ǿձ�
	{
		plist->last = p->prev;//��β�ڵ���β�ڵ�
		plist->last->next = plist->first;//β�ڵ����ӵ��׽ڵ�
		plist->first->prev = plist->last;//�׽ڵ����ӵ�β�ڵ�

		free(p);
		plist->size--;
	}
}

void DCListPopFront(DCList* plist)//��ͷ��ɾ�� 5
{
	assert(plist);

	DCListNode* p;
	if (plist->size == 0)//����ǿ�����ֱ�ӷ���
		return;

	p = plist->first->next;

	p->prev->next = p->next;
	p->next->prev = p->prev;

	free(p);
	plist->size--;
	if (plist->size == 0)//���ɾ���Ľ�������һ���ڵ����޸�last��ָ��
		plist->last = plist->first;

}

size_t DCListLength(DCList* plist)//�鿴�� 6
{
	return plist->size;
}

void DCListInsertByVal(DCList* plist, ElemType x)//��ֵ���� 8 ��ǰ������Ҫ������������
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(x);
	DCListNode* p = plist->first->next;
	while (p != plist->first && x > p->data)
		p = p->next;
	if (p == plist->first)//�����Ԫ�أ��������һ��λ��
		plist->last = s;

	s->next = p;//s�ĺ�̸�Ϊp
	s->prev = p->prev;//s��ǰ����Ϊp
	s->prev->next = s;//sǰ���ڵ�ĺ�̸�Ϊs
	s->next->prev = s;//��̽ڵ��ǰ����Ϊs
}

void DCListDeleteByVal(DCList* plist, ElemType key)//��ֵɾ�� 10
{
	assert(plist);
	DCListNode* p = DCListFind(plist, key);
	if (p != NULL)
	{
		if (p == plist->last) //��Ҫ�ж��Ƿ������һ���ڵ�
			plist->last = p->prev;

		p->prev->next = p->next;
		p->next->prev = p->prev;

		free(p);
		plist->size--;
	}
}

DCListNode* DCListFind(DCList* plist, ElemType key)//����Ԫ�� 12
{
	assert(plist);
	DCListNode* p = plist->first->next;
	while (p != plist->first && p->data != key)
		p = p->next;
	if (p == plist->first)
		return NULL;
	return p;
}
void DCListReverse(DCList* plist)//λ�÷�ת 14
{
	assert(plist);
	DCListNode* p, * q;
	if (plist->size <= 1)//����ǿձ����ֻ��һ�����ݽڵ�
		return;

	p = plist->first->next;//���׽ڵ㸳ֵ��P
	q = p->next;
	plist->last = p;//β�ڵ�תΪp
	plist->last->next = plist->first;//β���ӵ���
	plist->first->prev = plist->last;//�����ӵ�β

	while (q != plist->first)//��ʣ��Ľ�����ͷ��
	{
		p = q;
		q = q->next;

		p->next = plist->first->next;//p������ӵ����׽ڵ�
		p->next->prev = p;//���׽ڵ����ӵ�p
		p->prev = plist->first;////p������ӵ��׽ڵ�
		p->prev->next = p;//�׽ڵ����ӵ�p
	}
}
void DCListClear(DCList* plist)//��� ���������Ԫ�أ�����ͷ�ڵ㣩16
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
void DCListDestroy(DCList* plist)//�ݻ٣������ݱ�ֱ���ͷţ� 17
{
	DCListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
	plist->size = 0;
}

#endif


