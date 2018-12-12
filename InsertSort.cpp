#include<bits/stdc++.h>
using namespace std;
int b[100];

typedef int KeyType;
typedef int InfoType;
typedef struct
{
    KeyType key;
    InfoType data;
}RecType;

int route;
void InsertSort(RecType R[],int n)
{
    int i,j;RecType tmp;
    for(i=1;i<n;i++)
    {
        if(R[i].key<R[i-1].key)
        {
            tmp=R[i];
            j=i-1;
            while(j>=0&&R[j].key>tmp.key)
            {
                R[j+1]=R[j];
                j--;
            }
            R[j+1]=tmp;
            b[i]=R[j+1].key;
        }
        b[route++]=tmp.key;
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

    InsertSort(R,n);

    printf("afer sort: ");
    for(int i=0;i<n;i++)
        cout<<R[i].key<<' ';
    cout<<endl;

    printf("ÅÅÐò¹ý³ÌÎª: ");
    for(int i=0;i<route;i++)
        cout<<b[i]<<' ';

}
