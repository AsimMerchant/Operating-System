#include<stdio.h>
#include "all_fun.h"

int main()
{
	int x=10, y=5, a, s, m, d; 
	a= addition(x,y);
	printf("add:%d\n", a);
	s= subtraction(x,y);
	printf("sub:%d\n",s);
	m= multiplication(x,y);
	printf("mul:%d\n", m);
	d= division(x,y);
	printf("div:%d\n", d);
}
