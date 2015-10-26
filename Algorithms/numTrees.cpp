// https://leetcode.com/problems/unique-binary-search-trees/
/*
 *  以第 i (i=0,1,2...n-1)个节点为根节点时，其左子树有 i 个节点，右子树
 *  有 n-1-i 个节点，所以这种情况共有 p(i)*p(n-i-1) 颗树。所以n个节点的结果为
 *    p(n) = \sigma_{i=0}^{n-1}{p(i)*p(n-i-1)}
 *  注意初始值 p[0]=1;
 *  这是个卡特兰数。
 *  用自底向上的动态规划来求解。
 */

#include <vector>
class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dp(n+1, 0); // dp[i] 表示总共i个节点对应的结果数
        dp[0] = 1;
        for (int i=1; i<=n; i++) { // i 为总节点个数
            for (int j=0; j<i; j++) { // j 为左子树节点个数
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};
// Accepted

#include <iostream>
int main()
{
    Solution s;
    std::cout << s.numTrees(1) << std::endl;
    std::cout << s.numTrees(2) << std::endl;
    std::cout << s.numTrees(3) << std::endl;
    return 0;
}
