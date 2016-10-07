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
 *      使用C标准库中的bsearch
 */
int find_minimum(int *nums, int beg, int end);
int compare(const void *i1, const void *i2);
int search(int* nums, int numsSize, int target) {
    if(numsSize<=0)
        return 0;
    int index = find_minimum(nums, 0, numsSize-1);
    void *ret1 = bsearch(&target, nums, index, sizeof(int), compare);
    if (ret1)
        return (int *)ret1 - nums;  // 注意返回值为下标
    else {
        void *ret2 = bsearch(&target, nums+index, numsSize-index, sizeof(int), compare);
        if (ret2)
            return (int *)ret2 - nums;
        else
            return -1;
    }
}

int compare(const void *i1, const void *i2)
{
    return *(int *)i1 - *(int *)i2;
}
       
int find_minimum(int *nums, int beg, int end){ // return the index of minimum element.
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
