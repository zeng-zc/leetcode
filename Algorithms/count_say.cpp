// https://leetcode.com/problems/count-and-say/#/description
// accepted
class Solution {
public:
    string countAndSay(int n) {
        if (n<1)
            return "";
        if (n==1) {
            table[1] = "1";
            return "1";
        }
        if (table.count(n))
            return table[n];
        else {
           auto res =  getNext(countAndSay(n-1));
           return table[n] = res;
        }
    }

    string getNext(std::string prev) {
        std::string result;
        int i,j, repeated=1;
        std::stringstream ss;
        prev += "0"; // 最后加一个哨兵元素，0 不可能跟任何字符相同
        for (i=0, j=1; j< prev.size(); ++i, ++j) {
            if (prev[j] == prev[i])
                repeated++;
            else {
                ss << repeated << prev[i];
                result += ss.str();
                ss.str("");
                repeated = 1;
            }
        }
        return result;
    }
private:
    std::map<int, std::string> table;
};

