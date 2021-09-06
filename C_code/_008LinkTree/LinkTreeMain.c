#define _CRT_SECURE_NO_WARNINGS 0

#include"LinkTree.h"

void main()
{

// 创建二叉树的第1种方式
	//BinTree bt;
	//BinTreeInit(&bt); // 初始化二叉树
	//BinTreeCreate_1(&bt); // 调用创建二叉树函数需要输入数据，测试用例：ABC##DE##F##G#H##
	//printf("VLR : ");
	//PreOrder(bt); // 前序遍历
	//printf("\n");
	//printf("LVR : ");
	//InOrder(bt); // 中序遍历
	//printf("\n");
	//printf("LRV : ");
	//PostOrder(bt); // 后序遍历

// 创建二叉树的第2种方式
	//BinTree bt = BinTreeCreate_2(); // 输入测试用例：ABC##DE##F##G#H##
	//printf("VLR : ");
	//PreOrder(bt); // 前序遍历
	//printf("\n");
	//printf("LVR : ");
	//InOrder(bt); // 中序遍历
	//printf("\n");
	//printf("LRV : ");
	//PostOrder(bt); // 后序遍历

 // 第3种创建二叉树方式
	//int index = 0;
	//char* str = "ABC##DE##F##G#H##";
	//BinTree bt = BinTreeCreate_3(str, &index);
	//printf("VLR : ");
	//PreOrder(bt); // 前序遍历
	//printf("\n");
	//printf("LVR : ");
	//InOrder(bt); // 中序遍历
	//printf("\n");
	//printf("LRV : ");
	//PostOrder(bt); // 后序遍历
	//printf("\n");
	//printf("Level : ");
	//LevelOrder(bt); // 层次遍历
	//printf("\n");
 // 第4种创建二叉树方式
	char* vlr = "ABCDEFGH"; // 前序遍历结果
	char* lvr = "CBEDFAGH"; // 中序遍历结果
	char* lrv = "CEFDBHGA"; // 后序遍历结果
	BinTree bt;
	BinTreeInit(&bt);
	int n = strlen(vlr);
	//bt = BinTreeCreate_VLR_LVR(vlr, lvr, n);// 根据前序和中序遍历结果恢复二叉树结构，n是节点个数
	bt = BinTreeCreate_LVR_LRV(lvr, lrv, n);// 根据中序和后序遍历结果恢复二叉树结构
	printf("VLR : ");
	PreOrder(bt); // 前序遍历
	printf("\n");
	printf("LVR : ");
	InOrder(bt); // 中序遍历
	printf("\n");
	printf("LRV : ");
	PostOrder(bt); // 后序遍历
	printf("\n");
	printf("Level : ");
	LevelOrder(bt); // 层次遍历
	printf("\n");

	printf("NVLR : "); // 非递归前序遍历
	PreOrder_Nor(bt);
	printf("\n");
	printf("NLVR : "); // 非递归中序遍历
	InOrder_Nor(bt);
	printf("\n");
	printf("NLRV : "); // 非递归后序遍历
	PostOrder_Nor(bt);
	printf("\n");


	printf("Size = %d\n", Size(bt)); // 求取二叉树节点个数
	printf("Height = %d\n", Height(bt)); // 求二叉树的高度

	char key = 'A';
	BinTreeNode* p = Find(bt, key); // 查找值为'A'的节点
	if (p == NULL)
		printf("没有查找到该节点。\n");
	else
		printf("p->data = %c\n", p->data);

	BinTreeNode* pr = Parent(bt, p);
	if (pr == NULL)
		printf("没有查找到该节点的父节点。\n"); // 查找值为'A'的节点的父节点
	else
		printf("pr->data = %c\n", pr->data);

	BinTree bt1 = Clone(bt); // 克隆二叉树（深拷贝）
	printf("层次遍历bt1 : ");
	LevelOrder(bt1); // 层次遍历
	printf("\n");

	bool flag = Equal(bt, bt1);
	if (flag)
		printf("两个二叉树相等\n");
	else
		printf("两个二叉树不相等\n");

	BinTreeDestroy(&bt); // 释放二叉树
}
