// https://leetcode.com/problems/maximum-subarray/

// DP: maintain two variables: local and global
// local[i+1] = max(local[i] + a[i+1], a[i+1]);
// global[i+1] = max(global[i], local[i+1]);

int maxSubArray(int* nums, int numsSize) {
    int local=nums[0], global=nums[0];
    for(int i=1; i<numsSize; i++){
        local = fmax(local+nums[i], nums[i]);
        global = fmax(global, local);
    }
    return global;
}
