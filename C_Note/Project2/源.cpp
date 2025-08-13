#pragma once
//#include <stdio.h>
//#include<string.h>

//int main() 
//{
//    printf("Hello cpp!");
//    return 0;
//}
//int main()
//{
//	int g_val=2022;
//	printf("g_val=%d\n", g_val);
//	return 0;
//}
// 
//int Max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int main()
//{
//	int a = 7;
//	int b = 9;
//	int max = Max(a, b);
//	printf("max=%d\n", max);
//	return 0;
//}//函数定义比大小
//int main()
//{
//	int 
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}a = 7;
//	int b = 9;
//	int sum = Add(a, b);
//	printf("sum=%d\n", sum);
//	return 0;
//}//函数定义加法
//extern int Add(int, int);
//int main()
//{
//	int a = 8;
//	int b = 28;
//	int add = Add(a, b);
//	printf("add=%d\n", add);
//	return 0;
//}//外部函数调用--extern
// 
//extern int Add(int, int);
//int main()
//{
//	int a = 9;
//	int b = 8;
//	int add = Add(a, b);
//	printf("add=%d\n", add);
//	return 0;
//}//static用于全局变量可限制外部调用
//
//void test()
//{
//	static int a = 0;//static作用于局部变量，增长局部变量的生命周期
//	a++;
//	printf("a=%d\n", a);
//}
//int main()
//{
//	int i = 0;
//	while (i < 5)
//	{
//		test();
//	    i++;
//	}
//	return 0;
//}
//#define定义标识符常亮
//#define MAX 100
//#define定义宏-带参数：
//int MAX(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}//函数的实现
// 
//#define MAX(X,Y) (X>Y?X:Y)
////宏的定义
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int max = MAX(a, b);
//	printf("max=%d\n", max);
//	//函数的方式
//	max = MAX(a, b);
//	//max=(a>b?a:b)
//	printf("max=%d\n", max);
//	//宏的方式
//	return 0;
//}
//int main()
//{
//	int a = 10;//向内存申请4byte（字节）空间
//	int* p = &a;//&a:取地址
//	//有一种变量是专门用来存放地址的--这种变量叫指针变量
//	//printf("%p\n", &a);
//	printf("%p\n", &a);
//	printf("%p\n", p);
//	//*：解引用操作符
//	*p = 20;
//	printf("a=%d\n", a);
//	return 0;
//}
//将整型指针推广到字符型指针
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//	*pc = 'g';
//	printf("ch=%c\n", ch);
//	printf("%d\n", sizeof pc);
//	return 0;
//}//字符型指针
//int main()
//{
//	//int a = 0;//向内存申请4个字节的空间
//	//printf("%p\n", &a);
//	//int* p = &a;//p是一个指针变量
//	//printf("%p\n", p);
//	//*p = 20;//*--解引用操作符/间接访问操作符
//	//printf("%d\n", a);
//
//	//double b = 3.14;
//	//double* pb = &b;
//	//*pb = 7.62;
//	//printf("%p\n", pb);
//	//printf("%lf\n", b);
//	//printf("%d\n", sizeof(pb));//32--4;64--8
//
//	/*printf("%d\n", sizeof(char*));
//	printf("%d\n", sizeof(int*));
//	printf("%d\n", sizeof(double*));
//	printf("%d\n", sizeof(short*));*///无论什么类型的指针变量，其大小都一样（4或8byte）
//	return 0;
//}
// 
// 
// 
//结构体：
//struct Book
//{
//	char name[20];
//	short price;
//};
//int main()
//{
//	struct Book b1 = { "C语言设计",60 };
//	/*struct Book* pb = &b1;
//	if (pb == NULL)
//	{
//		printf("%s", (char*)strerror(errno));
//	}
//	else
//	{
//		printf("%s\n", pb->name);
//	}*/
//	
//	//利用指针pb打印书名和价格（赋值有问题）
//	/*printf("%s\n", pb->name);
//	printf("%d\n", pb->price);*///结构体指针->成员
// 
//	/*printf("%s\n", (*pb).name);
//	printf("%s\n", (*pb).price);*///结构体变量.成员
//
//	/*printf( "书名：%s\n",b1.name );
//	printf("价格：%d元\n",b1.price );
//	printf("太贵了\n");
//	b1.price = 20;
//	printf("那就这个价：%d元\n", b1.price);
//	printf("就这个价，你买不买吧\n我拿兔兔换\n好的");*/
//	return 0;
//}//疑似指针赋值为0引起越界访问
//0x00007FFD6B29AC87 (ucrtbased.dll)处(位于 Project2.exe 中)引发的异常: 0xC0000005: 读取位置 0x000000000000003C 时发生访问冲突。
// 结构体
//
//
//与上文对比，下面代码可正常运行
//struct Book
//	{
//		char name[20];
//		short price;
//	};
//int main()
//{
//	struct Book b1 = { "C语言设计",60 };
//	struct Book* pb = &b1;
//	/*printf("%s\n", (*pb).name);
//	printf("%d\n", (*pb).price);*/
//	printf("%s\n", pb->name);
//	printf("%d\n", pb->price);
//	/*b1.price = 20;
//	printf("价格：%d元\n", b1.price);
//	strcpy(b1.name, "C++语言设计");//库函数，应引用头文件<string.h>,vs中strcpy报unsafe，可改用strcpy_s或修改预处理器定义
//	printf("书名：%s\n", b1.name);*/
//	return 0;
//}
////相似字符串：
//bool is_similar(char a, char b)
//{
//	if (a == b)
//	{
//		return true;
//	}
//	else
//	{
//		if ((a == 'l' && b == '1') || (a == '1' && b == 'l') ||(a == '0' && b == 'o') || (a == 'o' && b == '0'))
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	char arr1[100010] = " ";
//	char arr2[100010] = " ";
//	for (int i = 0; i <= n; i++)
//	{
//		scanf("%c", &arr1[i]);
//	}
//	for (int i = 0; i <= n; i++)
//	{
//		scanf("%c", &arr2[i]);
//	}
//	bool j = true;
//	for (int i = 0; i < n; i++)
//	{
//		if (!is_similar(arr1[i], arr2[i]))
//		{
//			j = false;
//		}
//	}
//	if (j)
//	{
//		printf("Yes\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//	return 0;
// }

//#include<stdio.h>
//int main()
//{
//	char arr[100] = " ";
//	int i = 0;
//	int n = 0;
//	printf("Input a line of characters: ");
//	gets_s(arr);
//	int count = 0;
//	while(arr[i])
//	{
//		if (arr[i] == 'c')
//		{
//			count++;
//		}
//		i++;
//	}
//	printf("There are totally %d 'c'.\n", count);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int sum_even = 0;
//	int sum_odd = 0;
//	printf("Input an integer: ");
//	scanf("%d", &n);
//	if (n > 0)
//	{
//		for (int i = 0; i <= n; i += 2)
//		{
//			sum_odd += i;
//		}
//		for (int i = 1; i <= n; i += 2)
//		{
//			sum_even += i;
//		}
//		int diff = sum_even - sum_odd;
//		printf("sum_even is %d, sum_odd is %d, diff is %d.\n", sum_even, sum_odd, diff);
//	}
//	else
//	{
//		printf("Warning! You should input a positive integer.\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	for (int n = 1; n < 6; n++)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	for (int i = 5; i > 0; i--)
//	{
//		if (i % 2 != 0) 
//		{
//			for (int j = 2*i-1; j > 0; j--)
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//		else
//		{
//			for (int j = 2*i-1; j > 0; j--)
//			{
//				printf("=");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int My_trans(char m)
//{
//	if (m == 'A')
//	{
//		return 4;
//	}
//	else if (m == 'B')
//	{
//		return 3;
//	}
//	else if (m == 'C')
//	{
//		return 2;
//	}
//	else if (m == 'D')
//	{
//		return 1;
//	}
//	else if (m == 'F')
//	{
//		return 0;
//	}
//	else
//		return 5;
//}

/*int main()
{
	char m=' ';
	int n = 0;
	int ret = 0;
	for (int i = 0; i < 3; i++)
	{
		scanf("%c %d", &m, &n);
		ret = (int)m - 61 + n;
	}
	printf("%d", ret);
	return 0;
}*/
/*Assume that a student has 6 courses in one semester.
Write a program to input grades for all the courses and the units for each course (units can only be 1 or 3 in UIC)
and then calculate sGPA (semester GPA) for this semester.
Grades and points:
A: 4, B: 3, C: 2, D: 1, F: 0.
Assumption: Consider exactly 6 courses. GPA calculation method: ∑(points+units)∑units\frac{\sum \left ( points+units \right )}{\sum units}∑units∑(points+units)?*/

