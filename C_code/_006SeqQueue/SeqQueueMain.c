#include"SeqQueue.h"

void main()
{
	SeqQueue Q;
	SeqQueueInit(&Q, 0); // 顺序队列初始化
	// 入队
	SeqQueueEn(&Q, 1);
	SeqQueueEn(&Q, 3);
	SeqQueueEn(&Q, 5);
	SeqQueueEn(&Q, 4);
	SeqQueueEn(&Q, 2);
	SeqQueueShow(&Q);
	printf("====================\n");
	// 出队
	SeqQueueDe(&Q);
	SeqQueueShow(&Q);

	// 取队尾元素
	int val = SeqQueueBack(&Q);
	printf("back val = %d\n", val);
	SeqQueueShow(&Q);

	// 取队头元素
	val = SeqQueueFront(&Q);
	printf("front val = %d\n", val);
	SeqQueueShow(&Q);

	SeqQueueDestroy(&Q);
}
