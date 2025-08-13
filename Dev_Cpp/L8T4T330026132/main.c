#include<digit.h>
int main()
{
	char a=0;
	printf("Enter a character: ");
	scanf("%c",&a);
	int n=isDigitChar(a);
	printf("%d",n);
	return 0;

}
