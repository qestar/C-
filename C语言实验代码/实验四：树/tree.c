#include<stdio.h>
#include<stdlib.h>

typedef struct BiNode
{
	char data;
	struct BiNode *lchild, *rchild;
}BiNode;

//二叉树访问
void Visit(char e)
{
	printf("%c",e);
} 

BiNode *creat()
{
	BiNode *t;
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
	{
		t=NULL;
	}
	else
	{
		t=(BiNode*)malloc(sizeof(BiNode));
		if(!t)
		{
			printf("内存分配失败");
		}
		t->data=ch;
		t->lchild=creat(t->lchild);
	    t->rchild=creat(t->rchild);
	}
	return t;
}

void PreOrder(BiNode *t)//先序
{
	if(t)
	{
		Visit(t->data);
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}

void InOrder(BiNode *t)//中序
{
	if(t)
	{
		InOrder(t->lchild);
		Visit(t->data);
		InOrder(t->rchild);
	}
}

void LasOrder(BiNode *t)//后序
{
	if(t)
	{
		LasOrder(t->lchild);
		LasOrder(t->rchild);
		Visit(t->data);
	}
}

void main()
{
	BiNode *t=NULL;
	t=creat();
	printf("先序："); PreOrder(t);printf("\n");
	printf("中序："); InOrder(t);printf("\n");
	printf("后序："); LasOrder(t);printf("\n");
}
