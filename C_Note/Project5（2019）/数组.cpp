#include<Windows.h>
#include<stdio.h>
#include<string.h>
//������̨�ף�
//int dance_step(int n)
//{
//	if (n == 1)
//	{
//		return 1;//��ֻ��һ��̨��ʱֱ�ӷ���1
//	}
//	if (n == 2)
//	{
//		return 2;//��ֻ��2��̨��ʱֱ�ӷ���2
//	}
//	if (n > 2)
//	{
//		return dance_step(n - 1) + dance_step(n - 2);
//	}//��n>2ʱ�����õݹ���з���
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int num = dance_step(n);
//	printf("%d\n", num);
//	return 0;
//}
//��ŵ�����⣺
//void move(char pos1, char pos2)
//{
//	printf(" %c->%c ", pos1, pos2);
//}
////     n:���Ӹ��� pos1:��ʼλ�� pos2:��תλ�� pos3:����λ��
//void Hanoi(int n, char pos1, char pos2, char pos3)
//{
//	//���ֻ��һ�����ӣ�ֻ��Ҫ�����Ӵ���ʼλ���ƶ���Ŀ��λ����
//	if (n == 1)
//	{
//		move(pos1, pos3);
//	}
//	//�����n(n>=2)�����ӣ�����Ҫ��n������ͨ����תλ���ƶ���Ŀ��λ����
//	else
//	{
//		//��n-1������ͨ����תλ���ƶ���Ŀ��λ����
//		Hanoi(n - 1, pos1, pos3, pos2);
//		//����n���ƶ���Ŀ��λ����
//		move(pos1, pos3);
//		//��n-1������ͨ����תλ���ƶ���Ŀ��λ����
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
//	printf("\n�������>:");
//	scanf("%d", &n);
//	Hanoi(n, 'A', 'B', 'C');
//	return 0;
//}
//
//
//
//int main()
//{
//	int arr[20] = { 1,2,3 };//����ȫ��ʼ����ʣ�µ�Ԫ��Ĭ�ϳ�ʼ��Ϊ0
//	char arr2[5] = { 'a','b' };
//	char arr3[5] = "ab";
//	char arr4[] = "abcdef";
//	printf("%d\n", sizeof(arr4));//7--arr4��ռ�ռ��С
//	printf("%d\n", strlen(arr4));//6--arr4�ַ������ȣ���/0����ռ���ȣ�
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
//	printf("%d\n", strlen(arr2));//42(���ֵ)
//	return 0;
//}
//
//
//һά���飺
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
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };//�������ڴ�����������ŵ�
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		printf("&arr[%d]=%p\n", i, &arr[i]);
//	}
//	return 0;
//}
//
//��ά���飺
//int main()
//{
//	//int arr1[3][4] = { {1,2,3 }, {4, 5 } };//������������
//	//char ch[5][6];
//	//int arr2[][4] = { {1,2,3,4},{5,6,7,8} };//�п���ʡ�ԡ��в���ʡ��
//	// 
// //   //��ά����ʹ��Ҳ��ͨ���±�ʵ��
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
//��ά�������ڴ��еĴ洢��
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
//ð������
//void bubble_sort(int arr[], int sz)
//{
// //ȷ��ð�������������
//	int i = 0;
//	for ( i = 0; i < sz-1; i++)
//	{
//		int flag = 1;//������һ��Ҫ����������Ѿ�����
//		int j = 0;
//		for ( j = 0; j <sz-1-i ; j++)
//		{
//			if (arr[j] > arr [j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;//���������������ʵ����ȫ����
//			}
//		}
//		if (flag == 1)
//		{
//			break;//�Ż�
//		}
//	}
//
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//��arr���������ų�����
//	//arr�����飬������arr���д���,ʵ���ϴ��ݹ�ȥ��������arr��Ԫ�صĵ�ַ��&arr[0]��
//	bubble_sort(arr, sz);//ð��������
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
//	printf("%p\n", arr);//��Ԫ�ص�ַ(��һ��Ԫ�صĵ�ַ��
//	printf("%p\n", &arr[0]);//ͬ��
//	//��������������ĵ�ַ�����ζ���ӡ���һ����
//	printf("%d\n", *arr);//1
//	printf("%p\n", &arr);//����ĵ�ַ����һ��Ԫ�����ڵ�ַ��ʼ����ʾ��������ĵ�ַ��
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//1.sizeof������������ʾ�������飬���������������Ĵ�С����λ���ֽ�
//	//2.&��������������������������������ȡ��������������ĵ�ַ
//	return 0;
//} 
