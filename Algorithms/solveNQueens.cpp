/* https://leetcode.com/problems/n-queens/
The n-queens puzzle is the problem of placing n queens on an n×n chessboard
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens'
placement, where 'Q' and '.' both indicate a queen and an empty space
respectively.
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        initBoard(board);
        placeRow(board, 0);
        return res;
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

    // return whether a queen can be placed in the current row.
    bool placeRow(vector<string>& board, int row){
        auto N = board.size();
        if(row > N-1){ // out of bound
            res.push_back(board);
            return false;
        }
        for(int col=0; col<N; col++){
            board[row][col]='Q';  // try it.
            if(isValidGrid(board, row, col)){
                placeRow(board, row+1);
            }
            board[row][col]='.'; // reset
        }
        return true;
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
    auto res = s.solveNQueens(10);
    auto nsolutions = res.size();
    cout << "Number of Solutions: " << nsolutions << endl;
    for(int i=0; i< nsolutions; i++){
        cout << "Solution " << i << endl;
        s.printboard(res[i]);
        cout << endl;
    }
    return 0;
}
