#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include"Sysutil.h"
//˳�����

#define ElemType int//����˳������Ԫ�ص�����
#define SEQLIST_DEFAULT_SIZE  8 // ����˳����Ĭ�Ͽռ�Ϊ8��Ԫ��
#define SEQLIST_INC_SIZE 4 // ����һ�������Ŀռ��С����ÿ����һ�Σ��ռ�����4��Ԫ��

//����˳�������ݽṹ
typedef struct SeqList
{
	ElemType* base;//ָ��˳���ռ��ָ��
	size_t    capacity;//����
	size_t    size;//˳��������е�Ԫ�ظ���
}SeqList;


///////////////��������/////////////////////////////////
bool IsFull(SeqList* pst);//�ж�˳����Ƿ���
bool IsEmpty(SeqList* pst);//�ж�˳����Ƿ��
void SeqListInit(SeqList* pst);//˳����ʼ��

void SeqListPushBack(SeqList* pst, ElemType x);//β�� 1
void SeqListPushFront(SeqList* pst, ElemType x);//ͷ�� 2

void SeqListShow(SeqList* pst);//��ʾ˳��� 3
void SeqListPopBack(SeqList* pst);//��β��ɾ�� 4
void SeqListPopFront(SeqList* pst);//��ͷ��ɾ�� 5
size_t SeqListLength(SeqList* pst);//�鿴˳����� 6
size_t SeqListCapacity(SeqList* pst);//�鿴˳������� 7
void SeqListInsertByVal(SeqList* pst, ElemType x);//��ֵ���� 8
void SeqListInsertByPos(SeqList* pst, int pos, ElemType x);//��λ�ò��� 9
void SeqListDeleteByVal(SeqList* pst, ElemType key);//��ֵɾ�� 10
void SeqListDeleteByPos(SeqList* pst, size_t pos); //��λ��ɾ�� 11
int SeqListFind(SeqList* pst, ElemType key);//����Ԫ�� 12
void SeqListSort(SeqList* pst);//���� 13
void SeqListReverse(SeqList* pst);//˳���λ�÷�ת 14
void SeqListRemoveAll(SeqList* pst, ElemType key);//�Ƴ�����ĳһԪ�� 15
void SeqListClear(SeqList* pst); //��� ���������Ԫ�أ�16 
void SeqListDestroy(SeqList* pst);//�ݻ٣������ݱ�ֱ���ͷţ� 17
int SeqListFindByBinary(SeqList* pst, ElemType key);//���ֲ��ң������Ƚ������� 18

//////////////////����ʵ��/////////////////////////////////////
//������������1����������0��
bool IsFull(SeqList* pst)
{
	return pst->size >= pst->capacity;
}

//�п�
bool IsEmpty(SeqList* pst)
{
	return pst->size == 0;
}

//���ݺ���������false˵������ʧ�ܣ�����ture˵�����ݳɹ���
//һ��Լ�������»��߿�ͷ�����ĺ����������������ֻ�����ڲ�����
//��mallocʵ������
bool _Inc(SeqList* pst)
{
	//�����¿ռ�
	ElemType *new_base = (ElemType*)malloc(sizeof(ElemType)*(pst->capacity+SEQLIST_INC_SIZE));
	if (new_base == NULL)//�ж������Ƿ�ɹ�
	{
		printf("����ʧ��.\n");
		return false;
	}
	//��������
	memcpy(new_base, pst->base, sizeof(ElemType) * pst->capacity);

	//�ͷžɿռ�
	free(pst->base);

	//����base��ָ��
	pst->base = new_base;
	pst->capacity += SEQLIST_INC_SIZE;
	return true;
}

//��reallocʵ������
/*
bool _Inc(SeqList *pst)
{
	ElemType *new_base = (ElemType*)realloc(pst->base, sizeof(ElemType)*(pst->capacity + SEQLIST_INC_SIZE));
	if(new_base == NULL)
	{
		printf("����ʧ��.\n");
		return false;
	}
	pst->base = new_base;
	pst->capacity += SEQLIST_INC_SIZE;
	return true;
}
*/


//˳����ʼ��
void SeqListInit(SeqList* pst)
{
	assert(pst);
	pst->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL); //������ٿռ�ɹ�����������ԡ�assert�Ĳ���Ϊ���򲻻ᱨ��
	memset(pst->base, 0, sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);// ��˳�����ڴ�ֵ��ʼ��Ϊ0
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}

//β�� 1
void SeqListPushBack(SeqList* pst, ElemType x)
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))	//��˳������ˣ��������ݲ��ɹ�������ʾ˳������ˡ�ע��ǧ��
	{								//Ҫд��if (!_Inc(pst) && IsFull(pst))����ͻ����,��Ϊ�߼���(&&)���ж�·����
		printf("˳���������%d ������β������.\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}

//ͷ�� 2
void SeqListPushFront(SeqList* pst, ElemType x)
{
	assert(pst);
	//����
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳���������%d ������ͷ������.\n", x);
		return;
	}
	//�ƶ�����
	for (int i = pst->size; i > 0; --i)
		pst->base[i] = pst->base[i - 1];

	//ͷ������
	pst->base[0] = x;

	//Ԫ�ظ�����1
	pst->size++;
}

//��ʾ˳��� 3
void SeqListShow(SeqList* pst)
{
	assert(pst);
	for (size_t i = 0; i < pst->size; ++i)  //0 1 2 3 4 5
	{
		printf("%d\t", pst->base[i]);
	}
	printf("\n");
}

//βɾ 4
void SeqListPopBack(SeqList* pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("˳����ѿ�, ����β��ɾ��.\n");
		return;
	}
	pst->size--;
}

