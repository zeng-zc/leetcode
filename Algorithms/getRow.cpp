/* https://leetcode.com/problems/pascals-triangle-ii/
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1]. 
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        auto res = generate(rowIndex+1);
        return res.back();

    }

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
