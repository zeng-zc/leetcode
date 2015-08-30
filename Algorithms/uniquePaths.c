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


#include <stdio.h>
int main(){
    int m=10, n=10;
    printf("m=%d, n=%d, res=%d\n", m, n, uniquePaths(m, n));
    return 0;
}
