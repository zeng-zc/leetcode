/* https://leetcode.com/problems/longest-common-prefix/
 * Write a function to find the longest common prefix string amongst an array
 * of strings. 
 */

// recursion.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int size = strs.size();
        if(size == 0)
            return res;
        if(size == 1)
            return strs[0];
        vector<string> sub;
        sub.insert(sub.begin(), strs.begin()+1, strs.end());
        auto res_sub = longestCommonPrefix(sub);
        auto size1 = strs[0].size();
        auto size2 = res_sub.size();
        int i;
        for(i=0; i<size1 && i<size1; i++)
            if(strs[0][i] != res_sub[i])
                break;
        res = res_sub.substr(0, i);
        return res;
    }
};

// accpted for the first submit.
