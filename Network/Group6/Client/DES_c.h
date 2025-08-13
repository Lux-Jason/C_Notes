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
// 如果项目不使用预编译头文件，可以安全地移除以下行  
// #include "stdafx.h"  

// 如果项目需要预编译头文件，请确保在项目设置中启用了预编译头，并且文件名正确。  
// 如果需要启用预编译头，请在 Visual Studio 中：  
// 1. 右键单击项目 -> 属性  
// 2. 转到 "C/C++" -> "预编译头"  
// 3. 将 "预编译头" 设置为 "使用 (/Yu)"  
// 4. 确保 "预编译头文件" 设置为 "stdafx.h" 或项目中实际使用的文件名。  


// 如果项目不使用预编译头文件，可以安全地移除以下行  
// #include "stdafx.h"  

// 如果项目需要预编译头文件，请确保在项目设置中启用了预编译头，并且文件名正确。  
// 如果需要启用预编译头，请在 Visual Studio 中：  
// 1. 右键单击项目 -> 属性  
// 2. 转到 "C/C++" -> "预编译头"  
// 3. 将 "预编译头" 设置为 "使用 (/Yu)"  
// 4. 确保 "预编译头文件" 设置为 "stdafx.h" 或项目中实际使用的文件名。  

// 如果不需要预编译头文件，直接移除以下行即可解决问题。
int  des_init(int mode);
void des_set_key(char* key);
void des_encrypt(char* block);
// 如果项目不使用预编译头文件，可以安全地移除以下行  
// #include "stdafx.h"  

// 如果项目需要预编译头文件，请确保在项目设置中启用了预编译头，并且文件名正确。  
// 如果需要启用预编译头，请在 Visual Studio 中：  
// 1. 右键单击项目 -> 属性  
// 2. 转到 "C/C++" -> "预编译头"  
// 3. 将 "预编译头" 设置为 "使用 (/Yu)"  
// 4. 确保 "预编译头文件" 设置为 "stdafx.h" 或项目中实际使用的文件名。  

#ifdef _MSC_VER
#endif

// 修复方法：如果不需要预编译头文件，直接移除以下行即可解决问题。
#ifndef _MSC_VER
#include <iostream> // 替代 stdafx.h 的必要头文件
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#ifndef _MSC_VER  
#include <iostream> // 替代 stdafx.h 的必要头文件  
#include <string>  
#include <vector>  
#include <algorithm>  
#include <ctime>  
#include <iomanip>  
#else  
#include "stdafx.h" // 或项目指定的预编译头文件名  
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