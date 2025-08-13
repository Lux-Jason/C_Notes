 #define _CRT_SECERT_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//分支和循环语句
//分支语句：
//  if···else···语句：
//int main()
//{
//	int a = 67;
//	if (a < 20)
//		printf("a");
//	else if (a >= 20 && a < 50)
//		printf("b");
//	else if (a >= 50 && a < 70)
//		printf("c");
//	else
//		printf("d");
//	return 0;
//}
//int main()
//{
//	/*int a = 5;
//	if (5 == a)
//		printf("hehe");*/
//
//		/*int a = 9;
//		int b = 8;
//		if (6 <= a)
//			if (8 == b)
//				printf("hehe");
//			else
//				printf("haha");
//		else
//			printf("heihei");*/
//
//	/*int a = 9;
//	int b = 8;
//	if (10 <= a)
//	{
//		if (0 == b)
//			printf("hehe");
//	}//利用括号使else与第一个if匹配
//	else
//		printf("heihei");*/
//
//	return 0;
//}
//判断一个数是否为奇数
//int main()
//{
//	int a = 5;
//	if (1 == a % 2)
//		printf("a是奇数\n");
//	return 0;
//}
//打印1~100间的奇数
//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		if (1 == i % 2)
//		{
//			printf("i=%d\n",i);
//		}
//		i++;
//	}
//
//	
//	return 0;
//}

//  switch语句：
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);//
//	switch (day)
//	{
//	default:
//		Printf("输入错误\n");
//		break;//输入非法变量的处理
//	case 1://识别变量的赋值
//		printf("星期一");
//		break;//跳出switch语句
//	case 2:
//		printf("星期二");
//		break;
//	case 3:
//		printf("星期三");
//		break;
//	case 4:
//		printf("星期四");
//		break;
//	case 5:
//		printf("星期五");
//		break;
//	case 6:
//		printf("星期六");
//		break;
//	case 7:
//		printf("星期日");
//		break;
//	}
//	
//	return 0;
//}
//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)//以n为入口
//	{
//	case 1:
//		m++;
//	case 2:
//	    n++;
//	case 3:
//		switch (n)//此时n=2，从case2进入
//	//switch允许嵌套使用
//		{
//		case 1:
//			n++;
//		case 2:
//			m++;
//			n++;
//			break;
//		}
//	case 4:
//		m++;
//		break;
//	default:
//		break;
//
//	}
//	printf("m=%d,n=%d\n", m, n);
//	return 0;
//}
//
//
//
//循环语句：
//  while语句：
//int main()
//{
//	/*while (1)
//		printf("haha\n");*///死循环
//
//	int i = 1;
//	while (i<=10)
//	{
//		if (5 == i)
//			//break;//永久结束循环
//			continue;//跳过本次循环后面的代码--下面代码不执行
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}
// 
//int main()
//{
//	int ch = getchar();
//	putchar(ch);//putchar（ch）==printf（"%c\n",ch)
//
//	return 0;
//}//getchar--输入字符；putchar--输出（打印）字符
//int main()
//{
//	int ch = 0;
//	//ctrl+z
//	//EOF==End Of File-> -1
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	return 0;
//
//}
//int main()
//{
//	int ret = 0;
//	char password1[20] = { 0 };
//	char password2[20] = { 0 };
//	int ch = 0;
//	printf("请输入密码:>");
//	scanf("%s", password1);//输入密码，并存放在password数组中
//	//缓冲区剩余一个‘\n'
//	//读取一下'\n'
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//	printf("请确认密码:>");
//	scanf("%s", password2);
//    while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//	if (strcmp( password2,password1)==0)//判断字符类型是否一致
//	{
//		printf("请确认(Y/N):>");
//		ret = getchar();
//		if ('Y' == ret)
//		{
//			printf("确认成功\n");
//		}
//		else
//		{
//			printf("确认放弃\n");
//		}
//	}
//	else
//		printf("密码不一致\n");
//	return 0;
//}
//
//
//for循环：
//int main()
//{
//	int i = 0;
//	//for ( i = 1; i <=10; i++)//初始化；判断；调整
//	//{
//	//	printf("%d\n", i);
//	//}
//	// 
//	for (i = 1; i <= 10; i++)
//	{
//		if (5 == i)
//			continue;//1,2,3,4,6,7,8,9,10
//		   // break;//1,2,3,4
//		printf("%d\n", i);
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for ( i = 0; i < 10; i++)
//	{
//		if (i = 5)//不可在for循环体内部修改变量，防止for循环失去控制
//			printf("hehe\n");
//		printf("haha\n");//陷入死循环
//	}
//	return 0;
// }
//int main()
//{
//	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int i = 0;
//	//for ( i = 0; i < 10; i++)//左闭右开写法
//	//{
//	//	printf("%d\n", arr[i]);
//	//}
//
//	//for (;;) 
//	//	printf("haha");
//	//}//for循环的初始化，判断和调整部分都可以省略
//	////但当省略判断部分，则认为恒为真
//	////不熟练时莫省略代码
//
//	//int i = 0;
//	//int j = 0;
//	//for ( i = 0; i < 10; i++)
//	//{
//	//	//for (; j < 10; j++)
//	//	//{
//	//	//	printf("haha\n");
//	//	//}//打印十次
//	//	//for (j=0; j < 10; j++)
//	//	//	{
//	//	//		printf("haha\n");
//	//	//	}//打印一百次
//	//}
//	int x, y;
//	for (x=0, y= 0; x<2&&y<5; ++x,y++)
//	{
//		printf("haha\n");
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++)//k=0为假
//		k++;//死循环
//	return 0;
//}
//
//
//do...while语句：(至少执行一次）
//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d ", i);
//		i++;
//	} while (i<=10);
//	return 0;//打印1~10
//}
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			continue;//死循环
//		printf("%d\n", i);
//		i++;
//	} while (i <= 10);//跳到判断部分
//	
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			break;//结束代码
//		printf("%d\n", i);
//		i++;
//	} while (i <= 10);
//	//跳出程序，结束代码
//	return 0;
//}

