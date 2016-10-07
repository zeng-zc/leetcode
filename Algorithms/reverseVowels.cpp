// https://leetcode.com/problems/reverse-vowels-of-a-string/
// 一头一尾两个指针向中间靠拢
// 这是最直观的算法
// 易错点：不要忽略了大写元音字母

class Solution {
public:
    bool isvowel(const char c) {
        std::set<char> vowel{'a', 'o', 'e', 'i', 'u',
            'A', 'O', 'E', 'I', 'U'};
        if (find(vowel.begin(), vowel.end(), c) != vowel.end())
            return true;
        else
            return false;
    }
    string reverseVowels(string s) {
        int i, j;
        for (i=0, j=s.size()-1; i<j;) {
            if (isvowel(s[i]) && isvowel(s[j])) {
                std::swap(s[i++], s[j--]);
            } else { 
                if(!isvowel(s[i]))
                    ++i;
                if(!isvowel(s[j]))
                    --j;
            }
        }
        return s;
    }
};
// accepted, but too slow, 992ms

class Solution {
public:
    bool isvowel(const char c) {
        std::array<char, 10> vowel{'a', 'o', 'e', 'i', 'u',
            'A', 'O', 'E', 'I', 'U'};
        int i;
        for (i=0; i<10; ++i) {
            if (vowel[i] == c)
                break;
        }
        return i!=10;

    }
    string reverseVowels(string s) {
        int i, j;
        for (i=0, j=s.size()-1; i<j;) {
            bool flag1 = isvowel(s[i]);
            bool flag2 = isvowel(s[j]);
            if (flag1 && flag2) {
                std::swap(s[i++], s[j--]);
            } else { 
                if(!flag1)
                    ++i;
                if(!flag2)
                    --j;
            }
        }
        return s;
    }
};
// 19ms
// 改进点：
// (1)如果简单的std::array 能满足需求，就不要上std::set 这些红黑树结构，拖慢了速度
// (2)缓存函数调用结果，不要重复调用函数。
