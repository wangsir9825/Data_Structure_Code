#ifndef _LINKTREE_H_
#define _LINKTREE_H_

#include"Sysutil.h"
#include"LinkQueue.h"
#include"LinkStack.h"

#define TreeElemType char // ����Ԫ������

//�������νڵ�
typedef struct BinTreeNode
{
	TreeElemType data; // ������
	struct BinTreeNode* leftChild; // ��ָ��
	struct BinTreeNode* rightChild; // ��ָ��
}BinTreeNode;

//�������νṹ
typedef BinTreeNode* BinTree;

void BinTreeInit(BinTree* t); // ��������ʼ��
void BinTreeCreate_1(BinTree* t); // ��һ�ִ�����������ʽ
BinTree BinTreeCreate_2(); // �ڶ��ִ�����������ʽ
BinTree BinTreeCreate_3(const char* str, int* i); // ��3�ִ�����������ʽ
BinTree BinTreeCreate_VLR_LVR(const char* vlr, const char* lvr, int n); // ����ǰ��������������ָ��������ṹ��n�ǽڵ����
BinTree BinTreeCreate_LVR_LRV(const char* lvr, const char* lrv, int n); // ��������ͺ����������ָ��������ṹ

//�ݹ����
void PreOrder(BinTree t); // ǰ�����
void InOrder(BinTree t); // �������
void PostOrder(BinTree t); // �������
void LevelOrder(BinTree t); // ��α���
//
////�ǵݹ����
void PreOrder_Nor(BinTree t); // ǰ�����
void InOrder_Nor(BinTree t); // �������
void PostOrder_Nor(BinTree t); // �������


size_t Size(BinTree t); // ��ȡ�������ڵ����
size_t Height(BinTree t); // ��������ĸ߶�
BinTreeNode* Find(BinTree t, TreeElemType key); // ����ĳ���ڵ�
BinTreeNode* Parent(BinTree t, BinTreeNode* s); // ����ָ���ڵ�ĸ��ڵ�

BinTree Clone(BinTree t); // ��¡�������������
bool    Equal(BinTree t1, BinTree t2); // �ж������������Ƿ����

void BinTreeDestroy(BinTree* t);

void BinTreeInit(BinTree* t) // ��ʼ��Ϊ����
{
	*t = NULL;
}
// ����ǰ�򴴽������������ַ�ʽ�����������ʽ��BC##DE##F##G#H##����#����NULL��
void BinTreeCreate_1(BinTree* t) // ��һ�ַ�ʽ������Ϊ����ָ��
{
	TreeElemType item;
	scanf("%c", &item);
	if (item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item; // �������
		BinTreeCreate_1(&((*t)->leftChild)); // ����������
		BinTreeCreate_1(&((*t)->rightChild)); // ����������
	}
}
BinTree BinTreeCreate_2() // �ڶ��ַ�ʽ���޲�
{
	TreeElemType item;
	scanf("%c", &item);
	if (item == '#')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item; // �������
		t->leftChild = BinTreeCreate_2(); // ����������
		t->rightChild = BinTreeCreate_2();; // ����������
		return t;
	}
}
BinTree BinTreeCreate_3(const char* str, int* i) // ��3�ַ�ʽ�������ַ���������������
{
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*i]; // �������
		(*i)++;
		t->leftChild = BinTreeCreate_3(str, i); // ����������
		(*i)++;
		t->rightChild = BinTreeCreate_3(str, i); // ����������
		return t;
	}
}
// ����ǰ��������������ָ��������ṹ��n�ǽڵ����
BinTree BinTreeCreate_VLR_LVR(const char* vlr, const char* lvr, int n)
{
	if (n == 0)
		return NULL;

	int k = 0;
	while (lvr[k] != vlr[0]) // �������������в��Ҹ��ڵ�
		k++;

	BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode)); // ����ռ�
	assert(t != NULL);
	t->data = lvr[k]; // ���ֵ

	t->leftChild = BinTreeCreate_VLR_LVR(vlr + 1, lvr, k); // ����������
	t->rightChild = BinTreeCreate_VLR_LVR(vlr + k + 1, lvr + k + 1, n - k - 1); // ����������

	return t;
}
// ��������ͺ����������ָ��������ṹ��n�ǽڵ����
BinTree BinTreeCreate_LVR_LRV(const char* lvr, const char* lrv, int n)
{
	//1���ִӺ������������ҵ����ڵ�
	//2���ȴ�������
	//3���ڴ�������
	if (n == 0)
		return NULL;

	int k = 0;
	while (lvr[k] != lrv[n - 1])// �������������в��Ҹ��ڵ�
		k++;

	BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = lvr[k];

	t->rightChild = BinTreeCreate_LVR_LRV(lvr + k + 1, lrv + k, n - k - 1);// ����������
	t->leftChild = BinTreeCreate_LVR_LRV(lvr, lrv, k); // ����������

	return t;
}

