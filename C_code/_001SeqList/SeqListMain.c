#define  _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

int main()
{
	SeqList mylist;//����˳���
	SeqListInit(&mylist);//˳����ʼ����ȷ�����С

	ElemType item, key;

	size_t pos;

	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("*************��ǰ˳����Ԫ���У�***********\n");
		SeqListShow(&mylist);//��ʾ˳���
		printf("******Ԫ�ظ�����%d *******˳���������%d *****\n", SeqListLength(&mylist), SeqListCapacity(&mylist));
		printf("********************************************\n");
		printf("* [1] push_back        [2] push_front      *\n");//β���ͷ��
		printf("* [3] show_list        [0] quit_system     *\n");//��ʾ���˳�
		printf("* [4] pop_back         [5] pop_front       *\n");//βɾ��ͷɾ
		printf("* [6] length           [7] capacity        *\n");//�鿴˳����Ⱥ�����
		printf("* [8] insert_val       [9] insert_pos      *\n");//��ֵ���롢��λ�ò���
		printf("* [10] delete_val      [11] delete_pos     *\n");//��ֵɾ������λ��ɾ��
		printf("* [12] find            [13] sort           *\n");//����Ԫ�غ�ð������
		printf("* [14] reverse         [15] remove_all     *\n");//λ�÷�ת���Ƴ�����ĳһԪ��
		printf("* [16] clear           [*17] destroy       *\n");//����ʹݻ�
		printf("* [18] find_binary                         *\n");//���ֲ��ң������Ƚ�������
		printf("********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1://β��
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //�����������룬��-1���������ű��ʽ
				SeqListPushBack(&mylist, item);
			break;
		case 2://ͷ��
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //���ű��ʽ
				SeqListPushFront(&mylist, item);
			break;
		case 3://��ʾ
			SeqListShow(&mylist);//��ʾ˳���
			break;
		case 4://βɾ
			SeqListPopBack(&mylist);
			break;
		case 5://ͷɾ
			SeqListPopFront(&mylist);
			break;
		case 6://�鿴����
			printf("��Ϊ:>%d\n", SeqListLength(&mylist));//�鿴����
			break;
		case 7://�鿴����
			printf("�������Ϊ:>%d\n", SeqListCapacity(&mylist));//�鿴����
			break;
		case 8://��ֵ���룬����֮ǰҪ��֤��������
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			break;
		case 9://��λ�ò���
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);
			break;

		case 10://��ֵɾ��
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			SeqListDeleteByVal(&mylist, key);
			break;
		case 11://��λ��ɾ��
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 12://����Ԫ��
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			pos = SeqListFind(&mylist, key);
			if (pos == -1)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("Ҫ���ҵ�ֵ%d���±�Ϊ%d��λ��.\n", key, pos);
			break;
		case 13://ð������
			SeqListSort(&mylist);
			break;
		case 14://λ�÷�ת
			SeqListReverse(&mylist);
			break;
		case 15://�Ƴ�����ĳһԪ��
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			SeqListRemoveAll(&mylist, key);
			break;
		case 16://��� ���������Ԫ�أ�
			SeqListClear(&mylist);
			break;
		case 18://���ֲ��ң������Ƚ�������
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			pos = SeqListFindByBinary(&mylist, key);
			if (pos == -1)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("Ҫ���ҵ�ֵ%d���±�Ϊ%d��λ��.\n", key, pos);
			break;
		}
		system("pause");//��ͣ
		//system("cls");//����
	}

	SeqListDestroy(&mylist);//�ڳ������ǰ���ݻ�˳������ͷ��ڴ�

	return 0;
}