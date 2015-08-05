/*
 *  Given a sorted array, remove the duplicates in place such that each
 *  element appear only once and return the new length.
 *
 *  Do not allocate extra space for another array, you must do this in place
 *  with constant memory.
 *
 *  For example,
 *  Given input array nums = [1,1,2],
 *
 *  Your function should return length = 2, with the first two elements of
 *  nums being 1 and 2 respectively. It doesn't matter what you leave beyond
 *  the new length. 
 */

int removeDuplicates(int* nums, int numsSize) {
    int dst, cursor;
    if(numsSize <= 0)
        return 0;
    for(dst=0, cursor=1; cursor< numsSize; cursor++){
        if(nums[cursor] > nums[dst])
            nums[++dst] = nums[cursor];
    }
    return dst+1;
}

/*
 * notes:
 * 容易犯错的一点是：没有判断 numsSize 为 0 的情况。
 * 作为专业程序员，肯定不应该犯这种错，要考虑边界情况。
 */
