// https://leetcode.com/problems/count-primes/
/*
 * Description:
 *
 * Count the number of prime numbers less than a non-negative number, n.
 */
// 筛法，hint 非常给力。
class Solution {
    public:
        int countPrimes(int n) {
            bool isPrime[n];
            for(int i=2; i<n; i++)
                isPrime[i] = true;
            for(int i=2; i*i<n; i++){
                if(isPrime[i] == false)
                    continue;
                for(int j=i*i; j<n; j+=i)
                    isPrime[j] = false;
            }
            int count=0;
            for(int i=2; i<n; i++)
                if(isPrime[i])
                    count++;
            return count;
        }
};
