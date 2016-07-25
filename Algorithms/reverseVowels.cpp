// https://leetcode.com/problems/reverse-vowels-of-a-string/
// 一头一尾两个指针向中间靠拢
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

// accepted
