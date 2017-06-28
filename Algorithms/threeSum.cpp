// https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::multimap<int, int> mmap;
        for (int i=0; i<nums.size(); ++i) {
            mmap.insert(std::make_pair(nums[i], i));
        }

        vector<vector<int>> res;
        for (auto it1=mmap.begin(); it1!=mmap.end(); ++it1) {
            for (auto it2=it1+1; it2!=mmap.end(); ++it2) {
                int target = -it1->first - it2->first;
                for (auto it3=mmap.lower_bound(target); 
                        it3 != mmap.upper_bound(target);
                        ++it3) {
                    if (it3 != mmap.end() && *it3->first == target && 
                            it3->second != it1->second &&
                            it3->second != it2->second)
                        res.push_back(std::vector(it1->first, it2->first, it3->first));
                }
            }
        }
        return res; 
    }
};
