#include<stdio.h>
#define MAX 80
typedef struct
{
	int key;
}Binary;

int BinSearch(Binary D[],int k)
{
	int low=0,high=MAX-1,mid,count=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		printf("%d:在[%d，%d]中比较元素D[%d]：%d\n",++count,low,high,mid,D[mid].key);
		if(D[mid].key==k)
		   return mid;
		if(D[mid].key>k)
		   high=mid-1;
		else 
		   low=mid+1;
	}
	printf("查询失败!");
	return -1;
}

void main()
{
	Binary D[MAX];
	int i,j,k,a[MAX];
	a[0]= rand() % 10;
	for(i=1;i<MAX;i++)
	{
		a[i]=a[i-1]+rand() % 10 + 1;
	}
	for(j=0;j<MAX;j++)
	{
		D[j].key=a[j];
		printf("%d ",D[j].key);
	}
	printf("\n");
	printf("输入查询元素:");
	scanf("%d",&k);
	BinSearch(D,k);
}