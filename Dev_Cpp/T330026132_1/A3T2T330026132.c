/*
=============================================
 Name: A3T2T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include"isPrime.h"
int main()
{
	int i = 0;
	int j = 0;
	for (i = 5; i < 100; i++)
	{
		if (isPrime(i))
		{
			printf("%d is a prime\n",i);
		}
	}
	return 0;
}
