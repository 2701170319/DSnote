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
void ShellSort(RecType R[], int n)
{
    int i,j,d;
    RecType tmp;
    d=n/2;
    while(d>0)
    {
        for(i=d;i<n;i++)
        {
            tmp=R[i];
            j=i-d;
            while(j>=0&&tmp.key<R[j].key)
            {
                R[j+d]=R[j];
                j=j-d;
                b[route++]=tmp.key;
                //cout<<tmp.key;
            }
            R[j+d]=tmp;
        }
        d=d/2;
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

    ShellSort(R,n);

    printf("afer sort: ");
    for(int i=0;i<n;i++)
        cout<<R[i].key<<' ';
    cout<<endl;

    printf("ÅÅÐò¹ý³ÌÎª: ");
    for(int i=0;i<route;i++)
        cout<<b[i]<<' ';
}

