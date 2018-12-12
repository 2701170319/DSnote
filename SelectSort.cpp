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
void SelectSort(RecType R[], int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(R[j].key<R[k].key)
                k=j;
        if(k!=i)
            swap(R[i],R[k]);
        cout<<R[i].key;
        b[route++]=R[k].key;
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

    SelectSort(R,n);

    printf("afer sort: ");
    for(int i=0;i<n;i++)
        cout<<R[i].key<<' ';
    cout<<endl;
//cout<<"k= "<<route;
    printf("ÅÅÐò¹ý³ÌÎª: ");
    for(int i=0;i<route;i++)
        cout<<b[i]<<' ';
}

