/* https://leetcode.com/problems/climbing-stairs/
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

// 查表法的裴波拉契数列。
// 查表递归方法（自顶向下）
int * init_table(int n)
{
    int *table = malloc(sizeof(int) * (n+1));
    for (int i=0; i<=n; i++)
        table[i] = -1;
    return table;
}

int helper(int n, int *table)
{
    if (n==0 || n==1)
        return 1;
    if (table[n] < 0)
        table[n] = helper(n-1, table) + helper(n-2, table);
    return table[n];
}

int climbStairs(int n)
{
    int *table = init_table(n);
    return helper(n, table);
}


// bottom-up building the table
// no recursion function, simper
int climbStairs3(int n)
{ 
    int *table = malloc(sizeof(int) * (n+1));
    table[0] = 1;  
    if (n > 0)
        table[1] = 1;  
    for (int i = 2; i <= n; i++){  
        table[i] = table[i-1] + table[i-2];  
    }  
    return table[n];  
}  

