// https://leetcode.com/problems/summary-ranges/
/*
 Given a sorted integer array without duplicates, return the summary of its
ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        auto it1 = nums.begin();
        decltype(it1) it2 = it1+1, pre=it1;
        vector<string> res;
        if(nums.empty())
            return res;
        while(true){
            while(it2 != nums.end() && *it2 - *pre == 1){
                pre = it2;
                it2++;
            }
            if(*pre == *it1)
                res.push_back(to_string(*it1));
            else
                res.push_back(to_string(*it1) + "->" + to_string(*pre));
            if(it2 == nums.end())
                return res;
            it1 = it2;  // maintain the three iterator variables.
            pre = it1;
            it2++;
        }
    }
};

// Accepted.
