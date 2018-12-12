#include<bits/stdc++.h>
using namespace std;
typedef int KeyType;
typedef int InfoType;
int b[100];
typedef struct
{
    KeyType key;
    InfoType data;
} RecType;

int route;
void BinInsertSort(RecType R[], int n)
{
    int i,j,low,high,mid;
    RecType tmp;
    for(i=1; i<n; i++)
    {
        if(R[i].key<R[i-1].key)
        {
            tmp=R[i];
            low=0;
            high=i-1;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(tmp.key<R[mid].key)
                    high=mid-1;
                else
                    low=mid+1;
                b[route++]=R[mid].key;
            }
            for(j=i-1; j>=high+1; j--) //error j<high
                R[j+1]=R[j];
            R[high+1]=tmp;
        }

    }
}

int main()
{
    int a[]= {3,2,1};
    RecType R[10];
    int n=3;
    for(int i=0; i<n; i++)
        R[i].key=a[i];
    printf("befor sort: ");
    for(int i=0; i<n; i++)
        cout<<R[i].key<<' ';
    cout<<endl;

    BinInsertSort(R,n);

    printf("afer sort: ");
    for(int i=0; i<n; i++)
        cout<<R[i].key<<' ';
    cout<<endl;

    printf("ÅÅÐò¹ý³ÌÎª: ");
    for(int i=0; i<route; i++)
        cout<<b[i]<<' ';
}

