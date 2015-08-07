/* https://leetcode.com/problems/jump-game/
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

 Each element in the array represents your maximum jump length at that position.

 Determine if you are able to reach the last index.

 For example:
 A = [2,3,1,1,4], return true.

 A = [3,2,1,0,4], return false. 
*/

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            stack<int> stk;
            int i=0;
            auto size = nums.size();
            if(size == 0 || size == 1)
                return true;
            int step = nums[i];
            while(1){
                while(step != 0){
                    i += step;
                    stk.push(step);
                    if(i >= size-1)
                        return true;
                    step = nums[i];
                }
                if(stk.empty())
                    return false;
                step = stk.top();
                stk.pop();
                i -= step;
                step--;
            }
            return true;
        }
/* notes:
 * This version is Time Limit Exceeded on leetcode.
 * There are too many duplicated pop and push.
 * And the logic is a bit complicated, it's easy to make a mistake.
 * Now find a more effective solution.
 */

        bool canJump2(vector<int>& nums) {
            int coverage = nums[0];
            auto size = nums.size();
            if(size == 0 || size == 1)
                return true;
            for(int i=0; i<size-1; i++){
                if(i <= coverage && i + nums[i] > coverage)
                    coverage = i + nums[i];
                if(coverage >= size-1)
                    return true;
            }
            return false;
        }
/* notes:
 * It's very easy to forget the condition i<=coverage in the for loop.
 * The coverage area must be connected. See example [0, 2, 3].
 */
};

int main(){
    Solution s;
    vector<int> s1={2,3,1,1,4};
    vector<int> s2={3,2,1,0,4};
    cout << s.canJump2(s1) << endl;
    cout << s.canJump2(s2) << endl;
    return 0;
}
