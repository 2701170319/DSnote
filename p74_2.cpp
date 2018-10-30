#include<bits/stdc++.h>
using namespace std;
typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode*next;
}LinkNode;

void InitList(LinkNode*&L)
{
    L=(LinkNode*)malloc(sizeof(LinkNode));
    L->next=NULL;
}

void CreateListF(LinkNode*&L, ElemType a[], int n)
{
    LinkNode *s;
    L=(LinkNode*)malloc(sizeof(LinkNode));
    L->next=NULL;
    for(int i=0;i<n;i++)
    {
        s=(LinkNode*)malloc(sizeof(LinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;

    }
}

void CreateListR(LinkNode*&L, ElemType a[], int n)
{
    LinkNode*s,*r;
    L=(LinkNode*)malloc(sizeof(LinkNode));
    r=L;
    for(int i=0;i<n;i++)
    {
         s=(LinkNode*)malloc(sizeof(LinkNode));
         s->data=a[i];
         r->next=s;
         r=s;

    }
    r->next=NULL;
}

int ListLength(LinkNode*L)
{
    int n=0;
    LinkNode*p=L;
    while(p->next!=NULL)
    {
        n++;
        p=p->next;
    }
    return n;
}

void DispList(LinkNode*L)
{
    LinkNode*p=L->next;
    while(p!=NULL)
    {
        cout<< p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}

bool GetElem(LinkNode *L,int i,ElemType &e)
{
    int j=0;
    LinkNode *p=L;
    if(i<=0)return false;
    while(j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        e=p->data;
        return true;
    }
}

int LocateElem(LinkNode *L,ElemType e)
{
    int i=1;
    LinkNode *p=L->next;
    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)
        return(0);
    else
        return(i);
}

bool ListInsert(LinkNode *&L,int i,ElemType e)

{
    int j=0;
    LinkNode *p=L,*s;
    if(i<=0)return false;
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}

bool ListDelete(LinkNode *&L,int i,ElemType &e)
{
    int j=0;
    LinkNode *p=L,*q;
    if(i<=0) return false;
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        q=p->next;
        if(q==NULL)
            return false;
        e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }
}

void DestroyList(LinkNode*&L)
{
    LinkNode *pre=L,*p=L->next;
    while(p!=NULL)
    {
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}

int main()
{
    LinkNode *L;
    ElemType a[]={'a','b','c','d','e'};
    ElemType e;
    InitList(L);//(1)
    //CreateListF(L,a,4);
    CreateListR(L,a,4);//(2)
    DispList(L);//(3)
    cout<<ListLength(L)<<endl;//(4)
    if(ListLength(L)==0)//(5)
        printf("NO DATA\n");
    else
        printf("Get\n");
    GetElem(L,3,e);
    cout<<e<<"\n";//(6)
    cout<<LocateElem(L,'a')<<"\n";//(7)
    ListInsert(L,4,'f');//(8)
    DispList(L);//(9)
    ListDelete(L,3,e);//(10)
    DispList(L);//(11)
    DestroyList(L);//(12)
}
