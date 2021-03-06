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
 */
int find_minimum(int *nums, int beg, int end);
int bisearch(int *nums, int beg, int end, int target);
int search(int* nums, int numsSize, int target) {
    if(numsSize<=0)
        return 0;
    int index = find_minimum(nums, 0, numsSize-1);
    int res1 = bisearch(nums, 0, index-1, target);
    if(res1 != -1){
        return res1;
    } else {
        res2 = bisearch(nums, index, numsSize-1, target);
        if(res2 != -1)
            return res2;
        else 
            return -1;
    }
}
int bisearch(int *nums, int beg, int end, int target) { // in a sorted array
    if(beg > end)
        return -1;
    int mid = (beg + end)/2;
    if(target > nums[mid])
        return bisearch(nums, mid+1, end, target);
    else if(target < nums[mid])
        return bisearch(nums, beg, mid-1, target);
    else
        return mid;
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
