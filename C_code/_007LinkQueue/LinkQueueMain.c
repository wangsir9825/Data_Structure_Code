#include"LinkQueue.h"

void main()
{
	LinkQueue Q;
	LinkQueueInit(&Q); // 初始化链队列
	// 入队
	LinkQueueEn(&Q, 1);
	LinkQueueEn(&Q, 2);
	LinkQueueEn(&Q, 3);
	LinkQueueEn(&Q, 4);
	LinkQueueEn(&Q, 15);
	LinkQueueEn(&Q, 6);
	LinkQueueShow(&Q);
	printf("==============\n");
	// 取队头元素与出队配合使用
	QueueElemType val = LinkQueueFront(&Q);
	LinkQueueDe(&Q);
	printf("%d 出队.\n", val);
	LinkQueueDestroy(&Q);
}
