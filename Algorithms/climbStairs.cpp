/* https://leetcode.com/problems/climbing-stairs/
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top? 
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
    public:
        map<int, int> table;
        int climbStairs(int n) {
            if (n == 1){ 
                table[1] = 1;
                return table[n];
            }
            if (n == 2){
                table[2] = 2;
                return table[n];
            }
            if(table[n] == 0){
                table[n] = climbStairs(n-1) + climbStairs(n-2);
                return table[n];
            }
            else
                return table[n];
        }

        // use vector
        int climbStairs2(int n){ 
            vector<int> res(n+1);  
            res[0] = 1;  
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
