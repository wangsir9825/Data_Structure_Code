#define  _CRT_SECURE_NO_WARNINGS 1

#include"DCList.h"

int main()
{
	DCList mylist;
	DCListInit(&mylist);
	ElemType item, key;
	int pos;
	DCListNode* p;
	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("* [1] push_back        [2] push_front      *\n");//尾插和头插
		printf("* [3] show_list        [0] quit_system     *\n");//显示和退出
		printf("* [4] pop_back         [5] pop_front       *\n");//尾删和头删
		printf("* [6] length           [*7] capacity       *\n");//查看链表的长度和容量
		printf("* [8] insert_val       [*9] insert_pos     *\n");//按值插入、按位置插入
		printf("* [10] delete_val      [*11] delete_pos    *\n");//按值删除、按位置删除
		printf("* [12] find            [13] sort           *\n");//查找元素和冒泡排序
		printf("* [14] reverse         [15] remove_all     *\n");//位置翻转和移除所有某一元素
		printf("* [16] clear           [*17] destroy       *\n");//清除和摧毁
		printf("* [*18] find_binary                        *\n");//二分查找（必须先进行排序）

		printf("********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1://尾插 1
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				DCListPushBack(&mylist, item);
			break;
		case 2:// 头插 2
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				DCListPushFront(&mylist, item);
			break;
		case 3://显示链表 3
			DCListShow(&mylist);
			break;
		case 4://尾部删除 4
			DCListPopBack(&mylist);
			break;
		case 5://从头部删除 5
			DCListPopFront(&mylist);
			break;
		case 6://查看表长 6
			printf("表长为:>%d\n", DCListLength(&mylist));
			break;
		case 7:
			//printf("表的容量为:>%d\n", SeqListCapacity(&mylist));
			break;
		case 8://按值插入 8
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);
			break;
		case 9:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 10://按值删除 10
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			DCListDeleteByVal(&mylist, key);
			break;
		case 11:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 12://查找元素 12
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = DCListFind(&mylist, key);
			if (p == NULL)
				printf("要查找的值%d不存在.\n", key);
			else
				printf("要查找的值%d存在.\n", key);
			break;
		case 13:
			//SListSort(&mylist);
			break;
		case 14://位置翻转 14
			DCListReverse(&mylist);
			break;
		case 15:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			//SListRemoveAll(&mylist, key);
			break;
		case 16://清除 （清除所有元素）16
			DCListClear(&mylist);
			break;
		case 18:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			//pos = SeqListFindByBinary(&mylist, key);
			if (pos == -1)
				printf("要查找的值%d不存在.\n", key);
			else
				printf("要查找的值%d在下标为%d的位置.\n", key, pos);
			break;
		}
		system("pause");
		system("cls");
	}
	DCListDestroy(&mylist);
	return 0;
}
