// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    string reverseString(string s) {
        string res;
        std::copy(s.rbegin(), s.rend(), back_inserter(res));
        return res;
    }
};


// solution 2
class Solution {
public:
    string reverseString(string s) {
        std::reverse(s.begin(), s.end());
        return s;
    }
};
