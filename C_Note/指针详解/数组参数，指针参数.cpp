#include<iostream>
using namespace std;
//数组参数，指针参数：
//将数组或指针传给函数的设计

//一维数组
//void test(int arr[3][5])
//{
//
//}
//void test2(int (*arr)[][5])
//{
//
//}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);//二维数组传参
//	return 0;
//}

//void print(int* p, int sz)
//{
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(p,sz);
//	return 0;
//}

//一级指针传参：
//void test1(int* p)
//{
//
//}
//void test2(char* pch)
//{
//
//}
//int main()
//{
//	int a = 10;
//	int* p1 = &a;
//	test1(&a);
//	test1(p1);
//	char ch = 'w';
//	char* pch = &ch;
//	test2(&ch);
//	test2(pch);
//	return 0;
//}
//二级指针传参：
//void test(int** ptr)
//{
//	printf("num=%d\n", **ptr);
//}
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	int** pp = &p;
//	test(pp);
//	test(&p);
//	return 0;
//}
//void test(char** p)
//{
//
//}
//int main()
//{
//	char c = 'b';
//	char* pc = &c;
//	char** ppc = &pc;
//	char* arr[10];
//	test(&pc);
//	test(ppc);
//	test(arr);//都可以被接收
//	return 0;
//}

//函数指针：
// 对比：
//  数组指针--指向数组的指针
//  函数指针--指向函数的指针
//int ADD(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 30;
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;
//
//	int c = ADD(a, b);//调用函数
//	printf("%d\n", c);
//
//	printf("%d\n", ADD(a, b));
//	//&函数名和函数名都是函数地址
//	/*printf("%d\n", &ADD);
//	printf("%d\n", ADD);*/
//	//int* pa(int, int) = ADD;//pa是函数名，不能做指针
//
//
//	int (*pa)(int, int) = ADD;//pa是指针（与数组指针类似）
//	printf("%d\n", (*pa)(2, 3));//5--推论正确
//	//函数指针--存放函数地址的一个指针
//	return 0;
//}
//void print(const char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	void (*p)(const char*) = print;//函数指针--void(*)()函数指针类型
//	(*p)("helo world");//函数指针传参--赋值常量
//	return 0;
//}
//void signal(int x)
//{
//
//}
//int main()
//{
//	//(*(void(*)())0)()--把0强制类型转换成：void
//	//调用0地址处的该函数
//	void (*signal(int, void(*)))(int);//signal--函数名，void（*）（int）--函数指针类型
//	 
//	return 0;
//}
// 
// signal是一个函数声明
// signal函数的参数有两个，第一个是int，第二个是函数指针，该函数指针指向的函数的参数是int，返回值是void
// signal函数的返回值类型也是一个函数指针：该函数指针指向的函数的参数是int，返回类型是void                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
//void(*           signal(int, void(*)(int)/*两个参数--一个整型一个函数指针*/))(int);//函数返回类型是整型
////简化：
//typedef void(* pfun_t/*给函数指针类型重起名*/)(int);  
//typedef unsigned int uint/*对unsigned int重起名*/;
//pfun_t signal(int, pfun_t);
////简化前提是要理解typedef重命名函数的结果是括号内的pfun_t，类型为函数指针类型

//int ADD(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int(*pa)(int, int) = ADD;
//	printf("%d\n", (pa)(2, 3));//解引用传参
//	//以下方法多此一举：
//	printf("%d\n", (*pa)(2, 3));//解引用调用函数
//	printf("%d\n", (**pa)(2, 3));//
//	printf("%d\n", (***pa)(2, 3));//多次解引用无效
//	return 0;
//}


//函数指针数组：
//int ADD(int x, int y)
//{
//	return x + y;
//}
//int SUB(int x, int y)
//{
//	return x - y;
//}
//int MUL(int x, int y)
//{
//	return x * y;
//}
//int DIV(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int* arr[5];
//	int (*pa)(int, int) = ADD;
//	int(*parr[4])(int, int) = { ADD,SUB,MUL,DIV };//函数指针的数组
//	int i = 0;
//	for ( i = 0; i < 4; i++)
//	{
//		printf("%d\n",parr[i](2, 3));//直接利用指针传参，结果--5 -1 6 0（依次传函数计算）
//	}
//	return 0;
//}

