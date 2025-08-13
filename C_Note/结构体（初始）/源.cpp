#include<stdio.h>
#include<iostream>
//结构体：
// 1.类型声明
//2.初始化
//3.成员访问
//4.传参
//结构：
//结构是一些值的集合，这些值被称为成员变量。结构的每个成员可以是不同类型的变量。

//结构的声明：
//struct tag
//{
//	member - list;
//
//
//}variable -  ist;(变量列表）

//struct--结构体关键字；Stu--结构体标签；struct Stu--结构体类型
//定义一个结构体类型：（不占据内存空间）
//struct Stu
//{
//	//描述一个学生：
//	char name;
//	char sex[5];
//	int age;
//	char tel[12];
//}S1, S2, S3;//三个全局的结构体变量（尽量少用）
//typedef struct Stu//重新起名
//{
//	char name;
//	char sex[5];
//	int age;
//	char tel[12];
//}Stu;//struct Stu-->Stu
//int main()
//{
//	struct Stu S1;//S占有内存空间（局部变量）
//	Stu S2;
//	return 0;
//}
//结构体成员可以是任何类型的变量
//结构体变量的定义及初始化：
//struct Point
//{
//	int a;
//	char c;
//	char arr[20];
//	double d;
//};
//typedef struct Stu//重新起名
//{
//	char name[10];
//	char sex[7];
//	int age;
//	char tel[12];
//	struct Point P;
//	char* pc;
//}Stu;
//void Print2(struct Point* ps)
//{
//	printf("%d ", ps->a);
//	printf("%s ", ps->c);
//	printf("%s ", ps->arr[20]);
//	printf("%lf", ps->d);
//	printf("\n");
//}
//void Print1(Stu tmp1)
//{
//	printf("name=%s\n", tmp1.name);
//	printf("sex=%s\n", tmp1.sex);
//	printf("age=%d\n", tmp1.age);
//	printf("tel=%s\n", tmp1.tel);
//	printf("%s\n", tmp1.pc);
//}
//int main() 
//{
//	char arr[] = "hello bit\n";
//	Stu S1 = { "John","male",20,"5764975" };//局部变量
//	struct Stu S2 = { "Kiky","secret",30,"20391837",{100,'w',"hello world",3.14},arr };
//	/*printf("%s\n", S2.P.arr);*/
//	Print1(S2);
//	return 0;
//}
//桟区：局部变量；函数形参；函数调用开辟空间
//堆区：动态内存分配；malloc/free；realloc；ralloc
//全局区：
// 全局变量区：全局变量；
// 静态变量区：静态变量（static修饰），包括静态局部变量和静态全局变量
// 常量区：字符常量；const修饰的全局变量（常量区数据不可更改）
//
//数据结构：
//1.线性数据结构：
// 顺序表
// 链表
// 栈：先进去的后出，后进去的先出
//   压栈：插入一个元素
//   出栈：删除一个元素
//		结构体传参时，要传结构体地址
// 队列
// 2.树形数据结构：
// 二叉树
// 3.图：
//