/*
=============================================
 Name: L12T1T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include<stdio.h>
int* exchange(int* x, int* y);
int main()
{
	int a = 10, b = 20;
	printf("before exchange:a=%d,b=%d\n", a, b);
	exchange(&a, &b);
	printf("after exchange:a=%d,b=%d\n", a, b);
	return 0;
}
int* exchange(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	return x, y;
}
