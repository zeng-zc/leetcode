/* https://leetcode.com/problems/add-binary/
 Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        auto size_a = a.size();
        auto size_b = b.size();
        string res;
        string zero(llabs(size_a - size_b), '0'); // padding zeroes
        if(size_a < size_b)
            a.insert(a.begin(), zero.begin(), zero.end());
        else
            b.insert(b.begin(), zero.begin(), zero.end());
        for(int i = max(size_a, size_b)-1; i>=0; i--){
            auto tmp = carry + (a[i]-'0') + (b[i]-'0'); // be care of the conversion
            carry = tmp/2; 
            res.insert(res.begin(), tmp%2 + '0'); // caution: don't forget to convert to char
        }
        if(carry == 1)
            res.insert(res.begin(), '1');
        if(res.empty())
            res.push_back('0');
        return res;
    }
};