//ͷɾ 5
void SeqListPopFront(SeqList* pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("˳����ѿ�, ����ͷ��ɾ��.\n");
		return;
	}
	// �ƶ�����
	for (size_t i = 0; i < pst->size - 1; ++i)
		pst->base[i] = pst->base[i + 1];
		
	pst->size--;
}

//�鿴���� 6
size_t SeqListLength(SeqList* pst)
{
	return pst->size;
}

//�鿴���� 7
size_t SeqListCapacity(SeqList* pst)
{
	return pst->capacity;
}

//��ֵ���� 8 ������֮ǰҪ��֤��������
void SeqListInsertByVal(SeqList* pst, ElemType x)
{
	//����֮ǰҪ��֤��������
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳���������%d ���ܰ�ֵ����.\n", x);
		return;
	}

	//Ѱ��λ�ò���
	int pos = 0;
	while (pos < pst->size && x > pst->base[pos])//Ѱ��Ӧ�ò����λ��
		pos++;

	for (int i = pst->size; i > pos; --i)//����posλ�ü�pos�������Ҫ�����ƶ���Ϊ�²������������λ��
		pst->base[i] = pst->base[i - 1];

	pst->base[pos] = x;//����Ԫ��
	pst->size++;//Ԫ�ظ�����1
}

//��λ�ò��� 9
void SeqListInsertByPos(SeqList* pst, int pos, ElemType x)
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳���������%d ���ܰ�λ�ò���.\n", x);
		return;
	}
	if (pos<0 || pos>pst->size)
	{
		printf("�����λ�÷Ƿ���%d ���ܰ�λ�ò���.\n", x);
		return;
	}

	for (int i = pst->size; i > pos; --i)//Ԫ���ƶ�
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = x;
	pst->size++;
}

//��ֵɾ�� 10
void SeqListDeleteByVal(SeqList* pst, ElemType key)
{
	assert(pst);
	int index = SeqListFind(pst, key);
	if (index == -1)
	{
		printf("Ҫɾ����Ԫ��%d�����ڣ�����ɾ��.\n", key);
		return;
	}
	//for(int i=index; i<pst->size; ++i)
	//	pst->base[i] = pst->base[i+1];
	//pst->size--;
	SeqListDeleteByPos(pst, index);
}

//��λ��ɾ�� 11
void SeqListDeleteByPos(SeqList* pst, size_t pos)
{
	
	assert(pst && (pos >= 0 && pos < pst->size)); // �ж�λ�õĺϷ���
	for (size_t i = pos; i < pst->size; ++i)
		pst->base[i] = pst->base[i + 1];
	pst->size--;
}

////����Ԫ�� 12(˳�����)
int SeqListFind(SeqList* pst, ElemType key)
{
	for (size_t i = 0; i < pst->size; ++i)
	{
		if (key == pst->base[i])
			return i;
	}
	return -1;//���Ҳ�����Ԫ���򷵻�-1
}

//ð������ 13
void SeqListSort(SeqList* pst)
{
	for (size_t i = 0; i < pst->size - 1; ++i) //��������
	{
		for (size_t j = 0; j < pst->size - i - 1; ++j)
		{
			if (pst->base[j] > pst->base[j + 1])
			{
				//��������
				ElemType tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
		}
	}
}

//λ�÷�ת 14
void SeqListReverse(SeqList* pst)
{
	assert(pst);
	int start = 0, end = pst->size - 1;
	while (start < end)
	{
		ElemType tmp = pst->base[start];
		pst->base[start] = pst->base[end];
		pst->base[end] = tmp;

		start++;
		end--;
	}
}

//�Ƴ�����ĳһԪ�� 15
void SeqListRemoveAll(SeqList* pst, ElemType key)
{
	assert(pst);
	int index;
	do
	{
		index = SeqListFind(pst, key);//����Ԫ�ص�λ��
		if (index == -1)
			break;
		SeqListDeleteByPos(pst, index);
	} while (1);
}

//��� ���������Ԫ�أ�16 
void SeqListClear(SeqList* pst)
{
	pst->size = 0;
}

//�ݻ٣������ݱ�ֱ���ͷţ� 17
void SeqListDestroy(SeqList* pst)
{
	assert(pst);
	free(pst->base);//�ͷſռ�
	pst->base = NULL; // Ԥ��Ұָ��
	pst->capacity = pst->size = 0;
}

//���ֲ��ң������Ƚ������� 18
int SeqListFindByBinary(SeqList* pst, ElemType key)
{
	assert(pst);
	SeqListSort(pst); //�ȱ�֤���ҵ���������

	int low = 0, high = pst->size - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == pst->base[mid])
			return mid;
		else if (key < pst->base[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}


#endif /*_SEQLIST_H_*/