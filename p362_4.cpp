#include<bits/stdc++.h>
using namespace std;
typedef int KeyType;
typedef int InfoType;
int b[100];
typedef struct node
{
    KeyType key;
    InfoType data;
    struct node *lchild, *rchild;
}BSTNode;

bool InsertBST(BSTNode *&bt, KeyType k)
{
    if(bt==NULL)
    {
        bt=(BSTNode *)malloc(sizeof(BSTNode));
        bt->key=k;bt->lchild=bt->rchild=NULL;
        return true;

    }
    else if(k==bt->key)
        return false;
    else if(k<bt->key)
        return InsertBST(bt->lchild,k);
    else
        return InsertBST(bt->rchild,k);
}

BSTNode *CreateBST(KeyType a[], int n)
{
    BSTNode *bt=NULL;
    int i=0;
    while(i<n)
    {
        InsertBST(bt,a[i]);
        i++;
    }
    return bt;
}

int i;
BSTNode *SearchBST(BSTNode *bt, KeyType k)
{
    if(bt==NULL||bt->key==k)
    {
        b[i++]=bt->key;
        return bt;
    }
    if(k<bt->key)
    {
        b[i++]=bt->key;
        return SearchBST(bt->lchild,k);

    }
    else
    {
        b[i++]=bt->key;
        return SearchBST(bt->rchild,k);
    }
}

void DispBTree(BSTNode *b)
{
    if(b!=NULL)
    {
        cout<<b->key;//error cout<<b->data;
        if(b->lchild!=NULL||b->rchild!=NULL)
        {
            cout<<'(';
            DispBTree(b->lchild);
            if(b->rchild!=NULL)cout<<',';
            DispBTree(b->rchild);
            cout<<')';
        }
    }
}

int main()
{
    BSTNode *bt,*p;
    bt=NULL;
    int a[]={4,9,0,1,8,6,3,5,2,7};
    int n=10,k=6;
    bt=CreateBST(a,n);
    DispBTree(bt);
    cout<<endl;
    p=SearchBST(bt,k);
    if(p=NULL)
        printf("%d不在表中\n",k);
    else
        printf("%d在表中\n",k);

    printf("寻找关键字%d的路径是: ",k);
    for(int j=0;j<i;j++)
        cout<<b[j]<<' ';
    cout<<endl;
}