void PreOrder(BinTree t) // ǰ����� VLR
{
	if (t != NULL)
	{
		printf("%c ", t->data);  // ���ʸ��ڵ�
		PreOrder(t->leftChild); // �ݹ����������
		PreOrder(t->rightChild); // �ݹ����������
	}
}
void InOrder(BinTree t) // ������� LVR
{
	if (t != NULL)
	{
		InOrder(t->leftChild);  // �ݹ����������
		printf("%c ", t->data); // ���ʸ��ڵ�
		InOrder(t->rightChild); // �ݹ����������
	}
}
void PostOrder(BinTree t) // ������� LRV
{
	if (t != NULL)
	{
		PostOrder(t->leftChild); // �ݹ����������
		PostOrder(t->rightChild); // �ݹ����������
		printf("%c ", t->data); // �ݹ���ʸ��ڵ�
	}
}
void LevelOrder(BinTree t) // ��α���
{
	if (t != NULL) // ������в�Ϊ��
	{
		LinkQueue Q;
		LinkQueueInit(&Q);

		LinkQueueEn(&Q, t); // �ڵ����
		while (!LinkQueueEmpty(&Q)) // ������в�Ϊ��
		{
			BinTreeNode* p = LinkQueueFront(&Q); // ȡ��ͷԪ��
			LinkQueueDe(&Q); // ����
			printf("%c ", p->data); // 
			if (p->leftChild != NULL)
				LinkQueueEn(&Q, p->leftChild); // �������
			if (p->rightChild != NULL)
				LinkQueueEn(&Q, p->rightChild);  // �������
		}
	}
}
void PreOrder_Nor(BinTree t) // �ǵݹ�ǰ�����
{
	if (t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);

		LinkStackPush(&st, t); // ��ջ
		while (!LinkStackEmpty(&st))
		{
			BinTreeNode* p = LinkStackTop(&st); // ȡջ��
			LinkStackPop(&st); // ��ջ

			printf("%c ", p->data);
			if (p->rightChild != NULL)
				LinkStackPush(&st, p->rightChild); // ������ջ
			if (p->leftChild != NULL)
				LinkStackPush(&st, p->leftChild); // ������ջ
		}
	}
}

