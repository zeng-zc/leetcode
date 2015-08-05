/*
 * Given an array and a value, remove all instances of that value in place and
 * return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length. 
 */

int removeElement(int* nums, int numsSize, int val) {
    if(nums == NULL)
        return -1;
    int *p=nums;
    for(int i=0; i<numsSize; i++){
        if(nums[i] != val) // 将满足条件的数依次重新放入这个数组。
            *p++ = nums[i];
    }
    return p-nums;
}

