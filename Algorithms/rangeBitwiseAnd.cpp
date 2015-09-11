// https://leetcode.com/problems/bitwise-and-of-numbers-range/#include <iostream>

/* Algorithm:
 * 2 consecutive number AND will cause 1 lowest bit to be 0.
 * 3 ..................................2...................
 * 5 => 3
 * 
 * Understand it in another way, 2 bits can cantain 4 numbers, 
 * then 4+1 numbers will cause the 3nd bit to switch
 * between 1 and 0 (thus cause the AND of the 3nd bit to be 0).
 *
 * Generally:
 * pth_bit_to_be_0    must_have_at_least_q_numbers
 *    1                     2 = 2^0 + 1
 *    2                     3 = 2^1 +1
 *    3                     5 = 2^2 +1
 *    4                     9 = 2^3 +1
 *    ...                       ...
 *  p = log2(q-1) = log2(n-m)
 *
 *  So the algorithm is:
 *  (1) Given q, compute p;
 *  (2) The p lowest bit of the final result will be zero.
 *
 */
using namespace std;
class Solution {
    public:
        int rangeBitwiseAnd(int m, int n) {
            int diff = n-m;  // q = diff+1;
            int bitNums=0; // p
            if (diff==0)
                return m;
            while(diff != 0){
                diff >>= 1;
                bitNums++;
            }
            unsigned int  mask = (0xffffffff << bitNums);
            return m & mask & n;
        }
};

int main(){
    Solution s;
    cout << s.rangeBitwiseAnd(3, 4) << endl;
    return 0;
}

// Accepted.
