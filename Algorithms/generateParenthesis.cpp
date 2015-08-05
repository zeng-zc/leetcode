// https://leetcode.com/problems/generate-parentheses/
/*
 *  Given n pairs of parentheses, write a function to generate all
 *  combinations of well-formed parentheses.
 *
 *  For example, given n = 3, a solution set is:
 *
 *  "((()))", "(()())", "(())()", "()(())", "()()()" 
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        if(n==0)
            return vs;
        if(n==1){
            string tmp("()");
            vs.push_back(tmp);
            return vs;
        }
        vector<string> vs2 = generateParenthesis(n-1);
        for(auto &it: vs2){
            vs.push_back("("+it+")");
            string tmp1 = "()"+it;
            string tmp2 = it + "()";
            if(tmp1 == tmp2)
                vs.push_back(tmp1);
            else{
                vs.push_back(tmp1);
                vs.push_back(tmp2);
            }
        }
        return vs;
    }
};

int main(){
    Solution s;
    auto res = s.generateParenthesis(4);
    for(auto it: res)
        cout << it << endl;
    return 0;
}


/*
 * notes:
 * 很奇怪，我只是和 leetcode 产生的结果的顺序不同，它居然说我是错结果！
 */
