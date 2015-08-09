/* https://leetcode.com/problems/subsets/
 Given a set of distinct integers, nums, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> vi;

    vector<vector<int>> subsets(vector<int>& nums) {
        auto size = nums.size();
        sort(nums.begin(), nums.end());  // notes: the input nums are not sorted.
        for(int i=0; i<=size; i++)
            backtracker(nums, i, -1);
        return res; 
    }

    void backtracker(vector<int>& num, int k, int maxindex){
        // maxindex: the index of maximum value in current vi.
        if(vi.size() == k){
            res.push_back(vi);
            return;
        }
        auto numsize = num.size();
        for(int i= maxindex + 1; i<numsize; i++){
            vi.push_back(num[i]);
            backtracker(num, k, i);
            vi.pop_back();
        }
    }

};

int main(){
    Solution s;
    vector<int> nums{1,2,3};
    auto res = s.subsets(nums);
    for(auto it: res){
        for(auto it2: it)
            cout << it2 << " ";
        cout << endl;
    }
    return 0;
}
