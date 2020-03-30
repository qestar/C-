#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int key; 
	char data;
}DataType;
//直接插入排序 
void InsertSort(DataType D[],int n)
{
	int i,j,count=0,k;
	DataType temp;
	for(i=1;i<n;i++)
	{
		temp=D[i];
		j=i-1;  
		while(j>=0&&temp.key<D[j].key)
		{
			D[j+1]=D[j]; 
			j--;
		}
		D[j+1]=temp; 
		count++;
	}
	printf("直接插入排序比较次数:%d",count);
	printf("\n");printf("排序后:");
	for(k=0;k<n;k++)
		printf("%d ",D[k].key);
}
//希尔排序 
void  ShellSort(DataType D[],int n)
{
	int i,j,d,k,count=0;
	DataType temp;
	d=n/2; 
	while(d>0)
	{
		for(i=d;i<n;i++)
		{
			j=i-d;
			while(j>=0&&D[j].key>D[j+d].key)
			{
				temp=D[j]; 
				D[j]=D[j+d];
				D[j+d]=temp;
				i=j-d;
			}
		}
		count++;
		d=d/2;
	}
	printf("希尔排序比较次数:%d",count);
	printf("\n");printf("排序后:");
	for(k=0;k<n;k++)
		printf("%d ",D[k].key);
}
//快速排序
void QuickSort(DataType D[],int s,int t)
{
	int i=s,j=t,k;
	DataType temp;
	if(s<t) 
	{
		temp=D[s]; 
		while(i!=j)
		{
			while(j>i&&D[j].key>temp.key)
			   j--; 
			D[i]=D[j];
			while(i<j&&D[i].key<temp.key)
			   i++;
			D[j]=D[i];
		}
		D[i]=temp;
		for(k=0;k<10;k++)
		{
			if(k==i)
			   printf("[%d]",D[k].key);
			else
			   printf("%4d",D[k].key);
		}
		printf("\n\n");
		QuickSort(D,s,i-1);     //对左区间递归排序 
		QuickSort(D,i+1,t);     //对右区间递归排序 
	}
}

void MaopaoSort(DataType D[],int n)
{
	int i,j,t,p,count=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
			if(D[j].key>D[j+1].key)
			{
				t=D[j].key;
				D[j].key=D[j+1].key;
				D[j+1].key=t;
			}
		count++;
	}
	printf("冒泡法比较次数:%d\n",count);
	printf("排序后:");
	for(p=0;p<n;p++)
		printf("%d ",D[p].key);
}
void menu()
{
	printf("***************************\n");
	printf("********请输入你的选择*****\n");
	printf("********1:直接插入排序*****\n");
	printf("********2:冒泡排序*********\n");
	printf("********3:希尔排序*********\n");
	printf("********3:快速排序*********\n");
	printf("********0:退出*************\n");
} 

int main()
{
	int i,j,k,n=300,t=9,m;
	int a[300];
	for(j=0;j<n;j++)
	{
		a[j]=rand()%600;
	}
	DataType D[300];
	printf("三百个数为:");
	for(i=0;i<n;i++)
	{
		D[i].key=a[i];
		printf("%d ",D[i].key);
	}
	printf("\n");
	do
	{	for(i=0;i<n;i++)
			D[i].key=a[i];
		printf("\n");menu();
		scanf("%d",&m);
		switch(m)
		{
		case 1:InsertSort(D,n);break;
		case 2:MaopaoSort(D,n);break;
		case 3:ShellSort(D,n);break;
		case 4:QuickSort(D,0,n-1);
		}
	}while(n!=0);
} 
