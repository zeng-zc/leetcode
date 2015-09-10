// https://leetcode.com/problems/contains-duplicate/
class Solution {

public:

    bool containsDuplicate(vector<int>& nums) {

        set<int> s;

        for(auto i=0; i<nums.size(); i++){

            auto ret = s.insert(nums[i]);

            if(ret.second == false)

                return true;

        }

        return false;

    }

};
