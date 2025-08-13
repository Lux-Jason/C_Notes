#include<iostream>
#include<cmath>
#include<cstdlib>
#include<Windows.h>
//c语言类型：
// 1.内置类型：char,short,int,;ong,long long float,double
// 2.自定义类型(构造类型）
// 类型意义：
// 1.使用这个类型开辟内存空间的大小（大小决定了使用范围）。
// 2.如何看待内存空间的视角。
//
//using namespace std;
//int main()
//{
//	/*int a = 10;
//	float f = 10.0;
//	short a = 10;
//	short int b = 10;
//	unsigned long c = 20;
//	long int d = 30;*/
//
//	/*float f = 9.0;
//	double g = 4.0000;*/
//	return 0;
//}
//int main()
//{
//	/*using namespace std;
//	int a = 0;
//	double b = 0;
//	cout << "input:>";
//	scanf("%d", &a);
//	b = sqrt(a);
//	printf("%fl\n", b);*/
//	//int main = 0;//main can be used as function name,but don't do that.
//	//cout << main
//	//	<< endl;
//
//	return 0;
//}


//构造类型：
// 1.数组类型--自定义类型
// 2.结构体类型（struct）
// 3.枚举类型（enum）
// 4.联合类型（union）
//

//指针类型：
// int* pi;
// char* pc;
// float* pf;
// void* pv
//

//空类型：
// void表示空类型
//通常应用于函数的返回类型，函数的参数，指针类型。
//void test()
//{
//	printf("haha\n");
//}
//int main()
//{
//	test();//不可以传参，函数不会接收
//	return 0;
//}


//整型在内存中的存储：
//原码
//反码
//补码
//int main()
//{
//	int a = 20;//&a hex=0x00000014--二进制补码
//	int b = -10;//&b hex=0xfffffff6--二进制补码
//
//	return 0;
//}
// 
// 
//大端小端：
//
//int main()
//{
//	int a = 20;
//	//00000000000000000000000000010100
//	//0x00 00 00 14
//	//内存存储方式有两种：
//	//大端存储模式（大端字节序存储模式）--指数据低位保存在内存高地址，数据高位保存在低地址
//	//小端存储模式（小端字节序存储模式）--指数据低位保存在内存低地址，数据高位保存在高地址
//	//两种保存模式都支持
//	int b = 0x11223344;//此电脑ide为小端存储模式
//	return 0;
//}

//写一段代码，告诉我们当前机器的字节序是什么：
//int check_sys1()
//{
//	int a = 1;
//	char* pa = (char*)&a;
//	/*if (*pa==1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}*/
//	return *pa;
//}
//int check_sys2()
//{
//	int a = 1;
//	return *(char*)&a;//写法可读性较差，不推荐
//}
////指针类型的意义：
////1.指针类型决定了指针解引用操作符能访问几个字节：char* p：*p访问了一个字节；int* p：*p访问了四个字节
////2.指针类型决定了指针+1，-1等操作，加或减的是几个字节；char* p：p+1，跳过一个字符；int* p：p+1，跳过四个字节（一个整型）。
//int main()
//{
//	//返回1，小端
//	//返回0，大端
//	int ret = check_sys1();
//	if (ret==1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);//-1,-1,255
//	return 0;
//}

//int main()
//{
//	char a = -128;
//	//10000000000000000000000010000000
//	//11111111111111111111111101111111
//	//11111111111111111111111110000000--补码
//	//10000000//整型提升按符号位补
//	//11111111111111111111111110000000--整型提升后的补码
//	//无符号数的补码和原码相同
//	printf("%u\n", a);//打印十进制的无符号数字--4294967168
//	return 0;
//}
//char:
//signed char
//unsigned char
//一个字节，八个bit；

