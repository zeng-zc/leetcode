// https://leetcode.com/problems/happy-number/
/*
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 *     12 + 92 = 82
 *     82 + 22 = 68
 *     62 + 82 = 100
 *     12 + 02 + 02 = 1
 *
 */

// 由于要用到集合，所以考虑 c++
//

#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        set<int> si;
        si.insert(n);
        while(true){
            n=sum_square(n);
            if(n==1)
                return true;
            auto ret = si.insert(n);
            if(ret.second == false)
                return false;
        }
    }

    int sum_square(int n){
        int res=0, tmp;
        while (n != 0){
            tmp=(n%10); 
            n/=10;
            res += tmp * tmp;
        }
        return res;
    }
};

int main(){
    Solution s;
    cout<<"n=19: "<<s.isHappy(19)<<endl;
    cout<<"n=23: "<<s.isHappy(23)<<endl;
    cout<<"n=34: "<<s.isHappy(34)<<endl;
}

