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

void outputF(LinkStNode *s)//���ջ����ջ�׵�Ԫ��
{
    LinkStNode *p=s->next;//�׽��
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

/**void CreateListF(LinkStNode*&L, ElemType a[], int n) //������������Ԫ��
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
        printf("��ջ\n");
    else
        printf("�ǿ�ջ\n");

    Push(s,'a');Push(s,'b');Push(s,'c');Push(s,'d');Push(s,'e');//(3)
    //CreateListF(s,a,5);


    if(s->next==NULL)//(4)
        printf("��ջ\n");
    else
        printf("�ǿ�ջ\n");

    outputF(s);///ϰ��(1)
    printf("ջ�ĳ�����%d\n",ListLen(s));///ϰ��(2)

    while(s->next!=NULL)//(5)
    {
        Pop(s,e);
        cout<<e<<' ';
    }
    cout<<endl;

    if(s->next==NULL)//(4)
        printf("��ջ\n");
    else
        printf("�ǿ�ջ\n");

    DestroyStack(s);
}
