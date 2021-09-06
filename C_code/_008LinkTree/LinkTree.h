#ifndef _LINKTREE_H_
#define _LINKTREE_H_

#include"Sysutil.h"
#include"LinkQueue.h"
#include"LinkStack.h"

#define TreeElemType char // 树的元素类型

//定义树形节点
typedef struct BinTreeNode
{
	TreeElemType data; // 数据域
	struct BinTreeNode* leftChild; // 左指数
	struct BinTreeNode* rightChild; // 右指数
}BinTreeNode;

//定义树形结构
typedef BinTreeNode* BinTree;

void BinTreeInit(BinTree* t); // 二叉树初始化
void BinTreeCreate_1(BinTree* t); // 第一种创建二叉树方式
BinTree BinTreeCreate_2(); // 第二种创建二叉树方式
BinTree BinTreeCreate_3(const char* str, int* i); // 第3种创建二叉树方式
BinTree BinTreeCreate_VLR_LVR(const char* vlr, const char* lvr, int n); // 根据前序和中序遍历结果恢复二叉树结构，n是节点个数
BinTree BinTreeCreate_LVR_LRV(const char* lvr, const char* lrv, int n); // 根据中序和后序遍历结果恢复二叉树结构

//递归遍历
void PreOrder(BinTree t); // 前序遍历
void InOrder(BinTree t); // 中序遍历
void PostOrder(BinTree t); // 后序遍历
void LevelOrder(BinTree t); // 层次遍历
//
////非递归遍历
void PreOrder_Nor(BinTree t); // 前序遍历
void InOrder_Nor(BinTree t); // 中序遍历
void PostOrder_Nor(BinTree t); // 后序遍历


size_t Size(BinTree t); // 求取二叉树节点个数
size_t Height(BinTree t); // 求二叉树的高度
BinTreeNode* Find(BinTree t, TreeElemType key); // 查找某个节点
BinTreeNode* Parent(BinTree t, BinTreeNode* s); // 查找指定节点的父节点

BinTree Clone(BinTree t); // 克隆二叉树（深拷贝）
bool    Equal(BinTree t1, BinTree t2); // 判断两个二叉树是否相等

void BinTreeDestroy(BinTree* t);

void BinTreeInit(BinTree* t) // 初始化为空树
{
	*t = NULL;
}
// 按照前序创建二叉树的三种方式（数据输入格式：BC##DE##F##G#H##，以#代表NULL）
void BinTreeCreate_1(BinTree* t) // 第一种方式：参数为二级指针
{
	TreeElemType item;
	scanf("%c", &item);
	if (item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item; // 填充数据
		BinTreeCreate_1(&((*t)->leftChild)); // 创建左子树
		BinTreeCreate_1(&((*t)->rightChild)); // 创建右子树
	}
}
BinTree BinTreeCreate_2() // 第二种方式：无参
{
	TreeElemType item;
	scanf("%c", &item);
	if (item == '#')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item; // 填充数据
		t->leftChild = BinTreeCreate_2(); // 创建左子树
		t->rightChild = BinTreeCreate_2();; // 创建右子树
		return t;
	}
}
BinTree BinTreeCreate_3(const char* str, int* i) // 第3种方式（给定字符串创建二叉树）
{
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*i]; // 填充数据
		(*i)++;
		t->leftChild = BinTreeCreate_3(str, i); // 创建左子树
		(*i)++;
		t->rightChild = BinTreeCreate_3(str, i); // 创建右子树
		return t;
	}
}
// 根据前序和中序遍历结果恢复二叉树结构，n是节点个数
BinTree BinTreeCreate_VLR_LVR(const char* vlr, const char* lvr, int n)
{
	if (n == 0)
		return NULL;

	int k = 0;
	while (lvr[k] != vlr[0]) // 从中序遍历结果中查找父节点
		k++;

	BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode)); // 申请空间
	assert(t != NULL);
	t->data = lvr[k]; // 填充值

	t->leftChild = BinTreeCreate_VLR_LVR(vlr + 1, lvr, k); // 创建左子树
	t->rightChild = BinTreeCreate_VLR_LVR(vlr + k + 1, lvr + k + 1, n - k - 1); // 创建右子树

	return t;
}
// 根据中序和后序遍历结果恢复二叉树结构，n是节点个数
BinTree BinTreeCreate_LVR_LRV(const char* lvr, const char* lrv, int n)
{
	//1、现从后续在中序中找到根节点
	//2、先创建右树
	//3、在创建左树
	if (n == 0)
		return NULL;

	int k = 0;
	while (lvr[k] != lrv[n - 1])// 从中序遍历结果中查找父节点
		k++;

	BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = lvr[k];

	t->rightChild = BinTreeCreate_LVR_LRV(lvr + k + 1, lrv + k, n - k - 1);// 创建右子树
	t->leftChild = BinTreeCreate_LVR_LRV(lvr, lrv, k); // 创建左子树

	return t;
}

