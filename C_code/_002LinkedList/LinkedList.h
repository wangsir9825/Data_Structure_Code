#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include"Sysutil.h"

#define ElemType int//元素类型

//无头单链表
typedef struct SListNode//定义链表结点
{
	ElemType data; //数据域
	struct SListNode* next; //指针域
}SListNode;

typedef struct SList//将链表封装为结构体，这样更方便管理（结构体内部保存的是链表结点指针，这个指针要指向链表的第一个结点，这样就可以用它来代表整个链表）
{
	SListNode* head;  //成员封装
}SList;

void SListInit(SList* plist);//初始化
void SListPushBack(SList* plist, ElemType x);	//尾插 1
void SListPushFront(SList* plist, ElemType x);	// 头插 2
void SListShow(SList* plist);					//显示链表 3
void SListPopBack(SList* plist);				//从尾部删除 4
void SListPopFront(SList* plist);				//从头部删除 5
int SListLength(SList* plist);					//查看表长 6
void SListInsertByVal(SList* plist, ElemType x);//按值插入 8
void SListDeleteByVal(SList* plist, ElemType key);//按值删除 10

SListNode* SeqListFind(SList* plist, ElemType key);//查找元素 12
void SListSort(SList* plist);//链表排序 13
void SListRemoveAll(SList* plist, ElemType key);//移除所有指定元素 15
void SListClear(SList* plist);//清除 （清除所有元素）16 
void SListDestroy(SList* plist);//摧毁（把数据表直接释放） 17



void SListReverse(SList* plist);

SListNode* _Buynode()//购买结点，亦即创建结点
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = 0;//初始结点的内容为0
	s->next = NULL;
	return s;
}

void SListInit(SList* plist)//将链表初始化为空链表，如果不初始化，对链表第一次操作时，进行头插就会出错，原因就是链表没有的结束标志。第一次进行尾插则不会出错
{
	plist->head = NULL;//链表首结点的指针为空，则代表该指针指向的链表为“空链表”
}

void SListPushBack(SList* plist, ElemType x)//尾插 1
{
	assert(plist);

	SListNode* s = _Buynode();//首先创建一个新结点
	s->data = x;//然后将需要插入的值放入这个结点

	SListNode* p = plist->head;//令p指向链表的第一个结点
	if (p == NULL)//如果链表为空，则将新节点作为链表的第一个结点
		plist->head = s;
	else
	{
		while (p->next != NULL)//利用p查找链表的尾部结点
			p = p->next;
		p->next = s;//找到最后一个节点后，将新节点粘接在链表后面
	}

}

void SListPushFront(SList* plist, ElemType x)// 头插 2
{
	assert(plist);//合法检查
	SListNode* s = _Buynode(); //创建新节点，存储数据
	s->data = x;

	s->next = plist->head;//将新节点粘接在链表前面
	plist->head = s;//将新节点设置为第一个结点
}
void SListShow(SList* plist)//显示链表 3
{
	SListNode* p = plist->head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;//转到下一个结点
	}
	printf("Over.\n");
}
void SListPopBack(SList* plist)//从尾部删除 4 （即删除最后一个结点）
{
	assert(plist);//传入的结构体指针不能为空，但链表可以为空
	SListNode* p = plist->head;

	if (p != NULL) //如果链表为空链表，则不进行删除
	{
		if (p->next == NULL) // 如果链表只有一个节点，则该结点为最后一个结点
			plist->head = NULL;//则将链表设置为空链表
		else//如果链表有多个结点
		{
			SListNode* pre = NULL;
			while (p->next != NULL)//先找到最后一个结点
			{
				pre = p;
				p = p->next;
			}
			pre->next = NULL;//找到最后一个结点之后，将其删除
		}
		free(p);//摧毁最后一个结点（释放结点）
	}
}

void SListPopFront(SList* plist)//从头部删除 5
{
	assert(plist);
	SListNode* p = plist->head;//令p指向链表的第一个结点
	if (p != NULL)
	{
		plist->head = p->next;//将第二个结点设置为第一个结点
		free(p);////摧毁原第一个结点（释放结点）
	}
}



int SListLength(SList* plist)//查看表长 6
{
	assert(plist);
	int len = 0;
	SListNode* p = plist->head;

	while (p != NULL)//遍历整个链表
	{
		len++;
		p = p->next;
	}
	return len;
}
void SListInsertByVal(SList* plist, ElemType x)//按值插入 8
{
	assert(plist);
	SListNode* s = _Buynode();//为要插入的值购买一个“目标节点”
	s->data = x;//将该值放入目标节点

	if (plist->head == NULL)//如果是空链表则直接插在首节点上
		plist->head = s;
	else
	{
		SListNode* p = plist->head;
		SListNode* pre = NULL;
		while (p != NULL && x > p->data)//寻找目标节点的前驱节点和后驱节点
		{
			pre = p;
			p = p->next;
		}

		if (pre == NULL) //如果pre=NULL，说明要在链表的头部插入
		{
			s->next = p;  //将链表的首节点（即后驱节点）连接在目标节点后
			plist->head = s;//将目标节点设置为链表的首节点
		}
		else
		{
			s->next = pre->next;//将后驱节点连接在目标节点后
			pre->next = s;//将目标节点连接在前驱节点后
		}
	}
}

