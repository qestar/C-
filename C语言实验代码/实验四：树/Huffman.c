#include<string.h>
#include<stdio.h>
#define N 50
#define M 2*N-1
typedef struct 
{
	int weight;
	int parent,lchild,rchild;
}HTnode;
typedef struct
{
	char cd[N];
	int start;
}HCode;
void CreateHT(HTnode ht[],int n)
{
	int  i,k,lnode,rnode;
	int min1,min2;
	for(i=0;i<2*n-1;i++)
	{
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	}
	for(i=n;i<2*n-1;i++)
	{
		min1=min2=32767;
		lnode=rnode=-1;
		for(k=0;k<=i-1;k++)
		{
			if(ht[k].parent==-1)
			{
				if(ht[k].weight<min1)
				{
					min2=min1;
					rnode=lnode;
					min1=ht[k].weight;
					lnode=k;
				}
				else if(ht[k].weight<min2)
				{
					min2=ht[k].weight;
					rnode=k;
				}
			}
		}
		ht[lnode].parent=i;
		ht[rnode].parent=i;
		ht[i].weight=ht[lnode].weight+ht[rnode].weight;
		ht[i].lchild=lnode;
		ht[i].rchild=rnode;
	}
}
void CreateHCode(HTnode ht[],HCode hcd[],int n)
{
	int i,f,c;
	HCode hc;
	for(i=0;i<n;i++)
	{
		hc.start=n;
		c=i;
		f=ht[i].parent;
		while(f!=-1)
		{
			if(ht[f].lchild==c)
				hc.cd[hc.start--]='0';
			else
				hc.cd[hc.start--]='1';
			c=f;
			f=ht[f].parent;
		}
		hc.start++;
		hcd[i]=hc;
	}
}
void DispHCode(HTnode ht[],HCode hcd[],int n)
{
	int i,k;
	int sum=0,m=0,j;
	printf("Êä³ö¹þ·òÂü±àÂë£º\n");
	for(i=0;i<n;i++)
	{
		j=0;
		for(k=hcd[i].start;k<=n;k++)
		{
			printf("%c",hcd[i].cd[k]);
			j++;
		}
		printf("\n");
	}
}
int main()
{
	int n=8,i;
	int fnum[]={2, 15, 30, 8, 10, 5, 12, 18};
	HTnode ht[M];
	HCode hcd[N];
	for(i=0;i<n;i++)
	{
		ht[i].weight=fnum[i];
	}
	CreateHT(ht,n);
	CreateHCode(ht,hcd,n);
	DispHCode(ht,hcd,n);
}