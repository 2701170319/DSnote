#include<bits/stdc++.h>
using namespace std;
//1、定义二叉树节点类型
#define MaxSize 100
typedef char ElemType;
typedef struct node
{  ElemType data;
   struct node *lchild;
   struct node *rchild;
}BTNode;

typedef struct
{
     BTNode *data[MaxSize];
     int front,rear;
} SqQueue;//定义顺序队列

//2、P207二叉树的建立算法、P210输出二叉树算法、求二叉树的高度，P212 二叉树的先序、中序和后序遍历递归算法，P226二叉树的层次遍历

void CreateBTree(BTNode *&b, char *str)
{
    BTNode *St[MaxSize],*p;
    int top=-1,k,j=0;
    char ch;
    b=NULL;
    ch=str[j];
    while(ch!='\0')
    {
        switch(ch)
        {
            case '(':top++;St[top]=p;k=1;break;
            case ')':top--;break;
            case ',':k=2;break;
            default:p=(BTNode *)malloc(sizeof(BTNode));
                    p->data=ch;
                    p->lchild=p->rchild=NULL;
                    if(b==NULL)
                        b=p;
                    else
                    {
                        switch(k)
                        {
                            case 1:St[top]->lchild=p;break;
                            case 2:St[top]->rchild=p;break;
                        }
                    }
        }
        j++;
        ch=str[j];
    }
}

void DispBTree(BTNode *b)
{
    if(b!=NULL)
    {
        cout<<b->data;
        if(b->lchild!=NULL||b->rchild!=NULL)
        {
            printf("(");
            DispBTree(b->lchild);
            if(b->rchild!=NULL)printf(",");
            DispBTree(b->rchild);
            printf(")");
        }
    }
}

int BTHeight(BTNode *b)
{
    int lchildh,rchildh;
    if(b==NULL)return 0;
    else
    {
        lchildh=BTHeight(b->lchild);
        rchildh=BTHeight(b->rchild);
        return (lchildh>rchildh)?(lchildh+1):(rchildh+1);
    }
}


//队列算法
void InitQueue(SqQueue *&q)
{
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}

bool enQueue(SqQueue *&q,BTNode *e)
{
     if (q->rear==MaxSize-1)
         return 0;
     q->rear++;
     q->data[q->rear]=e;
     return 1;
}

bool deQueue(SqQueue *&q, BTNode *&e)
{
    if(q->front ==q->rear)
        return false;
    q->front++;
    e=q->data[q->front];
    return true;
}

bool QueueEmpty(SqQueue *q)
{
    return (q->front==q->rear);
}

void PreOrder(BTNode *b)
{
    if(b!=NULL)
    {
        cout<<b->data<<' ';
        PreOrder(b->lchild);
        //n++;
        PreOrder(b->rchild);
    }
}

void InOrder(BTNode *b)
{
    if(b!=NULL)
    {
        InOrder(b->lchild);
        cout<<b->data<<' ';
        InOrder(b->rchild);
    }
}

void PostOrder(BTNode *b)
{
    if(b!=NULL)
    {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        cout<<b->data<<' ';
    }
}

void LevelOrder(BTNode *b)
{
    BTNode *p;
    SqQueue *qu;
    InitQueue(qu);
    enQueue(qu,b);
    while(!QueueEmpty(qu))
    {
        deQueue(qu,p);
        cout<<p->data<<' ';
        if(p->lchild!=NULL)
            enQueue(qu,p->lchild);
        if(p->rchild!=NULL)
            enQueue(qu,p->rchild);
    }
}
int n;
int Node_num(BTNode *b)
{

    if(b!=NULL)
    {
        Node_num(b->lchild);
        n++;
        Node_num(b->rchild);
    }
    return n;
}
int Leafnum;
void LeafCount(BTNode *b)
{
    if(b==NULL)
        return;
    if(b->lchild==NULL&&b->rchild==NULL)
        Leafnum++;
    LeafCount(b->lchild);
    LeafCount(b->rchild);
    return;
}
//3、编写主函数
int main()
{
///I
    BTNode *b;
    char str[]="A(B(D,E(H(J,K(L,M(,N)))))M,C(F,G(I)))";
    CreateBTree(b,str);//1.(1)建立二叉树b
    DispBTree(b);//1.(2)输出二叉树b
    cout<<endl;
    printf("该二叉树的高度为%d\n",BTHeight(b));//1.（4）

///II
    printf("该二叉树的先序遍历为: ");//2(1) 先序遍历
    PreOrder(b);
    printf("\n该二叉树的中序遍历为: ");//2(2) 中先序遍历
    InOrder(b);
    printf("\n该二叉树的后序遍历为: ");//2(3) 后序遍历
    PostOrder(b);
    printf("\n该二叉树的层次序遍历为: ");//2(4) 层次遍历
    LevelOrder(b);
    cout<<endl;
    //补充求出该二叉树叶子节点的个数
    LeafCount(b);
    printf("该二叉树的叶子节点个数为: %d\n",Leafnum);
    //思考题：求出该二叉树节点的个数
    printf("该二叉树的节点个数为: %d\n",Node_num(b));
}
//思考题：求出该二叉树节点的个数

