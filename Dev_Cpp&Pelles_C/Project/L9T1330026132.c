/*
=============================================
 Name: L9T1T330026132.c
 Author:Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include<stdio.h>
int My_Cal(int n);

int main()
{
	int n = 0;
	printf("Input a positive integer (>=1): ");
	scanf("%d", &n);
	if (1 > n)
	{
		printf("Warning! A positive integer no smaller than 1 should be input.\n");
	}
	else
	{
		int sum = My_Cal(n);
		printf("Sum is %d when n is %d.\n", sum, n);
	}
	return 0;
}

int My_Cal(int n)
{
	int m = 0;
	if (1 < n)
	{
		m = n * n;
		return m + My_Cal(n - 1);
	}
}
