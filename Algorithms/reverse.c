/* https://leetcode.com/problems/reverse-integer/
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321 
*/

#include <limits.h>
#include <stdio.h>
int reverse(int x) {
    int sign;
    long y = (long)x;
    printf("in fun: x=%d y=%ld\n", x, y);
    long long res=0;
    if(x >= 0)
        sign = 1;
    else{
        sign = -1;
        x = -x;
    }
    while(x != 0){
        int lowbit = x%10;
        res = res * 10 + lowbit;
        x /= 10;
    }
    res *= sign;
    if(res > INT_MAX || res < INT_MIN)
        return 0;
    return (int)res;
}
/* The only thing needs attention is overflow.
 * note that -123 % 10 =-3
 */

// A more concise version.
int reverse(int x) {
    long res = 0;
    while(x != 0){
        res = res*10 + x%10;
        x = x/10;
    }
    if(res > INT_MAX || res < INT_MIN) // Check whether overflowed.
        return 0;
    return res;
}


int main(){
    int x1= 3, x2=-123; 
    long x3=12345678912;
    printf("x1 = %d, reverse=%d\n", x1, reverse2(x1));
    printf("x2 = %d, reverse=%d\n", x2, reverse2(x2));
    printf("x3 = %ld, reverse=%d\n", x3, reverse2(x3));
    return 0;
}
