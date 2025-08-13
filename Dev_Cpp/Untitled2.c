#include<stdio.h>
int My_Fac(int n, int m);
int main()
{
	int n = 0;
	int m = 0;
	printf("Please input n and m: ");
	scanf("%d%d", &n, &m);
	if (n>1 && m>1)
	{
		int s = My_Fac(n, m);
		printf("There are %d %d(s) in %d.\n", s, m, n);
	}
	else if(m > 1 && n < 2)
	{
		printf("Warning! value of n is invalid!\n");
	}
	else if(m < 2 && n >1)
	{
		printf("Warning! value of m is invalid!\n");
	}
	else
	{
		printf("Warning! value of m and n are invalid!\n");
	}

	return 0;
}

int My_Fac(int n, int m) 
{
	if (n<=1||m<=1||n%m!=0) 
	{
		return 0;
	}
	else 
	{
		return 1 + My_Fac(n / m, m);
	}
}
