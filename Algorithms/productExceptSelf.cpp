/* https://leetcode.com/problems/product-of-array-except-self/
 Given an array of n integers where n > 1, nums, return an array output such
that output[i] is equal to the product of all the elements of nums except
nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array
does not count as extra space for the purpose of space complexity analysis.)
*/

// Not my own idea, reference to Discuss:
// https://leetcode.com/discuss/46104/simple-java-solution-in-o-n-without-extra-space
// Two passes: left->right, right->left
#include <iostream>
#include <vector>
using namespace std;

class Solution { 
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++)
            res[i] = res[i - 1] * nums[i - 1];

        int right = 1;  // cum product of the right part
        for (int i = n - 1; i >= 0; i--){
            res[i] *= right;
            right *= nums[i];
        }
        return res; 
    }
};


int main(){
    vector<int> nums={1,2,3,4};
    vector<int> nums2={8};
    Solution s;
    auto res=s.productExceptSelf(nums);
    for(auto i: res)
        cout << i << " ";
    cout << endl;
    res=s.productExceptSelf(nums2);
    for(auto i: res)
        cout << i << " ";
    cout << endl;
    return 0;
}
