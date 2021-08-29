#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include"Sysutil.h"

#define ElemType int//Ԫ������

//��ͷ������
typedef struct SListNode//����������
{
	ElemType data; //������
	struct SListNode* next; //ָ����
}SListNode;

typedef struct SList//�������װΪ�ṹ�壬��������������ṹ���ڲ��������������ָ�룬���ָ��Ҫָ������ĵ�һ����㣬�����Ϳ���������������������
{
	SListNode* head;  //��Ա��װ
}SList;

void SListInit(SList* plist);//��ʼ��
void SListPushBack(SList* plist, ElemType x);	//β�� 1
void SListPushFront(SList* plist, ElemType x);	// ͷ�� 2
void SListShow(SList* plist);					//��ʾ���� 3
void SListPopBack(SList* plist);				//��β��ɾ�� 4
void SListPopFront(SList* plist);				//��ͷ��ɾ�� 5
int SListLength(SList* plist);					//�鿴�� 6
void SListInsertByVal(SList* plist, ElemType x);//��ֵ���� 8
void SListDeleteByVal(SList* plist, ElemType key);//��ֵɾ�� 10

SListNode* SeqListFind(SList* plist, ElemType key);//����Ԫ�� 12
void SListSort(SList* plist);//�������� 13
void SListRemoveAll(SList* plist, ElemType key);//�Ƴ�����ָ��Ԫ�� 15
void SListClear(SList* plist);//��� ���������Ԫ�أ�16 
void SListDestroy(SList* plist);//�ݻ٣������ݱ�ֱ���ͷţ� 17



void SListReverse(SList* plist);

SListNode* _Buynode()//�����㣬�༴�������
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = 0;//��ʼ��������Ϊ0
	s->next = NULL;
	return s;
}

void SListInit(SList* plist)//�������ʼ��Ϊ�������������ʼ�����������һ�β���ʱ������ͷ��ͻ����ԭ���������û�еĽ�����־����һ�ν���β���򲻻����
{
	plist->head = NULL;//�����׽���ָ��Ϊ�գ�������ָ��ָ�������Ϊ��������
}

void SListPushBack(SList* plist, ElemType x)//β�� 1
{
	assert(plist);

	SListNode* s = _Buynode();//���ȴ���һ���½��
	s->data = x;//Ȼ����Ҫ�����ֵ����������

	SListNode* p = plist->head;//��pָ������ĵ�һ�����
	if (p == NULL)//�������Ϊ�գ����½ڵ���Ϊ����ĵ�һ�����
		plist->head = s;
	else
	{
		while (p->next != NULL)//����p���������β�����
			p = p->next;
		p->next = s;//�ҵ����һ���ڵ�󣬽��½ڵ�ճ�����������
	}

}

void SListPushFront(SList* plist, ElemType x)// ͷ�� 2
{
	assert(plist);//�Ϸ����
	SListNode* s = _Buynode(); //�����½ڵ㣬�洢����
	s->data = x;

	s->next = plist->head;//���½ڵ�ճ��������ǰ��
	plist->head = s;//���½ڵ�����Ϊ��һ�����
}
void SListShow(SList* plist)//��ʾ���� 3
{
	SListNode* p = plist->head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;//ת����һ�����
	}
	printf("Over.\n");
}
void SListPopBack(SList* plist)//��β��ɾ�� 4 ����ɾ�����һ����㣩
{
	assert(plist);//����Ľṹ��ָ�벻��Ϊ�գ����������Ϊ��
	SListNode* p = plist->head;

	if (p != NULL) //�������Ϊ�������򲻽���ɾ��
	{
		if (p->next == NULL) // �������ֻ��һ���ڵ㣬��ý��Ϊ���һ�����
			plist->head = NULL;//����������Ϊ������
		else//��������ж�����
		{
			SListNode* pre = NULL;
			while (p->next != NULL)//���ҵ����һ�����
			{
				pre = p;
				p = p->next;
			}
			pre->next = NULL;//�ҵ����һ�����֮�󣬽���ɾ��
		}
		free(p);//�ݻ����һ����㣨�ͷŽ�㣩
	}
}

