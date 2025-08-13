/*
=============================================
 Name: A4T3T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>

int merge(const char* file1, const char* file2, const char* outputFile);

int main() 
{
	if (!merge("1001.txt", "1002.txt", "class.txt"))
		printf("Failed to merge\n");
	else
		printf("Merge successfully\n");
	return 0;
}

int merge(const char* file1, const char* file2, const char* outputFile)
{
	FILE* fp1 = fopen(file1, "r");
	FILE* fp2 = fopen(file2, "r");
	FILE* outp = fopen(outputFile, "w");

	if (fp1 == NULL || fp2 == NULL || outp == NULL) 
	{
		perror("Error opening files");
		return 0;
	}
	char line[100];
	char str1[10], str2[10], str3[10];
	while (fgets(line, sizeof(line), fp1)) 
	{
		sscanf(line, "%s %s %s", str1, str2, str3);
		fprintf(outp, "%s %s %s\n", str1, str2, str3);
	}
	while (fgets(line, sizeof(line), fp2)) 
	{
		sscanf(line, "%s %s %s", str1, str2, str3);
		fprintf(outp, "%s %s %s\n", str1, str2, str3);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(outp);

	return 1;
}
