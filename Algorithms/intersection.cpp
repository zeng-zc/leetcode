// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    void sort_uniq(vector<int> &nums1) {
        std::sort(nums1.begin(), nums1.end());
        auto it = std::unique(nums1.begin(), nums1.end());
        nums1.resize(std::distance(nums1.begin(), it));
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort_uniq(nums1);
        sort_uniq(nums2);
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
