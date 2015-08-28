// https://leetcode.com/problems/missing-number/
/*  Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 *  find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it
using only constant extra space complexity? 
*/

#include <stdio.h>
int missingNumber(int* nums, int numsSize) {
    int sum=0, sum0=0, i;
    for(i=0; i<numsSize; i++){
        sum += nums[i];
        sum0 += i+1;
    }
    return sum0 - sum;
}

int main(){
    int arr[]={0,1,3};
    int len = sizeof arr/ sizeof arr[0];
    printf("%d\n", missingNumber(arr, len));
    return 0;
}

// Accepted.
