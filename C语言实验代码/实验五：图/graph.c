#include<stdio.h>
#include<malloc.h>
#define MaxVertexNum 30
#define MAXSIZE 100
#define MAXV 100
int Visited[MAXV];
typedef  int  DataType;
typedef int InfoType;
typedef char VertexType;
typedef struct node{
	int adjvertex;
	InfoType info;
	struct node *next;
}EdgeNode;
typedef struct vnode{
	VertexType vertex;
	EdgeNode *firstedge;
}VertexNode;
typedef struct{
	VertexNode adjlist[MaxVertexNum];
	int n,e;
}ALGraph;
typedef struct{
	DataType data[MAXSIZE];
	int front,rear;
}SeqQueue,*PSeqQueue;
/*typedef struct Lnode{
	int data[100];
	int top;
}SeqStack,*PSeqStack;
//初始化栈 
PSeqStack Init_SeqStack(void)
{
	PSeqStack S;
	S=(PSeqStack)malloc(sizeof(SeqStack));
	if(S)
	  S->top=-1;
	return(S); 
}
//判断栈是否为空
int Empty_SeqStack(PSeqStack S)
{
	if(S->top==-1)
	  return(1);
	else
	  return(0);
	
}
//入栈
int Push_SeqStack(PSeqStack S,int x)
{
	if(S->top==MAXSIZE-1)
	  return 0;
	else
	{
		S->top++;
		S->data[S->top]=x;
		return 1;
	}
 } 
//出栈
int Pop_SeqStack(PSeqStack S,int *x)
{
	if(Empty_SeqStack(S))
	{
		printf("栈空，不能出栈");
		return(0);
	}
	else
	{
		*x=S->data[S->top];
		S->top--;
		return *x;
	}
}*/
//队列的初始化 
PSeqQueue Init_SeqQueue()
{
	PSeqQueue Q;
	Q=(PSeqQueue)malloc(sizeof(SeqQueue));
	if(Q)
	{
		Q->front=0;
		Q->rear=0;
	}
	return Q;
}
//判断队空
int Empty_SeqQueue(PSeqQueue Q)
{
	if(Q&&Q->front==Q->rear)
	   return (1);
	else 
	   return (0);
}
//入队
int In_SeqQueue(PSeqQueue Q,DataType x)
{
	if((Q->rear+1)%MAXSIZE==Q->front)
	{
		printf("队满");
		return -1;
	}
	else 
	{
		Q->rear=(Q->rear+1)%MAXSIZE;
		Q->data[Q->rear]=x;
		return 1;
	}
 } 
