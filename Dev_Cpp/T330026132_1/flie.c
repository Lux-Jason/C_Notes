#include<stdio.h>
void My_File()
{
	FILE* fp;
	char c;
	fp = fopen("infile.txt", "r");
	if (fp == NULL)
	{
		printf("The file does not exist.\n");
		return;
	}
	while ((c = fgetc(fp) != EOF))
	{
		printf("%c", c);
	}
	fclose(fp);
}
int main()
{
	My_File();
	return 0;
}
