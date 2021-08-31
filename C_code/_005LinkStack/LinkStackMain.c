
#include"LinkStack.h"

void main()
{
	LinkStack st; // 定义链栈
	LinkStackInit(&st); // 初始化链栈
	// 入栈
	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 4);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 5);
	LinkStackShow(&st);
	printf("============\n");
	// 取栈顶与出栈配合使用
	StackElemType  val = LinkStackTop(&st); // 取栈顶
	printf("%d 出栈.\n", val); 
	LinkStackPop(&st); // 出栈
	printf("============\n");
	LinkStackShow(&st);

	LinkStackDestroy(&st);
}