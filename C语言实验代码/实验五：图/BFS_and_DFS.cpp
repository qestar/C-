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

//���еĳ�ʼ�� 
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
//�ж϶ӿ�
int Empty_SeqQueue(PSeqQueue Q)
{
	if(Q&&Q->front==Q->rear)
	   return (1);
	else 
	   return (0);
}
//���
int In_SeqQueue(PSeqQueue Q,DataType x)
{
	if((Q->rear+1)%MAXSIZE==Q->front)
	{
		printf("����");
		return -1;
	}
	else 
	{
		Q->rear=(Q->rear+1)%MAXSIZE;
		Q->data[Q->rear]=x;
		return 1;
	}
 } 
//����
int Out_SeqQueue(PSeqQueue Q,DataType *x)
{
	if(Empty_SeqQueue(Q))
	{
		printf("�ӿգ����ܳ���");
		return -1;
	}
	else
	{
		Q->front=(Q->front+1)%MAXSIZE;
		*x=Q->data[Q->front];
		return (*x);
	}
}
//��ȱ����ݹ��㷨
void DFS(ALGraph *G,int v)
{
	EdgeNode *p;
	printf("%3d",v);                          
	printf("%c ",G->adjlist[v].vertex);	      
	Visited[v]=1;                              
	p=G->adjlist[v].firstedge;                 
	while(p!=NULL)
	{
		if(Visited[p->adjvertex]==0)           
		   DFS(G,p->adjvertex);                
		p=p->next;
	}
} 

//��ȱ����㷨 
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


//��������ͼ���ڽӱ� 
void CreateALGraph(ALGraph *G)
{
	int i,j,k;
	EdgeNode *p;
	printf("���붥����n�ͱ���e(�ã�������:");
	scanf("%d,%d",&(G->n),&(G->e));
	printf("\n");
	for(i=0;i<G->n;i++)
	{
		printf("���붥����Ϣ���ַ���:\n");
		scanf("%s",&(G->adjlist[i].vertex));
		G->adjlist[i].firstedge=NULL;
	}
	for(k=0;k<G->e;k++)
	{
		printf("�����(vi,vj)�ϵĶ������(���Ÿ���)��\n");
		scanf("%d,%d",&i,&j);
		p=(EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvertex=j;                      //�ڽ����Ϊj
		p->next=G->adjlist[i].firstedge;     //��p��ָ��ָ��ǰ������ָ��Ľڵ�
		G->adjlist[i].firstedge=p;           //����ǰ����ָ��ָ��e

		p=(EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvertex=i;
		p->next=G->adjlist[j].firstedge;
		G->adjlist[j].firstedge=p;
	}
}
//����ڽӱ�
void PrintAlgraph(ALGraph *G)
{
	int i;
	EdgeNode *p;
	printf("ͼ���ڽӱ��ʾ����\n");
	printf("%6s%8s%12s\n","���","����","���ڱ߱��");
	for(i=0;i<G->n;i++)
	{
		printf("%4d %8c",i,G->adjlist[i].vertex);
		for(p=G->adjlist[i].firstedge;p!=NULL;p=p->next)
			printf("%4d",p->adjvertex);
		printf("\n");
	}
} 
//������
int main(void)
{
	ALGraph *G;
	G=(ALGraph*)malloc(sizeof(ALGraph));
	printf("��������ͼG��������ݣ�\n");
	CreateALGraph(G);
	printf("����ͼG���ڽӱ�Ϊ��\n");
	PrintAlgraph(G);
	printf("�Ӷ���0��ʼ����ȱ�����\n");
	DFS(G,0);
	printf("\n");
	printf("�Ӷ���0��ʼ�Ĺ�ȱ�����\n");
	BFS(G,0);
	printf("\n");
	return 0;

}








