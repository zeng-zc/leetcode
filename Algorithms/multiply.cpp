/* https://leetcode.com/problems/multiply-strings/
Given two numbers represented as strings, return multiplication of the numbers
as a string.

Note: The numbers can be arbitrarily large and are non-negative.
class Solution {
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int carry = 0;
        string res;
        auto size1 = num1.size();
        auto size2 = num2.size();
        string *shortter;  // point to the shotter one
        string *longer;  // point to the longer one
        if(size1 < size2){
            shortter = &num1;
            longer = &num2;
        }
        else{
            shortter = &num2;
            longer = &num1;
        }
        for(int i = shortter->size()-1; i>=0; i--){
            auto digit = (*shortter)[i]-'0';
            if(digit == 0)
                continue;  // return in advance
            auto cur = this->multi_one_digit(*longer, digit);
            string zero(shortter->size()-i-1, '0');
            cur.insert(cur.end(), zero.begin(), zero.end());
            res = addBinary(res, cur);
        }
        if(res.empty())
            res.push_back('0');
        return res;
    }

    string multi_one_digit(string num, int digit){ // digit: 0~9
        if (digit == 0)
            return "0";
        int carry=0;
        string res;
        auto size = num.size();
        for(int i=size-1; i>=0; i--){
            int tmp = (num[i]-'0') * digit + carry;
            carry = tmp/10;
            res.insert(res.begin(), tmp%10 + '0');
        }
        if(carry != 0)
            res.insert(res.begin(), carry+'0');
        return res;
    }

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
            carry = tmp/10; 
            res.insert(res.begin(), tmp%10 + '0'); // caution: don't forget to convert to char
        }
        if(carry !=0)
            res.insert(res.begin(), carry+'0');
        if(res.empty())
            res.push_back('0');
        return res;
    }
};

