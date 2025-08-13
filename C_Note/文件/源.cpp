#pragma once
#include<stdio.h>

/*文件操作：
* 1.程序文件：源程序文件.c，目标文件（windows环境后缀为.obj），可执行程序（windows环境后缀为.exe）
* 2.数据文件：程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件）
*/
//数据文件：文本文件，二进制文件
// 数据在内存中以二进制存储，如果不加转换地输入到外存的文件中，就是二进制文件。
// 如果要求在外存上以ASCII的形式存储，则需要在存储前转换。以ASCII字符的形式存储的文件就是文本文件。
//
//int main()
//{
//	int n = 0;
//	printf("%d\n", n);
//	scanf("%d", &n);
//	printf("%d\n", n);
//	return 0;
//}

int main()
{
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");
	if (pf==NULL)
	{
		perror("fopen");
		return 1;
	}
	fwrite(&a, 4, 1, pf);
	fclose(pf);
	pf = NULL;
	return 0;
}
