// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// 感觉比 twoSum 1 要更简单！ 
class Solution { 
public: 
    vector<int> twoSum(vector<int>& numbers, int target) { 
            vector<int> res; for (int i=0; i<numbers.size(); ++i) {
            auto ret = std::lower_bound(numbers.begin()+i+1, numbers.end(), target-numbers[i]);
            if (ret != numbers.end() && *ret==target-numbers[i]) {  
                // 注意使用lower_bound 一定要对返回值做相等性检验！
                res.push_back(i+1);  // 下标从1开始
                res.push_back(std::distance(numbers.begin(), ret) + 1 );
                break;
            }
        }
        return res; 
    }
};

// 16ms
