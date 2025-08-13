#include<stdio.h>
//操作符分类：
//算数操作符
//移位操作符
// 位操作符
// 赋值操作符
// 单目操作符
// 关系操作符
// 逻辑操作符
// 条件操作符
// 逗号表达式
//下标引用，函数调用和结构成员

//int main()
//{
//	int a = 5 / 2;//商2余1，
//	printf("a=%d\n", a);
//	return 0;
//}
//移位操作符：
//int main()
//{
//	int a = 16;
//	//右移操作符:
//	// 1.算术右移：右边丢弃，左边补符号位
//	// 2.逻辑右移：右边直接丢弃，左边直接补“0”
//	//移动的是二进制位
//	//00000000000000000000000000010000
//	//00000000000000000000000000001000
//	int b = a >> 1;
//	int c = -1;
//	int d = c >> 1;
//	printf("%d\n%d\n", b, d);
//	return 0;
//}
//int main()
//{
//	int a = -1;
//	//整数的二进制表示有：原码，反码，补码
//	//存储到内存的是补码
//	//移位的也是补码
//	int b = a >> 2;
//	printf("%d\n", b);
//	return 0;
//}
//int main()
//{
//	int a = 5;
//	int b = a << 1;
//	//00000000000000000000000000000101
//	//00000000000000000000000000001010 (b=a*2)
//	printf("%d", b);
//	return 0;
//}
//注意：对于移位操作符，不要移动负数位，这种操作未定义
//只能作用于整数，浮点数定义不同

//按位与：
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a & b;
//	//00000000000000000000000000000011
//	//00000000000000000000000000000101
//	//00000000000000000000000000000001
//	printf("%d\n", c);//1
//	return 0;
//}
//按位或：
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a|b;
//	//00000000000000000000000000000011
//	//00000000000000000000000000000101
//	//00000000000000000000000000000111
//	printf("%d\n", c);//7
//	return 0;
//}
//按位异或：
//int main()
//{
//	//按二进制位异或
//	//相同为0，相异为1
//	int a = 5;
//	int b = 3;
//	int c = a ^ b;
//	//00000000000000000000000000000011
//	//00000000000000000000000000000101
//	//00000000000000000000000000000110
//	printf("%d\n", c);//6
//	return 0;
//}
//在不创建临时变量的情况下，交换两个数的值:
//int main()
//{
//	/*int a = 3;
//	int b = 5;
//	int tmp = 0;
//	printf("before:a=%d b=%d\n", a, b);
//	tmp = a;
//	a = b;
//	b = tmp;
//	printf("after:a=%d b=%d\n", a, b);*/
//
//	//int a = 3;
//	//int b = 5;
//	//a = a + b;
//	//b = a - b;
//	//a = a - b;
//	//printf("after:a=%d b=%d\n", a, b);//有缺陷，有丢失二进制位的可能，或数据溢出
//
//	////异或方法：
//	//int a = 3;
//	//int b = 5;
//	//a = a ^ b;
//	//b = a ^ b;
//	//a = a ^ b;
//	//printf("a=%d b=%d\n", a, b);//可读性差，效率低
//	
//	//编写代码实现：求一个整数存储在内存中的二进制中1的个数
//	//32bit
//	//00000000000000000000000000000011
//	//00000000000000000000000000000001
//	//00000000000000000000000000000000
//	//统计num补码中有几个1
//
//	int num = 0;
//	int count = 0;
//	scanf("%d", &num);//-1
//	int i = 0;
//	for ( i = 0; i < 32; i++)
//	{
//		if (1 == ((num >> i) & 1))
//			count++;
//	}
//	printf("%d", count);
//	
//	return 0;
//}

//赋值操作符
//""="--赋值
//复合赋值操作符
//int main()
//{
//	int a = 10;
//	a = a + 2;
//	a += 2;//复合赋值
//
//	a = a >> 1;
//	a >>= 1;
//
//	a = a & 1;
//	a &= 1;
//	//......
//	return 0;
//}

