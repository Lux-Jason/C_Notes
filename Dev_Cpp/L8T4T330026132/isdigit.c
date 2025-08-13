#include<stdio.h>
#include<stdbool.h>
_Bool isDigitChar(char c)
{
	if(48<=c&&c<=57)
	{
		return true;
	}
	else
	{
		return false;
	}
}
