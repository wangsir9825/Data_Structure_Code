#define  _CRT_SECURE_NO_WARNINGS 1
#include"LinkedList.h"

int main()
{

	SList mylist;
	SListInit(&mylist);

	ElemType item, key;
	int pos;

	SListNode* p;//���ڱ���Ҫ���ҵ�ֵ

	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("* [1] push_back        [2] push_front      *\n");//β���ͷ��
		printf("* [3] show_list        [0] quit_system     *\n");//��ʾ���˳�
		printf("* [4] pop_back         [5] pop_front       *\n");//βɾ��ͷɾ
		printf("* [6] length           [*7] capacity       *\n");//�鿴�����ĳ��Ⱥ�����
		printf("* [8] insert_val       [*9] insert_pos      *\n");//��ֵ���롢��λ�ò���
		printf("* [10] delete_val      [*11] delete_pos     *\n");//��ֵɾ������λ��ɾ��
		printf("* [12] find            [13] sort           *\n");//����Ԫ�غ�ð������
		printf("* [14] reverse         [15] remove_all     *\n");//λ�÷�ת���Ƴ�����ĳһԪ��
		printf("* [16] clear           [*17] destroy       *\n");//����ʹݻ�
		printf("* [*18] find_binary                         *\n");//���ֲ��ң������Ƚ�������
		printf("********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1://β��
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //���ű���ʽ
				SListPushBack(&mylist, item);
			break;
		case 2://ͷ��
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //���ű���ʽ
				SListPushFront(&mylist, item);
			break;
		case 3://��ʾ
			SListShow(&mylist);
			break;
		case 4://��β��ɾ�� 4
			SListPopBack(&mylist);
			break;
		case 5://��ͷ��ɾ�� 5
			SListPopFront(&mylist);
			break;
		case 6://�鿴���� 6
			printf("����Ϊ:>%d\n", SListLength(&mylist));
			break;
		case 7://�鿴�������� 7������û�������ĸ�����Ըù���ʡ�ԣ�
			//printf("��������Ϊ:>%d\n", SeqListCapacity(&mylist));
			break;
		case 8://��ֵ���� 8
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SListInsertByVal(&mylist, item);
			break;
		case 9:
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 10://��ֵɾ�� 10
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			SListDeleteByVal(&mylist, key);
			break;
		case 11:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 12://����Ԫ�� 12
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			p = SeqListFind(&mylist, key);
			if (p == NULL)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("Ҫ���ҵ�ֵ%d����.\n", key);
			break;
		case 13://��������
			//SeqListSort(&mylist);
			SListSort(&mylist);
			break;
		case 14://����ת�� 14
			SListReverse(&mylist);
			break;
		case 15:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			//SeqListRemoveAll(&mylist, key);
			SListRemoveAll(&mylist, key);
			break;
		case 16://��� ���������Ԫ�أ�16 
			SListClear(&mylist);
			break;
		case 18:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			//pos = SeqListFindByBinary(&mylist, key);
			if (pos == -1)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("Ҫ���ҵ�ֵ%d���±�Ϊ%d��λ��.\n", key, pos);
			break;
		}
		system("pause");
		system("cls");
	}

	SListDestroy(&mylist);

	return 0;
}