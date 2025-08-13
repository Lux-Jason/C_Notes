#include<stdio.h>
#include<string.h>
#include<Windows.h>
//函数(库函数，自定义函数）
//
//
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}//自定义函数
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//	//库函数
//	return 0;
//}
//#include<string.h>
//int main()
//{
//	char arr1[] = "bit";
//	char arr2[] = "###########";
//	strcpy(arr2, arr1);//string.h
//	printf("%s\n", arr2);
//	return 0;
//}
// 
// 推箱子：
//#include <cstdio>
//#include <windows.h>
//#include <conio.h>
//
//char a[20][20] = { "##########",
//				"##     ###",
//				"##O###   #",
//				"# S  O O #",
//				"# **# O ##",
//				"##**#   ##",
//				"##########" };
//
//void Hide()
//{
//	HANDLE              hOut;
//	CONSOLE_CURSOR_INFO curInfo;
//
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	curInfo.dwSize = 1;
//	curInfo.bVisible = FALSE;
//	SetConsoleCursorInfo(hOut, &curInfo);
//}
//
//void Welcome()
//{
//	printf("\n\n            推箱子");
//	printf("\n\n     请按任意键开始");
//	_getch();
//	system("cls");
//}
//
//void Set()
//{
//	HANDLE hOut;
//	COORD pos = { 0,0 };
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(hOut, pos);
//}
//
//int main()
//{
//	Hide();
//	Welcome();
//	int x = 3, y = 2;
//	int cnt = 0;
//	for (int i = 0; i <= 6; i++)
//		puts(a[i]);
//	while (1)
//	{
//		char ch;
//		ch = _getch();
//		if (ch == 's')
//		{
//			if (a[x + 1][y] == ' ')
//			{
//				a[x][y] = ' ';
//				x++;
//				a[x][y] = 's';
//			}
//			else if (a[x + 1][y] == 'O')
//			{
//				if (a[x + 2][y] == ' ')
//				{
//					a[x][y] = ' ';
//					x++;
//					a[x][y] = 's';
//					a[x + 1][y] = 'O';
//					cnt++;
//				}
//				else if (a[x + 2][y] == '*')
//				{
//					a[x][y] = ' ';
//					x++;
//					a[x][y] = 's';
//					a[x + 1][y] = ' ';
//					cnt++;
//				}
//			}
//		}
//		else if (ch == 'w')
//		{
//			if (a[x - 1][y] == ' ')
//			{
//				a[x][y] = ' ';
//				x--;
//				a[x][y] = 's';
//			}
//			else if (a[x - 1][y] == 'O')
//			{
//				if (a[x - 2][y] == ' ')
//				{
//					a[x][y] = ' ';
//					x--;
//					a[x][y] = 's';
//					a[x - 1][y] = 'O';
//					cnt++;
//				}
//				else if (a[x - 2][y] == '*')
//				{
//					a[x][y] = ' ';
//					x--;
//					a[x][y] = 's';
//					a[x - 1][y] = ' ';
//					cnt++;
//				}
//			}
//		}
//		else if (ch == 'a')
//		{
//			if (a[x][y - 1] == ' ')
//			{
//				a[x][y] = ' ';
//				y--;
//				a[x][y] = 's';
//			}
//			else if (a[x][y - 1] == 'O')
//			{
//				if (a[x][y - 2] == ' ')
//				{
//					a[x][y] = ' ';
//					y--;
//					a[x][y] = 's';
//					a[x][y - 1] = 'O';
//					cnt++;
//				}
//				else if (a[x][y - 2] == '*')
//				{
//					a[x][y] = ' ';
//					y--;
//					a[x][y] = 's';
//					a[x][y - 1] = ' ';
//					cnt++;
//				}
//			}
//		}
//		else if (ch == 'd')
//		{
//			if (a[x][y + 1] == ' ')
//			{
//				a[x][y] = ' ';
//				y++;
//				a[x][y] = 's';
//			}
//			else if (a[x][y + 1] == 'O')
//			{
//				if (a[x][y + 2] == ' ')
//				{
//					a[x][y] = ' ';
//					y++;
//					a[x][y] = 's';
//					a[x][y + 1] = 'O';
//					cnt++;
//				}
//				else if (a[x][y + 2] == '*')
//				{
//					a[x][y] = ' ';
//					y++;
//					a[x][y] = 's';
//					a[x][y + 1] = ' ';
//					cnt++;
//				}
//			}
//		}
//		Set();
//		for (int i = 0; i <= 6; i++)
//			puts(a[i]);
//		if (cnt == 4)
//			break;
//	}
//	printf("你赢了！");
//	Sleep(10000);
//	return 0;
//}
//memory--内存(字符都是以ASC存储）
//memset--内存设置
//
//int main()
//{
//	char arr[] = "hello world";
//	memset(arr, '*', 5);
//	printf("%s\n", arr);//***** world
//	return 0;
//}
//
//自定义函数（自己设计函数名，返回类型，参数）：
//ret_type(返回类型） fun_name（函数名）(paral（函数参数）, *)
//{
//	statment;（语句项）
//}
//类比：
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}//自定义函数
//写一个函数，找出三个数的最大值：
//int get_max(int x, int y, int z)
//{
//	int max = x;
//	if (y > max)
//	{
//		max = y;
//	}
//	else if (z > max)
//	{
//		max = z;
//	}
//	
//	return max;
//}
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	int max = get_max(a, b, c);
//	printf("max=%d\n", max);
//	return 0;
//}
//
//写一个函数，交换两个整型之间的内容：
//int main()
//{
//	int a = 0;
//	int b = 20;
//	int tmp = 0;
//	tmp = a;
//	a = b;
//	b = tmp;
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}//主函数写法
//void Swap1(int x, int y)
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//	return x, y;
//}//不可行
//void Swap2(int* px, int* py)
//{
//	int tmp = 0;
//	tmp = *px;
//	*px = *py;
//	*py = tmp;
//}//自定义函数写法
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("a=%d b=%d\n", a, b);
//	/*int* pa = &a;
//	int* pb = &b;*/
//	Swap2(&a, &b);
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}
//实参--实际参数（真实传给函数的参数），可以是变量，常量，比哦大师，函数等，无论种类，在调用时都必须有确定的值，以便将这些值传给形参。
//形参--形式参数（形式上的参数），只在函数内部有效，在函数调用的过程中才实例化，函数调用完成后销毁。
//
//
//写一个函数，判断一个数是不是素数：
//#include<math.h>
//int prime(int n)
//{
//	//2~n-1
//	int j = 0;
//	for (int j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//			return 0;
//	}
//	//if (j==n)
//	return 1;
//}//是素数返回1，不是素数返回0
//int main()
//{
//	int i = 0;
//	for ( i = 2; i <= 200; i++)
//	{
//		if (prime(i) == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}
//
//写一个函数，判断一个年份是闰年
//int is_leap_year(int y)
//{
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		//判断year是否为闰年
//		if (1 == is_leap_year(year))
//		{
//			printf("%d ", year);
//		}
//	}
//	return 0;
//}
//
//
//函数实现二分查找：
//int binary_search(int arr[], int k,int sz)//本质上arr[]是一个指针
//{
//	//算法的实现
//	int left = 0;
//	int right = sz - 1;
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;//中间元素的下标
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	//二分查找
//	//在一个有序数组中查找具体的某个数
//	//找到了返回下标，找不到返回-1
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	scanf("%d", &k);
//	int ret = binary_search(arr, k, sz);//传递过去的是arr首元素的地址
//	if (ret == -1)
//	{
//		printf("找不到指定的数字\n");
//	}
//	else
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//	return 0;
//}
//
//
//写一个函数，每调用一次，num值加1：
//void Add(int* p)
//{
//	(*p)++;
//}
//int main()
//{
//	int num = 0;
//	Add(&num);
//	printf("num=%d\n", num);//1
//	Add(&num);
//	printf("num=%d\n", num);//2
//	Add(&num);
//	printf("num=%d\n", num);//3
//	return 0;
//}
//函数的嵌套调用和访问：
//void new_line()
//{
//	printf("haha\n");
//}
//void three_line()
//{
//	int i = 0;
//	for ( i = 0; i < 3; i++)
//	{
//		new_line();
//	}
//}
//int main()
//{
//	three_line();
//	return 0;
//}
//
//
// 链式访问（把一个函数的返回值作为另一个函数的参数）：
//int main()
//{
//	int len = 0;
//	//第一种：
//	len = strlen("abc");
//	printf("%d\n", len);
//	//第二种：
//	printf("%d\n", strlen("abc"));
//	return 0;
//}
//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));//printf打印的为函数的返回值--printf函数的类型为整型
//	return 0;
//}
//#include "ADD.h"//在源文件中定义函数，在头文件中声明函数，可直接引用头文件以调用函数（分模块写法）
////先声明后使用
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int sum = 0;
//	sum = Add(a, b);
//	printf("%d\n", sum);
//	return 0;
//}
