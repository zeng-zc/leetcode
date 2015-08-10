/* https://leetcode.com/problems/combination-sum-ii/
 Given a collection of candidate numbers (C) and a target number (T), find all
unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending
order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Solution 2 below is the final answer.
class Solution {
public:
    vector<vector<int>> res;
    vector<int> vi;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        auto nums = candidates;
        sort(nums.begin(), nums.end());  // notes: the input nums are not sorted.
        auto size = nums.size();
        for(int i=1; i<=size; i++)
            backtracker(nums, i, -1, target);
        return res; 
    }

    void backtracker(vector<int>& nums, int k, int maxindex, int target){ 
        int sum=0;
        int visize = 0;
        for(auto element: vi){
            sum += element;
            visize++;
        }
        if(visize == k || sum >= target){
            if(sum == target)
                res.push_back(vi);
            return;
        }
        auto size = nums.size();
        for(int i = maxindex+1; i<size; i++){
            if(i > maxindex+1 && nums[i] == nums[i-1]) // nums may have dupicated values.
                continue;
            vi.push_back(nums[i]);
            backtracker(nums, k, i, target);
            vi.pop_back();
        }
    }

};  
/* notes:
 * The above version was *Time Limit Exceeded* on leetcode.
 * It's not neccesary to divide it into 1,2,3... elements subset.
 * So the backtracker method doesn't need the parameter k.
 * Below is improver one. Accepted on leetcode.
 */
class Solution2 {
public:
    vector<vector<int>> res;
    vector<int> vi;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        auto nums = candidates;
        sort(nums.begin(), nums.end());  // notes: the input nums are not sorted.
        auto size = nums.size();
        backtracker(nums, -1, target);
        return res; 
    }

    void backtracker(vector<int>& nums, int maxindex, int target){ 
        int sum=0;
        for(auto element: vi){
            sum += element;
            if(sum == target){
                res.push_back(vi);
                return;
            }else if(sum > target)
                return;
        }
        auto size = nums.size();
        for(int i = maxindex+1; i<size; i++){
            if(i > maxindex+1 && nums[i] == nums[i-1]) // nums may have dupicated values.
                continue;
            vi.push_back(nums[i]);
            backtracker(nums, i, target);
            vi.pop_back();
        }
    }

};  

int main(){
    Solution s;
    vector<int> nums2{10,1,2,7,6,1,5};
    int target2 = 8;
    vector<int> nums4{18,6,18,18,11,30,18,33,24,18,17,15,29,8,18,30,28,34,10,28,20,34,5,15,18,28,34,7,10,8,33,23,31,16,29,7,33,12,27,23,18,9,25,34,34,30,29,27,21,26,21,6,25,21,16,30,6,15,32,11,10,23,30,29,26,24}; 
    int target4=  28;
    auto res = s.combinationSum2(nums4, target4);
    for(auto it: res){
        for(auto it2: it)
            cout << it2 << " ";
        cout << endl;
    }
    return 0;
}
