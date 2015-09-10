// https://leetcode.com/problems/pascals-triangle/
/*
 * 
 * Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> res;
            if(numRows<=0)  // 要进行参数检查。否则通不过 leetcode
                return res;
            if(numRows==1){
                res.push_back((vector<int>){1});
                return res;
            } else if(numRows==2){
                res.push_back((vector<int>){1});
                res.push_back((vector<int>){1,1});
                return res;
            }else{
                vector<int> row;
                row.push_back(1);
                res=generate(numRows-1);
                auto last=res.back();
                for(auto i=1; i<numRows-1; i++)
                    row.push_back(last[i-1]+last[i]);
                row.push_back(1);
                res.push_back(row);
                return res;
            }
        }
};

int main(){
    auto s=Solution();
    auto res=s.generate(5);
    for(auto outer: res){
        for(auto inner: outer)
            cout << inner << " ";
        cout << endl;
    }
    return 0;
}

