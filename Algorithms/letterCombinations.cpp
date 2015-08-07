/* https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Given a digit string, return all possible letter combinations that the number
could represent.

A mapping of digit to letters (just like on the telephone buttons) is given
below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in
any order you want. 
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

// recursion
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> map={" ", "", "abc", "def",  // index 2 mapped to "abc"
                "ghi", "jkl", "mno",
                "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if(digits.size() == 0)
            return res;
        if(digits.size() == 1){
            for(auto c: map[digits[0]-'0']){
                res.push_back((string){c});
            }
            return  res;
        }
        string sub; // the substring, for recursion input
        sub.insert(sub.begin(), digits.begin()+1, digits.end());
        auto res_sub = letterCombinations(sub);
        for(auto it=res_sub.begin(); it!=res_sub.end(); it++){
            for(auto first: map[digits[0]-'0']){
                auto copy = *it;
                copy.insert(copy.begin(), first);
                res.push_back(copy);
            }
        }
        return res;
    }
};

/* notes:
 * very good! Accepted by leetcode at the first submit.
 */

int main(){
    Solution s;
    string digits("23");
    auto res = s.letterCombinations(digits);
    for(auto it: res)
        cout << it << " ";
    cout << endl;
    return 0;
}
