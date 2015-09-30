/* https://leetcode.com/problems/longest-common-prefix/
 * Write a function to find the longest common prefix string amongst an array
 * of strings. 
 */

class Solution {
  public:
      // recursion.
    string longestCommonPrefix(vector < string > &strs) {
        int size = strs.size();
        if (size == 0)
            return "";
        if (size == 1)
            return strs[0];
        vector < string > sub(strs.begin() + 1, strs.end());
        auto res_sub = longestCommonPrefix(sub);
        int i;
        for (i = 0; i < strs[0].size() && i < res_sub.size(); i++)
            if (strs[0][i] != res_sub[i])
                break;
        return res_sub.substr(0, i);
    }
    // accpted for the first submit.

    // non-recursion
    string longestCommonPrefix2(vector < string > &strs) {
        string res;
        auto sz = strs.size();
        if (0 == sz)
            return res;
        for (int i = 0; i < strs[0].size(); ++i) { // each char
            char t = strs[0][i];
            for (int j = 1; j < sz; ++j) {  // each string
                if (i >= strs[j].size() || t != strs[j][i])
                    return res;
            }
            res.push_back(t);
        }
        return res;
    }
};