void InOrder_Nor(BinTree t) // �ǵݹ��������
{
	if (t != NULL) // ���������
	{
		LinkStack st;
		LinkStackInit(&st);

		BinTreeNode* p;

		LinkStackPush(&st, t); // ���ڵ���ջ

		while (!LinkStackEmpty(&st)) // �����ջ���վ�ѭ��
		{
			while (t && t->leftChild != NULL)
			{
				LinkStackPush(&st, t->leftChild); // ��������ջ
				t = t->leftChild;
			}

			p = LinkStackTop(&st); // ȡջ��
			LinkStackPop(&st); // ��ջ
			printf("%c ", p->data);

			t = p->rightChild; // ����������
			if (t != NULL)
				LinkStackPush(&st, t); // ��ջ
		}
	}
}
/*   // �ǵݹ���������ڶ���д��
void InOrder_Nor(BinTree t)
{
	if(t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		BinTreeNode *p;
		while(t || !LinkStackEmpty(&st))
		{
			while(t)
			{
				LinkStackPush(&st, t);
				t = t->leftChild;
			}
			p = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c ", p->data);

			t = p->rightChild;
		}
	}
}
*/
void PostOrder_Nor(BinTree t) // �ǵݹ�������
{
	if (t != NULL) // ���������
	{
		LinkStack st;
		LinkStackInit(&st); // ��ʼ��ջ

		BinTreeNode* p, * prev = t; //prev����ǰ�ڵ��ǰ�����ʽڵ�
		while (t || !LinkStackEmpty(&st)) // ��������ջ����
		{
			while (t)
			{
				LinkStackPush(&st, t); // ��ջ
				t = t->leftChild;
			}
			
			p = LinkStackTop(&st); // ȡջ��
			if (p->rightChild == NULL || p->rightChild == prev) // �����ǰջ���ڵ��������Ϊ�ջ����������Ѿ����ʹ�
			{ 
				printf("%c ", p->data);
				LinkStackPop(&st); //��ջ
				prev = p; //����prev���ʽڵ�
			}
			else
				t = p->rightChild;
		}
	}
}


size_t Size(BinTree t) // ��ȡ�������ڵ����
{
	if (t == NULL)
		return 0;
	else
		return Size(t->leftChild) + Size(t->rightChild) + 1; // �ݹ���ڵ����
}
size_t Height(BinTree t) // ��������ĸ߶�
{
	if (t == NULL)
		return 0;
	else
	{
		int left_h = Height(t->leftChild); // ���������߶�
		int right_h = Height(t->rightChild); // ���������߶�
		return (left_h > right_h ? left_h : right_h) + 1; // ������ߵĸ߶ȣ������˼��ϸ��ڵ�
	}
}

BinTreeNode* Find(BinTree t, TreeElemType key) // ����ĳ���ڵ�
{
	BinTreeNode* p;

	if (t == NULL || t->data == key)
		return t;

	p = Find(t->leftChild, key); // ��������������������������ҵ�����������������
	if (p != NULL) //˵���������ҵ���
		return p;
	return Find(t->rightChild, key);
}

BinTreeNode* Parent(BinTree t, BinTreeNode* s) // ����ָ���ڵ�ĸ��ڵ�
{
	BinTreeNode* p;

	if (t == NULL || t == s) // ���������Ϊ�ղ��Ҳ��ҵ��Ǹ��ڵ㣨���ڵ��޸��ڵ㣩
		return NULL;

	if (t->leftChild == s || t->rightChild == s) // ���t��s�ĸ��ڵ��򷵻�t
		return t;
	p = Parent(t->leftChild, s); // ��������������������������ҵ�����������������
	if (p != NULL)
		return p;
	return Parent(t->rightChild, s);
}

BinTree Clone(BinTree t) // ��¡�������������
{
	if (t == NULL)
		return NULL;
	else
	{
		BinTreeNode* new_t = (BinTreeNode*)malloc(sizeof(BinTreeNode)); // ����һ���ڵ�
		assert(new_t != NULL);
		new_t->data = t->data; // ���ֵ
		new_t->leftChild = Clone(t->leftChild); // ��¡������
		new_t->rightChild = Clone(t->rightChild); // ��¡������

		return new_t;
	}
}

bool Equal(BinTree t1, BinTree t2) // �ж������������Ƿ����
{
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;

	return (t1->data == t2->data) // ���������
		&& Equal(t1->leftChild, t2->leftChild) // ���������
		&& Equal(t1->rightChild, t2->rightChild); // ���������
}

void BinTreeDestroy(BinTree* t) // �ͷŶ�����
{
	if (*t != NULL)
	{
		BinTreeDestroy(&((*t)->leftChild));
		BinTreeDestroy(&((*t)->rightChild));
		free(*t);
		*t = NULL;
	}
}


#endif /* _LINKTREE_H_ */

