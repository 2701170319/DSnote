//定义数据结构
//算法
//主函数
int LocateElem(LinkNode*L,ElemType e)
{
    int i=1;
    LinkNode*p=L;
    while(p->next!=NULL&&p->next->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)
        return 0;
    else
        return i;
}


void CreateListR(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s,*r;
    L=(LinkNode*)malloc(sizeof(LinkNode));
    r=L;
    for(int i=0; i<n; i++)
    {
        s=(LinkNode*)malloc(sizeof(LinkNode));
        s->data=a[i];
        r->next=s;
        r=s;

    }
    r->next=NULL;
}

void CreateListF(LinkNode *&L, ElemType a[], int n)
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

int LocateElem(LinkNode *&L, ElemType e)
{
    int i=0;
    LinkNode *p=L;//头结点且i置为零时如何实现
    while(p->next!=NULL)
    {
        i++;
        p=p->next;
        if(p->data==e)
            return i;
    }
    return 0;
}

int LocateElem(LinkNode *&L, ElemType e)
{
    int i=1;
    LinkNode *p=L->next;
    while(p!=NULL)
    {
        if(p->data==e)
            return i;
        i++;
        p=p->next;
    }
    return 0;
}
