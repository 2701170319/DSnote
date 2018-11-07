#include<bits/stdc++.h>
using namespace std;
typedef char ElemType;
#define MaxSize 50
typedef struct linknode
{
    ElemType data;
    struct linknode *next;
}LinkStNode;

void InitStack(LinkStNode *&s)
{
    s=(LinkStNode*)malloc(sizeof(LinkStNode));
    s->next=NULL;
}

bool Push(LinkStNode *&s,ElemType e)
{
    LinkStNode *p;
    p=(LinkStNode*)malloc(sizeof(LinkStNode));
    p->data=e;
    p->next=s->next;
    s->next=p;

}

bool Pop(LinkStNode*&s,ElemType &e)
{
    LinkStNode *p;
    if(s->next==NULL)
        return false;
    p=s->next;
    e=p->data;
    s->next=p->next;
    free(p);
    return false;
}

void DestroyStack(LinkStNode *&s)
{
    LinkStNode *pre=s,*p=s->next;
    while(p!=NULL)
    {
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}

void outputF(LinkStNode *s)//输出栈顶到栈底的元素
{
    LinkStNode *p=s->next;//首结点
    while(p!=NULL)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}

void outputR(LinkStNode *s)
{

}

int ListLen(LinkStNode *s)
{
    int n=0;
    LinkStNode *p=s->next;
    while(p!=NULL)
    {
        n++;
        p=p->next;
    }
    return n;
}

/**void CreateListF(LinkStNode*&L, ElemType a[], int n) //建立链表输入元素
{
    LinkStNode *s;
    L=(LinkStNode*)malloc(sizeof(LinkStNode));
    L->next=NULL;
    for(int i=0;i<n;i++)
    {
        s=(LinkStNode*)malloc(sizeof(LinkStNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;

    }
}*/

int main()
{
    LinkStNode *s;ElemType e;
    ElemType a[]={'a','b','c','d','e'};
    InitStack(s);//(1)
    if(s->next==NULL)//(2)
        printf("空栈\n");
    else
        printf("非空栈\n");

    Push(s,'a');Push(s,'b');Push(s,'c');Push(s,'d');Push(s,'e');//(3)
    //CreateListF(s,a,5);


    if(s->next==NULL)//(4)
        printf("空栈\n");
    else
        printf("非空栈\n");

    outputF(s);///习题(1)
    printf("栈的长度是%d\n",ListLen(s));///习题(2)

    while(s->next!=NULL)//(5)
    {
        Pop(s,e);
        cout<<e<<' ';
    }
    cout<<endl;

    if(s->next==NULL)//(4)
        printf("空栈\n");
    else
        printf("非空栈\n");

    DestroyStack(s);
}
