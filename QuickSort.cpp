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
int partition(RecType R[], int s, int t)
{
    int i=s,j=t;
    RecType tmp=R[i];
    while(i<j)
    {
        while(j>i&&R[j].key>=tmp.key)
            j--;
        R[i]=R[j];
        while(i<j&&R[i].key<=tmp.key)
            i++;
        R[j]=R[i];
    }
    R[i]=tmp;
    b[route++]=tmp.key;
    return i;
}

void QuickSort(RecType R[], int s, int t)
{
    int i;
    if(s<t)
    {
        i=partition(R,s,t);
        QuickSort(R,s,i-1);
        QuickSort(R,i+1,t);
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

    QuickSort(R,0,n);

    printf("afer sort: ");
    for(int i=0;i<n;i++)
        cout<<R[i].key<<' ';
    cout<<endl;

    printf("ÅÅÐò¹ý³ÌÎª: ");
    for(int i=0;i<route;i++)
        cout<<b[i]<<' ';
}