//char* my_strcpy(char* dest, const char* src)
//{
//
//}
////写一个函数指针pf能够指向my_strcpy
////写一个函数指针数组pfarr，能够存放四个my_strcpy函数的地址
//int main()
//{
//	char* (*pf)(char*,const char*) = my_strcpy;
//	char* (*pfarr[4])(char*, const char*) = {my_strcpy,my_strcpy ,my_strcpy ,my_strcpy };
//	return 0;
//}
// 
// 
// 
////函数指针数组的用途：转移表
////案例：计算器
//
//void menu()
//{
//	printf("***************************\n");
//	printf("*****1.add       2.sub*****\n");
//	printf("*****3.mul       4.div*****\n");
//	printf("*****5.xor       0.exit****\n");
//	printf("***************************\n");
//}
//int ADD(int x, int y)
//{
//	return x + y;
//}
//int SUB(int x, int y)
//{
//	return x - y;
//}
//int MUL(int x, int y)
//{
//	return x * y;
//}
//int DIV(int x, int y)
//{
//	return x / y;
//}
//int XOR(int x, int y)
//{
//	return x ^ y;
//}
////int main()
////{
////	int input = 0;
////	int x = 0;
////	int y = 0;
////	//pfarr是一个函数指针数组--转移表
////	int (*pfarr[6])(int, int) = { 0,ADD,SUB,MUL,DIV,XOR };
////	do
////	{
////		menu();
////		printf("请选择:>");
////		scanf("%d", &input);
////		if (input >= 1 && input <= 5)
////		{
////
////			printf("请输入操作数:>");
////			scanf("%d %d", &x, &y);
////			int ret = pfarr[input](x, y);
////			printf("%d\n", ret);
////		}
////		else if (input == 0)
////		{
////			printf("exist\n");
////		}
////		else
////		{
////			printf("illegal chosen\n");
////		}
////
////
////		/*switch (input)
////		{
////		case 1:
////			printf("请选择两个操作数:>");
////			scanf("%d %d", &x, &y);
////			printf("%d\n", ADD(x, y));
////			break;
////		case 2:
////			printf("请选择两个操作数:>");
////			scanf("%d %d", &x, &y);
////			printf("%d\n", SUB(x, y));
////			break;
////		case 3:
////			printf("请选择两个操作数:>");
////			scanf("%d %d", &x, &y);
////			printf("%d\n", MUL(x, y));
////			break;
////		case 4:
////			printf("请选择两个操作数:>");
////			scanf("%d %d", &x, &y);
////			printf("%d\n", DIV(x, y));
////			break;
////		case 0:
////			printf("exit\n");
////			break;
////		default:
////			printf("illegal chosen\n");
////			break;
////		}*/
////	} while (input);
////	return 0;
////}
//
///*switch (input)
//		{
//		case 1:
//			printf("请选择两个操作数:>");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", ADD(x, y));
//			break;
//		case 2:
//			printf("请选择两个操作数:>");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", SUB(x, y));
//			break;
//		case 3:
//			printf("请选择两个操作数:>");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", MUL(x, y));
//			break;
//		case 4:
//			printf("请选择两个操作数:>");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", DIV(x, y));
//			break;
//		case 0:
//			printf("exit\n");
//			break;
//		default:
//			printf("illegal chosen\n");
//			break;
//		}*/
////简化（解决代码冗余问题）：
//// 回调函数：回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个函数，
//// 当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现方直接调用，
//// 而是在特定事件或条件发生时由另外一方调用的，用于对该事件或条件进行响应。
//
//void CALC(int (*pf)(int,int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请选择两个操作数:>");
//	scanf("%d %d", &x, &y);
//	printf("%d\n", pf(x, y));
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			CALC(ADD);
//			break;
//		case 2:
//			CALC(SUB);
//			break;
//		case 3:
//			CALC(MUL);
//			break;
//		case 4:
//			CALC(DIV);
//			break;
//		case 0:
//			printf("exit\n");
//			break;
//		default:
//			printf("illegal chosen\n");
//			break;
//		}
//	} while (input);
//}


