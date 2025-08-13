/*
=============================================
 Name: L12T4T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include<stdio.h>
int calSumAverage(int, int);
int main()
{
	int m = 0, n = 0;
	int average, sum;
	scanf("%d %d", &m, &n);
	sum = calSumAverage(m, n);
	printf("The sum is %d", sum);
	return 0;
}

int calSumAverage(int no1, int no2)
{
	int sum = 0;
	for (int i = no1; i <= no2; ++i) {
		sum += i;
	}
	return sum;
}
