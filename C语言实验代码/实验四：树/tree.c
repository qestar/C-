#include<stdio.h>
#include<stdlib.h>

typedef struct BiNode
{
	char data;
	struct BiNode *lchild, *rchild;
}BiNode;

//����������
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
			printf("�ڴ����ʧ��");
		}
		t->data=ch;
		t->lchild=creat(t->lchild);
	    t->rchild=creat(t->rchild);
	}
	return t;
}

void PreOrder(BiNode *t)//����
{
	if(t)
	{
		Visit(t->data);
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}

void InOrder(BiNode *t)//����
{
	if(t)
	{
		InOrder(t->lchild);
		Visit(t->data);
		InOrder(t->rchild);
	}
}

void LasOrder(BiNode *t)//����
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
	printf("����"); PreOrder(t);printf("\n");
	printf("����"); InOrder(t);printf("\n");
	printf("����"); LasOrder(t);printf("\n");
}
