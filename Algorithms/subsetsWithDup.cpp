/* https://leetcode.com/problems/subsets-ii/
 Given a collection of integers that might contain duplicates, nums, return
all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        auto size = nums.size();
        auto copy = nums;  // we don't alter nums
        sort(copy.begin(), copy.end());  // notes: the input nums are not sorted.
        for(int i=0; i<=size; i++)
            backtracker(copy, i, -1);
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
            if(i > maxindex+1 && num[i] == num[i-1])
                continue;
            vi.push_back(num[i]);
            backtracker(num, k, i);
            vi.pop_back();
        }
    }
/* notes:
 * The above for loop, at the firts time of the loop, 
 * we always push and call itself. But after that, we should check whether
 * it's duplicated as the previous one.
 */

};

int main(){
    Solution s;
    vector<int> nums{1,2,2};
    auto res = s.subsetsWithDup(nums);
    for(auto it: res){
        for(auto it2: it)
            cout << it2 << " ";
        cout << endl;
    }
    return 0;
}