void SListPopFront(SList* plist)//��ͷ��ɾ�� 5
{
	assert(plist);
	SListNode* p = plist->head;//��pָ������ĵ�һ�����
	if (p != NULL)
	{
		plist->head = p->next;//���ڶ����������Ϊ��һ�����
		free(p);////�ݻ�ԭ��һ����㣨�ͷŽ�㣩
	}
}



int SListLength(SList* plist)//�鿴�� 6
{
	assert(plist);
	int len = 0;
	SListNode* p = plist->head;

	while (p != NULL)//������������
	{
		len++;
		p = p->next;
	}
	return len;
}
void SListInsertByVal(SList* plist, ElemType x)//��ֵ���� 8
{
	assert(plist);
	SListNode* s = _Buynode();//ΪҪ�����ֵ����һ����Ŀ��ڵ㡱
	s->data = x;//����ֵ����Ŀ��ڵ�

	if (plist->head == NULL)//����ǿ�������ֱ�Ӳ����׽ڵ���
		plist->head = s;
	else
	{
		SListNode* p = plist->head;
		SListNode* pre = NULL;
		while (p != NULL && x > p->data)//Ѱ��Ŀ��ڵ��ǰ���ڵ�ͺ����ڵ�
		{
			pre = p;
			p = p->next;
		}

		if (pre == NULL) //���pre=NULL��˵��Ҫ�������ͷ������
		{
			s->next = p;  //��������׽ڵ㣨�������ڵ㣩������Ŀ��ڵ��
			plist->head = s;//��Ŀ��ڵ�����Ϊ������׽ڵ�
		}
		else
		{
			s->next = pre->next;//�������ڵ�������Ŀ��ڵ��
			pre->next = s;//��Ŀ��ڵ�������ǰ���ڵ��
		}
	}
}

void SListDeleteByVal(SList* plist, ElemType key)//��ֵɾ�� 10
{
	assert(plist);
	//�ڵ�
	SListNode* p = plist->head;
	SListNode* pre = NULL;//���ڱ���Ŀ��ڵ��ǰ���ڵ�
	while (p != NULL && p->data != key)//Ѱ��Ҫɾ����Ŀ��ڵ�
	{
		pre = p;
		p = p->next;
	}

	if (p != NULL)  //����ҵ�ɾ���Ľڵ��ɾ������p=NULL����˵������û��Ŀ��ڵ�
	{
		if (pre == NULL) //���pre=NULL��˵��Ҫɾ���Ľڵ�Ϊ��һ���ڵ�
			plist->head = p->next;//���ڶ����ڵ���Ϊ�׽ڵ�
		else
			pre->next = p->next;//��ǰ���ڵ�������ڵ�����

		free(p);//�ͷ�Ŀ��ڵ�
	}
}
SListNode* SeqListFind(SList* plist, ElemType key)//����Ԫ�� 12
{
	//�ҵ����ؽڵ�ĵ�ַ
	//�Ҳ�������NULL
	assert(plist);
	SListNode* p = plist->head;

	while (p != NULL && p->data != key)//��Ҫд��while (p->data != key && p != NULL)�����򵱲��ҵ�ֵ������ʱ������������ԭ����ǵ�p=NULLʱ��p->dataΪ�Ƿ�����
		p = p->next;
	return p;
}
void SListSort(SList* plist)//�������� 13
{
	assert(plist);
	SListNode* p, * q;

	if (plist->head == NULL || plist->head->next == NULL)
		return;

	//�Ͽ�����
	p = plist->head->next;
	plist->head->next = NULL;

	//ѭ����ֵ����
	q = p;
	while (q != NULL)
	{
		q = q->next;
		SListNode* t = plist->head;
		SListNode* pre = NULL;
		while (t != NULL && p->data > t->data)  //Ѱ��p�������еĲ���λ��
		{
			pre = t;
			t = t->next;
		}
		if (pre == NULL) //��ͷ������
		{
			p->next = plist->head;
			plist->head = p;
		}
		else
		{
			p->next = pre->next;
			pre->next = p;
		}
		p = q;
	}
}
void SListReverse(SList* plist)//����ת�� 14
{
	assert(plist);
	SListNode* p, * q;
	if (plist->head == NULL)//����ǿ�����
		return;

	if (plist->head->next == NULL) //���ֻ��һ���ڵ㲻��Ҫת��
		return;

	//1 �и�����
	p = plist->head->next;
	plist->head->next = NULL;

	//2 ��ʣ�������ڵ����һһͷ��
	q = p;
	while (q != NULL)
	{
		q = q->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}
}
void SListRemoveAll(SList* plist, ElemType key)//�Ƴ�����ָ��Ԫ�� 15
{
	assert(plist);
	SListNode* p = plist->head;
	SListNode* pre = NULL;

	while (p != NULL)
	{
		while (p != NULL && p->data != key)
		{
			pre = p;
			p = p->next;
		}
		if (p != NULL)
		{
			if (pre == NULL)//���Ҫɾ���ڵ��ǵ�һ���ڵ�
				plist->head = p->next;
			else//���Ҫɾ���ڵ����м�ڵ�
				pre->next = p->next;
			free(p);//�ͷ�data=key�Ľڵ�
		}
		if (NULL != pre)//
			p = pre->next;
		else
			p = plist->head;//��ͷ��ʼ
	}
}
void SListClear(SList* plist)//��� ���������Ԫ�أ�16 
{
	assert(plist);
	SListNode* p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;  //��ͷ����ɾ
		free(p);
		p = plist->head;
	}
}

