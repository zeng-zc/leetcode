/* https://leetcode.com/problems/n-queens-ii/
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of
distinct solutions.
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int result=0;
    int totalNQueens(int n) {
        vector<string> board(n);
        initBoard(board);
        placeRow(board, 0);
        return result;
    }

    void initBoard(vector<string>& board){
        auto size = board.size();
        for(int i=0; i<size; i++){
            string tmp(size, '.');
            board[i] = tmp;
        }
    }

    void printboard(vector<string>& board){
        auto size = board.size();
        for(int i=0; i<size; i++){
            cout << board[i]<< endl;
        }
    }

    void placeRow(vector<string>& board, int row){
        auto N = board.size();
        if(row > N-1){ // out of bound
            result++;
            return;
        }
        for(int col=0; col<N; col++){
            board[row][col]='Q';
            if(isValidGrid(board, row, col)){
                placeRow(board, row+1);
            }
            board[row][col]='.';
        }
        return;
    }

    bool isValidGrid(vector<string>& board, int row, int col){
        auto N = board.size();
        for(int i=0; i<N; i++){
            if(i != col && board[row][i] == 'Q')  // check the row
                return false;
            if(i != row && board[i][col] == 'Q')  // check the col
                return false;
        }
        for(int i=0; i<row; i++){
            int diag1 = row + col - i; // check diag
            if(diag1 < N && diag1 >=0 && board[i][diag1] == 'Q')
                return false;
            int diag2 = i + col - row;
            if(diag2 < N && diag2 >=0 && board[i][diag2] == 'Q')
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    auto nsolutions = s.totalNQueens(8);
    cout << "Number of Solutions: " << nsolutions << endl;
    return 0;
}
