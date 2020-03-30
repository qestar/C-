#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

typedef struct stack{
	int top;
	char checkstr[100];
}Stack,*SqStack;
//��ʼ��ջ 
SqStack InitStack(void)
{
	SqStack p;
	p=(SqStack)malloc(sizeof(Stack));
	if(p)
	  p->top=-1;
	return(p); 
}

//��ջ
int Push(SqStack p,char e)
{
	if(p->top>MAXSIZE)
	  return 0;
	else
	{
		p->top++;
		p->checkstr[p->top]=e;
	}
	return 1;
 } 
//��ջ
int Pop(SqStack p,char *e)
{
	if(p->top==-1)
	{ 
	return 0;
	}
	else
	{
		*e=p->checkstr[p->top];
		p->top--;
	}
	return (*e);
} 


//����ƥ���㷨 
int judge(SqStack p,char str[])
{
	int i;
	int j;
	char c;
	j=strlen(str);
	for(i=0;i<j;i++)
	{
		char bracket=str[i];
		if(bracket=="("||bracket=="["||bracket=="{")
		{
			Push(p,bracket);
		}
		else if(bracket==")")
		{
			if(Pop(p,&c)!="(")
			{printf("���Ϸ�!\n");
			return 0;}
		}
		else if(bracket=="]")
		{
			if(Pop(p,&c)!="[")
			{printf("���Ϸ�!\n");
			return 0;}
		}
		else
		{
			if(Pop(p,&c)!="{")
			{printf("���Ϸ�!\n");
			return 0;}
		}
	}
}

//������ 
int main()
{
	char str[100];
	SqStack p;
	p=InitStack();
	printf("�������ַ�����");
	scanf("%s",str);
	judge(p,str);
}


