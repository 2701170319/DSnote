#include<bits/stdc++.h>
using namespace std;
typedef int KeyType;
typedef int InfoType;
#define MaxSize 100
typedef struct
{
    KeyType key;
    InfoType data;
}RecType;

int SeqSearch(RecType R[], int n, KeyType k)
{
    int i=0;
    R[n].key=k;
    while(R[i].key!=k)
        i++;
    if(i==n)
        return 0;
    else
        return i+1;
}

int BinSearch(RecType R[], int n, KeyType k)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(k==R[mid].key)
            return mid+1;
        else
            low=mid+1;
    }
}
//输出路径函数
void DispR(RecType R[], int n, KeyType k)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        cout<<mid<<' ';
        if(k==R[mid].key)
        {
            cout<<k;
            break;
        }
        else
            low=mid+1;
    }
    cout<<endl;
}
int main()
{
RecType r[MaxSize];
int n=10,i,k=9;
for(i=0;i<n;i++)
    r[i].key=i+1;
i=BinSearch(r,n,k);
if(i==0)
    printf("该表没有关键字为%d的记录\n",k);
else
    printf("关键字%d在表中第%d的位置\n",k,i);

printf("寻找关键字%d的路径是: ",k);
DispR(r,n,k);
}