//calculate:n!--一个for或while循环
//for循环：
//int main()
//{
//	int ret = 1;
//	int n = 0;
//	int i = 1;
//	scanf("%d", &n);//限定i的最大值为n
//	for ( i= 1; i<= n; i++)
//	{
//		ret *= i;//i的阶乘=ret=ret*i
//	}
//	printf("%d\n", ret);//本质==计算i的阶乘
//	return 0;
//}
//while循环：
//int main()
//{
//	int ret = 1;
//	int n = 0;
//	int i = 1;
//	scanf("%d" ,&n);
//	while (i <= n)
//	{
//		ret *= i;
//		i++;
//	}
//	printf("%d\n", ret);
//	return 0;
//}
//do...while语句：
//int main()
//{
//	int ret = 1;
//	int n = 0;
//	int i = 1;
//	scanf("%d", &n);
//	do
//	{
//		ret *= i;
//		i++;
//	} while (i <= n);
//	printf("%d\n", ret);
//	return 0;
//}
//递归函数法：
//int Fact(int n);
//int Fact(int n)//递归函数 
//{
//    int res = n;
//    if (n > 1)
//        res = res * Fact(n - 1);
//    return res;
//}
//int main()
//{
//    int n, cnt;
//    scanf("%d", &n);
//    cnt = Fact(n);
//    printf("%d\n", cnt);
//    return 0;
//}

//写一个代码，在arr数组中找到里面的一个数：
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	scanf("%d", &k);
//	for ( i = 0; i < sz; i++)
//	{
//		if (k == arr[i])
//		{
//			printf("找到了,下标是：%d\n",i);
//			break;
//		}
//	}
//	if (i == sz)
//		printf("找不到\n");
//	return 0;
//}
// 
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	int left = 0;//左下标
//	int right = sz-1;//右下标
//	scanf("%d", &k);
//	while (left<=right)//只有满足此条件，说明存在中间元素
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标是：%d\n", mid);
//			break;
//		}//二分查找循环体
//	}
//	if(left>right)//两个元素中间无中间元素
//	{ 
//		printf("找不到");
//	}
//	return 0;//**只找元素，若存在两个一样的元素，也只打印其中一个
//}


// 阶乘运算：
//#define EOF (-1)
//int main()
//{
//	long long a;
//	int i;
//    int x;
//	int n;
//	while (scanf("%d %d", &x, &n) != EOF)
//	{
//		a = 1;
//		for (i = 0; i < n; i++)
//		{
//			a = a * x;
//		}
//		printf("%lld\n", a);
//	}
//	return 0;
//}