//#include<stdio.h>
//int main()
//{
//	char c = ' ';
//	scanf("%c", &c);
//	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
//	{
//		printf("It is an English letter!\n");
//	}
//	else if (c >= '0' && c <= '9')
//	{
//		printf("It is a digit!\n");
//	}
//	else
//		printf("It is other character!\n");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a > 0 && b > 0 && c > 0)
//	{
//		if (a * a + b * b == c * c || b * b + c * c == a * a || a * a + c * c == b * b)
//		{
//			printf("This is a right-angled triangle!\n");
//		}
//		else
//		{
//			printf("Not a right-angled triangle!\n");
//		}
//	}
//	else
//	{
//		printf("Please input positive numbers!\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int rev = 0;
//	scanf("%d", &m);
//	while (m!=0)
//	{
//		n = m % 10;
//		rev = (rev * 10) + n;
//		m /= 10;
//	}
//	printf("reversed number: %d\n", rev);
//	return 0;
//}

//#include<stdio.h>
//int change(char m)
//{
//	if (m >= 'a' && m <= 'z')
//	{
//		return m - 'a'+1;
//	}
//	else if (m >= 'A' && m <= 'Z')
//	{
//		return m - 'A'+1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char a = ' ';
//	char b = ' ';
//	printf("Input: ");
//	scanf("%c %c", &a, &b);
//	int x = change(a);
//	int y = change(b);
//	if (x != 0 && y != 0)
//	{
//		if (x < y && x != 0 && y != 0)
//		{
//			printf("Output: %c %c\n", a, b);
//		}
//		else if (x > y && x != 0 && y != 0)
//		{
//			printf("Output: %c %c\n", b, a);
//		}
//	}
//	else if (y == 0 && x != 0)
//	{
//		printf("Warning! '%c' is not an English letter.\n", b);
//	}
//	else
//	{
//		printf("Warning! '%c' is not an English letter.\n", a);
//	}
//	return 0;
//}

////别人写的大数加法运算程序（数组存储各个位数，利用竖式计算结果存在另一个数组中）：
//#include<stdio.h>
//#include<string.h>
//char a[100010];
//char b[100010];
//int c[100010];
//int d[100010];
//int e[100010];
//int check(char array[])
//{
//	int i = 0;
//	for (i = 0;; i++)
//		if (*(array + i) == NULL)
//			break;
//	return i;
//}
//int add(int  array1[], int array2[], int strlen_array1, int strlen_array2)
//{
//	int i , t = 0, j = 0;
//	for (i = 0; i < strlen_array1 || i < strlen_array2; i++)
//	{
//		if (i < strlen_array1) t += array1[i];
//		if (i < strlen_array2) t += array2[i];
//		e[i] = t % 10;
//		t /= 10;
//	}
//	if (t) e[i] = 1;
//	return i;
//}
//int main()
//{
//	gets_s(a,100010);
//	gets_s(b,100010);
//	int strlen_a = check(a);
//	int strlen_b = check(b);
//	int strlen_e = 0;
//	for (int i = strlen_a - 1; i > -1; i--)
//		c[strlen_a - i - 1] = a[i] - '0';
//	for (int i = strlen_b - 1; i > -1; i--)
//		d[strlen_b - i - 1] = b[i] - '0';
//	strlen_e = add(c, d, strlen_a, strlen_b);
//	int i = 0;
//	for (i = strlen_e;; i--)
//		if (e[i] != 0)
//			break;
//	for (; i >= 0; i--)
//		printf("%d", e[i]);
//	return 0;
//}
////乘法运算：
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#define M 10000
//
//int main(int argc, char** argv) {
//	char x[M] = { 0 }, y[M] = { 0 }, z[M] = { 0 };
//	char s1[M] = { 0 }, s2[M] = { 0 };
//
//	printf("请输入两个数字: \n");
//	scanf("%s %s", s1, s2);
//	int len_s1 = strlen(s1), len_s2 = strlen(s2);
//	int max = 0;
//
//	for (int i = 0; i < len_s1; i++) {
//		x[i] = s1[len_s1 - i - 1];
//	}
//	for (int j = 0; j < len_s2; j++) {
//		y[j] = s2[len_s2 - j - 1];
//	}
//	int add_number, flag, result;
//	for (int i = 0; i < len_s1; i++) {
//		int index = i;
//		for (int j = 0; j < len_s2; j++) {
//			result = (x[i] - 48) * (y[j] - 48);
//			if ((result + z[index]) < 10) {
//				z[index] += result;
//
//				if (max < index) {
//					max = index;
//				}
//			}
//			else {
//				add_number = (z[index] + result) / 10;
//				z[index] = (z[index] + result) % 10;
//
//				flag = 1;
//				while (1) {
//					if ((add_number + z[index + flag]) < 10) {
//						z[index + flag] += add_number;
//						if (max < index + flag) {
//							max = index + flag;
//						}
//						break;
//					}
//					else {
//						int sum = add_number + z[index + flag];
//						add_number = sum / 10;
//						z[index + flag] = sum % 10;
//						flag++;
//					}
//
//				}
//			}
//			index++;
//		}
//
//	}
//	printf("当前所得如下:");
//	for (int i = max; i >= 0; i--) {
//		printf("%c", z[i] + 48);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//int change(char m)
//{
//	if (m >= 'a' && m <= 'z')
//	{
//		return m - 'a' + 1;
//	}
//	else if (m >= 'A' && m <= 'Z')
//	{
//		return m - 'A' + 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char a = ' ';
//	char b = ' ';
//	printf("Input: ");
//	scanf("%c %c", &a, &b);
//	int x = change(a);
//	int y = change(b);
//	if (x != 0 && y != 0)
//	{
//		if (x <= y && x != 0 && y != 0)
//		{
//			printf("Output: %c %c\n", a, b);
//		}
//		else if (x > y && x != 0 && y != 0)
//		{
//			printf("Output: %c %c\n", b, a);
//		}
//	}
//	else if (y == 0 && x != 0)
//	{
//		printf("Warning! '%c' is not an English letter.\n", b);
//	}
//	else
//	{
//		printf("Warning! '%c' is not an English letter.\n", a);
//	}
//	return 0;
//}

//#include<stdio.h>
//float Grade(char m)
//{
//	if ('A' == m)
//	{
//		return 4;
//	}
//	else if ('B' == m)
//	{
//		return 3;
//	}
//	else if ('C' == m)
//	{
//		return 2;
//	}
//	else if ('D' == m)
//	{
//		return 1;
//	}
//	else if ('F' == m)
//	{
//		return 0;
//	}
//	else
//		return -1;
//}
//int main()
//{
//	char m1, m2, m3, m4, m5, m6;
//	int n1, n2, n3, n4, n5, n6;
//	printf("Please input grade and units for each course (6 courses): ");
//	scanf("%c %d %c %d %c %d %c %d %c %d %c %d", &m1, &n1, &m2, &n2, &m3, &n3, &m4, &n4, &m5, &n5, &m6, &n6);
//	float g1 = Grade(m1);
//	float g2 = Grade(m2);
//	float g3 = Grade(m3);
//	float g4 = Grade(m4);
//	float g5 = Grade(m5);
//	float g6 = Grade(m6);
//	if (((g1>=0&&g1<=4)&& (g2 >= 0 && g2 <= 4)&& (g3 >= 0 && g3 <= 4)&& (g4 >= 0 && g4 <= 4)&& (g5 >= 0 && g5 <= 4)&& (g6 >= 0 && g6 <= 4))&&(3==n1||1==n1)&& (3 == n2 || 1 == n2)&& (3 == n3 || 1 == n3)&& (3 == n4 || 1 == n4)&& (3 == n5 || 1 == n5)&& (3 == n6 || 1 == n6))
//	{
//		float p = ((g1 * n1) + (g2 * n2) + (g3 * n3) + (g4 * n4) + (g5 * n5) + (g6 * n6))/(n1+ n2 + n3 + n4 + n5 + n6);
//		printf("The GPA for this semester is: %.2f\n", p);
//	}
//	else
//	{
//		printf("Warning! Invalid grade.\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//const int total_courses = 6;
//
//int main()
//{
//	int total_units = 0;
//	int total_grade = 0;
//	int grade = 0;
//	for (int i = 1; i <= total_courses * 2; i++)
//	{
//
//		if (i == 1)
//		{
//			printf("Please input grade and units for each course (6 courses):");
//		}
//		int tmp = getchar() - '0';
//
//
//
//		if (i % 2 == 1)
//		{
//			if (tmp < 17 || tmp > 22 || tmp == 21)
//			{
//				printf("Warning! Invalid grade.");
//				break;
//			}
//			else
//			{
//				if (tmp >= 17 && tmp <= 20)
//					tmp = 21 - tmp;
//				else
//					tmp = 0;
//			}
//			grade = tmp;
//		}
//
//		if (i % 2 == 0)
//		{
//			if (tmp != 1 && tmp != 3)
//			{
//				printf("Warning! Invalid grade.");
//				break;
//			}
//			total_units = total_units + tmp * 1;
//			total_grade = total_grade + tmp * grade;
//
//		}
//		getchar();
//		if (i==total_courses*2)
//		{
//			double GPA = 0;
//			GPA = double(total_grade) / double(total_units);
//
//			printf("The GPA for this semester is : %.2f\n", GPA);
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//    char c1 = ' ', c2;
//    int grade, point, counter = 0, a = 0, sum_point = 0;
//    float GPA;
//    printf("Please input grade and units for each course (6 courses): ");
//    while (/*(int)c1 == 32 && */counter < 6) {
//        scanf("%c%d", &c2, &point);
//        getchar();
//        if (c2 == 'A') {
//            grade = 4;
//        }
//        else if (c2 == 'B') {
//            grade = 3;
//        }
//        else if (c2 == 'C') {
//            grade = 2;
//        }
//        else if (c2 == 'D') {
//            grade = 1;
//        }
//        else if (c2 == 'F') {
//            grade = 0;
//        }
//        a = a + grade * point;
//        sum_point = sum_point + point;
//        /*scanf("%c", &c1);*/
//        if ((point != 3 && point != 1) || (c2 != 'A' && c2 != 'B' && c2 != 'C' && c2 != 'D' && c2 != 'F'))
//            break;
//        counter++;
//    }
//    if (counter != 6)
//        printf("Warning! Invalid grade.\n");
//    else {
//        GPA = (float)a / sum_point;
//        printf("The GPA for this semeser is: %.2f\n", GPA);
//    }
//    return 0;
//}


