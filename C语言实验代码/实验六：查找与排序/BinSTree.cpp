#include<stdio.h>
#include<malloc.h>
typedef struct Node{
	int key;
	struct Node *lchild,*rchild;
}BSTNode;
int InsertBST(BSTNode *&t,int k);
void PrintBST(BSTNode *t);
//二叉排序树的创建
BSTNode* CreateBST(int A[],int n)
{
	BSTNode *t=NULL; 
	int i=0;
	while(i<n)
	{
		if(InsertBST(t,A[i])==1)
		{
			printf("第%d步，插入%d：",i+1,A[i]);
			PrintBST(t);
			printf("\n\n");
			i++;
		}
	}
	return t;
 } 
//二叉排序树的输出 
void PrintBST(BSTNode *t)
{
	if(t!=NULL)
	{
		printf("%d",t->key);
		if(t->lchild!=NULL||t->rchild!=NULL)
		{
			printf("(");
			PrintBST(t->lchild);
			if(t->rchild!=NULL)
			   printf(",");
			PrintBST(t->rchild);
			printf(")");
		}
	}
}
//二叉排序树的插入 
int InsertBST(BSTNode *&p,int k)
{
	if(p==NULL)
	{
		p=(BSTNode*)malloc(sizeof(BSTNode));
		p->key=k;
		p->lchild=p->rchild=NULL;
		return 1; 
	}
	else if(k<p->key)
	     return InsertBST(p->lchild,k);
	else
	     return InsertBST(p->rchild,k);
}
void Visit(int e)
{
	printf("%d ",e);
}
//中序
void InOrder(BSTNode *t)
{
	if(t)
	{
		InOrder(t->lchild);
		Visit(t->key);
		InOrder(t->rchild);
	}
}

int main()
{
	BSTNode *t;
	int a[10],n=10,i;
	printf("输入10个数：");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("创建一棵BST树：");
	printf("\n\n");
	t=CreateBST(a,n);
	printf("BST:");
	PrintBST(t);
	printf("\n");
	printf("中序遍历：");
	InOrder(t);
}	
	
	
	
