/* https://leetcode.com/problems/climbing-stairs/
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top? 
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/* Algorithm:
 * DP, let dp[i] stands for the result for i stairs, then recursion:
 *      dp[i] = dp[i-1] + dp[i-2]
 *      dp[0] = dp[1] =1
 * Build dp[0..n] from bottom to top.
 */

class Solution {
    public:
        int climbStairs(int n){ 
            vector<int> res(n+1);  
            res[0] = 1;  
            if (n > 0)
                res[1] = 1;  
            for (int i = 2; i <= n; i++){  
                res[i] = res[i-1] + res[i-2];  
            }  
            return res[n];  
        }  
};

int main(){
    Solution s;
    cout << s.climbStairs(5) << endl;
    return 0;
}
