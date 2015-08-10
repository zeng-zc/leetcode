/* https://leetcode.com/problems/combination-sum/
 Given a set of candidate numbers (C) and a target number (T), find all unique
combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending
order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> vi;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        auto nums = candidates;
        sort(nums.begin(), nums.end());  // notes: the input nums are not sorted.
        auto size = nums.size();
        backtracker(nums, 0, target);
        return res; 
    }

    void backtracker(vector<int>& nums, int maxindex, int target){ 
        int sum=0;
        for(auto element: vi)
            sum += element;
        if(sum == target){
            res.push_back(vi);
            return;
        }else if(sum > target)
            return;  // failure also returns
        auto size = nums.size();
        for(int i = maxindex; i<size; i++){
            vi.push_back(nums[i]);
            backtracker(nums, i, target);
            vi.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<int> nums{2,3, 6, 7};
    vector<int> nums2{48,22,49,24,26,47,33,40,37,39,31,46,36,43,45,34,28,20,29,25,41,32,23};
    int target2 = 69;
    vector<int> nums3{2,3, 6, 7, 10};
    int target3 = 20;
    auto res = s.combinationSum(nums3, target3);
    for(auto it: res){
        for(auto it2: it)
            cout << it2 << " ";
        cout << endl;
    }
    return 0;
}
