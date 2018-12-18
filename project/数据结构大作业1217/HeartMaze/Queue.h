#include "public.h"

typedef struct {

	Block *base;
	int front;
	int rear;
}SqQueue;

void initQueue(SqQueue &Q)//初始化环形队列P101
{
	Q.base = (Block*)malloc(MAXQSIZE * sizeof(Block));
	if (!Q.base)
		return;
	Q.front = Q.rear = 0;
}

void enQueue(SqQueue &Q, Block e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return;

	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;//注释则只生成边界
}
/*bool enQueue(SqQueue Q, Block e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return false;

	Q.base[Q.rear] = e;
	//Q.rear = (Q.rear + 1) % MAXQSIZE;
    return true;
}///√可行，迷宫生成错误*/

int getLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

void deQueue(SqQueue &Q, Block &e)
{
	if (Q.front == Q.rear)
		return;
	srand((unsigned)time(NULL));
	int randIdx = rand() % getLength(Q);
	e = Q.base[randIdx];
	Q.base[randIdx] = Q.base[Q.rear - 1];
	Q.base[Q.rear - 1] = e;

	Q.rear = (Q.rear - 1) % MAXQSIZE;
}

bool isEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
