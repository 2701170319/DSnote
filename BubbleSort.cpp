#include<bits/stdc++.h>
using namespace std;
typedef int KeyType;
typedef int InfoType;
int b[100];
typedef struct
{
    KeyType key;
    InfoType data;
}RecType;

int route;
void BubbleSort(RecType R[], int n)
{
    int i,j;
    bool flag;
    for(i=0;i<n-1;i++)
    {
        flag=false;
        for(j=n-1;j>i;j--)
            if(R[j].key < R[j-1].key)
            {
                swap(R[j],R[j-1]);
                flag=true;
                b[route++]=R[j-1].key;
            }
        if(!flag)
            return ;
    }
}

int main()
{
    int a[]={3,2,1};
    RecType R[10];int n=3;
    for(int i=0;i<n;i++)
        R[i].key=a[i];
    printf("befor sort: ");
    for(int i=0;i<n;i++)
        cout<<R[i].key<<' ';
    cout<<endl;

    BubbleSort(R,n);

    printf("afer sort: ");
    for(int i=0;i<n;i++)
        cout<<R[i].key<<' ';
    cout<<endl;

    printf("ÅÅÐò¹ý³ÌÎª: ");
    for(int i=0;i<route;i++)
        cout<<b[i]<<' ';
}

