// https://leetcode.com/problems/guess-number-higher-or-lower/
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

// 注意别把 guess 的api搞反了，出题者的数字太小时返回-1，而不是答题者的太小！
int guess(int num);
class Solution {
public:
    int guessNumber(int n) {
        int beg=1, end=n, res=-1;
        while(beg <= end && res == -1) {
            int mid=beg+(end-beg)/2;
            switch(guess(mid)) {
                case 1:
                    beg = mid+1;
                    break;
                case 0:
                    res = mid;
                    break;
                case -1:
                    end = mid-1;
                    break;
            }
        }
        return res;
    }
};
