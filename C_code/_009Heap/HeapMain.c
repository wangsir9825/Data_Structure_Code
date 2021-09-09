#define _CRT_SECURE_NO_WARNINGS 0

#include"Heap.h"

void main()
{
	Heap hp, hp1;
	HeapElemType ar[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(ar) / sizeof(ar[0]);
	HeapInit(&hp, 16); // ��ʼ���ѿռ䣬����16���ռ�
	for (int i = 0; i < n; ++i) // ��������䵽�ѿռ���
		HeapInsert(&hp, ar[i]); 
	printf("��ӡ�ѣ�");
	HeapShow(&hp);
	printf("\n");

	printf("ѭ��ȡ�Ѷ�Ԫ�أ�");
	while (!HeapEmpty(&hp)) // ѭ��ȡ�Ѷ�Ԫ�أ���ӡ������Ԫ�ذ���С����˳������
	{
		HeapElemType top_val = HeapTop(&hp); // ȡ�Ѷ�Ԫ��
		printf("%d ", top_val);// 
		HeapRemove(&hp); // ɾ���Ѷ�Ԫ��
	}
	printf("\n");

	printf("�������鴴���Ѳ��ԣ�");
	HeapInitByArray(&hp1, ar, n); // �������鴴����,n������ĳ���
	while (!HeapEmpty(&hp1))
	{
		HeapElemType top_val = HeapTop(&hp1);
		printf("%d ", top_val);
		HeapRemove(&hp1);
	}
	printf("\n");

	return 0;

}