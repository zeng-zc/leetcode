/* https://leetcode.com/problems/combinations/
 Given two integers n and k, return all possible combinations of k numbers out
of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

// recursively backtrack
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> vi;

    vector<vector<int>> combine(int n, int k) {
        if(k>n)
            return res;
        backtracker(n, k, 0);
        return res;
    }

    void backtracker(int n, int k, int max){ // max: the maximum value in current vi.
        if(vi.size() == k){
            res.push_back(vi);
            return;
        }
        for(int i= max+1; i<=n; i++){
            vi.push_back(i);
            backtracker(n, k, i);
            vi.pop_back();
        }
    }

};

/* Now I write another version not to use the globals.
 */
class Solution2 {
public:
    vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
        if(k>n)
            return res;
        vector<int> vi;
        backtracker(vi, n, k, res);
        return res;
    }

    void backtracker(vector<int> &vi, int n, int k, 
            vector<vector<int>> &res){ 
        if(vi.size() == k){
            res.push_back(vi);
            return;
        }

        int max;
        if(vi.empty())
            max = 0;
        else
            max = vi.back();

        for(int i= max+1; i<=n; i++){
            vi.push_back(i);
            backtracker(vi, n, k, res);
            vi.pop_back();
        }
    }

};



int main(){
    Solution2 s;
    auto res = s.combine(4,2);
    for(auto it: res){
        for(auto it2: it)
            cout << it2 << " ";
        cout << endl;
    }
    return 0;
}
