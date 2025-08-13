// DES.h

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <thread>
#include <atomic>
#include <vector>
#include <algorithm>
#include<string.h>
#include <ctime>       // ����ʱ��ͷ�ļ�
#include <iomanip>     // ������ʽ�����
#if 2147483647L+1L == -2147483648L 
typedef long long32;
typedef unsigned long ulong32;
#else
typedef int long32;           /* In 64-bit systems, long may be 64-bit, */
typedef unsigned int ulong32; /* here we force it to be 32-bit. */
#endif

#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN
#endif
// �����Ŀ��ʹ��Ԥ����ͷ�ļ������԰�ȫ���Ƴ�������  
// #include "stdafx.h"  

// �����Ŀ��ҪԤ����ͷ�ļ�����ȷ������Ŀ������������Ԥ����ͷ�������ļ�����ȷ��  
// �����Ҫ����Ԥ����ͷ������ Visual Studio �У�  
// 1. �Ҽ�������Ŀ -> ����  
// 2. ת�� "C/C++" -> "Ԥ����ͷ"  
// 3. �� "Ԥ����ͷ" ����Ϊ "ʹ�� (/Yu)"  
// 4. ȷ�� "Ԥ����ͷ�ļ�" ����Ϊ "stdafx.h" ����Ŀ��ʵ��ʹ�õ��ļ�����  


// �����Ŀ��ʹ��Ԥ����ͷ�ļ������԰�ȫ���Ƴ�������  
// #include "stdafx.h"  

// �����Ŀ��ҪԤ����ͷ�ļ�����ȷ������Ŀ������������Ԥ����ͷ�������ļ�����ȷ��  
// �����Ҫ����Ԥ����ͷ������ Visual Studio �У�  
// 1. �Ҽ�������Ŀ -> ����  
// 2. ת�� "C/C++" -> "Ԥ����ͷ"  
// 3. �� "Ԥ����ͷ" ����Ϊ "ʹ�� (/Yu)"  
// 4. ȷ�� "Ԥ����ͷ�ļ�" ����Ϊ "stdafx.h" ����Ŀ��ʵ��ʹ�õ��ļ�����  

// �������ҪԤ����ͷ�ļ���ֱ���Ƴ������м��ɽ�����⡣
int  des_init(int mode);
void des_set_key(char* key);
void des_encrypt(char* block);
// �����Ŀ��ʹ��Ԥ����ͷ�ļ������԰�ȫ���Ƴ�������  
// #include "stdafx.h"  

// �����Ŀ��ҪԤ����ͷ�ļ�����ȷ������Ŀ������������Ԥ����ͷ�������ļ�����ȷ��  
// �����Ҫ����Ԥ����ͷ������ Visual Studio �У�  
// 1. �Ҽ�������Ŀ -> ����  
// 2. ת�� "C/C++" -> "Ԥ����ͷ"  
// 3. �� "Ԥ����ͷ" ����Ϊ "ʹ�� (/Yu)"  
// 4. ȷ�� "Ԥ����ͷ�ļ�" ����Ϊ "stdafx.h" ����Ŀ��ʵ��ʹ�õ��ļ�����  

#ifdef _MSC_VER
#endif

// �޸��������������ҪԤ����ͷ�ļ���ֱ���Ƴ������м��ɽ�����⡣
#ifndef _MSC_VER
#include <iostream> // ��� stdafx.h �ı�Ҫͷ�ļ�
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#ifndef _MSC_VER  
#include <iostream> // ��� stdafx.h �ı�Ҫͷ�ļ�  
#include <string>  
#include <vector>  
#include <algorithm>  
#include <ctime>  
#include <iomanip>  
#else  
#include "stdafx.h" // ����Ŀָ����Ԥ����ͷ�ļ���  
#endif
#include <iomanip>
#endif
void des_decrypt(char* block);
void des_done(void);
static void sbox_output_perm_table_init(void);
static void perm_init(char perm[16][16][8], char p[64]);
static void permute(char* inblock, char perm[16][16][8], char* outblock);
static void round(int num, ulong32* block);
static void reverse_round(int num, ulong32* block);
static long32 f(ulong32 r, unsigned char subkey[8]);


#ifdef   LITTLE_ENDIAN
static ulong32 byteswap(ulong32 x);
#endif