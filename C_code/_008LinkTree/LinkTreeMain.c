#define _CRT_SECURE_NO_WARNINGS 0

#include"LinkTree.h"

void main()
{

// �����������ĵ�1�ַ�ʽ
	//BinTree bt;
	//BinTreeInit(&bt); // ��ʼ��������
	//BinTreeCreate_1(&bt); // ���ô���������������Ҫ�������ݣ�����������ABC##DE##F##G#H##
	//printf("VLR : ");
	//PreOrder(bt); // ǰ�����
	//printf("\n");
	//printf("LVR : ");
	//InOrder(bt); // �������
	//printf("\n");
	//printf("LRV : ");
	//PostOrder(bt); // �������

// �����������ĵ�2�ַ�ʽ
	//BinTree bt = BinTreeCreate_2(); // �������������ABC##DE##F##G#H##
	//printf("VLR : ");
	//PreOrder(bt); // ǰ�����
	//printf("\n");
	//printf("LVR : ");
	//InOrder(bt); // �������
	//printf("\n");
	//printf("LRV : ");
	//PostOrder(bt); // �������

 // ��3�ִ�����������ʽ
	//int index = 0;
	//char* str = "ABC##DE##F##G#H##";
	//BinTree bt = BinTreeCreate_3(str, &index);
	//printf("VLR : ");
	//PreOrder(bt); // ǰ�����
	//printf("\n");
	//printf("LVR : ");
	//InOrder(bt); // �������
	//printf("\n");
	//printf("LRV : ");
	//PostOrder(bt); // �������
	//printf("\n");
	//printf("Level : ");
	//LevelOrder(bt); // ��α���
	//printf("\n");
 // ��4�ִ�����������ʽ
	char* vlr = "ABCDEFGH"; // ǰ��������
	char* lvr = "CBEDFAGH"; // ����������
	char* lrv = "CEFDBHGA"; // ����������
	BinTree bt;
	BinTreeInit(&bt);
	int n = strlen(vlr);
	//bt = BinTreeCreate_VLR_LVR(vlr, lvr, n);// ����ǰ��������������ָ��������ṹ��n�ǽڵ����
	bt = BinTreeCreate_LVR_LRV(lvr, lrv, n);// ��������ͺ����������ָ��������ṹ
	printf("VLR : ");
	PreOrder(bt); // ǰ�����
	printf("\n");
	printf("LVR : ");
	InOrder(bt); // �������
	printf("\n");
	printf("LRV : ");
	PostOrder(bt); // �������
	printf("\n");
	printf("Level : ");
	LevelOrder(bt); // ��α���
	printf("\n");

	printf("NVLR : "); // �ǵݹ�ǰ�����
	PreOrder_Nor(bt);
	printf("\n");
	printf("NLVR : "); // �ǵݹ��������
	InOrder_Nor(bt);
	printf("\n");
	printf("NLRV : "); // �ǵݹ�������
	PostOrder_Nor(bt);
	printf("\n");


	printf("Size = %d\n", Size(bt)); // ��ȡ�������ڵ����
	printf("Height = %d\n", Height(bt)); // ��������ĸ߶�

	char key = 'A';
	BinTreeNode* p = Find(bt, key); // ����ֵΪ'A'�Ľڵ�
	if (p == NULL)
		printf("û�в��ҵ��ýڵ㡣\n");
	else
		printf("p->data = %c\n", p->data);

	BinTreeNode* pr = Parent(bt, p);
	if (pr == NULL)
		printf("û�в��ҵ��ýڵ�ĸ��ڵ㡣\n"); // ����ֵΪ'A'�Ľڵ�ĸ��ڵ�
	else
		printf("pr->data = %c\n", pr->data);

	BinTree bt1 = Clone(bt); // ��¡�������������
	printf("��α���bt1 : ");
	LevelOrder(bt1); // ��α���
	printf("\n");

	bool flag = Equal(bt, bt1);
	if (flag)
		printf("�������������\n");
	else
		printf("���������������\n");

	BinTreeDestroy(&bt); // �ͷŶ�����
}
