/*
=============================================
 Name: L10T4T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>
int stringLength(char s[]) 
{
	int length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return length;
}

int main() {
	char str[50];

	printf("Input a string: ");
	scanf("%s", str);

	int length = stringLength(str);

	printf("The length of the string is %d.\n", length);

	return 0;
}
