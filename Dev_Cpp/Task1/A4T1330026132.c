/*
=============================================
 Name: A4T1T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct Product 
{
	char manufacturer[50];
	char name[50];
	float price;
};

int compareProducts(const void* a, const void* b) 
{
	return ((struct Product*)b)->price - ((struct Product*)a)->price;
}

int main()
{
	struct Product products[50];
	int count = 0;
	printf("Input:\n");
	while (scanf("%s %s %f", products[count].manufacturer, products[count].name, &products[count].price) == 3) 
	{
		if (products[count].price == -1)
			break;
		count++;
	}

	qsort(products, count, sizeof(struct Product), compareProducts);

	printf("\nSorted list:\n");
	for (int i = 0; i < count; i++) 
	{
		printf("%s %s %.2f\n", products[i].manufacturer, products[i].name, products[i].price);
	}

	return 0;
}