//int main()
//{
//	using namespace std;
//	char charr1[20];
//	char charr2[20] = "jaguar";
//	string str1;
//	string str2 = "panther";
//
//	//assignment for string objects and character arrays
//	str1 = str2;//copy str2 to str1
//	strcpy (charr1,charr2);//copy charr2 to char1
//
//	//qppending for string objects and character arrays
//	str1 += "paste";//add paste to end of str1
//	strcpy(charr1, "juice");//add "juice" to end of charr1
//
//	//finding the length of a string object and a C-style string
//	int len1 = str1.size();//obtain length of strl
//	int len2 = strlen(charr1);//obtain length of charr1
//
//	cout << "The string " << str1 << " contains "
//		<< len1 << " characters.\n";
//	cout << "The string " << charr1 << " contains "
//		<< len2 << " characters.\n";
//	return 0;
//}

//int main()
//{
//    int i, n;
//    scanf("%d", &n);
//    char arr[10][n] = {};
//    for (i = 0; i < n; i++)
//    {
//        scanf("%s", arr);
//        
//
//    }
//    if (arr[0] > arr[1] && arr[0] > arr[2])
//    {
//        if (arr[1] > arr[2])
//            printf("%c %c %c\n", arr[2], arr[1], arr[0]);
//        else
//            printf("%c %c %c\n", arr[1], arr[2], arr[0]);
//    }
//    if (arr[1] > arr[0] && arr[1] > arr[2])
//    {
//        if (arr[0] > arr[2])
//            printf("%c %c %c\n", arr[2], arr[0], arr[1]);
//        else
//            printf("%c %c %c\n", arr[0], arr[2], arr[1]);
//    }
//
//    if (arr[2] > arr[1] && arr[2] > arr[0])
//    {
//        if (arr[1] > arr[0])
//            printf("%c %c %c\n", arr[0], arr[1], arr[2]);
//        else
//            printf("%c %c %c\n", arr[1], arr[0], arr[2]);
//    }
//
//    return 0;
//}


//int main()
//{
//	using namespace std;
//	int n, i;
//	int* a;
//
//	scanf("%d", &n);
//	a = (int*)calloc(n, sizeof(char));
//	const int* b = const_cast<const int*>(a);
//	for ( i = 0; i < n; i++)
//	{
//		a[i] = i + 1;
//	}
//	return 0;
//}

//int main()
//{
//	int i = -20;
//	unsigned int j = 10;//无符号数正数取值与有符号数一样
//	printf("%d\n", i + j);//-10
//	return 0;
//}
//int main()
//{
//	/*unsigned int i;
//	for ( i = 9; i >=0; i--)
//	{
//		printf("%u\n", i);
//		Sleep(100);
//	}*/
//	//char a[1000];
//	//int i;
//	//for ( i = 0; i < 1000; i++)
//	//{
//	//	a[i] = -1 - i;
//	//}
//	//printf("%d", strlen(a));//255
//	return 0;
//}

//浮点型：
/*int main()
{
	int n = 9;
	float* pFloat = (float*)&n;
	printf("n的值为：%d\n", n);//9
	printf("*pFloat的值为：%f\n", *pFloat);//0.000000
	//(-1)^0*0.00000000000000000001001*2^(-126)->0（无限接近0）

	*pFloat = 9.0;
	//1001.0
	//1.001*(2^3)
	//(-1)^0*1.001*2^3
	//0 10000010 00100000000000000000000
	printf("num的值为：%d\n", n);//1091567616
	//将上二进制数转换为十进制数
	// 
 //浮点型内存存储形式和整型不同，其以整型的方式存储数值，二进制的科学计数法的方式移动小数点(电气电子工程师学会IEEE 754标准）
	printf("*pFloat的值为：%lf\n", *pFloat);//9.000000
	return 0;
}*/
//int main()
//{
//	float f = 5.5;
//	//5.5
//	//101.1
//	//(-1)^0*1.011*2^2
//	// S=0
//	// M=1.011
//	// E=2
//	// 0 10000001 01100000000000000000000
//	// 0100 0000 1011 0000 0000 0000 0000 0000
//	// 0x40b00000
//	//3.14
//	//11.001...
//	return 0;
//	
//}