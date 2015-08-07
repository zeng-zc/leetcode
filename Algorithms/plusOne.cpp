/* https://leetcode.com/problems/plus-one/
Given a non-negative number represented as an array of digits, plus one to the
number.

The digits are stored such that the most significant digit is at the head of
the list.

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto size = digits.size();
        vector<int> res;
        bool carry = true;
        int i;
        for(i = size-1; i>=0; i--){
            if(carry){
                if(digits[i] + 1 == 10){
                    res.insert(res.begin(), 0);
                    carry = true;
                }else{
                    res.insert(res.begin(), digits[i]+1);
                    carry = false;
                }
            } else {
                res.insert(res.begin(), digits[i]);
            }
        }
        if(carry)
            res.insert(res.begin(), 1);
        return res;
    }
};

