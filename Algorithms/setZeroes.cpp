#include <iostream>
#include <vector>
using namespace std;

// Two passes: one for scanning, one for modifying
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int row = matrix.size();
            cout << "row=" << row << endl;
            int col = matrix[0].size();
            cout << "col=" << col << endl;
            int buff1[row], buff2[col];
            memset(buff1, 0, col* sizeof(int));
            memset(buff2, 0, col* sizeof(int));
            // First pass: just scan, don't modify.
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    if(matrix[i][j]==0){
                        buff1[i]=1;
                        buff2[j]=1;
                    }
                }
            }

            // second pass: modify it.
            for(int i=0; i< row; i++)
                if(buff1[i]==1)
                    setZeroesRow(matrix, i);
            for(int j=0; j< col; j++)
                if(buff2[j]==1)
                    setZeroesCol(matrix, j);

        }

        void setZeroesRow(vector<vector<int>>& matrix, 
                int m) {
            int row = matrix.size();
            int col = matrix[0].size();
            for(int j=0; j<col; j++)
                matrix[m][j] = 0;
        }

        void setZeroesCol(vector<vector<int>>& matrix, 
                int n){
            int row = matrix.size();
            int col = matrix[0].size();
            for(int i=0; i<row; i++){
                matrix[i][n] = 0;
            }
        }

        void print(vector<vector<int>> matrix){
            for(auto i: matrix){
                for(auto j: i)
                    cout << j << " ";
                cout << endl;
            }
        }
};

int main(){
    vector<vector<int>> data={{1}};
    Solution s;
    s.print(data);
    s.setZeroes(data);
    s.print(data);
    return 0;
}

