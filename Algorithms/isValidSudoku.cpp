// https://leetcode.com/problems/valid-sudoku/
// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
// The Sudoku board could be partially filled, where empty cells are filled
// with the character '.'.
//
// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only
// the filled cells need to be validated. 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() != 9)
            return false;
        
        unsigned char hash[10]; // value i hashed to the index i
        // check each row
        for(auto outer: board){
            if(outer.size() != 9)
                return false;
            memset(hash, 0, 10);
            for(auto inner: outer){
                if(inner != '.'){
                    auto index = inner -'0';
                    if(hash[index] == 0)
                        hash[inner-'0']++;
                    else
                        return false;
                }
            }
        }
        
        // chech each column
        unsigned char colval[9];
        for(int col=0; col<9; col++){  
            memset(hash, 0, 10);
            for(int row=0; row<9; row++)
                colval[row] = board[row][col];
            for(auto inner: colval){
                if(inner != '.'){
                    auto index = inner -'0';
                    if(hash[index] == 0)
                        hash[index]++;
                    else
                        return false;
                }
            }
        }
            
        // chech each small square
        for(int m=0; m<3; m++){
            for(int n=0; n<3; n++){  // each tuple of (m,n) corresponds to a square
                // assign value to square
                memset(hash, 0, 10);
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        auto value = board[3*m+i][3*n+j];
                        if(value != '.'){
                            auto index = value -'0';
                            if(hash[index] == 0)
                                hash[index]++;
                            else
                                return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};


/* notes:
 * Accepted at the first submit!
 */
