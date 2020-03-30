#include <stdio.h>
#include <stdlib.H>

typedef struct Node
{
	int data;
	struct Node *next;
}LinkList;

LinkList *InitList(LinkList *L)
{
	LinkList *head=NULL;
	head=(LinkList *)malloc(sizeof(LinkList));
	if(!head)
	{
		return 0;
	}
	head->next=NULL;
	L=head;
	return L;
}

LinkList *CreateList(LinkList *L, int n)
{
	int i;
    LinkList *p = NULL,*tail=NULL;
	p=L;
	printf("请输入元素:");
	for(i=n;i>0;i--)
	{
		tail=(LinkList *)malloc(sizeof(LinkList));
		scanf("%d",&tail->data);
		tail->next=NULL;
		p->next=tail;
		p=p->next;
	}
	return L;
}

int LenList(LinkList *L)
{
	LinkList *p=NULL;
	int count=0;
	p=L;
	while(p->next)
	{
		count++;
		p=p->next;
	}
	return count;
}

void GetElem(LinkList *L, int i)
{
	int count=1;
	LinkList *p=NULL;
	p=L->next;
	while((p!=NULL)&&(p->data!=i))
    {
		p=p->next;
		count++;
	}
    printf("%d'在第'%d'个位置'\n",i,count);
}

LinkList *InsertList(LinkList *L, int m)
{
	LinkList *s=NULL, *p=NULL;
	int j=1;
	p=L;
	while(j<m)
	{
		p=p->next;
		j++;
	}
	if(!p||j>m)
	{
		printf("输入不合法!");
	}
	s=(LinkList *)malloc(sizeof(LinkList));
	printf("请输入插入元素:");
	scanf("%d",&s->data);
	s->next=p->next;
	p->next=s;
	return L;
}

LinkList *DeletList(LinkList *L, int l)
{
	LinkList *p=NULL,*q=NULL;
	p=L;
    q=p->next;
    while((q!=NULL)&&(q->data!=l))
    {
        p=q;
        q=q->next;
    }
    if(q==NULL)
    {
        printf("error\n");
    }
    else{
        p->next=q->next;
        free(q);
    }
	return L;
}

void PrintList(LinkList *L)
{
	LinkList *p=NULL;
	p=L;
	p=p->next;
	while(p!=NULL)
	{	
		printf("%d->",p->data);
		p=p->next;
	}
	printf("\n");
}


void main()
{	int n,i,m,l,point;
	LinkList *L=NULL,*p=NULL;
	L=InitList(L);
	printf("输入元素个数:");
	scanf("%d",&n);
	L=CreateList(L,n);
	printf("==================\n");
	printf("=====1:打印链表===\n");
	printf("=====2:插入元素===\n");
	printf("=====3:删除元素===\n");
	printf("=====4:查询元素===\n");
	printf("=====0:退出操作===\n");
	printf("==================\n");
	do
	{
		printf("选择操作:");
		scanf("%d",&point);
		switch(point)
		{
			case 1:
				printf("单链表为:");
				PrintList(L);
				break;
			case 2:
				printf("插入元素位置:");
				scanf("%d",&m);
				InsertList(L,m);
				break;
			case 3:
				printf("删除元素:");
				scanf("%d",&l);
				DeletList(L,l);
				break;
			case 4:
				printf("查询元素:");
				scanf("%d",&i);
				GetElem(L,i);
				break;
			case 0:
				printf("结束操作!");
				break;
			default :
				printf("无效输入");
				break;

		}
	}while(point!=0);
	
}



	
	
	
	
	
	
	
	
	
	
	
	
	

	