//#include<stdio.h>
//int judge(int n)
//{
//	int i = 0;
//	for (i = 2; i < n; i++)
//	{
//		if (n % i == 0)
//			return 0;
//	}
//	if (n == 1)
//	{
//		return 0;
//	}
//	return 1;
//}
//int main()
//{
//
//	int j = 0;
//	printf("Input a positive integer: ");
//	scanf("%d", &j);
//	if (0 < j)
//	{
//		if (judge(j) == 1)
//		{
//			printf("%d is a prime.\n", j);
//		}
//		else
//		{
//			printf("%d is not a prime.\n", j);
//		}
//	}
//	else
//	{
//		printf("Warning! You should input a positive integer.\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int sum = 0;
//	printf("Input a positive integer: ");
//	scanf("%d", &n);
//	if (0 < n)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			if ((0 == i % 5) && (0 != i % 7))
//			{
//				sum += i;
//				if (5 < (n - i)&&0 != ((i+5)%7))
//				{
//					printf("%d + ", i);
//
//				}
//				else if (10<(n-i))
//				{
//					printf("%d + ", i);
//				}
//				else
//				{
//					printf("%d = %d\n", i, sum);
//				}
//			}
//		}
//
//	}
//	else
//	{
//		printf("Warning! You should input a positive integer.\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define SIZE 10
//typedef struct stack_info
//{
//	int    data[SIZE];
//	int    top;
//	int    bottom;
//	int    size=SIZE;
//	int    count;
//}stack_t;
//
//void push(stack_t* stack, int data)
//{
//	if (stack->count == stack->size)
//	{
//		printf("Unsuccessful push operation: Stack is full\n");
//		return ;
//	}
//	else
//	{
//		stack->data[stack->top] = data;
//		//	printf("%d ", stack->data[stack->top ]);
//		stack->top++;
//		stack->count++;
//	}
//	return ;
//}
//int pop(stack_t* stack)
//{
//	int data;
//	if (stack->count == 0)
//	{
//		printf("Unsuccessful pop operation: Stack is empty\n");
//		return -1;
//	}
//	else
//	{
//		data = stack->data[--stack->top];
//		stack->count--;
//		return data;
//	}
//}
//int main()
//{
//	stack_t stack;
//	int i = 0;
//	int n = 0;
//		//stack.data = malloc(10);
//	memset(&stack, 0, sizeof(stack));
//	printf("Please choose action(1: Push 2: Pop  0: Exit):");
//	scanf("%d", &n);
//	while (n)
//	{
//		if (1==n)
//		{
//			int m = 0;
//			printf("Enter an integer to push: ");
//			scanf("%d", &m);
//			push(&stack, m);
//			printf("Please choose action(1: Push 2: Pop  0: Exit):");
//			scanf("%d", &n);
//		}
//		else if (2 == n)
//		{
//			printf("%d\n", pop(&stack));
//			printf("Please choose action(1: Push 2: Pop  0: Exit):");
//			scanf("%d", &n);
//		}
//	}
//	printf("Exiting the program\n");
//	return 0;
//}


//#define SIZE 20
//int arr[SIZE], top = -1;
//void push(int x)
//{
//	if (top == SIZE - 1)
//	{
//		printf("Unsuccessful push operation: Stack is full\n");
//	}
//	else
//	{
//		arr[++top] = x;
//	}
//}
//void pop()
//{
//	top--;
//}
//int My_check(int arr)
//{
//	return 
//}
//int main()
//{
//
//	return 0;
//}

//#define SIZE 10

//void push(stack_t* stack, int data)
//{
//	if (stack->count == stack->size)
//	{
//		printf("Unsuccessful push operation: Stack is full\n");
//		return ;
//	}
//	else
//	{
//		stack->data[stack->top] = data;
//		//	printf("%d ", stack->data[stack->top ]);
//		stack->top++;
//		stack->count++;
//	}
//	return ;
//}
//int pop(stack_t* stack)
//{
//	int data;
//	if (stack->count == 0)
//	{
//		printf("Unsuccessful pop operation: Stack is empty\n");
//		return -1;
//	}
//	else
//	{
//		data = stack->data[--stack->top];
//		stack->count--;
//		return data;
//	}
//}

//#include<stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define SIZE 4
//typedef struct stack_info
//{
//	int    Data[SIZE];
//	int    top;
//	int    bottom;
//	int    size;
//	int    count;
//}stack_t;
//
//void push(stack_t* stack, int data)
//{
//	if (stack->count == SIZE)
//	{
//		printf("Unsuccessful push operation: Stack is full\n");
//		return ;
//	}
//	else
//	{
//		stack->Data[stack->top] = data;
//		//printf("%d ", stack->data[stack->top ]);
//		stack->top++;
//		stack->count++;
//	}
//	return ;
//}
//int pop(stack_t* stack)
//{
//	int data;
//	if (stack->count == 0)
//	{
//		printf("Unsuccessful pop operation: Stack is empty\n");
//		//return -1;
//	}
//	else
//	{
//		data = stack->Data[--(stack->top)];
//		stack->count--;
//		return data;
//	}
//}
//int main()
//{
//	stack_t stack;
//	int i = 0;
//	int n = 0;
//		//stack.data = malloc(10);
//	memset(&stack, 0, sizeof(stack));
//	printf("Please choose action(1: Push 2: Pop  0: Exit):");
//	scanf("%d", &n);
//	while (n)
//	{
//		if (1==n)
//		{
//			int m = 0;
//			printf("Enter an integer to push: ");
//			scanf("%d", &m);
//			push(&stack, m);
//			printf("\n----------------------\n");
//			printf("| Stack:");
//			for (int i = 0; i < stack.count; i++)
//			{
//				printf("%d ", stack.Data[i]);
//			}
//			printf("\n----------------------\n");
//			printf("Please choose action(1: Push 2: Pop  0: Exit):");
//			scanf("%d", &n);
//		}
//		else if (2 == n)
//		{
//			if (0!=stack.count)
//			{
//				printf("Popped: %d\n", pop(&stack));
//			}
//			else
//			{
//				printf("Unsuccessful pop operation: Stack is empty\n");
//			}
//			printf("\n----------------------\n");
//			printf("| Stack: ");
//			for (int i = 0; i < stack.count; i++)
//			{
//					printf("%d ", stack.Data[i]);
//			}
//			printf("\n----------------------\n");
//			printf("Please choose action(1: Push 2: Pop  0: Exit):");
//			scanf("%d", &n);
//		}
//	}
//	printf("Exiting the program\n");
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[50] = { 0 };
//	int n = 0;
//	int i = 0; 
//	int count = 0;
//	printf("Please input a sequence of integers (end with -1): ");
//	scanf("%d", &n);
//	while (-1 != n)
//	{
//		arr[i++] = n;
//		scanf("%d", &n);
//		count++;
//	}
//	if (0!=count)
//	{
//		int m = 0;
//		printf("Enter the number you want to search:\n");
//		scanf("%d", &m);
//		for (int j = 0; j <= count; j++)
//		{
//			if (arr[j] == m)
//			{
//				printf("The index of %d in the array is %d\n", m, j + 1);
//				break;
//			}
//			if (j == (sizeof(arr)/sizeof(arr[0])))
//			{
//				printf("%d Not found.", m);
//			}
//		}
//	}
//	else
//	{
//		printf("Array is empty.\n");
//	}
//
//	return 0;
//}

/*#include<stdio.h>
int main()
{
	for (int i = 5; i > 0; i--)
	{
		if (i % 2 != 0) 
		{
			for (int j = 2*i-1; j > 0; j--)
			{
				printf("*");
			}
			printf("\n");
		}
		else
		{
			for (int j = 2*i-1; j > 0; j--)
			{
				printf("=");
			}
			printf("\n");
		}
	}
	return 0;
}*/

