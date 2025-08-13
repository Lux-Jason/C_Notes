/*
=============================================
 Name: L8T4T330026132.c
 Author:Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include"digit .h"
int main()
{
	char m=0;
	printf("Enter a character: ");
	scanf("%c",&m);
	_Bool n=isDiqitChar(m);
	if(n)
	{
		printf("%d\n",n);
	}
	else
	{
		printf("%d\n",n);
	}
	return 0;
}
