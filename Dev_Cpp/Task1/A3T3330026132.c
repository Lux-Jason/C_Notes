/*
=============================================
 Name: A3T3T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include<stdio.h>
int Fib(int n)
{
	if (n==1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}
int main()
{
	int a = 20;
	int i = 0;
	printf("Output: %d\n", Fib(20));
	return 0;
}
