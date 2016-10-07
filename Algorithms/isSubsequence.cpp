// https://leetcode.com/problems/is-subsequence/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        decltype(t.size()) pos = -1;
        for(auto &c: s) {
            pos = t.find(c, pos+1);
            if (pos == std::string::npos)
                return false;
        }
        return true;
    }
};

// beats 99.1%
