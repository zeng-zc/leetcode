// https://leetcode.com/problems/word-break/
/* Algorithm:
 * DP
 * 用 bool 数组 dp[i] 来保存包含i个字符串(从位置0开始)是否能成功
 * 关键是找递归式：
 *      dp[i+1]为true，当且仅当存在一个j，使得 dp[j] 为true 且
 *      s[j, i+1] 在字典中。
 */

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        auto size = s.size();
        bool res[size+1]={false}; // res[i] 表示包含 i(i=0, 1, 2, ... size) 个字符串的结果
        res[0] = true;
        for (int i=1; i<=size; i++) {  // i 为元素个数
            for (int j=0; j<=i; j++) { // j 也是元素个数
                auto tmp = s.substr(j, i-j); // substr 的第二个参数是元素个数！
                if (res[j] && wordDict.find(tmp) != wordDict.end()) {
                    res[i] = true;
                    break;
                }
            }
        }
        return res[size];
    }
};
// Accepted

// 注意 string 的substr 方法的api
