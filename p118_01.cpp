#include<bits/stdc++.h>
using namespace std;
typedef char ElemType;
#define MaxSize 50
typedef struct
{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack *&s)
{
    s=(SqStack*)malloc(sizeof(SqStack));
    s->top=-1;
}

bool Push(SqStack *&s,ElemType e)
{
    if(s->top==MaxSize-1)
        return false;
    s->top++;
    s->data[s->top]=e;
    return true;
}

bool Pop(SqStack*&s,ElemType &e)
{
    if(s->top==-1)
        return false;
    e=s->data[s->top];
    s->top--;
    return true;
}

void printF(SqStack *s)//’ª∂•µΩ’ªµ◊ ‰≥ˆ‘™Àÿ
{
    for(int i=s->top;i>=0;i--)
        cout<<s->data[i]<<' ';
    cout<<endl;
}

void printR(SqStack *s)//’ªµ◊µΩ’ª∂• ‰≥ˆ‘™Àÿ
{
    for(int i=0;i<=s->top;i++)
        cout<<s->data[i]<<' ';
    cout<<endl;
}

int main()
{
    SqStack *s;ElemType e;
    InitStack(s);//(1)
    if(s->top==-1)//(2)
        printf("ø’’ª\n");
    else
        printf("∑«ø’’ª\n");

    Push(s,'a');Push(s,'b');Push(s,'c');Push(s,'d');Push(s,'e');//(3)



    if(s->top==-1)//(4)
        printf("ø’’ª\n");
    else
        printf("∑«ø’’ª\n");

    printF(s);///(’ª∂•µΩ’ªµ◊)
    printR(s);///(’ªµ◊µΩ’ª∂•)

    while(s->top!=-1)//(5)
    {
        Pop(s,e);
        cout<<e<<' ';
    }
    cout<<endl;

    if(s->top==-1)//(4)
        printf("ø’’ª\n");
    else
        printf("∑«ø’’ª\n");

    free(s);
}
