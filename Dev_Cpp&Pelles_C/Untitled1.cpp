#include<stdio.h>
int main()
{
	int i = 10, j = 5;
	float x = 5.0, y;
	//y = x / i;//0.500000 
	//y = j / i;//0.000000
	y = (float)j / i;
	printf("%f\n", y);//0.500000
	return 0;
}

