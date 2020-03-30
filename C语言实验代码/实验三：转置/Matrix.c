#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int i,j;
	int e;
}Triple;

typedef struct
{
	Triple data[97];
	int m,n,t;
}Tmatrix;




int get_t(int a[8][12])
{
	int i,j,count=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<12;j++)
			if(a[i][j]!=0)
				count++;
	}
	return count;
}

Tmatrix To_3yz(Tmatrix k,int a[8][12])
{
	int i,j,x,t=1;
	k.m=8;
	k.n=12;
	k.t=get_t(a);
	for(i=0;i<8;i++)
		for(j=0;j<12;j++)
		{
			if(a[i][j]!=0)
			{
				k.data[t].i=i;
				k.data[t].j=j;
				k.data[t].e=a[i][j];
				t++;
			}
		}
	printf("\n");
	for(x=1;x<=k.t;x++)
	{
		printf("%d:%d %d %d\n",x,k.data[x].i,k.data[x].j,k.data[x].e);
	}
	printf("%\n");
	return k;

}
Tmatrix trans(Tmatrix k, Tmatrix p)
{
	int q,col,h,i,j;
    p.m=k.n; p.n=k.m; p.t=k.t;
    if(p.t)
	{
        q=1;
        for(col=1;col<=k.n;++col)
			for(h=1;h<=k.t;++h)
				if(k.data[h].j==col)
				{
					p.data[q].i=k.data[h].j;
					p.data[q].j=k.data[h].i;
					p.data[q].e=k.data[h].e;
					++q;
				}
	}
	for(i=1;i<=k.t;i++)
	{
		printf("%d:%d %d %d\n",i,p.data[i].i,p.data[i].j,p.data[i].e);
	}
	return p;	
}
void print(Tmatrix p)
{
	int i,j,k,putZero=1;
	printf("\n");
	for(i=0;i<p.m;i++)
	{
 
		for(j=0;j<p.n;j++)
		{
			for(k=1;k<=p.t;k++)
			{
				if(i==p.data[k].i && j==p.data[k].j) 
				{	 
					printf("%d ",p.data[k].e);
					putZero=0;
				}
			}
 
			if(putZero) printf("0 ");
			putZero=1;
		}
 
		printf("\n");
	}


}



void main()
{
	int i,j,r,a[8][12];
	Tmatrix k,p;
	printf("Ëæ»ú¾ØÕó\n");
	for(i=0;i<8;i++)
		for(j=0;j<12;j++)
		{
			a[i][j]=0;
		}
	for(r=0;r<4;r++)
		a[rand()%8][rand()%12]=rand()%10;

	for(i=0;i<8;i++)
	{
		for(j=0;j<12;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
	k=To_3yz(k,a);
	printf("×ªÖÃºó\n");
	p=trans(k,p);
	print(p);
}






