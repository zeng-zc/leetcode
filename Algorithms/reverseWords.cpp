// https://leetcode.com/problems/reverse-words-in-a-string/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
    public:
        void reverseWords(string &s) {
            vector<string> buff;
            auto sz = s.size();
            for (int i=0; i < sz;  ) {
                if (!isspace(s[i])) {
                    string word;
                    do {
                        word.push_back(s[i++]);
                    } while(i < sz && !isspace(s[i]));
                    buff.push_back(word);
                } else
                    i++;
            }

            s.erase();
            for (int i=buff.size()-1; i>=0; i--) {
                s += buff[i];
                s += " ";
            }
            if (!s.empty())
                s.pop_back();
        }
};

int main(){
    Solution s;
    string str(" i love  leetcode ");
    s.reverseWords(str);
    std::cout << "/"+str+"/" << std::endl;
    string str2(" love ");
    s.reverseWords(str2);
    std::cout << "/"+str2+ "/"<< std::endl;
    string str3("  programming  is fun.  ");
    s.reverseWords(str3);
    std::cout << "/" + str3 +"/" << std::endl;
    return 0;
}
