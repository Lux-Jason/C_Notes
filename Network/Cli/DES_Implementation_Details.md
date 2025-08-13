# DES加密算法实现详解

## 一、算法概述
DES(Data Encryption Standard)是一种对称密钥加密算法，采用64位分组和56位密钥。本实现包含以下核心模块：

```c
// DES.h 主要接口
int des_init(int mode);          // 初始化DES上下文
void des_set_key(char* key);     // 设置加密密钥
void des_encrypt(char* block);   // 加密64位数据块
void des_decrypt(char* block);   // 解密64位数据块
void des_done(void);             // 清理DES上下文
```

## 二、核心数据结构

### 1. 置换表(IP/IP-1)
```cpp
// 初始置换表
static char ip[64] = {
   58,50,42,34,26,18,10,2,
   ... // 完整64项
};

// 逆初始置换表  
static char fp[64] = {
   40,8,48,16,56,24,64,32,
   ... // 完整64项
};
```

### 2. S盒(Substitution Boxes)
```cpp
static char sbox[8][64] = {
    // S1
    {14,4,13,1,2,15,11,8,...},
    // S2
    {15,1,8,14,6,11,3,4,...},
    ... // 共8个S盒
};
```

### 3. 密钥处理
```cpp
static char key_perm_table[56];    // 密钥置换表
static char key_rol_steps[16];     // 轮密钥左移表
```

## 三、加密流程

### 1. 初始置换(IP)
```cpp
void des_encrypt(char* block) {
    permute(block, iperm, (char*)work); 
    // 执行IP置换
}
```
- 将64位明文按IP表重新排列

### 2. 生成子密钥
```cpp
void des_set_key(char* key) {
    // 通过PC-1置换生成56位密钥
    // 进行16轮左移生成子密钥
    for(i=0;i<16;i++){
        // 使用PC-2生成48位轮密钥
    }
}
```

### 3. Feistel网络
```cpp
static void round(int num, ulong32* block) {
    if(num & 1) {
        block[1] ^= f(block[0], kn[num]);
    } else {
        block[0] ^= f(block[1], kn[num]);
    }
}
```
- 16轮迭代处理，每轮包含：
  - 扩展置换(E)
  - 异或轮密钥
  - S盒替换
  - P置换

### 4. 最终置换(FP)
```cpp
permute((char*)work, fperm, block);
```
- 执行IP逆置换得到密文

## 四、解密流程
```cpp
void des_decrypt(char* block) {
    // 反向使用轮密钥
    for(i=15;i>=0;i--) 
        reverse_round(i, work);
}
```
- 使用相同结构但反向应用轮密钥

## 五、关键函数实现

### 1. S盒处理
```cpp
static long32 f(ulong32 r, unsigned char subkey[8]) {
    // 扩展置换
    rt = (r >> 1) | ((r & 1) ? 0x80000000 : 0);
    // S盒替换
    rval |= sbox_output_perm_table[0][(...)];
    ...
    return rval;
}
```

### 2. 置换运算
```cpp
static void permute(char* inblock, char perm[16][16][8], char* outblock) {
    // 使用三维置换表进行高效位操作
    for(j=0;j<16;j+=2,pin++){
        p = perm[j][(*pin >> 4) & 0x0F];
        q = perm[j+1][*pin & 0x0F];
    }
}
```

## 六、使用示例
```cpp
int main() {
    char key[] = "ABCD1234";
    char plain[9] = "test1234";
    
    des_init(0);
    des_set_key(key);
    
    // 加密
    des_encrypt(plain);
    
    // 解密
    des_decrypt(plain);
    
    des_done();
    return 0;
}
```

## 七、性能优化

1. **查表优化**：预计算S盒输出置换表
```cpp
static long32(*sbox_output_perm_table)[64];
sbox_output_perm_table_init();
```

2. **位操作优化**：使用位运算代替循环
```cpp
// 快速置换实现
*perm[i][j][k >> 3] |= bytebit[m];
```

3. **内存优化**：使用紧凑的置换表存储
```cpp
static char(*iperm)[16][8]; // 三维置换表
```

## 八、注意事项

1. 密钥安全：确保密钥存储安全
2. 工作模式：本实现为ECB模式，实际使用应选择CBC等更安全模式
3. 平台兼容性：处理字节序问题
```cpp
#ifdef LITTLE_ENDIAN
    work[0] = byteswap(work[0]);
#endif
