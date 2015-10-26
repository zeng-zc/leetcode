// https://leetcode.com/problems/ugly-number-ii/
/*
 *  Write a program to find the n-th ugly number.
 *
 *  Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 *
 *  Note that 1 is typically treated as an ugly number.
 *
 *  Hint:
 *
 *      The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
 *          An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
 *              The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
 *                  Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
 *
 *                  Credits:
 *                  Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 *
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>
/* Algorithm:
 * similar to merging 3-way sorted array.
 * array1: 1, 2, 4, 6, 8, ....;
 * array2: 1, 3, 6, 9, 12, ....;
 * array3: 1, 5, 10, 15, 20, ....;
 * Pop a smallest number x at the front of the three vectors;
 * then push 2x, 3x, 5x at the back!
 */
class Solution {
    public:
        int nthUglyNumber(int n) {
            std::vector<int>l1={1}, l2=l1, l3=l1;
            int count=0;
            while(true){
                int cur = std::min(std::min(l1.front(), 
                            l2.front()), l3.front());
                if(l1.front() == cur)
                    l1.erase(l1.begin());
                if(l2.front() == cur)
                    l2.erase(l2.begin());
                if(l3.front() == cur)
                    l3.erase(l3.begin());
                count++;
                if(count == n)
                    return cur;
                l1.push_back(cur*2);
                l2.push_back(cur*3);
                l3.push_back(cur*5);
            }
        }
};

int main(){
    Solution s;
    std::cout << s.nthUglyNumber(10) << std::endl;
    std::cout << s.nthUglyNumber(1) << std::endl;
    return 0;
}
