// https://leetcode.com/problems/majority-element/
/*
Given an array of size n, find the majority element. The majority element is
the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always
exist in the array.
*/
//
// 随机选取一个元素，然后检查它是不是majority。概率为 1/2 成功。

#include <stdlib.h>
int majorityElement(int* nums, int numsSize) {
    int rand, count;
    do{
        rand = random() % numsSize;
        count=0;
        for(int i=0; i<numsSize; i++)
            if(nums[i] == nums[rand])
                count++;
    }while(count <= numsSize/2);
    return nums[rand];
}
