#include <stdio.h>
typedef enum {false, true} bool;
bool isPowerOfTwo(int n) {
    if(n<=0)
        return 0;   // leetcode 系统会用负数来测试，导致 time exceed.
    int bit_len=0, n0 = n;
    while(n0 !=0){
        n0 >>= 1;
        bit_len++;
    }
    printf("n=%d, bit_len=%d\n", n, bit_len);
    if(n != (1 << (bit_len-1)))
        return 0;
    else
        return 1;
}
