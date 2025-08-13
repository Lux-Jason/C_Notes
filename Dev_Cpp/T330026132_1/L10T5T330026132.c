/*
=============================================
 Name: L10T5T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */

#include <stdio.h>
#include <string.h>
int main() 
{
	char word[20];
	int count = 0;

	printf("Please input some words: ");
	while (scanf("%s", word) == 1 && strcmp(word, "End") != 0) 
	{
		count++;
	}

	printf("There are totally %d words.\n", count);

	return 0;
}
