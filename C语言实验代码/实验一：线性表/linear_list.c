#include<stdio.h>
#include<stdlib.h> 
#define max_size 100

typedef struct Linear_List {
	int arr[max_size];
	int length;
} * sqlist;             

sqlist LA,LB,LC;       
int i;
int main()
{
	int * a,* b,* c,* LA_LAST,* LB_LAST;
	LA = (sqlist)malloc(sizeof(struct Linear_List));
	printf("�������A�ĳ��ȣ�");
	scanf("%d",&LA->length);
	printf("\n");
	printf("�����A��Ԫ�أ�") ; 
	for (i = 0;i<LA->length;i++){
	
		scanf("%d",&LA->arr[i]);
	} 
	printf("\n") ;
	a = LA->arr;
	LA_LAST = a + LA->length -1;
	
	LB = (sqlist)malloc(sizeof(struct Linear_List));
	printf("�������B�ĳ��ȣ�");
	scanf("%d",&LB->length);
	printf("\n");
	printf("�����B��Ԫ�أ�") ;
	for (i = 0;i<LB->length;i++){ 
		scanf("%d",&LB->arr[i]);
	} 
	printf("\n") ;
	b = LB->arr;
	LB_LAST = b + LB->length -1;
	
	LC = (sqlist)malloc(sizeof(struct Linear_List)); 
	LC->length= LA->length+LB->length;
	c = LC->arr;
	
	while(a<=LA_LAST&&b<=LB_LAST)
	{
		if (*a <= *b)
		{
			*c = *a;
			c++; a++;
		}

		else
		{
			*c=*b;
			c++; b++;
		}
	}

	while (a<=LA_LAST)
	{	
		*c = *a;
		c++; a++;
	}

	while (b<=LB_LAST)
	{
		*c=*b;
		c++;b++;
	}


	printf("�ϲ�������Ϊ:");
	for(i=0;i<LC->length;i++)
	{
		printf("%d ",LC->arr[i]);
	}
}