void SListDeleteByVal(SList* plist, ElemType key)//按值删除 10
{
	assert(plist);
	//节点
	SListNode* p = plist->head;
	SListNode* pre = NULL;//用于保存目标节点的前驱节点
	while (p != NULL && p->data != key)//寻找要删除的目标节点
	{
		pre = p;
		p = p->next;
	}

	if (p != NULL)  //如果找到删除的节点就删除，当p=NULL，则说明链表没有目标节点
	{
		if (pre == NULL) //如果pre=NULL，说明要删除的节点为第一个节点
			plist->head = p->next;//将第二个节点设为首节点
		else
			pre->next = p->next;//将前驱节点与后驱节点连接

		free(p);//释放目标节点
	}
}
SListNode* SeqListFind(SList* plist, ElemType key)//查找元素 12
{
	//找到返回节点的地址
	//找不到返回NULL
	assert(plist);
	SListNode* p = plist->head;

	while (p != NULL && p->data != key)//不要写成while (p->data != key && p != NULL)，否则当查找的值不存在时，程序会崩溃，原因就是当p=NULL时，p->data为非法操作
		p = p->next;
	return p;
}
void SListSort(SList* plist)//链表排序 13
{
	assert(plist);
	SListNode* p, * q;

	if (plist->head == NULL || plist->head->next == NULL)
		return;

	//断开链表
	p = plist->head->next;
	plist->head->next = NULL;

	//循环按值插入
	q = p;
	while (q != NULL)
	{
		q = q->next;
		SListNode* t = plist->head;
		SListNode* pre = NULL;
		while (t != NULL && p->data > t->data)  //寻找p在新链中的插入位置
		{
			pre = t;
			t = t->next;
		}
		if (pre == NULL) //在头部插入
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
void SListReverse(SList* plist)//链表转置 14
{
	assert(plist);
	SListNode* p, * q;
	if (plist->head == NULL)//如果是空链表
		return;

	if (plist->head->next == NULL) //如果只有一个节点不需要转置
		return;

	//1 切割链表
	p = plist->head->next;
	plist->head->next = NULL;

	//2 将剩余的链表节点进行一一头插
	q = p;
	while (q != NULL)
	{
		q = q->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}
}
void SListRemoveAll(SList* plist, ElemType key)//移除所有指定元素 15
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
			if (pre == NULL)//如果要删除节点是第一个节点
				plist->head = p->next;
			else//如果要删除节点是中间节点
				pre->next = p->next;
			free(p);//释放data=key的节点
		}
		if (NULL != pre)//
			p = pre->next;
		else
			p = plist->head;//从头开始
	}
}
void SListClear(SList* plist)//清除 （清除所有元素）16 
{
	assert(plist);
	SListNode* p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;  //从头往后删
		free(p);
		p = plist->head;
	}
}

void SListDestroy(SList* plist)//摧毁（把数据表直接释放） 17
{
	SListClear(plist);
}




//简单实现易于理解，可以看以下代码进行理解（未测试）

///////////////////////////////// （较为常用）无头单链表简单实现 Singly Linked List///////////////////////////////
#if 0
typedef struct ListNode//定义链表结点
{
	int data; //数据域
	struct ListNode *next;
}ListNode;

typedef ListNode* List;//List定义结点指针
void ListInit(List *head)  //初始化
{
	*head = NULL;
}

//1->2->3->4->....->10
void ListCreate_Tail(List *head)//尾插法创建单链表
{
	//处理第一个结点
	*head = (ListNode*)malloc(sizeof(ListNode));
	assert(*head != NULL);
	(*head)->data = 1;
	//处理剩余的结点
	ListNode *p = *head;
	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;
		//链接节点
		p->next = s;
		p = s;
	}
}
//10->9->8->7>....->1
void ListCreate_Head(List *head)//头插法创建单链表
{
	//处理第一个结点
	*head = (ListNode*)malloc(sizeof(ListNode));
	assert(*head != NULL);
	(*head)->data = 1;
	(*head)->next = NULL;//这时候第一个创建的结点，作为最后一个结点，所以要赋值为NULL作为结束标志
	//处理剩余的结点
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

/////////////////////////带头单链表简单实现////////////////////////////////////////////
#if 0
typedef struct ListNode//定义链表结点
{
	int data; //数据域
	struct ListNode* next;
}ListNode;

typedef ListNode* List;//List定义结点指针

void ListInit(List *head)  //初始化生成链表的头结点，不保存任何内容或只保存链表的长度，
{
	*head = (ListNode *)malloc(sizeof(ListNode));
	*head != NULL;
	(*head)->next = NULL;
}

//1->2->3->4->....->10
void ListCreate_Tail(List* head)//尾插法创建单链表
{
	//处理剩余的内部结点
	ListNode* p = *head;
	for (int i = 2; i <= 10; ++i)
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;
		//链接节点
		p->next = s;
		p = s;
	}
}
//尾插法创建单链表(简洁代码)
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
void ListCreate_Head(List* head)//头插法创建单链表
{
	//处理剩余的结点
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