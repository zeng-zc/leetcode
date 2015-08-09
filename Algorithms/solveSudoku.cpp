/* https://leetcode.com/problems/sudoku-solver/
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution. 
*/

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

// brute force, recursion
class Solution {
public:
    vector<vector<char>> res;
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() != 9)
            return;
        for(auto it: board)
            if(it.size() != 9)
                return;
        solveOnegrid2(board, 0, 0);
        board = res;  // we save the final result in res.
        return;
    }

// return whether the recursively *next* grid (row, col+1) can be filled in successfully.
// In orther words, wheather the current grid will cause a final successful result.
    bool solveOnegrid(vector<vector<char>>& board, int row, int col) {
        if(col == 9)
            return solveOnegrid(board, row+1, 0);
        if(row == 9)
            return true;
        if(board[row][col] == '.'){
            for(int i=1; i<=9; i++){
                board[row][col] = i + '0'; // try it.
                if(this->isValidOnegrid(board, row, col))
                    if(solveOnegrid(board, row, col+1))
                        return true;  // Find a solution, return now, and the result
                                      // in board can be kept.
                board[row][col] = '.'; // not valid, then reset.
            }
        }else
            return solveOnegrid(board, row, col+1);
        return false; 
    }

    // We don't care about the return value.
    // notes: after all the return of call, board is in the inial status.
    // But we can save the final result.
    void solveOnegrid2(vector<vector<char>>& board, int row, int col) {
        if(row >= 9){
            res = board; // save the result, as board will be reset after return. 
            return;
        }
        if(col >= 9){
            solveOnegrid2(board, row+1, 0);
            return;
        }
        if(board[row][col] == '.'){
            for(int i=1; i<=9; i++){
                board[row][col] = i + '0'; // try it.
                if(this->isValidOnegrid(board, row, col)){
                    solveOnegrid2(board, row, col+1);
                }
                board[row][col] = '.'; // reset
            }
        }else
            solveOnegrid2(board, row, col+1);
    }


    // check whether (row, col) gird is valid.
    bool isValidOnegrid(vector<vector<char>>& board, int row, int col) {
        for(int i=0; i<9; i++){
            if(i != col)
                if(board[row][i] == board[row][col])
                    return false;
        }
        
        for(int i=0; i<9; i++){
            if(i != row)
                if(board[i][col] == board[row][col])
                    return false;
        }

        for(int i = row/3*3; i<row/3*3+3; i++)  {  
            for(int j=col/3*3; j<col/3*3+3; j++)  {  
                if(!(row==i && col==j) && board[row][col]==board[i][j])  
                    return false;  
            }  
        } 

        return true;
    }

    void printboard(vector<vector<char>> board){
        for(auto row: board){
            for(auto col: row)
                cout << col;
            cout << endl;
        }
        return;
    }


};

int main(){
    vector<vector<char>> board;
    vector<string> vs = {
            "..9748...",
            "7........",
            ".2.1.9...",
            "..7...24.",
            ".64.1.59.",
            ".98...3..",
            "...8.3.2.",
            "........6",
            "...2759.."};
    for(auto it=vs.begin(); it != vs.end(); it++){
        vector<char> tmp(it->begin(), it->end());
        board.push_back(tmp);
    }
    Solution s;
    s.printboard(board);
    cout << endl;
    s.solveSudoku(board);
    s.printboard(board);
    return 0;
}