//编写代码，演示多个字符从两端移动，向中间汇聚：
//#include<Windows.h>
//#include<stdlib.h>
//int main()
//{
//	//welcome to uic
//	char arr1[] = "welcome to uic";
//	char arr2[] = "##############";
//	int left = 0;
//	//int right = sizeof(arr1) / sizeof(arr1[0]) - 2;//包含/0，麻烦不易理解
//	int right = strlen(arr1) - 1;//简单易理解
//	//将arr1中的元素赋值给arr2
//	while (left<=right)
//	{
//	arr2[left] = arr1[left];
//	arr2[right] = arr1[right];
//	printf("%s\n", arr2);
//	Sleep(1000);
//	system("cls");//执行系统命令的一个函数--cls（清空屏幕）
//	left++;
//	right--;
//	}
//	return 0;
//}


//模拟用户登录情景，且只能登陆三次（输入三次密码，若错误则无法登录）
//int main()
//{
//	char password[20];
//	int i = 0;
//	for ( i = 0; i <3; i++)
//	{
//		printf("请输入密码:>");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("登陆成功\n");
//			break;
//		}
//		
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//
//	if (i >= 3)
//		printf("验证失败\n");
//	return 0;
//}
//.................................................................
//练习：
// 
//编写代码实现三个数从大到小排列：
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d > %d > %d\n", a, b, c);
//		return 0;
//}
//
//求最大公因数--辗转相除法:
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int r = 0;
//	scanf("%d %d", &m, &n);
//	while (r = m % n)
//	{
//		//r = m % n;
//		m = n;
//		n = r;
//	}
//	printf("%d\n", n);
//	return 0;
//}
//
//打印闰年:
//int main()
//{
//	int year = 0;
//	int count = 0;
//	for ( year = 1000; year <=2000; year++)//从1000到2000年的闰年
//	{
//		////能被4整除的非整百年
//		////能被400整除的整百年
//		//if (year % 4 == 0 && year % 100 != 0)
//		//{
//		//	printf("%d ", year);
//		//	count++;
//		//}
//		//else if (year % 400 == 0)
//		//{
//		//	printf("%d ", year);
//		//	count++;
//		//}
//		if (((year%4==0)&&(year%100!=0))||(year%400==0))
//		{
//			printf("%d ", year);
//			count++;
//		}
//
//	}
//	printf("\n总计:%d\n", count);
//	return 0;
//}
//
//打印素数(质数):
//#include <math.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 2; i <= 200; i++)
//	{
//		//素数判断规则
//		//只能被1或本身整除
//		////1.试除法--产生2~i-1的数字(效果较差):
//		//int j = 0;
//		//for (j = 2; j < i; j++)
//		//{
//		//	if (i % j == 0)
//		//	{
//		//		break;
//		//	}
//		//}
//		//if (j == i)
//		//{
//		//	count++;
//		//	printf("%d ", i);
//		//}
//		//2.开平方法(sqrt库函数)(优化):
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j >sqrt (i))
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\n素数有:%d个\n", count);
//	return 0;
//}
//
//计算0~100内含数字"9"的个数:
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for ( i = 0; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		if (i / 10 == 9)
//			count++;
//	}
//	//9,19,29......99-10
//	//90,91,92,......99-10
//	printf("%d\n", count);
//	return 0;
//}
//
//分数求和:
//求1-1/2+1/3-1/4+...+1/99-1/100的值,打印结果
//int main()
//{
//	int i = 0; 
//	double sum = 0.0;
//	int flag = 1;
//	for ( i = 1; i <=100; i++)
//	{
//		sum += flag*1.0 / i;
//		flag = -flag;
//	}
//	printf("sum=%lf\n", sum);
//	return 0;
//}
//
//求最大值:
//求是个整数的最大值
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int max = arr[0];
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz ;i++)
//	{
//		if (arr[i] > max)
//		{
//		 max = arr[i];
//		}
//	}
//	printf("max=%d\n", max);
//	return 0;
//}
//
//打印99乘法表:
//int main()
//{
//	int i = 0;
//	for ( i = 1; i <= 9; i++)
//	{
//		int j = 1;
//		for ( j = 1; j <=i; j++)
//		{
//			printf("%d*%d=%-2d ", j, i, i * j);//%2d表示打印两位,不够两位用空格补齐--%-2d则表示从右到左两位
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//二分查找:
//在一个整型有序数组中查找一个具体的数
//int main()
//{
//	int arr[] = { 1,2,3,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	int left = 0;
//	int right = sz-1;
//	scanf("%d", &k);
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了,下标是:%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//     printf("找不到");
//	}
//	return 0;
//}//写过一次,第394行
//
//猜数字游戏：
//1.电脑随机生成一个数字
//2.猜数字
//#include<stdlib.h>
//#include<time.h>//使用time函数
//void menu()
//{
//	printf("**********************************\n");
//	printf("********1,play      0,exit********\n");
//	printf("**********************************\n");
//}
//void game()
//{
//	//1.生成一个随机数
//	int ret = 0;
//	int guess = 0;//接收猜的数字
//	//拿时间戳来设置随机数的生成起始点
//	//time_t(长整型） time(time_t *time)
//	ret = rand()%100+1;//生成1~100间的随机数
//	//2.猜数字
//	while (1)
//	{
//		printf("请猜数字:>");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了\n");
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对啦！！\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//（强制转换为整型）time（空指针）
//	do
//	{
//		menu(); 
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//
//goto语句--可跳转代码
//易出现bug，应用场景较少
//int main()
//{
//again:
//	printf("hello uic\n");
//	goto again;//跳回到“again”（死循环）
//	return 0;
//}
//应用--关机程序
//#include<Windows.h>//调用system
//#include<iostream>
////#include<string.h>
//int main()
//{
//	//	char input[20] = { 0 };
//	//	//shutdown -s -t 60(cmd命令设置60s后关机）
//	//	system("shutdown -s -t 3600");
//	//again:
//	//	printf("请注意，你的电脑将在1h后关机，如果输入：cancel，取消关机\n请输入:>");
//	//	scanf("%s", input);
//	//	if (strcmp(input,"cancel")==0)
//	//	{
//	//		system("shutdown -a");
//	//	}
//	//	else
//	//	{
//	//		goto again;
//	//	}
//
//	//char ch;
//	//int count = 0;
//	//while (scanf("%c", &ch)&&ch!='\n')//T or F
//	//{
//	//	count += (ch == 'c');
//
//	//}
//
//	//printf("%d", count);
//	float a = 10.56;
//	int b = a;
//	printf("%d\n", b);
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define max_times 3
//
//struct login {
//    char user_name[50]; //用户名
//    char password[50];  // 密码
//};
//
//int main() {
//    char username[50];
//    char password[50];
//    int times;
//
//    // 打开文件并读取
//    FILE* file = fopen("account.txt", "r");
//    if (file == NULL) {
//        printf("File not found.\n");
//        return 1;
//    }
//
//    for (times = 0; times < max_times; times++) {
//        // 提示用户输入用户名和密码
//        printf("Enter username: ");
//        scanf("%s", username);
//        printf("Enter password: ");
//        scanf("%s", password);
//
//        // 每次登录尝试之前重新定位文件指针到文件开头
//        rewind(file);
//
//        struct login Stu;
//        int found = 0; // 标记是否找到匹配的用户名和密码
//
//        // 从文件中读取每一行用户名和密码
//        while (fscanf(file, "%s %s", Stu.user_name, Stu.password) == 2) {
//            // 检查用户名和密码是否匹配
//            if (strcmp(username, Stu.user_name) == 0 && strcmp(password, Stu.password) == 0) {
//                printf("Login successful! Welcome to the system.\n");
//                fclose(file);
//                return 0; // 登录成功，退出程序
//            }
//        }
//
//        printf("Invalid account name or password!\n");
//    }
//
//    fclose(file);
//    return 1;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//    char ch[] = "world";
//    const char* p;
//    p = "hello";
//    cout << p <<" " << ch << endl;
//    printf("hello world\n");
//    printf("%s ", p);
//    printf("%s\n", ch);
//    return 0;
//} 

//头文件
/*
这都是
注释
*/
#include <stdio.h>
//int float double char bool
//int main() {
//	int i = 5;
//	short s = 9;
//	long l = 90;
//	long long lm = 9000000;
//
//	float f = 6.0;
//	double df = 9.0000;
//	bool m = false;
//	char ch = 'k';
//	char c = 98;
//	printf("%c", c);
//	return 0;
//
//}

//int main() {//c语言主函数的入口
//
//	int n = 9;
//
//	return 0;//表示c语言结束的标志，也可以被用作诊断程序能否正确运行的标志
//}

int add(int a, int b)//a和b是形式参数（形参）
{



	return a + b;// the type of return value can and only can be integer
}

int main() {
	int i = 9;
	int m = 8;
	scanf("%d %d", &i, &m);
	int n = add(i, m);
	int j = add(34, 89);
	printf("The sum of i and m is:%d, and the value of j is:%d", add(i,m), j);//标准输出流
	return 0;
}