
#include"SeqStack.h"

void main()
{
	SeqStack st;
	SeqStackInit(&st, 0);
	// 入栈
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

	// 出栈
	SeqStackPop(&st);
	SeqStackShow(&st);
	printf("============\n");
	SeqStackPop(&st);
	SeqStackShow(&st);
	printf("============\n");
	SeqStackPop(&st);
	SeqStackShow(&st);
	// 取栈顶与出栈配合使用
	while (!IsEmpty(&st))
	{
		StackElemType val = SeqStackTop(&st); // 取栈顶
		SeqStackPop(&st); // 出栈
		printf("%d 出栈.\n", val);
	}
	printf("出栈完毕.\n");
	SeqStackDestroy(&st);
}