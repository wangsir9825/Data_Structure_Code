#include"LinkQueue.h"

void main()
{
	LinkQueue Q;
	LinkQueueInit(&Q); // ��ʼ��������
	// ���
	LinkQueueEn(&Q, 1);
	LinkQueueEn(&Q, 2);
	LinkQueueEn(&Q, 3);
	LinkQueueEn(&Q, 4);
	LinkQueueEn(&Q, 15);
	LinkQueueEn(&Q, 6);
	LinkQueueShow(&Q);
	printf("==============\n");
	// ȡ��ͷԪ����������ʹ��
	QueueElemType val = LinkQueueFront(&Q);
	LinkQueueDe(&Q);
	printf("%d ����.\n", val);
	LinkQueueDestroy(&Q);
}
