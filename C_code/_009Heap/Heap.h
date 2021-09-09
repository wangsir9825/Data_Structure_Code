#ifndef _HEAP_H_
#define _HEAP_H_

#include"Sysutil.h"
#define HeapElemType int // 堆元素类型

// 形式上用二叉树比较好理解，实际上堆是采用数组进行存储，以下实现的是小堆

// 堆的数据结构
typedef struct Heap
{
	HeapElemType* heap; //堆空间指针
	size_t        capacity; // 堆空间容量
	size_t        size; // 已保存的元素个数
}Heap;

void HeapInit(Heap* php, int sz); // 堆初始化
void HeapInsert(Heap* php, HeapElemType x); // 将数据插入堆
void HeapShow(Heap* php); // 显示堆
HeapElemType HeapTop(Heap* php); // 取堆顶元素
void HeapRemove(Heap* php); // 删除堆顶元素

void HeapInitByArray(Heap* php, HeapElemType* ar, int n); // 根据数组创建堆
void HeapClear(Heap* php); // 清除元素
void HeapDestroy(Heap* php); // 销毁堆空间
//内部方法
void _AdjustUp(Heap* php, int start);
void _AdjustDown(Heap* php, int start);

bool HeapFull(Heap* php) // 判满
{
	return php->size >= php->capacity;
}
bool HeapEmpty(Heap* php) // 判空
{
	return php->size == 0;
}

void _AdjustUp(Heap* php, int start)
{
	int j = start;  //代表子节点的位置
	int i = (j - 1) / 2; //代表j的父节点位置

	HeapElemType tmp = php->heap[j];

	while (j > 0)
	{
		if (tmp < php->heap[i]) // 如果小于父节点，则交换值
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

void _AdjustDown(Heap* php, int start) // 向下调整
{
	int i = start;    //代表父节点位置
	int j = 2 * i + 1;  //代表i节点的左子树

	HeapElemType tmp = php->heap[i]; // 取出父节点

	while (j < php->size) // 如果没有调整到叶子节点，则继续调整
	{
		if (j + 1 < php->size && php->heap[j] > php->heap[j + 1]) // 如果右子树存在（j+1<size），并且左子树大于右子树
			j = j + 1;

		if (tmp > php->heap[j]) // 如果父节点大于子节点
		{
			php->heap[i] = php->heap[j];
			i = j; // 子节点变成父节点
			j = 2 * i + 1; // j代表父节点的左子树位置
		}
		else
			break;
	}

	php->heap[i] = tmp;
}



void HeapInit(Heap* php, int sz) // 堆初始化
{
	php->heap = (HeapElemType*)malloc(sizeof(HeapElemType) * sz); // 开辟空间，默认开辟sz个空间
	assert(php->heap != NULL);
	memset(php->heap, 0, sizeof(HeapElemType) * sz); // 空间初始化

	php->capacity = sz; // 空间容量
	php->size = 0; // 已占用的空间
}
void HeapInitByArray(Heap* php, HeapElemType* ar, int n) // 根据数组创建堆,n是数组的长度
{
	php->heap = (HeapElemType*)malloc(sizeof(HeapElemType) * n); // 开辟空间
	assert(php->heap != NULL);
	php->capacity = n; // 空间容量
	php->size = n; // 空间容量
	for (int i = 0; i < n; ++i)
		php->heap[i] = ar[i];

	int curpos = n / 2 - 1; //找到二叉树的最后一个分支的下标（分枝即是子树）
	while (curpos >= 0)
	{
		_AdjustDown(php, curpos); // 向下调整（小堆）
		curpos--;
	}
}
void HeapInsert(Heap* php, HeapElemType x) // 将数据插入堆（按小堆结构插入）
{
	if (HeapFull(php))
	{
		printf("堆空间已满，%d 不能插入.\n", x);
		return;
	}

	php->heap[php->size] = x;
	_AdjustUp(php, php->size); // 向上调整
	php->size++;
}


void HeapShow(Heap* php) // 显示堆
{
	for (int i = 0; i < php->size; ++i)
		printf("%d ", php->heap[i]);
	printf("\n");
}

void HeapClear(Heap* php) // 清除堆空间的数据
{
	php->size = 0;
}
void HeapDestroy(Heap* php) // 销毁堆空间
{
	free(php->heap);
	php->heap = NULL;
	php->capacity = php->size = 0;
}

HeapElemType HeapTop(Heap* php) // 取堆顶元素
{
	if (HeapEmpty(php))
	{
		printf("堆空间已空，不能取堆顶元素.\n");
		return;
	}

	return php->heap[0];
}



void HeapRemove(Heap* php) // 删除堆顶元素
{
	if (HeapEmpty(php))
	{
		printf("堆空间已空，不能删除堆顶元素.\n");
		return;
	}

	php->size--;
	php->heap[0] = php->heap[php->size]; // 将堆底元素填充到堆顶
	_AdjustDown(php, 0); // 向下调整
}


#endif /* _HEAP_H_ */