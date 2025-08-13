#include<Windows.h>
#include<stdio.h>
#include<string.h>
//青蛙跳台阶：
//int dance_step(int n)
//{
//	if (n == 1)
//	{
//		return 1;//当只有一层台阶时直接返回1
//	}
//	if (n == 2)
//	{
//		return 2;//当只有2层台阶时直接返回2
//	}
//	if (n > 2)
//	{
//		return dance_step(n - 1) + dance_step(n - 2);
//	}//当n>2时，利用递归进行返回
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int num = dance_step(n);
//	printf("%d\n", num);
//	return 0;
//}
//汉诺塔问题：
//void move(char pos1, char pos2)
//{
//	printf(" %c->%c ", pos1, pos2);
//}
////     n:盘子个数 pos1:起始位置 pos2:中转位置 pos3:最终位置
//void Hanoi(int n, char pos1, char pos2, char pos3)
//{
//	//如果只有一个盘子，只需要将盘子从起始位置移动到目的位置上
//	if (n == 1)
//	{
//		move(pos1, pos3);
//	}
//	//如果有n(n>=2)个盘子，则需要将n个盘子通过中转位置移动到目的位置上
//	else
//	{
//		//将n-1个盘子通过中转位置移动到目的位置上
//		Hanoi(n - 1, pos1, pos3, pos2);
//		//将第n个移动到目的位置上
//		move(pos1, pos3);
//		//将n-1个盘子通过中转位置移动到目的位置上
//		Hanoi(n - 1, pos2, pos1, pos3);
//	}
//}
//int main()
//{
//	Hanoi(1, 'A', 'B', 'C');
//	printf("\n");
//	Hanoi(2, 'A', 'B', 'C');
//	printf("\n");
//	Hanoi(3, 'A', 'B', 'C');
//
//	int n;
//	printf("\n输入层数>:");
//	scanf("%d", &n);
//	Hanoi(n, 'A', 'B', 'C');
//	return 0;
//}
//
//
//
//int main()
//{
//	int arr[20] = { 1,2,3 };//不完全初始化，剩下的元素默认初始化为0
//	char arr2[5] = { 'a','b' };
//	char arr3[5] = "ab";
//	char arr4[] = "abcdef";
//	printf("%d\n", sizeof(arr4));//7--arr4所占空间大小
//	printf("%d\n", strlen(arr4));//6--arr4字符串长度（“/0”不占长度）
//	return 0;
//}
//
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = { 'a','b','c' };
//	printf("%d\n", sizeof(arr1));//4
//	printf("%d\n", sizeof(arr2));//3
//	printf("%d\n", strlen(arr1));//3
//	printf("%d\n", strlen(arr2));//42(随机值)
//	return 0;
//}
//
//
//一维数组：
//int main()
//{
//	//char arr[] = "abcdef";//[a][b][c][d][e][f][/0]
//	//int i = 0;
//	//int len = strlen(arr);
//	//for ( i = 0; i < len; i++)
//	//{
//	//	printf( "%c ",arr[i] );
//	//}
//	//
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };//数组在内存中是连续存放的
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		printf("&arr[%d]=%p\n", i, &arr[i]);
//	}
//	return 0;
//}
//
//二维数组：
//int main()
//{
//	//int arr1[3][4] = { {1,2,3 }, {4, 5 } };//三行四列数组
//	//char ch[5][6];
//	//int arr2[][4] = { {1,2,3,4},{5,6,7,8} };//行可以省略。列不能省略
//	// 
// //   //二维数组使用也是通过下标实现
//	int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//	int i = 0;
//	for ( i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for ( j = 0; j < 4; j++)
//		{
//			printf("%d ",arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
// 
// 
//二维数组在内存中的存储：
//int main()
//{
//
//	int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d]=%p\n ",i,j,&arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//
//
//冒泡排序：
//void bubble_sort(int arr[], int sz)
//{
// //确定冒泡排序的趟数：
//	int i = 0;
//	for ( i = 0; i < sz-1; i++)
//	{
//		int flag = 1;//假设这一趟要排序的数组已经有序
//		int j = 0;
//		for ( j = 0; j <sz-1-i ; j++)
//		{
//			if (arr[j] > arr [j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;//本次排序的数据其实不完全有序
//			}
//		}
//		if (flag == 1)
//		{
//			break;//优化
//		}
//	}
//
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//对arr进行排序，排成升序：
//	//arr是数组，对数组arr进行传参,实际上传递过去的是数组arr首元素的地址（&arr[0]）
//	bubble_sort(arr, sz);//冒泡排序函数
//	for ( i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	printf("%p\n", arr);//首元素地址(第一个元素的地址）
//	printf("%p\n", &arr[0]);//同上
//	//数组名就是数组的地址（两次都打印结果一样）
//	printf("%d\n", *arr);//1
//	printf("%p\n", &arr);//数组的地址（第一个元素所在地址开始，表示整个数组的地址）
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//1.sizeof（数组名）表示整个数组，计算的是整个数组的大小，单位是字节
//	//2.&数组名，代表的是整个数组的数组名，取出的是整个数组的地址
//	return 0;
//} 
