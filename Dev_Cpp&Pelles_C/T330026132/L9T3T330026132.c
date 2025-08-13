/*
=============================================
 Name: L9T3T330026132.c
 Author:Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */

#include <stdio.h>
int PowerRec(int m, int n) 
{
	if (n == 0) 
	{
		return 1;
	}
	else 
	{
		return m * PowerRec(m, n - 1);
	}
}
int PowerLoop(int m, int n) 
{
	int r = 1;
	for (int i = 0; i < n; i++) 
	{
		r *= m;
	}
	return r;
}
int main() 
{
	int m, n;
	printf("Input m and n: ");
	scanf("%d %d", &m, &n);
	if (m <= 0) 
	{
		printf("Warning! Input of m is invalid!\n");
	}
	else if (n < 0) 
	{
		printf("Warning! Input of n is invalid!\n");
	}
	else 
	{
		int rec = PowerRec(m, n);
		int loop = PowerLoop(m, n);

		printf("Product is %d using recursion.\n", rec);
		printf("Product is %d using loop.\n", loop);
	}

	return 0;
}
