// https://leetcode.com/problems/unique-paths/
/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start'
 * in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The
 * robot is trying to reach the bottom-right corner of the grid (marked
 * 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 */

// comupte combinatorial number C(m+n-2, m-1)
int uniquePaths(int m, int n) {
    long p1=1, p2=1;
    int min = m<n ? m : n;
    min = min-1;
    for(int i=1; i<=min; i++){
        p1 *= (n+m-1-i); // p1 may overflow, should be declared as long.
        p2 *= i;
    }
    return p1/p2;
}
// An easy error: overflow

/* use this recursion formular to compute combination number C(n, m):
 *      c(n,m) = c(n-1,m-1) + c(n-1,m) for m=1, 2, ..., n-1
 */
// 下面的程序，画个矩阵图更好理解
int combination(int n, int m) // choose m from n
{
    if (n == 0 || m>n)
        return 1;
    int array[n+1][n+1];
    for (int i=0; i<=n; i++)
        array[i][0] = array[i][i] = 1; // 第0列全为1, 对角线全为1
    for (int i=2; i<=n; i++) {
        for (int j=1; j<i; j++) {
            array[i][j] = array[i-1][j-1] + array[i-1][j]; 
        }
    }
    return array[n][m];
}

int uniquePaths2(int m, int n) 
{
    return combination(m+n-2, m-1);
}

#include <stdio.h>
int main(){
    int m=10, n=10;
    printf("m=%d, n=%d, res=%d\n", m, n, uniquePaths2(m, n));
    printf("m=%d, n=%d, res=%d\n", m, n, uniquePaths(m, n));
    return 0;
}