void SListDestroy(SList* plist)//�ݻ٣������ݱ�ֱ���ͷţ� 17
{
	SListClear(plist);
}




//��ʵ��������⣬���Կ����´��������⣨δ���ԣ�

///////////////////////////////// ����Ϊ���ã���ͷ�������ʵ�� Singly Linked List///////////////////////////////
#if 0
typedef struct ListNode//����������
{
	int data; //������
	struct ListNode *next;
}ListNode;

typedef ListNode* List;//List������ָ��
void ListInit(List *head)  //��ʼ��
{
	*head = NULL;
}

//1->2->3->4->....->10
void ListCreate_Tail(List *head)//β�巨����������
{
	//�����һ�����
	*head = (ListNode*)malloc(sizeof(ListNode));
	assert(*head != NULL);
	(*head)->data = 1;
	//����ʣ��Ľ��
	ListNode *p = *head;
	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;
		//���ӽڵ�
		p->next = s;
		p = s;
	}
}
//10->9->8->7>....->1
void ListCreate_Head(List *head)//ͷ�巨����������
{
	//�����һ�����
	*head = (ListNode*)malloc(sizeof(ListNode));
	assert(*head != NULL);
	(*head)->data = 1;
	(*head)->next = NULL;//��ʱ���һ�������Ľ�㣬��Ϊ���һ����㣬����Ҫ��ֵΪNULL��Ϊ������־
	//����ʣ��Ľ��
	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;

		s->next = *head;
		*head = s;
	}
}

void ListShow(List head)
{
	ListNode *p = head;
	while(p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

#endif 

/////////////////////////��ͷ�������ʵ��////////////////////////////////////////////
#if 0
typedef struct ListNode//����������
{
	int data; //������
	struct ListNode* next;
}ListNode;

typedef ListNode* List;//List������ָ��

void ListInit(List *head)  //��ʼ�����������ͷ��㣬�������κ����ݻ�ֻ��������ĳ��ȣ�
{
	*head = (ListNode *)malloc(sizeof(ListNode));
	*head != NULL;
	(*head)->next = NULL;
}

//1->2->3->4->....->10
void ListCreate_Tail(List* head)//β�巨����������
{
	//����ʣ����ڲ����
	ListNode* p = *head;
	for (int i = 2; i <= 10; ++i)
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;
		//���ӽڵ�
		p->next = s;
		p = s;
	}
}
//β�巨����������(������)
void ListCreate(List *head)
{
	ListNode *p = *head;
	for(int i=1; i<=10; ++i)
	{
		p = p->next = (ListNode *)malloc(sizeof(ListNode));
		assert(p != NULL);
		p->data = i;
		p->next = NULL;
	}
}
//10->9->8->7>....->1
void ListCreate_Head(List* head)//ͷ�巨����������
{
	//����ʣ��Ľ��
	for (int i = 2; i <= 10; ++i)
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;

		s->next = *head;
		*head = s;
	}
}
void ListShow(List head)
{
	ListNode* p = head->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}


#endif

#endif /* _LINKEDLIST_H_ */