#include<stdio.h>
#include"arith.h"

int main()
{
	int sum,dif,a,b;
	printf("enter a&b\n");
	scanf("%d%d",&a,&b);
	sum=add(a,b);
	printf("the sum is %d\n",sum);
	dif=sub(a,b);
	printf("the dif is %d\n",dif);
}
