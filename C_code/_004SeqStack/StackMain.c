
#include"SeqStack.h"

void main()
{
	SeqStack st;
	SeqStackInit(&st, 0);
	// ��ջ
	SeqStackPush(&st, 1); 
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackShow(&st);
	printf("============\n");
	SeqStackPush(&st, 10);
	SeqStackShow(&st);
	printf("============\n");

	// ��ջ
	SeqStackPop(&st);
	SeqStackShow(&st);
	printf("============\n");
	SeqStackPop(&st);
	SeqStackShow(&st);
	printf("============\n");
	SeqStackPop(&st);
	SeqStackShow(&st);
	// ȡջ�����ջ���ʹ��
	while (!IsEmpty(&st))
	{
		StackElemType val = SeqStackTop(&st); // ȡջ��
		SeqStackPop(&st); // ��ջ
		printf("%d ��ջ.\n", val);
	}
	printf("��ջ���.\n");
	SeqStackDestroy(&st);
}