//单目操作符
//! - + & sizeof ~ -- ++ *
//int main()
//{
//	int a = 0;
//	if (a)//a为真
//	{
//		printf("hehe\n");
//	}
//	if (!a)//a为假
//	{
//		printf("haha\n");
//	}
//	return 0;
//}
//int main()
//{
//	int a = -5;
//	a = -a;
//	return 0;
//}
//取地址操作符
//int main()
//{
//	int a = 0;
//	int* p = &a;
//	*p=20;//解引用操作符
//	return 0;
//}

//sizeof
//int main()
//{
//	int a = 10;
//	char c = 'c';
//	char* p = &c;
//	int arr[10] = { 0 };
//	//sizeof单位是字节，计算变量所占内存空间的大小
//	printf("%d\n", sizeof(a));//4
//	printf("%d\n", sizeof(int));//4
//
//	printf("%d\n", sizeof(c));//1
//	printf("%d\n", sizeof(char));//1
//
//	printf("%d\n", sizeof(p));//8
//	printf("%d\n", sizeof(char*));//8
//
//	printf("%d\n", sizeof(arr));//40
//	printf("%d\n", sizeof(int[10]));//40
//
//	return 0;
//}
//int main()
//{
//	short s = 0;
//	int a = 10;
//	printf("%d\n", sizeof(s = a + 5));//2
//	printf("%d\n", s);//0
//	return 0;
//}
//int main()
//{
//	//int a = 11;
//	//printf("%d\n",~a );
//	////~按（二进制）位取反
//	////00000000000000000000000000000000
//	////11111111111111111111111111111111--补码
//	////10000000000000000000000000000001--原码
//	////~a=-1
//
//	int a = 11;
//	a = a | (1 << 2);
//	printf("%d\n", a);//15
//	a = a & (~(1 << 2));
//	printf("%d\n", a);//11
//	return 0;
//}

//++;--
//前置：先使用，后++
//后置：先使用，后--

//强制类型转换（不建议使用）
//int main()
//{
//	int a = (int)3.14;//会导致数据丢失
//	printf("%d", a);//3
//	return 0;
//}

//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr));
//}
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr));//40
//	printf("%d\n", sizeof(ch));//10
//	//数组传参过程，传入的是数组的首元素地址
//	test1(arr);//8
//	test2(ch);//8
//	//x64位为8，x32位为4
//	return 0;
//}

//逻辑操作符
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a && b;
//	printf("%d\n", c);//1
//	int x = 0;
//	int y = 5;
//	int d = x || y;
//	printf("%d\n", d);//1
//	int m = 0;
//	int n = 0;
//	int q = m || n;
//	printf("%d\n", q);//0
//	return 0;
//}
//int main()
//{
//	//int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ || ++b || d++;
//	//printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);
//	////1 2 3 4 
//	//int i = 0, a = 1, b = 2, c = 3, d = 4;
//	//i = a++ || ++b || d++;
//	//printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);
//	////2 2 3 4
//	//int i = 1, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ || ++b || d++;
//	//printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);
//	////1 3 3 4
//
//	//int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++;
//	//printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);
//	////1 2 3 4
//	//int i = 0, a = 1, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++;
//	//printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);
//	////2 2 3 5
//	//int i = 1, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++;
//	//printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);
//	////1 2 3 4
//	return 0;
//
//}


//条件操作符
//exp1 ? exp2 : esp3
//int main()
//{
//	int a = 0;
//	int b = 0;
//	/*if (a>5)
//	{
//		b = 3;
//	}
//	else
//	{
//		b = -3;
//	}*///等价于下式
//	b = (a > 5 ? 3 : -3);
//	return 0;
//}
//int amin()
//{
//	int a = 0;
//	int b = 0;
//	int max = 0;
//	/*if (a>b)
//	{
//		max = a;
//	}
//	else
//	{
//		max = b;
//	}*///等价于下式
//	max = (a > b ? a : b);
//	return 0;
//}

