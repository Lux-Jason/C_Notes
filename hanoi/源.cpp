#include<iostream>
void hanoi(int n, char pos1, char pos2, char pos3)
{
	if (n==1)
	{
		printf("%c-->%c\n", pos1, pos3);
	}
	else
	{
		hanoi(n - 1, pos1, pos3, pos2);
		printf("%c-->%c\n", pos1, pos3);
		hanoi(n - 1, pos2, pos1, pos3);
	}
}
int main()
{
	int n = 0;
	printf("ÇëÊäÈëººÅµËş²ãÊı:>");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}

//void move(char x, char y)
//{
//	printf("%c-->%c\n", x, y);
//}
//void generate(int n, char a, char b,char c)
//{
//	if (n==0)
//	{
//		return;
//	}
//	generate(n - 1, a, b, c);
//	move(a, c);
//	generate(n - 1, b, a, c);
//}
//int main()
//{
//	int n = 0;
//	printf("ÊäÈëººÅµËş²ãÊı:>");
//	scanf("%d", &n);
//	generate(n, 'A', 'B', 'C');
//	return 0;
//}