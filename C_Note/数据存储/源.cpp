#include<iostream>
#include<cmath>
#include<cstdlib>
#include<Windows.h>
//c�������ͣ�
// 1.�������ͣ�char,short,int,;ong,long long float,double
// 2.�Զ�������(�������ͣ�
// �������壺
// 1.ʹ��������Ϳ����ڴ�ռ�Ĵ�С����С������ʹ�÷�Χ����
// 2.��ο����ڴ�ռ���ӽǡ�
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


//�������ͣ�
// 1.��������--�Զ�������
// 2.�ṹ�����ͣ�struct��
// 3.ö�����ͣ�enum��
// 4.�������ͣ�union��
//

//ָ�����ͣ�
// int* pi;
// char* pc;
// float* pf;
// void* pv
//

//�����ͣ�
// void��ʾ������
//ͨ��Ӧ���ں����ķ������ͣ������Ĳ�����ָ�����͡�
//void test()
//{
//	printf("haha\n");
//}
//int main()
//{
//	test();//�����Դ��Σ������������
//	return 0;
//}


//�������ڴ��еĴ洢��
//ԭ��
//����
//����
//int main()
//{
//	int a = 20;//&a hex=0x00000014--�����Ʋ���
//	int b = -10;//&b hex=0xfffffff6--�����Ʋ���
//
//	return 0;
//}
// 
// 
//���С�ˣ�
//
//int main()
//{
//	int a = 20;
//	//00000000000000000000000000010100
//	//0x00 00 00 14
//	//�ڴ�洢��ʽ�����֣�
//	//��˴洢ģʽ������ֽ���洢ģʽ��--ָ���ݵ�λ�������ڴ�ߵ�ַ�����ݸ�λ�����ڵ͵�ַ
//	//С�˴洢ģʽ��С���ֽ���洢ģʽ��--ָ���ݵ�λ�������ڴ�͵�ַ�����ݸ�λ�����ڸߵ�ַ
//	//���ֱ���ģʽ��֧��
//	int b = 0x11223344;//�˵���ideΪС�˴洢ģʽ
//	return 0;
//}

//дһ�δ��룬�������ǵ�ǰ�������ֽ�����ʲô��
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
//	return *(char*)&a;//д���ɶ��Խϲ���Ƽ�
//}
////ָ�����͵����壺
////1.ָ�����;�����ָ������ò������ܷ��ʼ����ֽڣ�char* p��*p������һ���ֽڣ�int* p��*p�������ĸ��ֽ�
////2.ָ�����;�����ָ��+1��-1�Ȳ������ӻ�����Ǽ����ֽڣ�char* p��p+1������һ���ַ���int* p��p+1�������ĸ��ֽڣ�һ�����ͣ���
//int main()
//{
//	//����1��С��
//	//����0�����
//	int ret = check_sys1();
//	if (ret==1)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
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
//	//11111111111111111111111110000000--����
//	//10000000//��������������λ��
//	//11111111111111111111111110000000--����������Ĳ���
//	//�޷������Ĳ����ԭ����ͬ
//	printf("%u\n", a);//��ӡʮ���Ƶ��޷�������--4294967168
//	return 0;
//}
//char:
//signed char
//unsigned char
//һ���ֽڣ��˸�bit��

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
//	unsigned int j = 10;//�޷���������ȡֵ���з�����һ��
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

//�����ͣ�
/*int main()
{
	int n = 9;
	float* pFloat = (float*)&n;
	printf("n��ֵΪ��%d\n", n);//9
	printf("*pFloat��ֵΪ��%f\n", *pFloat);//0.000000
	//(-1)^0*0.00000000000000000001001*2^(-126)->0�����޽ӽ�0��

	*pFloat = 9.0;
	//1001.0
	//1.001*(2^3)
	//(-1)^0*1.001*2^3
	//0 10000010 00100000000000000000000
	printf("num��ֵΪ��%d\n", n);//1091567616
	//���϶�������ת��Ϊʮ������
	// 
 //�������ڴ�洢��ʽ�����Ͳ�ͬ���������͵ķ�ʽ�洢��ֵ�������ƵĿ�ѧ�������ķ�ʽ�ƶ�С����(�������ӹ���ʦѧ��IEEE 754��׼��
	printf("*pFloat��ֵΪ��%lf\n", *pFloat);//9.000000
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