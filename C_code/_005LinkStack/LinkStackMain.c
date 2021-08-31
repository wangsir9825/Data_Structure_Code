
#include"LinkStack.h"

void main()
{
	LinkStack st; // ������ջ
	LinkStackInit(&st); // ��ʼ����ջ
	// ��ջ
	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 4);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 5);
	LinkStackShow(&st);
	printf("============\n");
	// ȡջ�����ջ���ʹ��
	StackElemType  val = LinkStackTop(&st); // ȡջ��
	printf("%d ��ջ.\n", val); 
	LinkStackPop(&st); // ��ջ
	printf("============\n");
	LinkStackShow(&st);

	LinkStackDestroy(&st);
}