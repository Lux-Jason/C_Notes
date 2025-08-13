/*
=============================================
 Name: L13T3T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>

int main() {
	FILE* file = fopen("sample.bin", "rb");

	if (file != NULL) {
		float num1, num2;
		fseek(file, 4 * sizeof(float), SEEK_SET);
		fread(&num1, sizeof(float), 1, file);
		fseek(file, 2 * sizeof(float), SEEK_CUR);
		fread(&num2, sizeof(float), 1, file);

		printf("num1 is %.6f\nnum2 is %.6f\n", num1, num2);

		fclose(file);
	}

	return 0;
}
