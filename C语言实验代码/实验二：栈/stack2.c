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
	if (Q->front == Q->rear) printf("��������");
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
	printf("������Ա:");
	for (i=1; i<7; i++) {
		EnQueue(&Q, i);
		printf("%d ", i);printf("\n");
	}
	printf("***************************\n");
	printf("********���������ѡ��*****\n");
	printf("********1:���*************\n");
	printf("********2:ȡ��ͷԪ��*******\n");
	printf("********3:����*************\n");
	printf("********4:���ٶ�***********\n");
	printf("********0:�˳�*************\n");
	Print(&Q);

	printf("ѡ�����:");
	scanf("%d",&m);
	switch(m)
	{
	case 1:
		printf("�����Ŷ���Ա���:");scanf("%d",&e);
		EnQueue(&Q,e);
		Print(&Q);
	case 2:
		DeQueue(&Q,&e);
		Print(&Q);
	}
}