// https://leetcode.com/problems/isomorphic-strings/
// abb 和 cdd 映射成 122 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char dict1[256]{}, dict2[256]{}; // dict1 记录某个字符首次出现时的下标
        int sidx=0, tidx=0; // 记录当前字符是第几个唯一字符
        for (int i=0; i<s.size(); i++) {
            int tmp1, tmp2;
            if (dict1[s[i]] == 0) { // 当前字符首次出现
                dict1[s[i]] = ++sidx;
                tmp1 = dict1[s[i]];
            } else   // 之前出现过
                tmp1 = dict1[s[i]];
            if (dict2[t[i]] == 0) {
                dict2[t[i]] = ++tidx;
                tmp2 = dict2[t[i]];
            } else
                tmp2 = dict2[t[i]];
            if (tmp1 != tmp2)
                return false;
        }
        return true;
        
    }
};

// accepted
