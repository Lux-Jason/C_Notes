#include<iostream>

//指针：
// 1.字符指针
// 2.数组指针
// 3.指针数组
// 4.数组传参和指针传参
// 5.函数指针
// 6.函数指针数组
// 7.指向函数指针数组指针
// 8.回调函数
// 9.指针和数组题解
//
//指针概念：
// 1.指针就是一个变量，用来存放地址，地址唯一标识一块内存空间
// 2.指针大小是固定的（4/8字节）（32/64位平台）
// 3。指针是有类型，指针的类型决定了指针的+-整数的步长，指针解引用时的权限
// 4.指针的运算
//
//void test(int arr[])
//{
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", sz);
//}
//int main()
//{
//	int arr[10] = { 0 };
//	test(arr);//64位平台一个指针大小为8字节
//	return 0;
//}
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//
//	return 0;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	char* pc = arr;
//	printf("%s\n", arr);
//	printf("%s\n", pc);
//	return 0;
//}
//int main()
//{
//	char* p = (char*)"abcdef";//"abcdsf"是一个常量字符串,该操作是把字符串的首字符地址放入指针p（注意：此处指针必须为常量）
//	
//	printf("%s\n", p);
//	printf("%c\n", *p);//只打印第一个字符
//	return 0;
//}
//
//int main()
//{
//	/*char str1[] = "hello world";
//	char str2[] = "hello world";
//	const char* str3 = "hello world";
//	const char* str4 = "hello world";
//
//	if (str1 == str2)
//	{
//		printf("str1 and str2 are the same\n");
//	}
//	else
//	{
//		printf("str1 and str2 are different\n");
//	}
//	if (str3 == str4)
//	{
//		printf("str3 and str4 are the same\n");
//	}
//	else
//	{
//		printf("str3 and str4 are different\n");
//	}*/
//	const char str1[] = "abc";
//	const char str2[] = "abc";
//	//地址不同
//	const char* p1 = "abc";
//	const char* p2 = "abc";
//	//地址相同
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };//整型数组
//	char ch[5] = { 0 };//字符数组
//	int* parr[4];//存放整型指针的数组--指针数组
//	char* pch[5];//存放字符指针的数组--指针数组
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	int* arr[4] = { &a,&b,&c,&d };
//	int i = 0;
//	for ( i = 0; i < 4; i++)
//	{
//		printf("%d ", *(arr[i]));
//	}
//	return 0;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for ( i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for ( j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	//char arr1[] = "abcdef";
//	//char arr2[] = "abcdef";
//	//const char* p1 = "abcdef";
//	//const char* p2 = "abcdef";
//	//if (p1==p2)
//	//{
//	//	printf("hehe\n");//两个指针存储地址一样（常量字符串）
//	//}
//	//else
//	//{
//	//	printf("haha\n");
//	//}
//
//	//char arr1[] = "abcdef";
//	//char arr2[] = "abcdef";
//	//const char* p1 = "abcdef";
//	//const char* p2 = "abcdef";
//	//if (arr1==arr2)
//	//{
//	//	printf("hehe\n");
//	//}
//	//else
//	//{
//	//	printf("haha\n");//两个字符数组的地址不同，虽然内部元素相同
//	//}
//	return 0;
//}
//int main()
//{
//	/*char str1[] = "ooo";
//	char str2[] = "www";
//	strcat(str1, " ");
//	strcat(str1, str2);
//	printf("str1=%s\n", str1);*/
//	return 0;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for ( i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for ( j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//数组指针：
//数组指针定义：
// 数组指针是指针，是能够指向数组的指针
//
//int main()
//{
//	//int* p = NULL;//整型指针--指向整型的指针--可以存放整形的地址
//	//char* pc = NULL;//字符指针--指向数组的指针--可以存放数组的地址
// //       			//数组指针--指向数组的指针--存放数组的地址
//	//int arr[10] = { 0 };
//	////arr-首元素地址
//	////&arr[10]-首元素的地址
//	////&arr—数组的地址
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;//数组的地址要存起来--p是一个数组指针，指向一个数组
//
//	return 0;
//}

//int main()
//{
//	char* arr[5];
//	char* (*pa)[5] = &arr;//pa--指针变量名 ，*说明pa是指针
//	int arr2[10] = { 0 };
//	int (*pa2)[10] = &arr2;//&arr表示的是定义一个指针，存入数组的地址，而不是数组首元素的地址
//	return 0;
//}
//int main()
//{
//	/*int arr[10] = { 1,2,3,4,5,6,7,8,9,10};
//	int(*pa)[10] = &arr;
//	int i = 0;
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d ",(*pa)[i]);
//		printf("%d ", *(*pa + i));
//
//	}*///数组指针可以这么使用，但不需要
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}//更为方便实用
//	return 0;
//}

//参数是数组的形式
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for ( i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
////参数是指针的形式
//void print2(int(*p)[5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			/*printf("%d ", *(*(p + i) + j));*/
//			printf("%d ", p[i][j]);//*(p+i)==p[i];*(*(p+i)+j)==p[i][j]
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print1(arr, 3, 5);//arr-数组名--首元素地址
//	//把arr想成一维数组
//	printf("\n");
//	print2(arr, 3, 5);
//	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int i = 0;
//	//int* p = arr;
//	//for ( i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", p[i]);
//	//	printf("%d ", *(p + i));
//	//	printf("%d ", *(arr + i));
//	//	printf("%d ", arr[i]);//arr[i]==*(arr+i)==*(p+i)==p[i]
//	//}
//	return 0;
//}


//int main()
//{
//	//字符指针：
//	char ch = 'w';
//	char* p = &ch;
//	const char *p2 = "abcdef";//常量字符串
//	//指针数组--数组--存放指针的数组：
//	int* arr[10];
//	char* ch[5];
//	//数组指针：
//	//int* p1;//整型指针--指向整型的指针
//	//char* p2;//字符指针--指向字符的
//
//	int arr2[5];//数组
//	int(*pa)[5] = &arr2;//取出数组的地址，pa就是一个数组指针
//
//	int(*parr3[10])[5];//数组指针的数组
//	return 0;
//}
