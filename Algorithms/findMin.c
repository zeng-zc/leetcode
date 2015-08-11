/* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

// binary search
// Algorithm: 
// First search the minimum in the left half of the array,
// then do the same thing in the right half, 
// finally, return the smaller of the two.
// Do it recursively.
#include <stdio.h>
int binarySearch(int *nums, int beg, int end);
int findMin(int* nums, int numsSize) {
    if(numsSize<=0)
        return 0;
    int res = binarySearch(nums, 0, numsSize-1);
    return nums[res];
}

int binarySearch(int *nums, int beg, int end){ // return the index
    if(beg >= end)
        return beg;
    if(nums[end] > nums[beg])
        return beg;
    int mid = (beg+end)/2;
    int left = binarySearch(nums, beg, mid);
    int right = binarySearch(nums, mid+1, end);
    if(nums[left] > nums[right])
        return right;
    else
        return left;
}

int main(){
    int arr[]={4,5,6,7,1,2,3};
    int len= sizeof arr/ sizeof arr[0];
    printf("%d\n", findMin(arr, len));
    int arr2[0];
    printf("%d\n", findMin(arr2, 0));
    int arr3[]={2,3,1};
    int len3= sizeof arr3/ sizeof arr3[0];
    printf("%d\n", findMin(arr3, len3));
    return 0;
}

