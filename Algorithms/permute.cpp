// https://leetcode.com/problems/permutations/
/*
 Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
*/

#include <vector>
#include <iostream>
using namespace std;

// recursion
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int size=nums.size();
        if(size == 0)
            return res;
        if(size == 1){
            res.push_back(nums);
            return res;
        }

        // everytime, remove one element and permute it.
        vector<int> nums2;
        for(auto it=nums.begin(); it != nums.end(); it++){
            swap(*it, nums[0]);
            nums2.clear();
            nums2.insert(nums2.begin(), nums.begin()+1, nums.end());
            auto sub = permute(nums2);
            for(auto ele=sub.begin(); ele != sub.end(); ele++)
                ele->insert(ele->begin(), nums[0]);
            res.insert(res.end(), sub.begin(), sub.end());
            swap(*it, nums[0]); // swap to reset
        }
        return res;
    }
// This version can be accpted by leetcode. But the output isn't ordered
// correctly. For example, [1,2,3] -> [[1,2,3], [1,3,2], [2,1,3], [2,3,1],
// [3,2,1], [3,1,2]]. [3,1,2] should be before [3,2,1].
// Now improve it.

    vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int>> res;
        int size=nums.size();
        if(size == 0)
            return res;
        if(size == 1){
            res.push_back(nums);
            return res;
        }

        // everytime, remove one element and permute it.
        vector<int> nums2;
        for(auto it=nums.begin(); it != nums.end(); it++){
            nums2.clear();
//            if(it > nums.begin())  // not necessary
                nums2.insert(nums2.begin(), nums.begin(), it);
            nums2.insert(nums2.end(), it+1, nums.end()); 
            auto sub = permute(nums2);
            for(auto ele=sub.begin(); ele != sub.end(); ele++)
                ele->insert(ele->begin(), *it);
            res.insert(res.end(), sub.begin(), sub.end());
        }
        return res;
    }

};

int main(){
    vector<int> vi={1, 2, 3};
    Solution s;
    auto res=s.permute2(vi);
    for(auto it: res){
        for(auto it2: it)
            cout << it2;
        cout << endl;
    }
    return 0;
}
