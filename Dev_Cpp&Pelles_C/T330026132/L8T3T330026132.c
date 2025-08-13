/*
=============================================
 Name: L8T3T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include<stdio.h>
float exchange(float a[], int n);
int main()
{
	float data[4] = { 2.5,1,1.2,5.2 };
	int i;
	float max = exchange(data, 4);
	printf("The biggest element in the array is %.2f\n", max);
	for ( i = 0; i <= 3; i++)
	{
		printf("%.2f ", data[i]);
	}
	return 0;
}
float exchange(float a[], int n)
{
	float temp;
	temp = a[0];
	for (int i = 0; i < n; i++)
	{
		if (temp < a[i])
		{
			temp = a[i];
		}
	}
	/*a[0] = a[n - 1];
	a[n - 1] = temp;*/
	return temp;
}
