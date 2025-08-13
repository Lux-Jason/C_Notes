/*
=============================================
 Name: A3T4T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include<stdio.h>
int ZeroInBinary(int n[])
{
	int count = 0;
	for (int i = 0; i<32 ; i++)
	{
		if (n[i]==0)
		{
			count++;
		}
		if(n[i]==2)
		{
			break;
		}
	}
	return count;
}
int main()
{
	int a[32];
	int number = 0;
	int length = 0;
	printf("Input: ");
	scanf("%d", &number);
	while (number/2)
	{
		a[length++] = number % 2;
		number /= 2;
	}
	a[length++] = number % 2;
	a[length++] = 2;
	int total = ZeroInBinary(a);
	printf("Output: %d\n", total);
	return 0;
}
