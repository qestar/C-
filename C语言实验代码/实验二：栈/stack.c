#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

typedef struct stack{
	int top;
	char checkstr[100];
}Stack,*SqStack;
//初始化栈 
SqStack InitStack(void)
{
	SqStack p;
	p=(SqStack)malloc(sizeof(Stack));
	if(p)
	  p->top=-1;
	return(p); 
}

//入栈
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
//出栈
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


//括号匹配算法 
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
			{printf("不合法!\n");
			return 0;}
		}
		else if(bracket=="]")
		{
			if(Pop(p,&c)!="[")
			{printf("不合法!\n");
			return 0;}
		}
		else
		{
			if(Pop(p,&c)!="{")
			{printf("不合法!\n");
			return 0;}
		}
	}
}

//主函数 
int main()
{
	char str[100];
	SqStack p;
	p=InitStack();
	printf("请输入字符串：");
	scanf("%s",str);
	judge(p,str);
}


