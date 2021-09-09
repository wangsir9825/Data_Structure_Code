#define _CRT_SECURE_NO_WARNINGS 0

#include"Heap.h"

void main()
{
	Heap hp, hp1;
	HeapElemType ar[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(ar) / sizeof(ar[0]);
	HeapInit(&hp, 16); // 初始化堆空间，开辟16个空间
	for (int i = 0; i < n; ++i) // 将数组填充到堆空间中
		HeapInsert(&hp, ar[i]); 
	printf("打印堆：");
	HeapShow(&hp);
	printf("\n");

	printf("循环取堆顶元素：");
	while (!HeapEmpty(&hp)) // 循环取堆顶元素，打印出来的元素按从小到大顺序排序
	{
		HeapElemType top_val = HeapTop(&hp); // 取堆顶元素
		printf("%d ", top_val);// 
		HeapRemove(&hp); // 删除堆顶元素
	}
	printf("\n");

	printf("利用数组创建堆测试：");
	HeapInitByArray(&hp1, ar, n); // 根据数组创建堆,n是数组的长度
	while (!HeapEmpty(&hp1))
	{
		HeapElemType top_val = HeapTop(&hp1);
		printf("%d ", top_val);
		HeapRemove(&hp1);
	}
	printf("\n");

	return 0;

}