//逗号表达式
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = (a > b, a = b + 10, a, b = a + 1);
//
//	if (a = b + 1, c = a / 2, d > 0);
//
//	a = get_val();
//	count_val(a);//未定义函数
//	while (a>0)
//	{
//		a = get_val();
//		count_val(a);
//	}//等价于下式
//	while (a=get_val(),count_val(a),a>0)
//	{
//		//业务处理
//	}
//	return 0;
//}
// 
// 
//下标引用，函数调用和结构成员
//int main()
//{
//	//一个数组名+一个索引值
//	int a[10] = { 0 };
//	a[4] = 10;
//	1 + 2;
//	return 0;
//}

//int get_max(int x, int y)
//{
//	return x > y ? x : y;
//}
//int main()
//{
//	int a = 30;
//	int b = 20;
//	//调用函数时的（）就是函数调用操作符
//	// 操作数至少有一个 就是函数名，传参时还有参数
//	int max = get_max(a, b);
//	printf("max=%d\n", max);
//	return 0;
//}

//表示一个类型--学生
	//创建一个结构体类型-struct Stu
//struct Stu
//{
//	char name[20];
//	int age;
//	char id[20];
//};
//int main()
//{
//	int a = 10;
//	//使用struct Stu这个类型创建了一个学生对象s1，并初始化
//	struct Stu s1 = { "stu",20,"2019010305" };
//	struct Stu* ps= &s1;
//	printf("%s\n", ps->name);
//	printf("%d\n", ps->age);
//	printf("%s\n", ps->id);
//	//结构体指针操作符
//	printf("%s\n", s1.name);
//	printf("%d\n", s1.age);
//	printf("%s\n", s1.id);
//
//	return 0;
//}

//struct Min
//{
//	char name[10] = { '0'};
//	int grade = 0;
//	char id[20] = { '0'};
//};
//int main()
//{
//	struct Min min1 = { "std",30,"3029813" };
//	printf("%s\n", min1.name);
//
//	return 0;
//}

//表达式求值

//隐式类型转换
//c的整型算数运算总是至少以缺省整型类型的精度来进行的。
//为了获得这个精度，表达式中的字符和短整形操作数在使用之前被转换为普通整型，这种转换称为整型提升。
//int main()
//{
//	char a = 3;//(字节截断）
//	//000000000000000000000000
//	// a=00000011
//	char b = 127;
//	//000000000000000000000000
//	// 01111111=b
//
//	//整型提升是按照变量的数据类型的符号位来提升的
//	char c = a + b;
//	//a和b如何相加
//	//00000000000000000000000000000011
//	//00000000000000000000000001111111
//	//00000000000000000000000010000010
//	//10000010->c
//	//11111111111111111111111110000010-补码
//	//11111111111111111111111110000001-反码
//	//10000000000000000000000001111110-原码
//	printf("%d\n", c);
//	return 0;
//}
//int main()
//{
//	char a = 0xb6;
//	//10110110
//	short b = 0xb600;
//	//存在整型提升
//
//	int c = 0xb6000000;
//	if (a==0xb6)
//	{
//		printf("a\n");
//	}
//	if (b == 0xb600)
//	{
//		printf("b\n");
//	}
//	if (c == 0xb6000000)
//	{
//		printf("c\n");
//	}
//	return 0;
//}
//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c));//1
//	printf("%u\n", sizeof(+c));//4
//	printf("%u\n", sizeof(!c));//1
//	return 0;
//}
//算术转化
//若某个操作符的各个操作数属于不同的类型，那么除非其中一个操作数转换为另一个操作数的类型，否则操作就无法进行。
//
//操作符的属性
//1.操作符的优先级
//2.操作符的结合性
//3.是否控制求和顺序
// 
//问题代码：
//int fun()
//{
//	static int count = 1;
//	return ++count;
//}
//int main()
//{
//	int answer;
//	answer = fun() - fun() * fun();
//	printf("%d\n", answer);
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	int a = (++i) + (++i) + (++i);
//	printf("a=%d\n", a);//12(Linux中为10)
//	return 0;
//}