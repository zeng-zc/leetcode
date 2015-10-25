// https://leetcode.com/problems/house-robber/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/*
 * 递归式(i,j 为下标，a为数组)
 * f(i, j) = max{a[k] + f(i, k-2) + f(k+2, j)}, if 0 <= i <= j <= n-1
 *         = 0, elsewhere
 * 最终要求的结果为 f(0, n-1)
 */

// naiive 解法，会 LTE
int helper(int i, int j, int *nums, int n);
int rob(int* nums, int numsSize) {
    return helper(0, numsSize-1, nums, numsSize);
}

int helper(int i, int j, int *nums, int n)
{
    if (i<0 || j>n-1 || i>j)
        return 0;
    int res = INT_MIN;
    for (int k=i; k<=j; k++) {
        int tmp = helper(i, k-2, nums, n) + 
            helper(k+2, j, nums, n) + nums[k];
        if (res < tmp)
            res = tmp;
    }
    return res;
}

// 记忆的自顶向下方法
int **init_array(int numsSize) {
    int **array = malloc(sizeof (int *) * numsSize);
    for (int i=0; i<numsSize; i++)
        array[i] = malloc(sizeof (int) * numsSize);
    for (int i=0; i<numsSize; i++)
        for (int j=0; j<numsSize; j++)
            array[i][j] = INT_MIN;
    return array;
}

int helper2(int i, int j, int *nums, int n, int **array)
{
    if (i<0 || j>n-1 || i>j)
        return 0;
    if (array[i][j] != INT_MIN)
        return array[i][j];
    for (int k=i; k<=j; k++) {
        int tmp = helper2(i, k-2, nums, n, array) + 
            helper2(k+2, j, nums, n, array) + nums[k];
        if (array[i][j] < tmp)
            array[i][j] = tmp;
    }
    return array[i][j];
}
// Accepted


// DP 解法, 自底向上方法


int rob2(int* nums, int numsSize) {
    int **array = init_array(numsSize);
    return helper2(0, numsSize-1, nums, numsSize, array);
}


int main()
{
    int a[]={1, 2, 3, 4, 5};
    int res = rob2(a, sizeof a / sizeof a[0]);
    printf("res=%d\n", res);
    return 0;
}