//指向函数指针数组的指针：
// 指向函数指针数组的指针是一个指针，指针指向一个数组，数组的元素都是函数指针。
//int main()
//{
//	int arr[10] = { 0 };
//	int (*p)[10] = &arr;//取出数组的地址
//	int (*pfArr[4])(int, int);;//pfarr是一个数组--函数指针的数组
//	int (*(*ppfArr)[4])(int,int) = &pfArr;//ppfArr是一个数组指针，指针指向的数组有四个元素
//	//									  //指向的数组的每个元素的类型是一个函数指针 int(*)(int,int)
//
//	return 0;
//}

//冒泡排序函数
//只能排序整型数组
//void BubbleSort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	for ( i = 0; i < sz-1; i++)
//	{
//		for (j = 0; j < sz - 1; j++)
//		{
//			if (arr[j] > arr[j+1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = {1,6,3,5,2,76,2,7,23};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr,sz);
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	//指针数组：
//	int* arr[10];
//	//数组指针：
//	int* (*pa)[10] = &arr;
//	//函数指针：
//	int (*pAdd)(int, int) = Add;//&Add
//	int sum = (*pAdd)(1, 2);
//	int sum = pAdd(1, 2);
//	//函数指针的数组：
//	int (*pArr[5])(int, int);
//	//指向函数指针的数组的指针：
//	int(*(*ppArr)[5])(int, int) = &pArr;
//	return 0;
//}

////qsort--可以排序任意类型的数据:
//#include<stdio.h>
//# include<string.h>
//
//void Bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for ( i = 0; i < sz-1; i++)
//	{
//		int j = 0;
//		for ( j = 0; j < sz-1; j++)
//		{
//			if (arr[j]>arr[j+1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
////void qsort(void* base,
////		   size_t num, 
////		   size_t width, 
////		   int(__cdecl* compare)(const void* elem1, const void* elem2)
////		   ); 
//int cmp_int(const void* e1,const void* e2)
//{
//	//比较了两个整型值的
//	return *(int*)e1 - *(int*)e2;
//}
//int cmp_float(const void* e1, const void* e2)
//{
//	/*if (*(float*)e1 > *(float*)e2)
//	{
//		return 1;
//	}
//	else if (*(float*)e1 == *(float*)e2)
//	{
//		return 0;
//	}
//	else
//	{
//		return  -1;
//	}*/
//
//	return *(float*)e1 - *(float*)e2;
//}
//
//void test1()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz1 = sizeof(arr) / sizeof(arr[0]);
//	struct Stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
//	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0 };
//	//Bubble_sort(arr, sz1);
//	//Bubble_sort{ f,sz2 };//这种方法只能排序整型数组
//	qsort(arr, sz1, sizeof(arr[0]), cmp_int);//
//	int i = 0;
//	for (i = 0; i < sz1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void test2()
//{
//	float f[] = { 1.0,2.0,9.0,8.0,7.0,3.0,4.0,6.0,5.0 };
//	int sz = sizeof(f) / sizeof(f[0]);
//	qsort(f, sz, sizeof(f[0]), cmp_float);
//	int j = 0;
//	for ( j = 0; j < sz; j++)
//	{
//		printf("%f ", f[j]);
//	}
//}
//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);//利用strcmp函数比较两个字符串的大小（也可以利用strcmp比较两个字符串的长度
//}
//void test3()
//{
//	struct Stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//	int j = 0;
//	for ( j = 0; j < sz; j++)
//	{
//		printf("%d ", s->age);
//	}
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		printf("%s ", s->name);
//	}
//}
// 
//int main()
//{
//	test1();
//	test2();
//	test3();
//	return 0;
//}
////
////qsort--库函数--排序
//// 第一个参数：待排序数组的首元素地址
//// 第二个参数：待排序数组的元素个数
//// 第三个参数：待排序数组的每个元素大小--单位是字节
//// 第四个参数：是函数指针--比较两个元素的函数的地址--这个函数由使用者自己实现
////                                                   函数指针两个参数是：待比较的两个元素的地址


