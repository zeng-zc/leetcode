/* https://leetcode.com/problems/search-in-rotated-sorted-array/
   Suppose a sorted array is rotated at some pivot unknown to you beforehand.
   (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
   You are given a target value to search. If found in the array return its
   index, otherwise return -1.
   You may assume no duplicate exists in the array.
   */

/* Algorithm:
 * Two steps:
 *    (1) find the pivot using binary search;
 *    (2) search target in the two parts(before the pivot and after)
 *      using binary search.
 * 
 * 改进：
 *      使用 STL 算法 std::lower_bound
 */

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int index = find_minimum(nums, 0, nums.size()-1);
        auto it = nums.begin() + index;
        auto pos1 = std::lower_bound(nums.begin(), it, target);
        if (pos1 != it && *pos1 == target)  {  // found // 因为lower_bound 可能返回大于等于target的元素
            return pos1 - nums.begin();
        } else {  // not found
            auto pos2 = std::lower_bound(it, nums.end(), target);
            if (pos2 != nums.end() && *pos2 == target)  {  // found
                return pos2 - nums.begin();
            } else
                return -1;
        }
    }

    int find_minimum(vector<int> &nums, int beg, int end){ // return the index of minimum element.
        if(beg >= end)
            return beg;
        if(nums[end] > nums[beg])
            return beg;
        int mid = (beg+end)/2;
        int left = find_minimum(nums, beg, mid);
        int right = find_minimum(nums, mid+1, end);
        if(nums[left] > nums[right])
            return right;
        else
            return left;
    }
};


// 注意：C++ 中跟容器配合使用的二分搜索是 std::lower_bound，注意要搞清楚这个函数的返回值！
//       std::binary_search 一般来说不是你想要的函数！
