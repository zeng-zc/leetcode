/*
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 */
// 这个版本在 leetcode 上运行会超时，算法太naiive。
// 请参考本文件夹下的另一个版本
int fac_by_2(int n){
    int res=0;
    while(n % 2 ==0){
        res++;
        n /= 2;
    }
   return res;
}

int fac_by_5(int n){
    int res=0;
    while(n % 5 ==0){
        res++;
        n /= 5;
    }
    return res;
}
 
int trailingZeroes(int n) {
    int fac2=0, fac5=0;
    for(int i=1; i<=n; i++){
        fac2 += fac_by_2(i);
        fac5 += fac_by_5(i);
    }
    return fac2<fac5 ? fac2 :fac5 ;
}
