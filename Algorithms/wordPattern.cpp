// https://leetcode.com/problems/word-pattern/

// 都映射为[1,2,2,1] 这样的形式。使用模板
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        istream_iterator<string> in_iter(ss), eof;
        vector<string> vecStr(in_iter, eof);
        auto res1 = mapToOrdinal(pattern.begin(), pattern.end());
        auto res2= mapToOrdinal(vecStr.begin(), vecStr.end());
        return res1 == res2;
    }
    
// map [abba] to [1,2,2,1]
    template<typename Iter>
    vector<int> mapToOrdinal(Iter beg, Iter end) {
        int i=0;
        vector<int> res;
        map<typename std::remove_reference<decltype(*beg)>::type, int> mapping;
        for (auto it=beg; it!=end; ++it) {
            auto found = mapping.find(*it);
            if (found == mapping.end()) {
                mapping[*it] = ++i;
            }
            res.push_back(mapping[*it]);
        }
        return res;
    }
};
