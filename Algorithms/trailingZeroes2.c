#include <stdio.h>
int trailingZeroes(int n) {
    int res=0;
    while((n /= 5) != 0){
        res += n;
    }
    return res;
}

int main(){
    printf("n=10: %d\n", trailingZeroes(10));
    printf("n=15: %d\n", trailingZeroes(15));
    printf("n=25: %d\n", trailingZeroes(25));
    printf("n=35: %d\n", trailingZeroes(35));
    printf("n=1000: %d\n", trailingZeroes(1000));
    return 0;
}


/*
 * 算法：
 * 由于2比5多，只需要count有多少个5。
 * 在1～n 的数中，有 n/5 个数是5的倍数，这些数对5的指数贡献为1；
 * 这些数中，又有 n/25 个数是25的倍数，每个这些数对5的指数贡献再+1；
 * n/5^3 个数是 5^3 的倍数，以此类推。
 */
