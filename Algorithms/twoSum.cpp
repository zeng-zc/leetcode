// https://leetcode.com/problems/two-sum/
/*
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2 
 */
#include <map>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> mp;
            vector<int> res;
            auto size=nums.size();
            for(int i=0; i<size; i++){
                mp[nums[i]] = i;
            }
            for(int i=0; i<size; i++){
                auto it = mp.find(target - nums[i]);
                if(it != mp.end() && it->second != i){ // `it->second != i`, easy to overlook!
                    res.push_back(i+1);
                    res.push_back(it->second +1);
                    break;
                }
            }
            return res;
        }
};
/* easy to make mistake:
 * forget the condition `it->second != i`, error for input `{3,2,4}, 6`,
 * which returns [1,1]
 */

int main(){
    vector<int> vi={3, 2, 4};
    //vector<int> vi={2, 7, 11, 15};
    Solution s;
    auto res = s.twoSum(vi, 6);
    for(auto it: res)
        cout << it << " ";
    cout << endl;
    return 0;
}