void PreOrder(BinTree t) // 前序遍历 VLR
{
	if (t != NULL)
	{
		printf("%c ", t->data);  // 访问根节点
		PreOrder(t->leftChild); // 递归访问左子树
		PreOrder(t->rightChild); // 递归访问右子树
	}
}
void InOrder(BinTree t) // 中序遍历 LVR
{
	if (t != NULL)
	{
		InOrder(t->leftChild);  // 递归访问左子树
		printf("%c ", t->data); // 访问根节点
		InOrder(t->rightChild); // 递归访问右子树
	}
}
void PostOrder(BinTree t) // 后序遍历 LRV
{
	if (t != NULL)
	{
		PostOrder(t->leftChild); // 递归访问左子树
		PostOrder(t->rightChild); // 递归访问右子树
		printf("%c ", t->data); // 递归访问根节点
	}
}
void LevelOrder(BinTree t) // 层次遍历
{
	if (t != NULL) // 如果队列不为空
	{
		LinkQueue Q;
		LinkQueueInit(&Q);

		LinkQueueEn(&Q, t); // 节点入队
		while (!LinkQueueEmpty(&Q)) // 如果队列不为空
		{
			BinTreeNode* p = LinkQueueFront(&Q); // 取队头元素
			LinkQueueDe(&Q); // 出队
			printf("%c ", p->data); // 
			if (p->leftChild != NULL)
				LinkQueueEn(&Q, p->leftChild); // 左树入队
			if (p->rightChild != NULL)
				LinkQueueEn(&Q, p->rightChild);  // 右树入队
		}
	}
}
void PreOrder_Nor(BinTree t) // 非递归前序遍历
{
	if (t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);

		LinkStackPush(&st, t); // 入栈
		while (!LinkStackEmpty(&st))
		{
			BinTreeNode* p = LinkStackTop(&st); // 取栈顶
			LinkStackPop(&st); // 出栈

			printf("%c ", p->data);
			if (p->rightChild != NULL)
				LinkStackPush(&st, p->rightChild); // 右树入栈
			if (p->leftChild != NULL)
				LinkStackPush(&st, p->leftChild); // 左树入栈
		}
	}
}

void InOrder_Nor(BinTree t) // 非递归中序遍历
{
	if (t != NULL) // 如果树不空
	{
		LinkStack st;
		LinkStackInit(&st);

		BinTreeNode* p;

		LinkStackPush(&st, t); // 根节点入栈

		while (!LinkStackEmpty(&st)) // 如果链栈不空就循环
		{
			while (t && t->leftChild != NULL)
			{
				LinkStackPush(&st, t->leftChild); // 左子树入栈
				t = t->leftChild;
			}

			p = LinkStackTop(&st); // 取栈顶
			LinkStackPop(&st); // 出栈
			printf("%c ", p->data);

			t = p->rightChild; // 访问右子树
			if (t != NULL)
				LinkStackPush(&st, t); // 入栈
		}
	}
}
/*   // 非递归中序遍历第二种写法
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
void PostOrder_Nor(BinTree t) // 非递归后序遍历
{
	if (t != NULL) // 如果树不空
	{
		LinkStack st;
		LinkStackInit(&st); // 初始化栈

		BinTreeNode* p, * prev = t; //prev代表当前节点的前驱访问节点
		while (t || !LinkStackEmpty(&st)) // 树不空且栈不空
		{
			while (t)
			{
				LinkStackPush(&st, t); // 入栈
				t = t->leftChild;
			}
			
			p = LinkStackTop(&st); // 取栈顶
			if (p->rightChild == NULL || p->rightChild == prev) // 如果当前栈顶节点的右子树为空或者右子树已经访问过
			{ 
				printf("%c ", p->data);
				LinkStackPop(&st); //出栈
				prev = p; //更新prev访问节点
			}
			else
				t = p->rightChild;
		}
	}
}


size_t Size(BinTree t) // 求取二叉树节点个数
{
	if (t == NULL)
		return 0;
	else
		return Size(t->leftChild) + Size(t->rightChild) + 1; // 递归求节点个数
}
size_t Height(BinTree t) // 求二叉树的高度
{
	if (t == NULL)
		return 0;
	else
	{
		int left_h = Height(t->leftChild); // 求左子树高度
		int right_h = Height(t->rightChild); // 求右子树高度
		return (left_h > right_h ? left_h : right_h) + 1; // 返回最高的高度，别忘了加上根节点
	}
}

BinTreeNode* Find(BinTree t, TreeElemType key) // 查找某个节点
{
	BinTreeNode* p;

	if (t == NULL || t->data == key)
		return t;

	p = Find(t->leftChild, key); // 搜索左树（先搜索左树，如果找到则无需搜索右树）
	if (p != NULL) //说明在左树找到了
		return p;
	return Find(t->rightChild, key);
}

BinTreeNode* Parent(BinTree t, BinTreeNode* s) // 查找指定节点的父节点
{
	BinTreeNode* p;

	if (t == NULL || t == s) // 如果二叉树为空并且查找的是根节点（根节点无父节点）
		return NULL;

	if (t->leftChild == s || t->rightChild == s) // 如果t是s的父节点则返回t
		return t;
	p = Parent(t->leftChild, s); // 搜索左树（先搜索左树，如果找到则无需搜索右树）
	if (p != NULL)
		return p;
	return Parent(t->rightChild, s);
}

BinTree Clone(BinTree t) // 克隆二叉树（深拷贝）
{
	if (t == NULL)
		return NULL;
	else
	{
		BinTreeNode* new_t = (BinTreeNode*)malloc(sizeof(BinTreeNode)); // 申请一个节点
		assert(new_t != NULL);
		new_t->data = t->data; // 填充值
		new_t->leftChild = Clone(t->leftChild); // 克隆左子树
		new_t->rightChild = Clone(t->rightChild); // 克隆右子树

		return new_t;
	}
}

bool Equal(BinTree t1, BinTree t2) // 判断两个二叉树是否相等
{
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;

	return (t1->data == t2->data) // 数据域相等
		&& Equal(t1->leftChild, t2->leftChild) // 左子树相等
		&& Equal(t1->rightChild, t2->rightChild); // 右子树相等
}

void BinTreeDestroy(BinTree* t) // 释放二叉树
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

