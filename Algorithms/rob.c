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
int rob(int* nums, int numsSize) 
{
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
int **init_array(int numsSize) 
{
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

int rob2(int* nums, int numsSize) 
{
    int **array = init_array(numsSize);
    return helper2(0, numsSize-1, nums, numsSize, array);
}
// Accepted


// DP 解法, 自底向上方法
// 类似与矩阵链乘问题，见算法导论
int rob3(int* nums, int numsSize) 
{
    if (numsSize <=0)
        return 0;
    int **array = malloc(sizeof (int *) * numsSize);
    for (int i=0; i<numsSize; i++)
        array[i] = malloc(sizeof (int) * numsSize);

    for (int i=0; i<numsSize; i++)
        array[i][i] = nums[i];
    // 按照长度的顺序来对 array 自底向上赋值
    for (int length=2; length<=numsSize; length++) { // length: i到j的元素个数
        for (int i=0; i<numsSize-length+1; i++) {
            int j = i + length -1;
            array[i][j] = INT_MIN;
            for (int k=i; k<=j; k++) {
                int tmp=nums[k];
                if (k>=2+i && k<=j-2) // 前面和后面都存在子问题
                    tmp += array[i][k-2] + array[k+2][j];
                else if (k<=j-2) // 之后后面存在子问题
                    tmp += array[k+2][j];
                else if (k>=2+i) // 只有前面存在子问题
                    tmp += array[i][k-2];
                if (array[i][j] < tmp)
                    array[i][j] = tmp;
            }
        }
    }
    return array[0][numsSize-1];
}
// Accepted

/* 其实还有更简单的递归式
 * 设 dp[i] 为到位置 i 时的结果，分为使用num[i] 和不使用 num[i] 两种情况
 *      dp[i] = max(num[i] + dp[i - 2], dp[i - 1])
 * 下面按照这个新的递归式重新求解
 */
#define max(a,b) (a) > (b) ? (a) : (b)
int rob4(int* nums, int numsSize) 
{
    if (numsSize <= 0)
        return 0;
    int dp[numsSize];
    dp[0] = nums[0];
    if (numsSize > 1)
        dp[1] = max(dp[0], nums[1]);
    for (int i=2; i<numsSize; i++) {
        dp[i] =  max(nums[i] + dp[i-2], dp[i-1]);
    }
    return dp[numsSize-1];
}
// Accepted



int main()
{
    int a[]={1, 2, 3, 4, 5};
    int res = rob4(a, sizeof a / sizeof a[0]);
    printf("res=%d\n", res);
    return 0;
}
