/* https://leetcode.com/problems/sudoku-solver/
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution. 
*/


// brute force, recursion
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() != 9)
            return;
        for(auto it: board)
            if(it.size() != 9)
                return;
        solveOnegrid(board, 0, 0);
        return;
    }

// return whether the (row, col) grid is filled in successfully.
    bool solveOnegrid(vector<vector<char>>& board, int row, int col) {
        if(col >= 9)
            return solveOnegrid(board, row+1, 0);
        if(row == 9)
            return true;
        if(board[row][col] == '.'){
            for(int i=1; i<=9; i++){
                board[row][col] = i + '0'; // try it.
                if(this->isValidOnegrid(board, row, col))
                    if(solveOnegrid(board, row, col+1))
                        return true;
                board[row][col] = '.'; // backtrack
            }
        }else
            return solveOnegrid(board, row, col+1);
        return false;
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

};

