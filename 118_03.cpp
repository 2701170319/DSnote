#include<bits/stdc++.h>
using namespace std;
typedef char ElemType;

#define MaxSize 50

typedef struct
{
    ElemType data[MaxSize];
    int front,rear;
} SqQueue;

void InitQueue(SqQueue *&q)
{
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}

bool enQueue(SqQueue *&q,ElemType e)
{
    if((q->rear+1)%MaxSize==q->front)
        return false;
    q->rear=(q->rear+1)%MaxSize;
    q->data[q->rear]=e;
    return true;
}

bool deQueue(SqQueue *&q, ElemType &e)
{
    if(q->front ==q->rear)
        return false;
    q->front=(q->front+1)%MaxSize;
    e=q->data[q->front];
    return true;
}

bool QueueEmpty(SqQueue *q)
{
    return (q->front==q->rear);
}

int CircleLen(SqQueue *q)
{
    return (q->rear-q->front+MaxSize)%MaxSize;
}

int main()
{
    SqQueue *q;
    ElemType e;
    InitQueue(q);//(1)
    if(QueueEmpty(q)==1)//(2)
        cout<<"该队列为空\n";
    else
        cout<<"该队列不为空\n";
    enQueue(q,'a');enQueue(q,'b');enQueue(q,'c');//(3)
    deQueue(q,e);//(4)
    cout<<e<<endl;
    enQueue(q,'d');enQueue(q,'e');enQueue(q,'f');//(5)
    cout<<"该队列长度： "<<CircleLen(q)<<endl;///习题1
    while(QueueEmpty(q)!=1)//(7)
    {
        deQueue(q,e);
        cout<<e<<' ';
    }
    free(q);//(8)
}
