/*
Given a sorted array and a target value, return the index if the target is
found. If not, return the index where it would be if it were inserted in
order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0 
*/
int searchInsert(int* nums, int numsSize, int target) {
    int *cur=nums;
    while(cur - nums < numsSize){
        if(*cur >= target)
            return cur-nums;
    }
    return numsSize-1;
}

// 上面的这个版本 Time Limit Exceeded，那就采用二分法。



int searchInsert2(int* nums, int numsSize, int target) {
    int beg=0, end=numsSize-1, mid;
    while(beg <= end){
        mid = (beg+end)/2;
        if(nums[mid] > target)
            end = mid-1;
        else if(nums[mid] < target)
            beg = mid+1;
        else
            return mid;
    }
    return beg;
}

#include <stdio.h>
int main(){
    int a[]={1, 3, 5, 6}, len=sizeof a/ sizeof a[0];
    printf("%d\n", searchInsert2(a, len ,5));
    printf("%d\n", searchInsert2(a, len ,2));
    printf("%d\n", searchInsert2(a, len ,7));
    printf("%d\n", searchInsert2(a, len ,0));
    return 0;
}

/* notes:
 * 二分搜索算法虽然简单，但有一个地方容易犯错，就是循环
 * 执行的条件是 beg <= end, 注意等号必不可少。如果少了
 * 等号，即 beg < end, 则单个元素的区间就不执行循环体了，
 * 事实上是需要执行的。举个例子：[1,2] 寻找2, 没有等号
 * 时就会出错。
 */
