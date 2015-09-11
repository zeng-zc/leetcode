// https://leetcode.com/problems/majority-element/
// Given an array of size n, find the majority element. The majority element
// is the element that appears more than ⌊ n/2 ⌋ times.
//
// You may assume that the array is non-empty and the majority element always
// exist in the array.
//
// 尝试用 C++ 的 map 数据结构来实现
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, size_t> count;
        for(const auto &it: nums)
            count[it]++;  // 没有这个key就会自动创建
        for(const auto &it: count)
            if(it.second > nums.size()/2)
                return it.first;
    }
};
