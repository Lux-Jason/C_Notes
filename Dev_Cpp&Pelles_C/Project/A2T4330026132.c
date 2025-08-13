/*
=============================================
 Name: A2T4T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
/*#include <stdio.h>
int main() 
{
	_Bool n = 1;
	int t;
	int Count1 = 0; 
	int Count2 = 0;
	int score = 0;
	printf("How many scores do you have? ");
	scanf("%d", &t);

	for (int i = 0; i < t; i++) 
	{
		scanf("%d", &score); 

		if (score < 0 || score > 100) 
		{
			printf("Warning: Score out of range [0, 100]\n");
			n = 0;
			break;
		}
		else
		{
			if (score >= 90 && score <= 100)
			{
				Count1++;
			}
			else if (score < 60) 
			{
				Count2++;
			}
		}
	}
	if (n)
	{
		float percentage_90_to_100 = (float)Count1 * 100 / t;
		float percentage_under_60 = (float)Count2 * 100 / t;

		printf("The percentage of scores which are between 90 and 100 is %.2f%%\n", percentage_90_to_100);
		printf("The percentage of scores which are under 60 is %.2f%%\n", percentage_under_60);
	}
	return 0;
}
