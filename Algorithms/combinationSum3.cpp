/* https://leetcode.com/problems/combination-sum-iii/


Find all possible combinations of k numbers that add up to a number n, given
that only numbers from 1 to 9 can be used and each combination should be a
unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.

Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]


Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> vi;

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracker(k, n, 0);
        return res;
    }

    void backtracker(int k, int n, int max){ // max: the maximum value in current vi.
        int sum=0;
        int visize=0;
        for(auto element: vi){
            visize++;
            sum += element;
        }
        if(visize == k){
            if(sum == n)
                res.push_back(vi);
            return;
        }
        for(int i= max+1; i<=9; i++){
            vi.push_back(i);
            backtracker(k, n, i);
            vi.pop_back();
        }
    }

};


int main(){
    Solution s;
    auto res = s.combinationSum3(3,7);
    for(auto it: res){
        for(auto it2: it)
            cout << it2 << " ";
        cout << endl;
    }
    return 0;
}
