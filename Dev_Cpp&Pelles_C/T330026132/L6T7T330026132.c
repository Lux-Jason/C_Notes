/*
=============================================
 Name: L6T7T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
/*#include<stdio.h>
int judge(int n)
{
	int i = 0;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	if (n == 1)
	{
		return 0;
	}
	return 1;
}
int main()
{

	int j = 0;
	printf("Input a positive integer: ");
	scanf("%d", &j);
	if (0 < j)
	{
		if (judge(j) == 1)
		{
			printf("%d is a prime.\n", j);
		}
		else
		{
			printf("%d is not a prime.\n", j);
		}
	}
	else
	{
		printf("Warning! You should input a positive integer.\n");
	}
	return 0;
}
