// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// algo: only sorts, don't remove dumplicate elements
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1);
        std::sort(nums2);
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        vector<int> res;
        while(it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 < *it2) {
                ++it1;
            } else if (*it1 == *it2) {
                res.emplace(res.end(), *it2);
                ++it1, ++it2;
            }else
                ++it2;
        }
        return res;
    }
};

// accepted