//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
// 	for ( i = 1; i < 14; i++)
//	{
//		if (7>=i)
//		{
//   			if (i % 2 != 0)
//			{
//				for (int j = i; j > 0; j--)
//				{
//					printf("#");
//				}
//				printf("\n");
//			}
//			else
//			{
//				for (int j = i; j > 0; j--)
//				{
//					printf("+");
//				}
// 
//				printf("\n");
//			}
//		}
//		else
//		{
//			if (i % 2 != 0)
//			{
//				for (int j = 14; j > i; j--)
//				{
//					printf("#");
//				}
//				printf("\n");
//			}
//			else
//			{
//				for (int j = 14; j > i; j--)
//				{
//					printf("+");
//				}
//				printf("\n");
//			}
//		}
//				
//	}
//	return 0;
//}
//#include <stdio.h>
//
//int Is_prime(int n) 
//{
//	if (n <= 1) 
//	{
//		return 0;
//	}
//	for (int i = 2; i * i <= n; i++) 
//	{
//		if (n % i == 0) 
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main() 
//{
//	for (int even_number = 4; even_number <= 100; even_number += 2) 
//	{
//		int found = 0;
//		for (int prime1 = 2; prime1 <= even_number / 2; prime1++) 
//		{
//			int prime2 = even_number - prime1;
//			if (Is_prime(prime1) && Is_prime(prime2)) 
//			{
//				found = 1;
//				printf("%d = %d + %d\n", even_number, prime1, prime2);
//				break;
//			}
//		}
//		if (!found) 
//		{
//			printf("No prime sum for %d\n", even_number);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//int main() 
//{
//	int n;
//	printf("Input: ");
//	scanf("%d", &n);
//	printf("Output:\n");
//	while(n != 1)
//	{
//		printf("%d", n);
//		if (n % 2 == 0)
//		{
//			printf("/2=");
//			n /= 2;
//		}
//		else 
//      {
//			printf("*3+1=");
//			n = n * 3 + 1;
//		}
//		printf("%d\n", n);
//	}
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//const int total_courses = 6;
//
//int main()
//{
//	int total_units = 0;
//	int total_grade = 0;
//	int grade = 0;
//	for (int i = 1; i <= total_courses * 2; i++)
//	{
//
//		if (i == 1)
//			printf("Please input grade and units for each course (6 courses):");
//		int tmp = getchar() - '0';
//
//
//
//		if (i % 2 == 1)
//		{
//			if (tmp < 17 || tmp > 22 || tmp == 21)
//			{
//				printf("Warning! Invalid grade.");
//				break;
//			}
//			else
//			{
//				if (tmp >= 17 && tmp <= 20)
//					tmp = 21 - tmp;
//				else
//					tmp = 0;
//			}
//			grade = tmp;
//		}
//
//		if (i % 2 == 0)
//		{
//			if (tmp != 1 && tmp != 3)
//			{
//				printf("Warning! Invalid grade.");
//				break;
//			}
//			total_units = total_units + tmp * 1;
//			total_grade = total_grade + tmp * grade;
//
//		}
//		getchar();
//		if (i==total_courses*2)
//		{
//			double GPA = 0;
//			GPA = double(total_grade) / double(total_units);
//
//			printf("The GPA for this semester is : %.2f\n", GPA);
//		}
//	}
//	return 0;
//}
//#include <stdio.h>
//
//int main() 
//{
//	int total = 0;
//	int score = 0;
//	int count1 = 0;  // Counter for scores between 90 and 100
//	int count2 = 0;   // Counter for scores under 60
//	printf("How many scores do you have? ");
//	scanf("%d", &total);
//	getchar();
//	for (int i = 0; i < total; i++) 
//	{
//		score = getchar() - '0';
//		getchar();
//		if (score < 0 || score > 100) 
//		{
//			printf("please input score in range [0,100].\n");
//			break;
//		}
//
//		if (score >= 90 && score <= 100) 
//		{
//			count1++;
//		}
//		else if (score < 60) 
//		{
//			count2++;
//		}
//		float percentage_90_to_100 = (float)count1 * 100 / total;
//		float percentage_under_60 = (float)count2 * 100 / total;
//
//		printf("The percentage of scores which are between 90 and 100 is  %.2f%%\n", percentage_90_to_100);
//		printf("The percentage of scores which are under 60 is: %.2f%%\n", percentage_under_60);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main() 
//{
//	bool n = true;
//	int t;
//	int Count1 = 0; 
//	int Count2 = 0;
//	int score = 0;
//	printf("How many scores do you have? ");
//	scanf("%d", &t);
//
//	for (int i = 0; i < t; i++) 
//	{
//		scanf("%d", &score); 
//
//		if (score < 0 || score > 100) 
//		{
//			printf("Warning: Score out of range [0, 100]\n");
//			n = false;
//			break;
//		}
//		else
//		{
//			if (score >= 90 && score <= 100)
//			{
//				Count1++;
//			}
//			else if (score < 60) 
//			{
//				Count2++;
//			}
//		}
//	}
//	if (n)
//	{
//		float percentage_90_to_100 = (float)Count1 * 100 / t;
//		float percentage_under_60 = (float)Count2 * 100 / t;
//
//		printf("The percentage of scores which are between 90 and 100 is %.2f%%\n", percentage_90_to_100);
//		printf("The percentage of scores which are under 60 is %.2f%%\n", percentage_under_60);
//	}
//	return 0;
//}


//#include<stdio.h>
//#include<malloc.h>
//int main()
//{
//	int n;
//	printf("Input the total number of letters: ");
//	scanf("%d", &n);
//	int arr2[n];
//	char* ch = (char*)malloc(sizeof(int) * n);
//	if (n<0)
//	{
//		printf("Warning! Total number should be a positive integer!\n");
//	}
//	else
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (0 == i)
//			{
//				printf("Input %d ASCII codes: ",n);
//			}
//			scanf("%d", &ch[i]);
//			if (ch[i] < 65 || ch[i] > 122 || (ch[i] > 90 && ch[i] < 97))
//			{
//				printf("Warning! Invalid ASCII code.\n");
//				break;
//			}
//			if (i==n-1)
//			{
//				printf("%s\n", ch);
//			}
//		}
//	}
//	free(ch);
//	return 0;
//}

//#include <stdio.h>
//#include<malloc.h>
//
//void Bubble1(int a[], int n) 
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = i + 1; j < n; j++) 
//		{
//			if (a[i] > a[j]) 
//			{
//				int temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}
//void Bubble2(int a[], int n) 
//{
//	for (int i = 0; i < n - 1; i++) 
//	{
//		for (int j = i + 1; j < n; j++) 
//		{
//			if (a[i] < a[j]) 
//			{
//				int temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int n = 0;
//	printf("Input the size of the array: ");
//	scanf("%d", &n);
//	int* arr = (int*)malloc(sizeof(int) * n);
//	if (0 > n)
//	{
//		printf("Warning! Array size should be positive.\n");
//	}
//	else
//	{
//		int i = 0;
//		int j = 0;
//		for (int i = 0; i < n; i++)
//		{
//			if (0==i)
//			{
//				printf("Input %d integers of the array: ", n);
//			}
//			scanf("%d", &arr[i]);
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (0 == i)
//			{
//				printf("The original array is: ");
//			}
//			printf("%d ", arr[i]);
//		}
//		printf("\n");
//		Bubble1(arr, n);
//		printf("After sorting, the array in ascending order is: ");
//		for (int i = 0; i < n; i++) 
//		{
//			printf("%d ", arr[i]);
//		}
//		printf("\n");
//		Bubble2(arr, n);
//		printf("After sorting, the array in descending order is: ");
//		for (int i = 0; i < n; i++) 
//		{
//			printf("%d ", arr[i]);
//		}
//		printf("\n");
//	}
//	free(arr);
//	return 0;
//}


//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n = 0;
//	printf("Input a positive integer: ");
//	scanf("%d", &n);
//	if (n > 0)
//	{
//		printf("The square root of %d = %lf\n", n, sqrt(n));
//		printf("The Log10 of %d = %lf\n", n, log10(n));
//		printf("The natural log of %d = %lf\n", n, log(n));
//	}
//	else
//	{
//		printf("Warning! You should input a positive integer!\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int differenceASCIICode(char a, char b)
//{
//	int n = a - b;
//	return n;
//}
//int main()
//{
//	char a, b;
//	printf("Please enter two characters: ");
//	scanf("%c %c", &a, &b);
//	int n = differenceASCIICode(a, b);
//	printf("The difference between character '%c' and '%c' is %d\n", a, b, n);
//	return 0;
//}

//#include<stdio.h>
//float exchange(float a[], int n);
//int main()
//{
//	float data[4] = { 2.5,1,1.2,5.2 };
//	int i;
//	float max = exchange(data, 4);
//	printf("The biggest element in the array is %.2f\n", max);
//	for ( i = 0; i <= 3; i++)
//	{
//		printf("%.2f ", data[i]);
//	}
//	return 0;
//}
//float exchange(float a[], int n)
//{
//	float temp;
//	temp = a[0];
//	for (int i = 0; i < n; i++)
//	{
//		if (temp < a[i])
//		{
//			temp = a[i];
//		}
//	}
//	/*a[0] = a[n - 1];
//	a[n - 1] = temp;*/
//	return temp;
//}

