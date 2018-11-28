#include <bits/stdc++.h>
using namespace std;
//1������ͼ������
#define INF 32767				//�����
#define	MAXV 6				//��󶥵����
#define MaxSize 50
typedef char InfoType;

typedef struct
{	int no;						//������
	InfoType info;				//����������Ϣ
} VertexType;					//��������
typedef struct
{	int edges[MAXV][MAXV];		//�ڽӾ�������
	int n,e;					//������������
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MatGraph;						//������ͼ�ڽӾ�������

//���¶����ڽӱ�����
typedef struct ANode
{	int adjvex;					//�ñߵ��ڽӵ���
	struct ANode *nextarc;		//ָ����һ���ߵ�ָ��
	int weight;					//�ñߵ������Ϣ����Ȩֵ�������ͱ�ʾ��
} ArcNode;						//�߽������
typedef struct Vnode
{	InfoType info;				//����������Ϣ
	int count;					//��Ŷ������,����������������
	ArcNode *firstarc;			//ָ���һ����
} VNode;						//�ڽӱ�ͷ�������
typedef struct
{	VNode adjlist[MAXV];		//�ڽӱ�ͷ�������
	int n,e;					//ͼ�ж�����n�ͱ���e
} AdjGraph;						//������ͼ�ڽӱ�����

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int front,rear;		//���׺Ͷ�βָ��
} SqQueue;
void InitQueue(SqQueue *&q)
{	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)
{
	free(q);
}
bool QueueEmpty(SqQueue *q)
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,ElemType e)
{	if ((q->rear+1)%MaxSize==q->front)	//���������
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,ElemType &e)
{	if (q->front==q->rear)				//�ӿ������
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
//2��ͼ�Ļ����㷨P260����ͼ�ڽӱ�CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e)
void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)
{
    int i,j;ArcNode *p;
    G=(AdjGraph *)malloc(sizeof(AdjGraph));
    for(i=0;i<n;i++)
        G->adjlist[i].firstarc=NULL;
    for(i=0;i<n;i++)
        for(j=n-1;j>=0;j--)
            if(A[i][j]!=0&&A[i][j]!=INF)
    {
        p=(ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex=j;
        p->weight=A[i][j];
        p->nextarc=G->adjlist[i].firstarc;
        G->adjlist[i].firstarc=p;
    }
    G->n=n;G->e=e;
}

void DispAdj(AdjGraph *G)
{
    int i; ArcNode *p;
    for(i=0;i<G->n;i++)
    {
        p=G->adjlist[i].firstarc;
        printf("%2d:",i);
        while(p!=NULL)
        {
            printf("%2d[%d]->",p->adjvex,p->weight);
            p=p->nextarc;
        }
        printf("^\n");
    }
}

void ListToMat(AdjGraph *G, MatGraph &g)
{
    int i;
    ArcNode *p;
    for(i=0;i<G->n;i++)
    {
        p=G->adjlist[i].firstarc;
        while(p!=NULL)
        {
            g.edges[i][p->adjvex]=p->weight;
            p=p->nextarc;
        }
    }
    g.n=G->n;g.e=G->e;
}

void DispMat(MatGraph g);

//p261ͼ���ڽӱ����//P262ListToMat()  P265 ������ȱ���  P266������ȱ���

int visited[MaxSize];
void DFS(AdjGraph *G, int v)
{
    ArcNode *p;
    visited[v]=1;
    printf("%2d",v);
    p=G->adjlist[v].firstarc;
    while(p!=NULL)
    {
        if(visited[p->adjvex]==0)
            DFS(G,p->adjvex);
        p=p->nextarc;
    }
}

void BFS(AdjGraph *G, int v)
{
    int w,i;ArcNode *p;
    SqQueue *qu;
    InitQueue(qu);
    int visited[MAXV];
    for(i=0;i<G->n;i++) visited[i]=0;
    printf("%2d",v);
    visited[v]=1;
    enQueue(qu,v);
    while(!QueueEmpty(qu))
    {
        deQueue(qu,w);
        p=G->adjlist[w].firstarc;
        while(p!=NULL)
        {
            if(visited[p->adjvex]==0)
            {
                printf("%2d",p->adjvex);
                visited[p->adjvex]=1;
                enQueue(qu,p->adjvex);
            }
            p=p->nextarc;
        }
    }
    cout<<endl;
}

//���
int inDegree(AdjGraph *G, int n)
{
    ArcNode *p;
    int inD=0;
    p=G->adjlist[n].firstarc;
    while(p!=NULL)
    {
        inD++;
        p=p->nextarc;
    }
    return inD;
}

//����
int outDegree(AdjGraph *G, int n)
{
    ArcNode *p;
    int outD=0;
    p=G->adjlist[n].firstarc;
    while(p!=NULL)
    {
        outD++;
        p=p->nextarc;
    }
    return outD;
}
//3 ����д������

int main()
{
   AdjGraph *G;MatGraph g;
   int A[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,1,0,0,0},{1,0,0,0,0,1},{0,0,1,0,0,1},{0,0,0,1,0,0},{1,0,0,0,1,0}};
   int n=6,e=10;
   CreateAdj(G,A,n,e);//1.(2)
   printf("��ͼ���ڽӱ�Ϊ \n");
   DispAdj(G);//�����ͼ���ڽӱ�

   //��ʼ��g
   for(int i=0;i<n;i++)
	   for(int j=0;j<n;j++)
		   g.edges[i][j]=0;
   ListToMat(G,g);//1.(1)

    printf("��ͼ���ڽӾ���Ϊ \n");
   //ϰ��1������ڽӾ����Լ��ࣩ
   DispMat(g);


	printf("��ͼ��0��ʼ������ȱ���λ��\n");//2.(1)
	DFS(G,0);
	cout<<endl;

    printf("��ͼ��0��ʼ������ȱ���λ��\n");//2(3)
	BFS(G,0);
//ϰ��2�������ͼ����2�ĶȲ�������Լ��ࣩ
    //outDegree(G);///����
    cout<<"����2�Ķ�Ϊ; "<<inDegree(G,2)+outDegree(G,2)<<endl;
}

//˼���⣺ �󶥵�2��3֮�������·��



void DispMat(MatGraph g)
{
	int i,j;
		for(i=0;i<g.n;i++)
	{
		printf("%2d  | ",i);
		for(j=0;j<g.n;j++)
			printf("%3d",g.edges[i][j]);
		printf("   |\n");
	}
}
