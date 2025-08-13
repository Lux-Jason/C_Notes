#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22621.0/ucrt/stdio.h"
//函数递归
//int main()
//{
//	printf("haha\n");
//	main();
//	return 0;
//}//最简单的递归--递归常见错误：栈溢出
//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d\n", n % 10);
//}
//int main()
//{
//	unsigned int num;
//	scanf("%d", &num);
//	//递归--函数自己调用自己
//	print(num);
//	//print(1234)
//	//print(123) 4
//	//print(12) 3 4
//	//print(1) 2 3 4
//	return 0;
//}
// 
// 
//int my_strlen(char* str)//计算字符串的长度
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("lengh=%d\n", len);
//	return 0;
//}//以函数形式实现strlen函数的功能
//
//编写函数，不使用临时变量，求字符串长度:
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}//把大事化小
//int main()
//{
//	char arr[] = "uic";
//	int len = my_strlen(arr);
//	printf("length=%d\n", len);
//	return 0;
//}//递归方法
//
//
//
//递归与迭代
//求n的阶乘（不考虑溢出）：
// 使用递归：
//int factorial(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * factorial(n - 1);
//}
//int main()
//{
//	int n, fac;
//	scanf("%d", &n);
//	fac = factorial(n);
//	printf("fac=%d", fac);
//	return 0;
//}
//使用迭代：
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int ret = 1;
//	for ( i =1; i <=n; i++)
//	{
//		ret *= i;
//	}
//	printf("%d\n", ret);
//	return 0;
//}
//求解斐波那契数列：
//递归法：
//int count = 0;
//int fib(int n)
//{
//	if (n==3)
//	{
//		count++;//计算第3个斐波那契数被计算的次数
//	}
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fib(n);
//	printf("%d\n", ret);
//	printf("count=%d\n");
//	return 0;
//
//}
//迭代法：
//int fib(int n)
//{
//	int a, b, c;
//	a = 1, b = 1,c = 1;
//	while (n>2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret;
//	ret = fib(n);
//	printf("%d\n", ret);
//	return 0;
//}
//
////栈溢出特例：
//void test(int n)
//{
//	if (n < 10000)
//	{
//		test(n + 1);
//	}
//}
//int main()
//{
//	test(1);
//	return 0;
//}
//
//
//汉诺塔问题(递归法）：


//void move(char start, char aim)
//{
//    printf("%c -> %c\n", start, aim);
//}
//void hanoi(int n, char a, char b, char c)  //a:原位置,b:辅助,c:目标位置
//{
//    if (n < 1)
//    {
//        printf("n<0,data error!");   //输入的盘子序号<1,报错
//    }
//    else if 
//        (n == 1) move(a, c);            //当盘子为第一个最小的盘子时,直接进行移动,此次递归结束
//    else
//    {
//        hanoi(n - 1, a, c, b);
//        move(a, c);
//        hanoi(n - 1, b, a, c);
//    }
//}
//int main()
//{
//    int n;
//    printf("Print the num of disk: ");
//    scanf("%d", &n);
//    hanoi(n, 'A', 'B', 'C');
//    return 0;
//}
// 
// 
// 
void hanoi_move(int n, char A, char B, char C)
{
	if (n == 0)
	{
		return;
	}
	else if (n == 1)
	{
		printf("%c->%c\n", A, C);
	}
	else
	{
		hanoi_move(n - 1, A, C, B);
		printf("%c->%c\n", A, C);
		hanoi_move(n - 1, B, A, C);

	}
}
int main()
{
	int n = 0;
	printf("Print the num of disk:> ");
	scanf("%d", &n);
	hanoi_move(n, 'A', 'B', 'C');
	return 0;
}
//
//
//青蛙跳台阶问题：
//int dance_step(int n)
//{
//	if (n == 1)
//	{
//		return 1;//当只有一层台阶时直接返回1
//	}
//	if (n == 2)
//	{
//		return 2;//当只有2层台阶时直接返回2
//	}
//	if (n > 2)
//	{
//		return dance_step(n - 1) + dance_step(n - 2);
//	}//当n>2时，利用递归进行返回
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int num = dance_step(n);
//	printf("%d\n", num);
//	return 0;
//}