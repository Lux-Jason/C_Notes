#include<stdio.h>

 //规避野指针：
//1.指针初始化
//2.注意指针越界
//3.指针指向空间释放及时置为NULL
//4.指针使用之前检查有效性
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	//未初始化的指针变量--一种野指针
//	int* p = NULL;//一个局部变量不初始化。里面放的是随机值,NULL-用来初始化指针，给指针赋值为0
//	*pa = 20;
//	pa = NULL;//设置为空指针
//	/*if (pa!=NULL)
//	{
//		
//	}*///确定指针不用为空时，再执行后续程序
//
//	return 0;
//}
//
//
///指针运算：
//指针+-整数
//指针-指针
//指针的关系运算
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;//指针加整数
//	for ( i = 0; i < sz; i++)
//	{
//		printf("%d\n", *p);
//		p ++;
//	}
//	return 0;
//}
//
//#define N_VALUES 5
//int main()
//{
//	float values[N_VALUES];
//	float* vp;
//	for (vp = &values[0]; vp < &values[N_VALUES]; )
//	{
//		*vp++;
//	}
//	return 0;
//}
// **C语言标准规定：
// *允许指向数组元素的指针与指向数组最后一个元素后面那个内存位置的指针比较，但是不允许与指向第一个元素之前的那给内存位置的指针进行比较*
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	char ch[5] = { 0 };
//	printf("%d\n", &arr[10] - &arr[2]);//中间元素个数
//	printf("%d\n", &arr[1] - &arr[8]);//中间元素个数的相反数
//	//printf("%d\n", &arr[9] - &ch[0]);//绝对错误写法，无价值
//	return 0;
//}

//int my_strlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while (*end!='\0')
//	{
//		end++;
//	}
//	return end - start;//两指针相减
//}
//int main()
//{
//	//strlen--求字符串长度
//	//递归：模拟实现strlen--1.计数器方式；2.递归方式
//	char ch[] = "bit";
//	int len = my_strlen(ch);
//	printf("%d\n", len);
//	return 0;
//}
//
//
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;//数组可以通过指针被访问
//	int i = 0;
//	for ( i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%p ====== %p\n", p + i, &arr[i]);//两种方法所指数组内容完全一样
//	}for ( i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}


//二级指针：
//指针变量的地址就是二级指针
//int main()
//{
//	int a = 0;
//	int* pa = &a;
//	int** ppa = &pa;//ppa就是二级指针
//	**ppa = 290;
//	printf("%d\n%d\n%d\n%d\n", pa, ppa, *pa, **ppa);
//	return 0;
//}
//
//
//数组指针（本质为指针）--指向数组地址
//指针数组（本质为数组）--存放指针的数组
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	//int* pa = &a;
//	//int* pb = &b;
//	//int* pc = &c;//存放过程较麻烦
//	//整型数组--存放整型
//	//字符数组--存放字符
//	//指针数组--存放指针
//
//	/*int arr[10];*/
//	int* arr[3] = { &a,&b,&c };//指针数组
//	              //0   1  2
//			   // i:
//	int i = 0;
//	for ( i = 0; i < 3; i++)
//	{
//		printf("%d\n", * (arr[i]));//打印三个整型值
//	}
//	return 0;
//}