#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//int main()
//{
//	int n = 0;
//	char ch = 'a';
//	int arr[10] = { 0 };//申请内存空间已经固定，不变
//	//可能开辟的空间小或者大了，但无法改变
//	return 0;
//}

//动态内存分配，涉及四个函数：malloc和free,calloc,realloc

//int main()
//{
//	//void* p = malloc(40);//malloc只知道申请多大空间，但不知道会放什么类型的数据，所以malloc只能返回void*的指针
//	//int* p = (int*)malloc(10*sizeof(int));//若数值过大，则会开辟失败
//	int* p = (int*)calloc(10, sizeof(int));
//	//40Bytes
//	//若malloc开辟失败，则返回空指针，所以要对返回值做检查
//	if (p == NULL)
//	{
//		perror("malloc");//malloc: Not enough space
//		return 1;
//	}
//	int i = 0;
//	//使用
//	/*for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}*/
//	/*for (i = 0; i < 10; i++)
//	{
//		*p = i;
//		p++;
//	}*/
//	for (i = 0; i < 10; i++)
//	{
//		printf("%x ", *(p + i));//malloc:0 1 2 3 4 5 6 7 8 9
//								//(未初始化)
//								//mallloc：cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd
//								//calloc：0 0 0 0 0 0 0 0 0 0（calloc对申请空间直接初始化）
//	}
//	//malloc申请的空间在堆区
//	
//	//空间不够，想要扩大空间--realloc
//	//realloc(p, 20 * sizeof(int));
//	//realloc调整空间失败--返回空指针
//	//如果调整成功，也有两种情况：
//	// 情况1：在已经开辟好的空间后边，没有足够空间直接进行空间的扩大，在这种情况下，realloc会在内存堆区重新找一块空间（满足新的空间的大小需求）
//	// 同时把旧的空间的数据拷贝到新的空间，然后释放旧的空间，同时返回新的空间的起始地址
//	// 
//	// 情况2：在已经开辟好的空间后边，有足够的空间，直接进行扩大
//	// 直接返回旧的空间的起始地址
//	int* ptr = (int*)realloc(p, 20 * sizeof(int));
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//	else
//	{
//		perror("realloc");
//		return 1;
//	}
//	//realloc除了能调整空间，还能实现和malloc一样的功能
//
//	//释放空间：
//	//void free(void* ptr);--如果参数ptr指向的空间不是动态开辟的，那free函数的行为是未定义的
//	//如果参数ptr是NULL指针，则函数什么事都不做
//	//malloc和free的声明都在<stdlib.h>头文件中
//	free(p);
//	p = NULL;//防止p变为野指针
//	return 0;
//}

//realloc和malloc可以等价
//int main()
//{
//	int* p = (int*)realloc(NULL, 40);//第一个参数为空指针，则可以等价于malloc
//	free(p);
//	p = NULL;
//	return 0;
//}

//常见动态开辟的错误：
//1.对空指针进行操作
//int main()
//{
//	int* p = (int*)malloc(100);
//	*p = 20;//p有可能为空指针
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	*p = 20;
//	free(p);
//	p = NULL;
//	return 0;
//}

//2.对动态开辟空间的越界访问
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;//当循环到第十一次时，就越界访问了
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//3.对非动态开辟内存使用free释放
//int main()
//{
//	int a = 0;
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	p = &a;//p指向的空间不再是堆区上的空间
//	free(p);//此时释放会造成程序崩溃
//	p = NULL;
//	return 0;
//}

//malloc/calloc/realloc申请的空间
//如果不主动释放，出了作用域是不会销毁的
// 
//释放的方式：
//1.free主动释放
//2.直到程序结束才由操作系统回收

//int* test()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("malloc");
//		return NULL;
//	}
//	else
//	{
//		return p;
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}

//4.使用free释放动态开辟空间的一部分
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	p++;
//	free(p);
//	p = NULL;
//	return 0;
//}

//5.对同一块动态内存的多次释放
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	free(p);
//	p = NULL;//若即使将p设置为空指针，则重复释放也不会造成问题
//	free(p);
//	p = NULL;
//	return 0;
//}

