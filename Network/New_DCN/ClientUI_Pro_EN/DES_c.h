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
#include <ctime>       // 新增时间头文件
#include <iomanip>     // 新增格式化输出

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

int  des_init(int mode);
void des_set_key(char* key);
void des_encrypt(char* block);
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