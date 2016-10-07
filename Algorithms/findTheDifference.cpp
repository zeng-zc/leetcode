// https://leetcode.com/problems/find-the-difference/

// 使用STL 的 std::multiset 容器，以及 std::set_difference 算法
class Solution {
public:
    char findTheDifference(string s, string t) {
        std::multiset<char> s1,s2;
        std::vector<char> diff;
        for(auto c: s) {
            s1.insert(c);
        }
        for(auto c: t)
            s2.insert(c);
        auto res = std::set_difference(s2.begin(), s2.end(),
            s1.begin(), s1.end(), std::back_inserter(diff));
        return diff[0];
    }
};



// C 解法
// 自己构建hash表
char findTheDifference(char* s, char* t) {
    char hashtable1[26]={0}, hashtable2[26]={0};
    for(; *s; ++s) {
        ++hashtable1[*s-'a'];
    }
    for(; *t; ++t) {
        ++hashtable2[*t-'a'];
    }
    int i;
    for (i=0; i!=26; ++i) {
        if (hashtable2[i] != hashtable1[i])
            break;
    }
    return i+'a';
}
