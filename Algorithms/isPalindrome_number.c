// https://leetcode.com/problems/palindrome-number/

/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.
Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction
of using extra space.

You could also try reversing an integer. However, if you have solved the
problem "Reverse Integer", you know that the reversed integer might overflow.
How would you handle such case?

There is a more generic way of solving this problem.

*/

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

// The following version is buggy. Give wrong answer for input like 100021.
// the right one is at the bottom.
bool isPalindrome(int x) {
    if(x == 0)
        return true;
    if(x < 0)
        return false;
    int num_bit = 0, x0=x, pow10=1; // pow10 for extracting the highest bit
    while(x0 != 0){
        num_bit++;
        x0 /= 10;
        pow10 *= 10;
    }
    pow10 /= 10;
    int small = x % 10; // the lowest bit
    int high = x / pow10;
    if(small != high)
        return false;

    // remove the highest and lowest bit, recursively do it.
    x = x - high * pow10;
    x /= 10;  // remove lowest.
    return isPalindrome(x);
}

// Right answer.
int getBit(int x, int num_bit, int i);
bool isPalindrome2(int x) {
    if(x == 0)
        return true;
    if(x < 0)
        return false;
    int num_bit = 0, x0=x;
    while(x0 != 0){
        num_bit++;
        x0 /= 10;
    }
    for(int i=0, j=num_bit-1; i<j;  i++, j--){
        if(getBit(x, num_bit, i) != getBit(x, num_bit, j))
            return false;
    }
    return true;
}

// get the ith bit of a number x.
// The lowest bit is the 0th bit.
int getBit(int x, int num_bit, int i){
    if(i < 0 || i >= num_bit)
        return -1; // i must satisfy 0 <= i < num
    x /= pow(10, i); // right shift i bits
    return x % 10;
}


int main(){
    int arr[] = {323, 22, 3, 34, 100021};
    int len = sizeof arr/ sizeof arr[0];
    for(int i=0; i<len; i++){
        printf("%d: %d\n", arr[i], isPalindrome2(arr[i]));
    }
    return 0;
}
                
