// https://leetcode.com/problems/triangle/

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:  
    int minimumTotal(vector<vector<int> > &triangle){
        int array[triangle.size()+1];
        int total_len = triangle.size();
        for (int i = 0; i <= total_len; i++)// 相当于在最下面加了一个哨兵层（全0）。 
            array[i] = 0;

        // bottom-up
        for (int i = total_len - 1; i >= 0 ; i--){
            auto row=triangle[i];
            for (int j = 0; j <= i; j++){
                array[j] = row[j] + min(array[j], array[j+1]);
            }
        }
        return array[0];
    }
    // 自底向上的思维，这样来理解：
    // 由于目标是要寻找路径的和，而路径是可逆的，所以一条从下
    // 往上的路径和反过来的路径是等效的。
    // array 数组记录的就是这些路径的和，只是路径是从下往上走的。
    // 对于固定的 i，array[j] 记录的是从最下面到这一层第 j 个节点
    // 的路径和最小的路径。


};

int main(){
    //vector<vector<int>> vvi={{2}, {3,4}, {6,5,7},{4,1,8,3}};
    vector<vector<int>> vvi={{-1},{2,3},{1,-1,-3}}; // 可以这样初始化
    Solution s;
    /*
    for(int i=0; i<vvi.size(); i++){
        for(int j=0; j<vvi[i].size(); j++)
            cout << vvi[i][j] << " ";
        cout << endl;
    }
    */
    cout << s.minimumTotal(vvi)<< endl;
    return 0;
}

