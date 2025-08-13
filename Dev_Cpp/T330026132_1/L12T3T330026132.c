/*
=============================================
 Name: L12T3T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
# include <stdio.h>
void stringCombine(char* dest, char* src);
int main()
{
	char str1[100], str2[256];
	fgets(str1,100,stdin);
	fgets(str2,256,stdin);
	stringCombine(str1, str2);
	puts(str1);
	return 0;
}
void stringCombine(char* dest, char* src) {
	while (*(dest++) != '\n');
	dest--;
	while (*src != '\0')
	{
		*(dest++) = *(src++);
	}
	*dest = '\0';
}
