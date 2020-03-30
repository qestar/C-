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
	printf("������Ԫ��:");
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
    printf("%d'�ڵ�'%d'��λ��'\n",i,count);
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
		printf("���벻�Ϸ�!");
	}
	s=(LinkList *)malloc(sizeof(LinkList));
	printf("���������Ԫ��:");
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
	printf("����Ԫ�ظ���:");
	scanf("%d",&n);
	L=CreateList(L,n);
	printf("==================\n");
	printf("=====1:��ӡ����===\n");
	printf("=====2:����Ԫ��===\n");
	printf("=====3:ɾ��Ԫ��===\n");
	printf("=====4:��ѯԪ��===\n");
	printf("=====0:�˳�����===\n");
	printf("==================\n");
	do
	{
		printf("ѡ�����:");
		scanf("%d",&point);
		switch(point)
		{
			case 1:
				printf("������Ϊ:");
				PrintList(L);
				break;
			case 2:
				printf("����Ԫ��λ��:");
				scanf("%d",&m);
				InsertList(L,m);
				break;
			case 3:
				printf("ɾ��Ԫ��:");
				scanf("%d",&l);
				DeletList(L,l);
				break;
			case 4:
				printf("��ѯԪ��:");
				scanf("%d",&i);
				GetElem(L,i);
				break;
			case 0:
				printf("��������!");
				break;
			default :
				printf("��Ч����");
				break;

		}
	}while(point!=0);
	
}



	
	
	
	
	
	
	
	
	
	
	
	
	

	