//出队
int Out_SeqQueue(PSeqQueue Q,DataType *x)
{
	if(Empty_SeqQueue(Q))
	{
		printf("队空，不能出队");
		return -1;
	}
	else
	{
		Q->front=(Q->front+1)%MAXSIZE;
		*x=Q->data[Q->front];
		return (*x);
	}
}
//深度遍历递归算法
void DFS(ALGraph *G,int v)
{
	EdgeNode *p;
	printf("%3d",v);                          //输出被访问顶点的编号
	printf("%c ",G->adjlist[v].vertex);	      //输出顶点信息 
	Visited[v]=1;                             //已访问的做标记 
	p=G->adjlist[v].firstedge;                //p指向顶点v的第一条边的边头结点 
	while(p!=NULL)
	{
		if(Visited[p->adjvertex]==0)          //若p->adjvertex顶点未被访问，递归访问它 
		   DFS(G,p->adjvertex);               //p指向顶点v的下一条边的边头结点 
		p=p->next;
	}
} 
//深度遍历非递归算法
void DFS1(ALGraph *G,int v)
{
	printf("数组模拟栈深度遍历:\n");
	int top,i;
	EdgeNode *adress[MAXSIZE];
	EdgeNode *p;
	for(i=0;i<G->n;i++)
		Visited[i]=0;
	printf("Array DFS:");
	top=-1;
	for(i=v;i<G->n;i++)
	{
		if(Visited[i]==0)
		{
		
			printf("%3d",i);
			printf("%c ",G->adjlist[i].vertex);
			Visited[i]=1;
			for(p=G->adjlist[i].firstedge;p;p=p->next)
				if(Visited[p->adjvertex]==0)
				{
					printf("%3d",p->adjvertex);
					printf("%c ",G->adjlist[p->adjvertex].vertex);
					Visited[p->adjvertex]=1;
					top++;
					adress[top]=p;
					break;
				}
			while(p&&top>=-1)
			{
				for(p=G->adjlist[p->adjvertex].firstedge;p;p=p->next)
				{
					if(Visited[p->adjvertex]==0)
					{
						printf("%3d",p->adjvertex);
						printf("%c ",G->adjlist[p->adjvertex].vertex);
						Visited[p->adjvertex]=1;
						top++;
						adress[top]=p;
						break;
					}
				}
				if(top>-1)
				{
				    p=adress[top]->next;
				    top--;
				}
					
			}
		}

	}
}
/*
void shuzuvisit(PALGraph G)
{
	printf("数组模拟栈深度遍历:\n");
	int v,top,i=0;
	EdgeNode *adress[MAXSIZE];
	EdgeNode *p;
	for(v=0;v<G->vertexNum;v++)
		G->adjlist[v].tag=0;
	printf("Array DFS:");
	top=-1;
	for(v=0;v<G->vertexNum;v++)
	{
		printf("\n");
		printf("从第%d个顶点遍历\n",++i);

		if(!G->adjlist[v].tag)
		{
		
			Visit(G,v);
			G->adjlist[v].tag=1;
			for(p=G->adjlist[v].firstedge;p;p=p->next)
				if(G->adjlist[p->adjvertex].tag==0)
				{
					Visit(G,p->adjvertex);
					G->adjlist[p->adjvertex].tag=1;
					top++;
					adress[top]=p;
					break;
				}
			while(p&&top>=-1)
			{
				for(p=G->adjlist[p->adjvertex].firstedge;p;p=p->next)
				{
					if(!G->adjlist[p->adjvertex].tag)
					{
						Visit(G,p->adjvertex);
						G->adjlist[p->adjvertex].tag=1;
						top++;
						adress[top]=p;
						break;
					}
				}
				if(top>-1)
				{
				    p=adress[top]->next;
				    top--;
				}
					
			}
		}

	}
}
*/
//广度遍历算法 
void BFS(ALGraph *G,int v)
{
	int Visited[MAXV];
	EdgeNode *p;
	PSeqQueue Q;
	int w,i;
	Q=Init_SeqQueue();
	for(i=0;i<G->n;i++)
	   Visited[i]=0;
	printf("%3d",v);
	printf("%c ",G->adjlist[v].vertex);
	Visited[v]=1;
	In_SeqQueue(Q,v);
	while(!Empty_SeqQueue(Q))
	{
		w=Out_SeqQueue(Q,&w);
		p=G->adjlist[w].firstedge;
		while(p!=NULL)
		{
			if(Visited[p->adjvertex]==0)
			{
				printf("%3d",p->adjvertex);
				printf("%c ",G->adjlist[w].vertex);
				Visited[p->adjvertex]=1;
				In_SeqQueue(Q,p->adjvertex);
			}
			p=p->next;
		}
	}
	printf("\n");
}
//创建有向图的邻接表 
void CreateALGraph(ALGraph *G)
{
	int i,j,k;
	EdgeNode *p;
	printf("输入顶点数n和边数e(用，隔开）:");
	scanf("%d,%d",&(G->n),&(G->e));
	printf("\n");
	for(i=0;i<G->n;i++)
	{
		printf("输入顶点信息（字符）:\n");
		scanf("%s",&(G->adjlist[i].vertex));
		G->adjlist[i].firstedge=NULL;
	}
	for(k=0;k<G->e;k++)
	{
		printf("输入边(vi,vj)上的顶点序号(逗号隔开)：\n");
		scanf("%d,%d",&i,&j);
		p=(EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvertex=j;                      //邻接序号为j
		p->next=G->adjlist[i].firstedge;     //将p的指针指向当前顶点上指向的节点
		G->adjlist[i].firstedge=p;           //将当前顶点指针指向e

		p=(EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvertex=i;
		p->next=G->adjlist[j].firstedge;
		G->adjlist[j].firstedge=p;
	}
}
//输出邻接表
void PrintAlgraph(ALGraph *G)
{
	int i;
	EdgeNode *p;
	printf("图的邻接表表示如下\n");
	printf("%6s%8s%12s\n","编号","顶点","相邻边编号");
	for(i=0;i<G->n;i++)
	{
		printf("%4d %8c",i,G->adjlist[i].vertex);
		for(p=G->adjlist[i].firstedge;p!=NULL;p=p->next)
			printf("%4d",p->adjvertex);
		printf("\n");
	}
} 
//主函数
int main(void)
{
	ALGraph *G;
	G=(ALGraph*)malloc(sizeof(ALGraph));
	printf("输入有向图G的相关数据：\n");
	CreateALGraph(G);
	printf("有向图G的邻接表为：\n");
	PrintAlgraph(G);
	printf("从顶点0开始的深度遍历（递归）：\n");
	DFS(G,0);
	printf("\n");
	printf("从顶点0开始的深度遍历（非递归）：\n");
	DFS1(G,0);
	printf("\n");
	printf("从顶点0开始的广度遍历（递归）：\n");
	BFS(G,0);
	printf("\n");
	//shuzuvisit(PALGraph G)
	return 0;

}