//6.动态内存忘记释放（内存泄漏）
//void test()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return;
//	}
//	else
//	{
//		*p = 20;
//		return;//若提前结束，则无法释放
//	}
//
//	free(p);
//	p = NULL;
//
//}
//int main()
//{
//	test();
//	while (1);
//	return 0;
//}
// 
// 找错：
//#include<string.h>
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return;
//	}
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "Hello World");//对NULL指针解引用操作，程序崩溃
//	printf(str);//没问题
//}
//int main()
//{
//	Test();
//	return 0;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%s\n", arr);
//	printf("abcdef\n");
//	printf(arr);
//	return 0;
//}
//1.GetMemory函数采用值传递的方式，无法将maloc开辟空间地址，返回放在str中，调用结束后str依然是NULL指针
//2.strcpy中使用了str，就是对NULL指针解引用操作，程序崩溃
//3.内存泄漏

//修改：
//#include<string.h>
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return;
//	}
//}
//char* GetMemory2(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "Hello World");//对NULL指针解引用操作，程序崩溃
//	printf(str);//没问题
//	free(str);
//	str = NULL;
//
//	printf("\n");
//
//	char* str2 = NULL;
//	str2 = GetMemory2(str2);
//	strcpy(str2, "hello world");
//	printf(str2);//没问题
//	free(str2);
//	str2 = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//char* GetMemory(void)
//{
//	char p[] = "hello world";//局部数组，只在函数内部，出函数就销毁
//	return p;//返回数组起始地址
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();//返回后的p就是野指针
//	printf(str);//烫烫烫--未初始化的打印值
//}
//int main()
//{
//	Test();
//	return 0;
//}
//#include<string.h>
//void GetMemory(char** p,int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);//malloc申请的空间没有释放
//	//补加：
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//#include<string.h>
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	//此处的str就是野指针，但没有置为空指针
//	if (str!=NULL)
//	{
//		strcpy(str, "world");//非法访问
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}

//柔性数组：
//在C99中，结构体的最后一个元素允许是未知大小的数组，这就叫做“柔性数组”成员。
//struct st_type
//{
//	int i;
//	char c;
//	//int a[0];//有些编译器可能报错
//	int b[];//特点：
//	//1.前面必须至少有一个其他成员
//	//2.sizeof返回的这种结构大小不包括柔性数组的内存
//	//3.包括柔性数组成员的结构用malloc函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小
//};
//struct St
//{
//	char c;
//	int n;
//	int arr[0];
//};
//int main()
//{
//	printf("%d\n", sizeof(char));//1
//	printf("%d\n", sizeof(int));//4
//	printf("%d\n", sizeof(St));//8字节
//	struct St* ps =(struct St*) malloc(sizeof(struct St) + 10 * sizeof(int));
//	if (ps == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	ps->c = 'w';
//	ps->n = 100;
//	for (int i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	//数组空间不够
//	struct St* ptr = (struct St*)realloc(ps, sizeof(struct St) + 15 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps = ptr;
//		for (int i = 0; i < 10; i++)
//		{
//			printf("%d ", ps->arr[i]);//0 1 2 3 4 5 6 7 8 9
//		}
//		printf("\n");
//		printf("%c\n", ps->c);//w
//		printf("%d\n", ps->n);//100
//	}
//	else
//	{
//		perror("realloc");
//		return 1;
//	}
//	
//	free(ps);
//	ps = NULL;
//	return 0;
//}

struct St
{
	char c;
	int n;
	int* arr;
};
int main()
{
	struct St* ps = (struct St*)malloc(sizeof(struct St));
	if (ps == NULL)
	{
		perror("malloc");
		return 1;
	}

	ps->c = 'w';
	ps->n = 100;
	ps->arr = (int*)malloc(10 * sizeof(int));
	if (ps->arr == NULL)
	{
		perror("malloc-2");
		return 1;
	}
	//使用：
	int i = 0;
	for ( i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	//数组空间不够：
	int* ptr = (int*)realloc(ps->arr, 15 * sizeof(int));
	if (ptr == NULL)
	{
		perror("realloc");
		return 1;
	}
	else
	{
		ps->arr = ptr;
	}
	//使用：
	for ( i = 0; i < 15; i++)
	{
		ps->arr[i] = i;
	}

	for (i = 0; i < 15; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
	printf("%c\n", ps->c);
	printf("%d\n", ps->n);
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}