//#include<stdio.h>
//int My_Cal(int n);
//
//int main()
//{
//	int n = 0;
//	printf("Input a positive integer (>=1): ");
//	scanf("%d", &n);
//	if (0 > n)
//	{
//		printf("Warning! A positive integer no smaller than 1 should be input.\n");
//	}
//	else
//	{
//		int sum = My_Cal(n);
//		printf("Sum is %d when n is %d.", sum, n);
//	}
//	return 0;
//}
//
//int My_Cal(int n)
//{
//	int m = 0;
//	if (1 < n)
//	{
//		m = n * n;
//		return m + My_Cal(n - 1);
//	}
//}

//#include<stdio.h>
//int My_Fac(int n, int m);
//int main()
//{
//	int n = 0;
//	int m = 0;
//	printf("Please input n and m: ");
//	scanf("%d%d", &n, &m);
//	if (0 < n && 0 < m)
//	{
//		int s = My_Fac(n, m);
//		printf("There are %d %d(s) in %d.", s, m, n);
//	}
//	else if (m > 0 && n < 0)
//	{
//		printf("Warning! value of n is invalid!\n");
//	}
//	return 0;
//}
//
//int My_Fac(int n, int m) 
//{
//	if (n <= 1 || m <= 1 || n % m != 0) 
//	{
//		return 0;
//	}
//	else 
//	{
//		return 1 + My_Fac(n / m, m);
//	}
//}

//#include <stdio.h>
//
//int PowerRec(int m, int n) 
//{
//	if (n == 0) 
//	{
//		return 1;
//	}
//	else 
//	{
//		return m * PowerRec(m, n - 1);
//	}
//}
//
//int PowerLoop(int m, int n) 
//{
//	int r = 1;
//	for (int i = 0; i < n; i++) 
//	{
//		r *= m;
//	}
//	return r;
//}
//
//int main() 
//{
//	int m, n;
//	printf("Input m and n: ");
//	scanf("%d %d", &m, &n);
//
//	if (m <= 0) 
//	{
//		printf("Warning! Input of m is invalid!\n");
//	}
//	else if (n < 0) 
//	{
//		printf("Warning! Input of n is invalid!\n");
//	}
//	else 
//	{
//		int rec = PowerRec(m, n);
//		int loop = PowerLoop(m, n);
//
//		printf("Product is %d using recursion.\n", rec);
//		printf("Product is %d using loop.\n", loop);
//	}
//
//	return 0;
//}

//#include<stdio.h>
//int sumAll(int n);
//int main()
//{
//	int maxNum = 0;
//	printf("Input maxNum: ");
//	scanf("%d", &maxNum);
//	if (maxNum > 0)
//	{
//		int sum = sumAll(maxNum);
//		printf("Sum is %d\n", sum);
//	}
//	else
//	{
//		printf("Warning! Input of maxNum is invalid!\n");
//	}
//
//	return 0;
//}
//int sumAll(int n)
//{
//	if (n <= 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return n + sumAll(n - 1);
//	}
//
//}

//#include <stdio.h>
//
//int main() 
//{
//	char str[50];
//	int count = 0;
//	
//	printf("Input a string: ");
//	fgets(str, sizeof(str), stdin);
//
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		if (str[i] == 'a')
//		{
//			count++;
//		}
//	}
//
//	printf("There totally %d 'a' in %s\n", count, str);
//
//	return 0;
//}

//#include <stdio.h>
//#include<string.h>
//int Isupper(char n)
//{
//	if (n >= 'A' && n <= 'Z')
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int Islower(char n)
//{
//	if (n >= 'a' && n <= 'z')
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int Isspace(char n)
//{
//	if (n==' ')
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
//	char str[50];
//
//	printf("Input a string: ");
//	fgets(str, sizeof(str), stdin);
//	int upper = 0, lower = 0, spaces = 0;
//
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		if (Isupper(str[i])) 
//		{
//			upper++;
//		}
//		else if (Islower(str[i]))
//		{
//			lower++;
//		}
//		else if (Isspace(str[i]))
//		{
//			spaces++;
//		}
//	}
//	for (int i = 0; str[i] == '\n\0'; i++)
//	{
//		if (str[i] == '\n\0')
//		{
//			str[i] = '\0';
//		}
//	}
//	str[strlen(str) - 1] = '\0';
//	printf("Original str is %s.\n", str);
//	printf("There are %d upper-case letters, %d lower-case letters, %d spaces totally.\n", upper, lower, spaces);
//
//
//	int j = 0;
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		if (!Isspace(str[i]))
//		{
//			str[j++] = str[i];
//		}
//	}
//	str[j] = '\0';
//
//	printf("String now is %s.\n", str);
//
//	return 0;
//}


//#include <stdio.h>
//#include<assert.h>
//char* My_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* p = str1;
//	while (*p!='\0')
//	{
//		s1 = p; s2 = str2;
//		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)p;
//		}
//		p++;
//	}
//	return NULL;
//}
//int main()
//{
//	char str1[50], str2[50];
//
//	printf("Input 2 strings: ");
//	scanf("%s %s", str1, str2);
//
//	char* position = My_strstr(str1, str2);
//
//	if (position)
//	{
//		printf("str1 contains str2 at position %d\n", position - str1);
//	}
//	else 
//	{
//		printf("str1 does not contain str2\n");
//	}
//
//	return 0;
//}


