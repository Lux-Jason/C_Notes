/*
=============================================
 Name: A2T2T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
/*#include <stdio.h>
int Is_prime(int n) 
{
	if (n <= 1) 
	{
		return 0;
	}
	for (int i = 2; i * i <= n; i++) 
	{
		if (n % i == 0) 
		{
			return 0;
		}
	}
	return 1;
}

int main() 
{
	for (int even_number = 4; even_number <= 100; even_number += 2) 
	{
		int found = 0;
		for (int prime1 = 2; prime1 <= even_number / 2; prime1++) 
		{
			int prime2 = even_number - prime1;

			if (Is_prime(prime1) && Is_prime(prime2)) 
			{
				found = 1;
				printf("%d = %d + %d\n", even_number, prime1, prime2);
				break;
			}
		}
		if (!found) 
		{
			printf("No prime sum for %d\n", even_number);
		}
	}
	return 0;
}
