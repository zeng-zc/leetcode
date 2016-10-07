// https://leetcode.com/problems/single-number/
/*
 * Given an array of integers, every element appears twice except for one.
 * Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory? 
 */
int singleNumber(int* nums, int numsSize) {
    int res=nums[0];
    for(int i=1; i<numsSize; i++)
        res ^= nums[i]; 
    return res;
}

#include <stdio.h>
int main(){
    int a[]={1,2,3,4,5,1,2,3,5,0,0,10, 10};
    printf("%d\n", singleNumber(a, sizeof a/ sizeof a[0]));
    return 0;
}

// C++ 版本：利用std::accumulate就一行代码
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
    }
};
// 注意 std::bit_xor<> 是C++14引入的
// std::bit_xor<int> 是模板实例化后的class，是个类型
// std::bit_xor<int>() 是个可调用对象。stl算法的predicate(断言函数、谓词)都是可调用对象，不能传类型进去
