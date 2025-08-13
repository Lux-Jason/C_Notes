/*
=============================================
 Name: L9T4T330026132.c
 Author:Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include<stdio.h>
int sumAll(int n);
int main()
{
	int maxNum = 0;
	printf("Input maxNum: ");
	scanf("%d", &maxNum);
	if (maxNum > 0)
	{
		int sum = sumAll(maxNum);
		printf("Sum is %d\n", sum);
	}
	else
	{
		printf("Warning! Input of maxNum is invalid!\n");
	}

	return 0;
}
int sumAll(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	else
	{
		return n + sumAll(n - 1);
	}

}
