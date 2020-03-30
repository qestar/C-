#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

#define MAXQSIZE 6	
typedef int QElemType;
typedef struct {
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue *Q) {
	Q->base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q->base) exit(OVERFLOW);
	Q->front = Q->rear = 0;
	return OK;
}

Status EnQueue(SqQueue *Q,QElemType e) {
	if ((Q->rear + 1) % MAXQSIZE == Q->front)return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e) {
	if (Q->front == Q->rear)return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}

void Print(SqQueue *Q)
{
	if (Q->front == Q->rear) printf("队伍无人");
	while(Q->front != Q->rear)
	{
		printf("%d",Q->base[t]);
		Q->rear--;
	}
}

int main() {
	SqQueue Q;
	QElemType e;
	int i, j = 5, m;
	InitQueue(&Q);
	printf("队伍人员:");
	for (i=1; i<7; i++) {
		EnQueue(&Q, i);
		printf("%d ", i);printf("\n");
	}
	printf("***************************\n");
	printf("********请输入你的选择*****\n");
	printf("********1:入队*************\n");
	printf("********2:取队头元素*******\n");
	printf("********3:出队*************\n");
	printf("********4:销毁队***********\n");
	printf("********0:退出*************\n");
	Print(&Q);

	printf("选择操作:");
	scanf("%d",&m);
	switch(m)
	{
	case 1:
		printf("输入排队人员序号:");scanf("%d",&e);
		EnQueue(&Q,e);
		Print(&Q);
	case 2:
		DeQueue(&Q,&e);
		Print(&Q);
	}
}