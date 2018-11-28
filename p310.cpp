#include <bits/stdc++.h>
using namespace std;
//1、定义图的类型
#define INF 32767				//定义∞
#define	MAXV 6				//最大顶点个数
#define MaxSize 50
typedef char InfoType;

typedef struct
{	int no;						//顶点编号
	InfoType info;				//顶点其他信息
} VertexType;					//顶点类型
typedef struct
{	int edges[MAXV][MAXV];		//邻接矩阵数组
	int n,e;					//顶点数，边数
	VertexType vexs[MAXV];		//存放顶点信息
} MatGraph;						//完整的图邻接矩阵类型

//以下定义邻接表类型
typedef struct ANode
{	int adjvex;					//该边的邻接点编号
	struct ANode *nextarc;		//指向下一条边的指针
	int weight;					//该边的相关信息，如权值（用整型表示）
} ArcNode;						//边结点类型
typedef struct Vnode
{	InfoType info;				//顶点其他信息
	int count;					//存放顶点入度,仅仅用于拓扑排序
	ArcNode *firstarc;			//指向第一条边
} VNode;						//邻接表头结点类型
typedef struct
{	VNode adjlist[MAXV];		//邻接表头结点数组
	int n,e;					//图中顶点数n和边数e
} AdjGraph;						//完整的图邻接表类型

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int front,rear;		//队首和队尾指针
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
{	if ((q->rear+1)%MaxSize==q->front)	//队满上溢出
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,ElemType &e)
{	if (q->front==q->rear)				//队空下溢出
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
//2、图的基本算法P260建立图邻接表CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e)
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

//p261图的邻接表输出//P262ListToMat()  P265 深度优先遍历  P266广度优先遍历

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

//入度
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

//出度
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
//3 、编写主函数

int main()
{
   AdjGraph *G;MatGraph g;
   int A[MAXV][MAXV]={{0,1,0,1,0,0},{0,0,1,0,0,0},{1,0,0,0,0,1},{0,0,1,0,0,1},{0,0,0,1,0,0},{1,0,0,0,1,0}};
   int n=6,e=10;
   CreateAdj(G,A,n,e);//1.(2)
   printf("该图的邻接表为 \n");
   DispAdj(G);//输出了图的邻接表

   //初始化g
   for(int i=0;i<n;i++)
	   for(int j=0;j<n;j++)
		   g.edges[i][j]=0;
   ListToMat(G,g);//1.(1)

    printf("该图的邻接矩阵为 \n");
   //习题1、输出邻接矩阵（自己编）
   DispMat(g);


	printf("该图从0开始深度优先遍历位：\n");//2.(1)
	DFS(G,0);
	cout<<endl;

    printf("该图从0开始广度优先遍历位：\n");//2(3)
	BFS(G,0);
//习题2、求出该图顶点2的度并输出（自己编）
    //outDegree(G);///出度
    cout<<"顶点2的度为; "<<inDegree(G,2)+outDegree(G,2)<<endl;
}

//思考题： 求顶点2到3之间的所有路径



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
