#include"SeqQueue.h"

void main()
{
	SeqQueue Q;
	SeqQueueInit(&Q, 0); // ˳����г�ʼ��
	// ���
	SeqQueueEn(&Q, 1);
	SeqQueueEn(&Q, 3);
	SeqQueueEn(&Q, 5);
	SeqQueueEn(&Q, 4);
	SeqQueueEn(&Q, 2);
	SeqQueueShow(&Q);
	printf("====================\n");
	// ����
	SeqQueueDe(&Q);
	SeqQueueShow(&Q);

	// ȡ��βԪ��
	int val = SeqQueueBack(&Q);
	printf("back val = %d\n", val);
	SeqQueueShow(&Q);

	// ȡ��ͷԪ��
	val = SeqQueueFront(&Q);
	printf("front val = %d\n", val);
	SeqQueueShow(&Q);

	SeqQueueDestroy(&Q);
}