//#include <stdio.h>
//int stringLength(char s[]) 
//{
//	int length = 0;
//	while (s[length] != '\0')
//	{
//		length++;
//	}
//	return length;
//}
//
//int main() {
//	char str[50];
//
//	printf("Input a string: ");
//	scanf("%s", str);
//
//	int length = stringLength(str);
//
//	printf("The length of the string is %d.\n", length);
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main() 
//{
//	char word[20];
//	int count = 0;
//
//	printf("Please input some words: ");
//	while (scanf("%s", word) == 1 && strcmp(word, "End") != 0) 
//	{
//		count++;
//	}
//
//	printf("There are totally %d words.\n", count);
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main() 
//{
//	char str1[50], str2[50], str3[50];
//
//	printf("Input 3 strings: ");
//	scanf("%s %s %s", str1, str2, str3);
//
//	char* position = strstr(str1, str2);
//
//	if (position != NULL) 
//	{
//		strncpy(position, str3, strlen(str3));
//	}
//	else 
//	{
//		strcat(str1, str3);
//	}
//
//	printf("Originally, str1 is %s, str2 is %s, str3 is %s.\n", str1, str2, str3);
//	printf("now, str1 is %s, str2 is %s, str3 is %s.\n", str1, str2, str3);
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main() {
//	char str1[50], str2[50], str3[50];
//
//	printf("Input 3 strings: ");
//	scanf("%s %s %s", str1, str2, str3);
//
//	char* position = strstr(str1, str2);
//
//	if (position != NULL) {
//		strncpy(position, str3, strlen(str3));
//	}
//	else {
//		strcat(str1, str3);
//	}
//
//	printf("Originally, str1 is %s, str2 is %s, str3 is %s.\n", str1, str2, str3);
//	printf("now, str1 is %s, str2 is %s, str3 is %s.\n", str1, str2, str3);
//
//	return 0;
//}


//#include<stdio.h>
//#include<assert.h>
//
//#define COL1 3
//#define ROW1 3
//#define COL2 1
//#define ROW2 3
//
//void Mat_mul(double(*arr1)[COL1], double(*arr2)[COL2], double(*arr3)[COL2], int row1, int row2, int col1, int col2)
//{
//	assert(col1 == row2);
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for ( i = 0; i < row1; i++)
//	{
//		for (j = 0; j < col2; j++) 
//		{
//			for ( k = 0; k < col1; k++)
//			{
//				*(*(arr3 + i) + j) += *(*(arr1 + i) + k) * *(*(arr2 + k) + j);
//			}
//		}
//	}
//}
//int main()
//{
//	double arr1[ROW1][COL1] = { {1,2,5},{1,3,1},{0,1,1} };
//	double arr2[ROW2][COL2] = { 1,0,1 };
//	double arr3[ROW1][COL2] = { 0 };
//	Mat_mul(arr1, arr2, arr3, ROW1, ROW2, COL1, COL2);
//	for (int i = 0; i < ROW1; i++)
//	{
//		printf("| ");
//		for (int j = 0; j < COL1; j++)
//		{
//			printf("%.0f ", arr1[i][j]);
//
//		}
//		printf("|\n");
//	}
//	printf("times\n");
//	for (int i = 0; i < ROW2; i++)
//	{
//		printf("| ");
//		for (int j = 0; j < COL2; j++)
//		{
//			printf("%.0f ", arr2[i][j]);
//		}
//		printf("|\n");
//	}
//	printf("equal to:\n");
//	for (int i = 0; i < ROW1; i++)
//	{
//		printf("| ");
//		for (int j = 0; j < COL2; j++) 
//		{
//			printf("%.0f ",arr3[i][j]);
//		}
//		printf("|\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<stdbool.h>
//bool isPrime(int n)
//{
//	int boolen = 0;
//	for (int i = 2; i < n; i++)
//	{
//		if (n % i == 0)
//		{
//			boolen = false;
//			break;
//		}
//		if (i == n - 1)
//		{
//			boolen = true;
//			break;
//		}
//	}
//	return boolen;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 5; i < 100; i++)
//	{
//		if (isPrime(i))
//		{
//			printf("%d is a prime\n",i);
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//const struct point
//{
//	const int x;
//	const int y;
//};
//int main()
//{
//
//}

//#include<stdio.h>
//int Fib(int n)
//{
//	if (n==1)
//	{
//		return 1;
//	}
//	else if (n == 2)
//	{
//		return 2;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}
//int main()
//{
//	int a = 20;
//	int i = 0;
//	printf("%d\n\n", Fib(20));
//	return 0;
//}

#include<stdio.h>
//struct point
//{
//	double x;
//	double y;
//};
//struct line
//{
//	struct point p1;
//	struct point p2;
//};
//struct triangle
//{
//	struct point p1;
//	struct point p2;
//	struct point p3;
//};
//struct point p;
//struct line l;
//struct triangle t;
//int main()
//{
//	point p1 = {
//		4,
//		11
//	};
//	point p2 = {
//		2,
//		7
//	};
//	point p3 = {
//		10,
//		9
//	};
//	point p4 = {
//		2,
//		0
//	};
//	point p5 = {
//		6,
//		5
//	};
//	point p6 = {
//		8,
//		3
//	};
//	line l1 = {
//		p2,
//		p3
//	};
//	line l2 = {
//		p4,
//		p5
//	};
//	line l3 = {
//		p5,
//		p6
//	};
//	line l4 = {
//		p4,
//		p6
//	};
//	triangle t1 = {
//		p4,
//		p5,
//		p6
//	};
//}

//enum week{Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};
//int main()
//{
//	enum week day;
//	day = Sunday;
//	printf("%d\n", day);
//	day = Monday;
//	printf("%d\n", day);
//	return 0;
//}

//#include<stdio.h>
//#define INT 32
//int ZeroInBinary(int n[INT])
//{
//	int count = 0;
//	for (int i = 0; i < INT; i++)
//	{
//		if (n[i]==0)
//		{
//			count++;
//		}
//		if (n[i]==2)
//		{
//			break;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int a[32];
//	int number = 0;
//	int length = 0;
//	printf("Input: ");
//	scanf("%d", &number);
//	while (number/2)
//	{
//		a[length++] = number % 2;
//		number /= 2;
//	}
//	a[length++] = number % 2;
//	a[length++] = 2;
//	for (int j = 0; j < 32; j++)
//	{
//		printf("%d ", a[j]);
//	}
//	int total = ZeroInBinary(a);
//	printf("Output: %d\n", total);
//	return 0;
//}


//#include <stdio.h>
//#include <math.h>
//#define LINE_LENGTH(x1, y1, x2, y2) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
//
//struct Point 
//{
//	float x;
//	float y;
//};
//
//struct Triangle 
//{
//	struct Point p1;
//	struct Point p2;
//	struct Point p3;
//};
//
//int main()
//{
//	struct Triangle triangle;
//
//	printf("Enter the coordinates of the 1st point: ");
//	scanf("%f, %f", &triangle.p1.x, &triangle.p1.y);
//	printf("Enter the coordinates of the 2nd point: ");
//	scanf("%f, %f", &triangle.p2.x, &triangle.p2.y);
//	printf("Enter the coordinates of the 3rd point: ");
//	scanf("%f, %f", &triangle.p3.x, &triangle.p3.y);
//
//	float length1 = LINE_LENGTH(triangle.p1.x, triangle.p1.y, triangle.p2.x, triangle.p2.y);
//	float length2 = LINE_LENGTH(triangle.p2.x, triangle.p2.y, triangle.p3.x, triangle.p3.y);
//	float length3 = LINE_LENGTH(triangle.p3.x, triangle.p3.y, triangle.p1.x, triangle.p1.y);
//
//	float circumference = length1 + length2 + length3;
//	printf("The circumference of the triangle is %.6f.\n", circumference);
//
//	return 0;
//}

//#include <stdio.h>
//#include<stdbool.h>
//
//const struct Date
//{
//	int month;
//	int day;
//	int year;
//};
//
//bool isLeapYear(int year)
//{
//	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//}
//
//void findNextDay(struct Date* d) 
//{
//	struct Date nextDay = { 0 };
//	if (((d->month == 4 || d->month == 6 || d->month == 9 || d->month == 11) && d->day == 30)||( d->day == 31&&d->month!=12)|| (d->month == 2 && d->day == 29 && isLeapYear(d->year)) || (d->month == 2 && d->day == 28 && !isLeapYear(d->year)))
//	{
//		nextDay.day = 1;
//		nextDay.month = d->month + 1;
//		nextDay.year = d->year;
//	}
//	else if(d->day == 31 && d->month == 12)
//	{
//		nextDay.day = 1;
//		nextDay.month = 1;
//		nextDay.year = d->year + 1;
//	}
//	else
//	{
//		nextDay.day = d->day + 1;
//		nextDay.month = d->month;
//		nextDay.year = d->year;
//	}
//	printf("The next day of input date is %d/%d/%d.\n", nextDay.month, nextDay.day, nextDay.year);
//}
//
//int main() 
//{
//	struct Date currentDate;
//	printf("Input a date by the order of month, day, year: ");
//	scanf("%d %d %d", &currentDate.month, &currentDate.day, &currentDate.year);
//
//	if (currentDate.year <= 0)
//	{
//		printf("Warning! Year input should be positive.\n");
//	}
//	else if (currentDate.month < 1 || currentDate.month > 12)
//	{
//		printf("Warning! Month input should be ranging in [1, 12].\n");
//	}
//	else if ((currentDate.day < 1 || currentDate.day > 31)|| (currentDate.month == 2 && currentDate.day > 29)|| (currentDate.month == 2 && currentDate.day == 29 && !isLeapYear(currentDate.year))|| ((currentDate.month == 4 || currentDate.month == 6 || currentDate.month == 9 || currentDate.month == 11) && currentDate.day > 30))
//	{
//		printf("Warning! Date input is not real.\n");
//	}
//	else 
//	{
//		findNextDay(&currentDate);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct Stu
//{
//	char name[50];
//	int score;
//	char major[50];
//};
//
//int cmp_Names(const void* a, const void* b)
//{
//	return strcmp(((struct Stu*)a)->name, ((struct Stu*)b)->name);
//}
//
//int main() 
//{
//	int numStu;
//
//	printf("Input the number of students: ");
//	scanf("%d", &numStu);
//
//	if (numStu <= 0) 
//	{
//		printf("Warning! Student number should be positive.\n");
//		return 0;
//	}
//
//	struct Stu* students = (struct Stu*)malloc(numStu * sizeof(struct Stu));
//
//	printf("Please input students' information:\n");
//	for (int i = 0; i < numStu; i++) 
//	{
//		scanf("%s %d %s", students[i].name, &students[i].score, students[i].major);
//	}
//	qsort(students, numStu, sizeof(struct Stu), cmp_Names);
//
//	printf("The student list in ascending order by name is:\n");
//	for (int i = 0; i < numStu; i++) 
//	{
//		printf("%s %d %s\n", students[i].name, students[i].score, students[i].major);
//	}
//
//	free(students);
//
//	return 0;
//}

//enum year { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
//int main()
//{
//	int i;
//	for (i = Jan; i <= Dec; i++)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}



//#include<stdio.h>
//#include<string.h>
//struct Student {
//	char str[10];
//	int marks;
//};
//int main()
//{
//	int values[5] = { 5, 10, 15, 20, 22 };
//	char str[10], * p;
//	int n = 0, i;
//	struct Student stu[20], * ps;
//
//	strcpy(str, "UVWXYZ");
//	p = str;
//
//	// print the third element in the array values using three different expressions.
//	printf("%d %d %d\n", values[2], *(values+2),*( & values[0] +2));
//	printf("%c %c\n", str[2], p[2]); //print third char in str through str and p respectively
//	printf("%s, %s\n", str, p); //print str string through str and p respectively
//	for (i = 0; i < 20; i++) {
//		scanf("%s %d", stu[i].str, &stu[i].marks);  // read student's name and marks
//		if (stu[i].marks == -1)
//			break;
//	}
//	n = i - 1;
//	// with the following two statements, print out the name and marks throught ps
//	ps = stu;
//	printf("first student\'s name:%s, marks:%d\n", ps->str, ps->marks);
//	return 0;
//}

//#include<stdio.h>
//int* exchange(int* x, int* y);
//int main()
//{
//	int a = 10, b = 20;
//	printf("before exchange:a=%d,b=%d\n", a, b);
//	exchange(&a, &b);
//	printf("after exchange:a=%d,b=%d\n", a, b);
//	return 0;
//}
//int* exchange(int* x, int* y)
//{
//	/**x = *x + *y;
//	*y = *x - *y;
//	*x = *x - *y;*/
//	int temp;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//	return x, y;
//}

//# include <stdio.h>
//void stringCombine(char* dest, char* src);
//int main()
//{
//	char str1[100], str2[256];
//	fgets(str1,100,stdin);
//	fgets(str2,256,stdin);
//	stringCombine(str1, str2);
//	puts(str1);
//	return 0;
//}
//void stringCombine(char* dest, char* src) {
//	while (*(dest++) != '\n');
//	dest--;
//	while (*src != '\0')
//	{
//		*(dest++) = *(src++);
//	}
//	*dest = '\0';
//}

//#include<stdio.h>
//double calSumAverage(double, double, double*);
//int main()
//{
//	double x =0, y = 0;
//	double average, sum;
//	scanf("%lf %lf", &x, &y);
//	sum = calSumAverage(x, y, &average);
//	printf("The sum is %f, the average is %f", sum, average);
//	return 0;
//}
//double calSumAverage(double no1, double no2, double* pAverage)
//{
//	double sum;
//	sum = no1 + no2;
//	*pAverage = sum / 2;
//	return sum;
//}

//#include<stdio.h>
//double calSumAverage(double, double, double*);
//int main()
//{
//	double m = 0, n = 0;
//	double average, sum;
//	scanf("%lf %lf", &m, &n);
//	sum = calSumAverage(m, n, &average);
//	printf("The sum is %f, the average is %f", sum, average);
//	return 0;
//}
//
//double calSumAverage(double no1, double no2, double* pAverage)
//{
//	double sum = 0;
//	for (double i = no1; i <= no2; ++i) {
//		sum += i;
//	}
//	*pAverage = sum / (no2 - no1 + 1);
//	return sum;
//}

//#include<stdio.h>
//void My_File()
//{
//	FILE* fp;
//	char c;
//	fp = fopen("infile.txt", "r");
//	if (fp == NULL)
//	{
//		printf("The file does not exist.\n");
//		return;
//	}
//	if (c=fgetc(fp)==EOF)
//	{
//		fgetc(fp);
//	}
//	while ((c = fgetc(fp) != EOF))
//	{
//		printf("%c", c);
//	}
//	fclose(fp);
//}
//int main()
//{
//	My_File();
//	return 0;
//}

//fprintf() 成功返回写入的字符的个数，失败则返回负数。
//fscanf() 返回参数列表中被成功赋值的参数个数。
// 
// 
//#include<stdio.h>
//#include <stdlib.h>
//#define N 2
//
//struct book {
//    char name[10];
//    int num;
//    int year;
//} booka[N], bookb[N], * pa, * pb;
//
//int main() {
//    FILE* fp;
//    int i;
//    pa = booka;
//    pb = bookb;
//    if ((fp = fopen("Hello.txt", "wt + ")) == NULL) {
//        puts("Fail to open file!");
//        exit(0);
//    }
//
//    //从键盘读入数据，保存到booka
//    printf("输入数据：书名，数量，入馆年份:\n");
//    for (i = 0; i < N; i++, pa++) {
//        scanf("%s %d %d", pa->name, &pa->num, &pa->year);
//    }
//    pa = booka;
//    //将booka中的数据写入到文件
//    for (i = 0; i < N; i++, pa++) {
//        fprintf(fp, "%s %d %d\n", pa->name, pa->num, pa->year);
//    }
//    //重置文件指针
//    rewind(fp);
//    //从文件中读取数据，保存到bookb
//    for (i = 0; i < N; i++, pb++) {
//        fscanf(fp, "%s %d %d\n", pb->name, &pb->num, &pb->year);
//    }
//    pb = bookb;
//    //将bookb中的数据输出到显示器
//    for (i = 0; i < N; i++, pb++) {
//        printf("%s  %d  %d\n", pb->name, pb->num, pb->year);
//    }
//
//    fclose(fp);
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//int fileCopy(char* file1, char* file2) {
//	FILE* destFile, * resFile;
//	int ch;
//
//	destFile = fopen(file1, "w");
//	resFile = fopen(file2, "r");
//	if (destFile == NULL || resFile == NULL) {
//		return 0;
//	}
//
//	while ((ch = fgetc(resFile)) != EOF) {
//		fputc(ch, destFile);
//	}
//
//	fclose(destFile);
//	fclose(resFile);
//
//	return 1;
//}
//int main()
//{
//	char fileName1[20], fileName2[20];
//	int flag;
//	strcpy(fileName1, "a.txt");
//	strcpy(fileName2, "b.txt");
//	flag = fileCopy(fileName2, fileName1);
//	if (flag == 1)
//		printf("Success");
//	else
//		printf("Failure");
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//int fileCombine(char* file1, char* file2) {
//	FILE* destFile, * resFile;
//	int ch;
//
//	destFile = fopen(file1, "a");
//	resFile = fopen(file2, "r");
//
//	if (destFile == NULL || resFile == NULL) {
//		return 0;
//	}
//	fputc('\n\r', destFile);
//	while ((ch = fgetc(resFile)) != EOF) {
//		
//		fputc(ch, destFile);
//	}
//
//	fclose(destFile);
//	fclose(resFile);
//
//	return 1;
//}
//
//int main()
//{
//	char fileName1[20], fileName2[20];
//	int flag;
//	strcpy(fileName1, "a.txt");
//	strcpy(fileName2, "b.txt");
//	flag = fileCombine(fileName2, fileName1);
//	if (flag == 1)
//		printf("Success\n");
//	else
//		printf("Failure\n");
//	return 0;
//}

//#include <stdio.h>
//
//int main() {
//	FILE* file = fopen("sample.bin", "rb");
//
//	if (file != NULL) {
//		float num1, num2;
//		fseek(file, 4 * sizeof(float), SEEK_SET);
//		fread(&num1, sizeof(float), 1, file);
//		fseek(file, 2 * sizeof(float), SEEK_CUR);
//		fread(&num2, sizeof(float), 1, file);
//
//		printf("num1 is %.6f\nnum2 is %.6f\n", num1, num2);
//
//		fclose(file);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct stuRec {
//	char name[20];
//	int id;
//	char gender;
//};
//int main()
//{
//	struct stuRec* p;
//	p = (struct stuRec*)malloc(sizeof(struct stuRec));
//	if (p) {
//		printf("please input name, id and gender\n");
//		scanf("%s%d%*c%c", p->name, &p->id, &p->gender);
//		printf("name:%-10s,ID:%d,gender:%c\n", p->name, p->id, p->gender);
//		free(p);
//	}
//	return 0;
//}
///*
//1.This program allocates memory to record name, id, and sex of a student, takes input, then prints them.
//2.Memory is dynamically allocated using 'malloc'.
//3.%*c is used to consume the newline character from the previous input.
//4.Changing '%-10s' to '%10s' would right-align the name.
//5.free(p) deallocates the dynamically allocated memory.
//*/

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int n;
//
//	printf("Input the number of the data: ");
//	scanf("%d", &n);
//
//	if (n <= 0) {
//		printf("Warning! You should input a positive integer!\n");
//	}
//	else
//	{
//		int* data = (int*)malloc(n * sizeof(int));
//
//		printf("Input integer numbers: ");
//		for (int i = 0; i < n; ++i) {
//			scanf("%d", &data[i]);
//		}
//
//		printf("Numbers in reverse order are: ");
//		for (int i = n - 1; i >= 0; --i) {
//			printf("%d ", data[i]);
//		}
//		printf("\n");
//		free(data);
//	}
//	return 0;
//}
//
//#include <stdio.h>
//
//struct CourseItem {
//	char name[20];
//	float percentage;
//	float fullMark;
//};
//
//int main() {
//	struct CourseItem items[] = { {"Assignment", 30.0, 50.0}, {"Project", 30.0, 100.0}, {"Final", 40.0, 100.0} };
//
//	printf("COMP3012 Advanced Computer Vision\n");
//	printf("\t-----------------------------------\n");
//	printf("\t| No.    | Item                 | Percentage | Full Mark  | Grades\n");
//
//	for (int i = 0; i < sizeof(items) / sizeof(items[0]); ++i) {
//		printf("\t| %d      | %-20s | %-11f | %-11f |\n", i + 1, items[i].name, items[i].percentage, items[i].fullMark);
//	}
//
//	printf("\t-----------------------------------\n");
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include<stdlib.h>
//struct Product 
//{
//	char manufacturer[50];
//	char name[50];
//	float price;
//};
//
//int compareProducts(const void* a, const void* b) 
//{
//	return ((struct Product*)b)->price - ((struct Product*)a)->price;
//}
//
//int main()
//{
//	struct Product products[50];
//	int count = 0;
//	printf("Input:\n");
//	while (scanf("%s %s %f", products[count].manufacturer, products[count].name, &products[count].price) == 3) 
//	{
//		if (products[count].price == -1)
//			break;
//		count++;
//	}
//
//	qsort(products, count, sizeof(struct Product), compareProducts);
//
//	printf("\nSorted list:\n");
//	for (int i = 0; i < count; i++) 
//	{
//		printf("%s %s %.2f\n", products[i].manufacturer, products[i].name, products[i].price);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int occurrence1(char* sub, char* str);
//int occurrence2(char* sub, char* str);
//int occurrence1(char* sub, char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	return (strstr(str, sub) == str) + occurrence1(sub, str + 1);
//}
//
//int occurrence2(char* sub, char* str)
//{
//	int count = 0;
//	while ((str = strstr(str, sub)) != NULL)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main() 
//{
//	char str1[20], str2[80];
//	printf("Input two strings: ");
//	scanf("%s%s", str1, str2);
//	printf("Number of occurrences 1: %d\n", occurrence1(str1, str2));
//	printf("Number of occurrences 2: %d\n", occurrence2(str1, str2));
//	return 0;
//}

//#include <stdio.h>
//
//int merge(const char* file1, const char* file2, const char* outputFile);
//
//int main() 
//{
//	if (!merge("1001.txt", "1002.txt", "class.txt"))
//		printf("Failed to merge\n");
//	else
//		printf("Merge successfully\n");
//	return 0;
//}
//
//int merge(const char* file1, const char* file2, const char* outputFile)
//{
//	FILE* fp1 = fopen(file1, "r");
//	FILE* fp2 = fopen(file2, "r");
//	FILE* outp = fopen(outputFile, "w");s
//
//	if (fp1 == NULL || fp2 == NULL || outp == NULL) 
//	{
//		perror("Error opening files");
//		return 0;
//	}
//	char line[100];
//	char str1[10], str2[10], str3[10];
//	while (fgets(line, sizeof(line), fp1)) 
//	{
//		sscanf(line, "%s %s %s", str1, str2, str3);
//		fprintf(outp, "%s %s %s\n", str1, str2, str3);
//	}
//	while (fgets(line, sizeof(line), fp2)) 
//	{
//		sscanf(line, "%s %s %s", str1, str2, str3);
//		fprintf(outp, "%s %s %s\n", str1, str2, str3);
//	}
//	fclose(fp1);
//	fclose(fp2);
//	fclose(outp);
//
//	return 1;
//}

//#include <stdio.h>
//
//struct Student {
//	char name[20];
//	char ID[10];
//	int score;
//};
//
//int main() {
//	FILE* file = fopen("stuScore.bin", "rb");
//	if (file == NULL) {
//		perror("Error opening file");
//		return 1;
//	}
//
//	struct Student student;
//	while (fread(&student, sizeof(struct Student), 1, file) == 1) {
//		printf("%s %s %d\n", student.name, student.ID, student.score);
//	}
//
//	fclose(file);
//	return 0;
//}
//
//#include <stdio.h>
//
//struct Student {
//	char name[20];
//	char ID[10];
//	int score;
//};
//
//int main() {
//	FILE* file = fopen("stuScore.bin", "rb");
//	if (file == NULL) {
//		perror("Error opening file");
//		return 1;
//	}
//
//	struct Student student;
//	while (fread(&student, sizeof(struct Student), 1, file) == 1) {
//		printf("%s %s %d\n", student.name, student.ID, student.score);
//	}
//
//	fclose(file);
//	return 0;
//}
//
//static int arr[10086];
//int* printNumbers(int n, int* returnSize)
//{
//	int j = 1;
//	int i;
//	int k = 1;
//	for ( k= 0; k < n; k++)
//	{
//		j *= 10;
//	}
//	for (int i = 1; i < j; i++)
//	{
//		arr[i - 1] = i;
//	}
//	*returnSize = --i;
//	return arr;
//}

//#include <stdio.h>
//int isleapyear(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
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
//	int sum_leapyear[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
//	int sum_commonyear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	int a, b;
//	int year, month, day;
//	int n = 0;
//	scanf("%d %d %d", &year, &month, &day);
//	if (isleapyear(year)==1)
//	{
//
//		for (int i = 0; i < month - 1; i++)
//		{
//			n += sum_leapyear[i];
//		}
//	}
//	else
//	{
//		for (int i = 0; i < month - 1; i++)
//		{
//			n += sum_commonyear[i];
//		}
//	}
//	n += day;
//	printf("%d\n", n);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char s[] = "\\123456\123456\t";
//	printf("%d\n", strlen(s));//12
//	return 0;
//}

//#include<stdio.h>
//#define N 2
//#define M N + 1
//#define NUM (M + 1) * M / 2 
//int f(int n);
//int main()
//{
//	printf("%d\n", N);
//	printf("%d\n", M);
//	printf("%d\n", NUM);
//	printf("%d\n", f(1));
//	int a = 5;
//	const int* b = &a;
//	int const* c = &a;
//	int* const d = &a;
//	printf("%x\n%x\n%x\n", b, c, d);
//	/*char ch[14] = "Hello World!"; --在栈操作
//	ch = "Hello World!";--在静态空间操作*/
//	return 0;
//}
//int f(int n)
//{
//	static int i = 1;
//	if (n >= 5)
//		return n;
//	n = n + i;
//	i++;
//	return f(n);
//}

//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int m = n * n;
//	if (n % 2 != 0)
//	{
//		for (int i = 0; i <= (n - 1)*2; i += 2)
//		{
//			if (i==0)
//			{
//				printf("%d", m - ((n / 2) * 2) + i);
//			}
//			else
//			{
//				printf("+%d", m - ((n / 2) * 2) + i);
//			}
//			
//		}
//	}
//	else
//	{
//		for (int i = 0; i <= (n-1) * 2; i += 2)
//		{
//			if (i == 0)
//			{
//				printf("%d", m-1 - (((n / 2)-1) * 2) + i);
//			}
//			else
//			{
//				printf("+%d", m-1 - (((n / 2)-1) * 2) + i);
//			}
//		}
//	}
//	printf("\n");
//	return 0;
//}

//#include<stdio.h>
//int main() 
//{
//	int n = 0;
//	int a1 = 2;
//	int d = 3;
//	scanf("%d", &n);
//	int Sn = (n * a1) + (n * (n - 1) * d) / 2;
//	printf("%d", Sn);
//	int a = 248, b = 4;
//	int const* const f = &a;
//	a = 0x321f;
//	return 0;
//}


//#include<stdio.h>
//int i;
//void prt()
//{
//	for (i = 5; i < 8; i++)
//		printf("%c", '*');
//	printf("\t");
//}
//int main()
//{
//	for (i = 5; i <= 8; i++)
//		prt();
//	return 0;
//}

//int main() 
//{
//	int a = 3;
//	printf("%d\n", (a += a -= a * a));
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int n;
//	while (scanf("%d", &n) > 0)
//	{
//		int count_neg = 0;
//		int count_int = 0;
//		int num = 0;
//		int sum = 0;
//		double result;
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &num);
//			if (num < 0)
//			{
//				count_neg++;
//			}
//			else if (num > 0)
//			{
//				sum += num;
//				count_int++;
//			}
//		}
//		if (count_int!=0)
//		{
//			result = (float)sum / count_int;
//			printf("%d %0.1lf\n", count_neg, result);
//		}
//		else
//		{
//			printf("%d 0.0\n",count_neg);
//		}
//	}
//	return 0;
//}

