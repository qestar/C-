#include<stdio.h>
#include<malloc.h>
typedef struct Node{
	int key;
	struct Node *lchild,*rchild;
}BSTNode;
int InsertBST(BSTNode *&t,int k);
void PrintBST(BSTNode *t);
//�����������Ĵ���
BSTNode* CreateBST(int A[],int n)
{
	BSTNode *t=NULL; 
	int i=0;
	while(i<n)
	{
		if(InsertBST(t,A[i])==1)
		{
			printf("��%d��������%d��",i+1,A[i]);
			PrintBST(t);
			printf("\n\n");
			i++;
		}
	}
	return t;
 } 
//��������������� 
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
//�����������Ĳ��� 
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
//����
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
	printf("����10������");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("����һ��BST����");
	printf("\n\n");
	t=CreateBST(a,n);
	printf("BST:");
	PrintBST(t);
	printf("\n");
	printf("���������");
	InOrder(t);
}	
	
	
	
