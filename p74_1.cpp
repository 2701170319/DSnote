#include<bits/stdc++.h>

//定义数据结构
#define MaxSize 50
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

//算法
void InitList(SqList *&L)
{
	L=(SqList*)malloc(sizeof(SqList));
	L->length=0;
}
void DestroyList(SqList *&L)
{
	free(L);
}
bool ListEmpty(SqList *L)
{
	return (L->length==0);
}
int ListLength(SqList *L)
{
	return L->length;
}
void DispList(SqList *L)
{
	for(int i=0;i<L->length;i++)
		printf("%c",L->data[i]);
	printf("\n");
}
bool GetElem(SqList *L, int i, ElemType &e)
{
	if(i<1||i>L->length)
		return false;
	e=L->data[i-1];
	return true;
}
int LocateElem(SqList *L, ElemType e)
{
	int i=0;
	while(i<L->length&&L->data[i]!=e)
		i++;
	if(i>=L->length)
		return 0;
	else
		return i+1;
}
bool ListInsert(SqList *&L,int i,ElemType e)///error01
{
	int j;
	if(i<1||i>L->length+1)
		return false;
	i--;
	for(j=L->length;j>i;j--)
		L->data[j]=L->data[j-1];
	L->data[i]=e;
	L->length++;
	return true;

}
bool ListDelete(SqList *&L, int i, ElemType &e)
{
	int j;
	if(i<1||i>L->length)
		return false;
	i--;
	e=L->data[i];
	for(j=i;j<L->length-1;j++)
		L->data[j]=L->data[j+1];
	L->length--;
	return true;
}

//主函数
int main()
{
	SqList *L;
	ElemType e;int i;
	InitList(L);//(1)

	ListInsert(L,1,'a');ListInsert(L,2,'b');ListInsert(L,3,'c');ListInsert(L,4,'d');ListInsert(L,5,'e');//(2)

	DispList(L);//(3)

	printf("该线性表的长度是%d\n",ListLength(L));//(4)

	if(ListLength(L))//(5)
		printf("该表是不是空表\n");
	else
		printf("该表是空表\n");

	GetElem(L,3,e);//(6)
	printf("该表的第三个元素是%c\n",e);

	i=LocateElem(L,'a');//(7)
	if(i)
		printf("a在该表中的位置是%d\n",i);
	else
		printf("该表中没有a\n");

	ListInsert(L,4,'f');//(8)

	DispList(L);//(9)

	ListDelete(L,3,e);//(10)

	DispList(L);//(11)

	DestroyList(L);//(12)
}
