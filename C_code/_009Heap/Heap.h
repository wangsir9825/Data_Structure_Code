#ifndef _HEAP_H_
#define _HEAP_H_

#include"Sysutil.h"
#define HeapElemType int // ��Ԫ������

// ��ʽ���ö������ȽϺ���⣬ʵ���϶��ǲ���������д洢������ʵ�ֵ���С��

// �ѵ����ݽṹ
typedef struct Heap
{
	HeapElemType* heap; //�ѿռ�ָ��
	size_t        capacity; // �ѿռ�����
	size_t        size; // �ѱ����Ԫ�ظ���
}Heap;

void HeapInit(Heap* php, int sz); // �ѳ�ʼ��
void HeapInsert(Heap* php, HeapElemType x); // �����ݲ����
void HeapShow(Heap* php); // ��ʾ��
HeapElemType HeapTop(Heap* php); // ȡ�Ѷ�Ԫ��
void HeapRemove(Heap* php); // ɾ���Ѷ�Ԫ��

void HeapInitByArray(Heap* php, HeapElemType* ar, int n); // �������鴴����
void HeapClear(Heap* php); // ���Ԫ��
void HeapDestroy(Heap* php); // ���ٶѿռ�
//�ڲ�����
void _AdjustUp(Heap* php, int start);
void _AdjustDown(Heap* php, int start);

bool HeapFull(Heap* php) // ����
{
	return php->size >= php->capacity;
}
bool HeapEmpty(Heap* php) // �п�
{
	return php->size == 0;
}

void _AdjustUp(Heap* php, int start)
{
	int j = start;  //�����ӽڵ��λ��
	int i = (j - 1) / 2; //����j�ĸ��ڵ�λ��

	HeapElemType tmp = php->heap[j];

	while (j > 0)
	{
		if (tmp < php->heap[i]) // ���С�ڸ��ڵ㣬�򽻻�ֵ
		{
			php->heap[j] = php->heap[i];

			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
	php->heap[j] = tmp;
}

void _AdjustDown(Heap* php, int start) // ���µ���
{
	int i = start;    //�����ڵ�λ��
	int j = 2 * i + 1;  //����i�ڵ��������

	HeapElemType tmp = php->heap[i]; // ȡ�����ڵ�

	while (j < php->size) // ���û�е�����Ҷ�ӽڵ㣬���������
	{
		if (j + 1 < php->size && php->heap[j] > php->heap[j + 1]) // ������������ڣ�j+1<size������������������������
			j = j + 1;

		if (tmp > php->heap[j]) // ������ڵ�����ӽڵ�
		{
			php->heap[i] = php->heap[j];
			i = j; // �ӽڵ��ɸ��ڵ�
			j = 2 * i + 1; // j�����ڵ��������λ��
		}
		else
			break;
	}

	php->heap[i] = tmp;
}



void HeapInit(Heap* php, int sz) // �ѳ�ʼ��
{
	php->heap = (HeapElemType*)malloc(sizeof(HeapElemType) * sz); // ���ٿռ䣬Ĭ�Ͽ���sz���ռ�
	assert(php->heap != NULL);
	memset(php->heap, 0, sizeof(HeapElemType) * sz); // �ռ��ʼ��

	php->capacity = sz; // �ռ�����
	php->size = 0; // ��ռ�õĿռ�
}
void HeapInitByArray(Heap* php, HeapElemType* ar, int n) // �������鴴����,n������ĳ���
{
	php->heap = (HeapElemType*)malloc(sizeof(HeapElemType) * n); // ���ٿռ�
	assert(php->heap != NULL);
	php->capacity = n; // �ռ�����
	php->size = n; // �ռ�����
	for (int i = 0; i < n; ++i)
		php->heap[i] = ar[i];

	int curpos = n / 2 - 1; //�ҵ������������һ����֧���±꣨��֦����������
	while (curpos >= 0)
	{
		_AdjustDown(php, curpos); // ���µ�����С�ѣ�
		curpos--;
	}
}
void HeapInsert(Heap* php, HeapElemType x) // �����ݲ���ѣ���С�ѽṹ���룩
{
	if (HeapFull(php))
	{
		printf("�ѿռ�������%d ���ܲ���.\n", x);
		return;
	}

	php->heap[php->size] = x;
	_AdjustUp(php, php->size); // ���ϵ���
	php->size++;
}


void HeapShow(Heap* php) // ��ʾ��
{
	for (int i = 0; i < php->size; ++i)
		printf("%d ", php->heap[i]);
	printf("\n");
}

void HeapClear(Heap* php) // ����ѿռ������
{
	php->size = 0;
}
void HeapDestroy(Heap* php) // ���ٶѿռ�
{
	free(php->heap);
	php->heap = NULL;
	php->capacity = php->size = 0;
}

HeapElemType HeapTop(Heap* php) // ȡ�Ѷ�Ԫ��
{
	if (HeapEmpty(php))
	{
		printf("�ѿռ��ѿգ�����ȡ�Ѷ�Ԫ��.\n");
		return;
	}

	return php->heap[0];
}



void HeapRemove(Heap* php) // ɾ���Ѷ�Ԫ��
{
	if (HeapEmpty(php))
	{
		printf("�ѿռ��ѿգ�����ɾ���Ѷ�Ԫ��.\n");
		return;
	}

	php->size--;
	php->heap[0] = php->heap[php->size]; // ���ѵ�Ԫ����䵽�Ѷ�
	_AdjustDown(php, 0); // ���µ���
}


#endif /* _HEAP_H_ */