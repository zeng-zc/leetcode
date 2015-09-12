// https://leetcode.com/problems/ugly-number/
/*  Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
For example, 6, 8 are ugly while 14 is not ugly since it includes another
prime factor 7.

Note that 1 is typically treated as an ugly number. 
*/

#include <stdio.h>
#include <stdbool.h>
bool isUgly(int num) {
    if(num == 0)
        return 0;  // Easy to overlook!
    while(num % 2 ==0)
        num /= 2;
    while(num % 3 ==0)
        num /= 3;
    while(num % 5 ==0)
        num /= 5;
    if(num == 1)
        return 1;
    else
        return 0;
}
// Don't forget num=0 case.

int main(){
    int arr[]={1, 6, 8, 14};
    int len = sizeof arr/sizeof arr[0];
    for(int i=0; i<len; i++)
        printf("n=%d, result=%d\n", arr[i], isUgly(arr[i]));
    return 0;
}
