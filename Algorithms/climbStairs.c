/* https://leetcode.com/problems/climbing-stairs/
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

long f[1000];
int climbStairs(int n){
    if (n == 1) {
        f[0] = 1;
        return 1;
    }
    if (n == 2) {
        f[1] = 2;
        return 2;
    }
    if (f[n - 1] == 0)
        f[n - 1] = climbStairs(n - 1) + climbStairs(n - 2);
    return f[n - 1];
}

// 查表法的裴波拉契数列。