//int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) {
//	int i = 0;
//	int min = *rotateArray;
//	for (i = 0; i < rotateArrayLen - 1; i++)
//	{
//		rotateArray++;
//		if (*rotateArray < min)
//		{
//			min = *rotateArray;
//		}
//	}
//	return min;
//}
//#include<stdio.h>
//
//int main()
//{
//	int m, n;
//	printf("Enter m,n;");
//	scanf("%d%d", &m, &n);
//	while (m != n)//1
//	{
//		while (m > n)m = m - n; //2
//		while (n > m)n = n - m; //3
//	}
//	printf("m=%d\n", m);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char c;
//	int v0 = 0, v1 = 0, v2 = 0;
//	do
//	{
//		switch (c = getchar())
//		{
//			case'a':case'A':
//			case'e':case'E':
//			case'i':case'I':
//			case'o':case'O':
//			case'u':case'U':v1 += 1;
//			default:v0 += 1; v2 += 1;
//		}
//	} while (c != '\n');
//	printf("v0=%d,v1=%d,v2=%d\n", v0, v1, v2);
//	return 0;
//}
#include<stdio.h>
#include<string.h>
int main()
{
	char str[30] = { '/0' };
	gets_s(str, sizeof(str));
	char* a = str;
	char* b = str;
	b += strlen(str) - 1;
	char* tmp = str;
	while ((a!=b)&&(a+1!=b))
	{
		*tmp = *a;
		*a = *b;
		*b = *tmp;
		a++;
		b--;

	}
	puts(str);
	return 0;
}