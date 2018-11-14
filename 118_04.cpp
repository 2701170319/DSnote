#include<bits/stdc++.h>
using namespace std;
typedef char ElemType;

#define MaxSize 50

typedef struct qnode
{
    ElemType data;
    struct qnode *next;
} DataNode;

typedef struct
{
    DataNode *front;
    DataNode *rear;

}LinkQuNode;

void InitQueue(LinkQuNode *&q)
{
    q=(LinkQuNode*)malloc(sizeof(LinkQuNode));
    q->front=q->rear=0;
}

bool enQueue(LinkQuNode *&q,ElemType e)
{
    DataNode *p;
    p=(DataNode *)malloc(sizeof(DataNode));
    p->data=e;
    p->next=NULL;
    if(q->rear==NULL)
        q->front=q->rear=p;
    else
    {
        q->rear->next=p;
        q->rear=p;
    }
}

bool deQueue(LinkQuNode *&q, ElemType &e)
{
    DataNode *t;
    if(q->rear==NULL)
        return false;
    t=q->front;
    if(q->front==q->rear)
        q->front=q->rear=NULL;
    else
        q->front=q->front->next;
    e=t->data;
    free(t);
    return true;
}

bool QueueEmpty(LinkQuNode *q)
{
    return (q->front==NULL);///error: (q->front==q->rear)
}

void DestroyQueue(LinkQuNode *&q)
{

}

int ListLen(LinkQuNode *p)
{
    int n=0;
    DataNode *q=p->front;
    while(q!=NULL)
    {
        n++;
        q=q->next;
    }
    return n;
}

int main()
{
    LinkQuNode *q;
    ElemType e;
    InitQueue(q);
    if(QueueEmpty(q)==1)//(1)
        cout<<"该队列为空\n";
    else
        cout<<"该队列不为空\n";
    enQueue(q,'a');enQueue(q,'b');enQueue(q,'c');//(2)
    cout<<ListLen(q)<<endl;
    deQueue(q,e);//(3)
    cout<<e<<endl;

    enQueue(q,'d');enQueue(q,'e');enQueue(q,'f');//(4)
    cout<<"该队列长度： "<<ListLen(q)<<endl;//习题1
    while(QueueEmpty(q)!=1)//(5)
    {
        deQueue(q,e);
        cout<<e<<' ';
    }
    cout<<endl;

    DestroyQueue(q);//(6)
}

