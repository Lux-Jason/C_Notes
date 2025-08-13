/*
=============================================
 Name: L13T2T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int fileCombine(char* file1, char* file2) {
	FILE* destFile, * resFile;
	int ch;

	destFile = fopen(file1, "a");
	resFile = fopen(file2, "r");

	if (destFile == NULL || resFile == NULL) {
		return 0;
	}
	//fputc('\n\r', destFile);
	while ((ch = fgetc(resFile)) != EOF) {
		
		fputc(ch, destFile);
	}

	fclose(destFile);
	fclose(resFile);

	return 1;
}

int main()
{
	char fileName1[20], fileName2[20];
	int flag;
	strcpy(fileName1, "a.txt");
	strcpy(fileName2, "b.txt");
	flag = fileCombine(fileName2, fileName1);
	if (flag == 1)
		printf("Success\n");
	else
		printf("Failure\n");
	return 0;
}
