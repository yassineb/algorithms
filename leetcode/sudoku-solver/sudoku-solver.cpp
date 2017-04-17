#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        print(board);
    }
    
    bool solve(vector<vector<char>> &board) {
        pair<int, int> cell = getEmptyCell(board);
        
        if (cell.first == -1)
            return true;
        else {
            for (int value = 1; value <= 9; value++) {
                setCell(board, value, cell.first, cell.second);
                
                if (isValidSudoku(board)) {
                    if (solve(board))
                        return true;
                }
                    
                emptyCell(board, cell.first, cell.second);
            }
        }
        
        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {0},
			 cols[9][9] = {0},
			 sq[9][9] = {0};
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                
                if (rows[i][c % 9]++ || cols[j][c % 9]++ || sq[(i / 3)*3 + j/3][c % 9]++)
                    return false;
            }
        }
        
        return true;
    }
    
    void setCell(vector<vector<char>> &board, int n, int row, int col) {
        board[row][col] = n + '0';
    }
    
    void emptyCell(vector<vector<char>> &board, int row, int col) {
        board[row][col] = '.';
    }
    
    void print(vector<vector<char>> & board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << "|";
            }
            
            cout << endl;
        }
    }
    
    pair<int, int> getEmptyCell(vector<vector<char>> &board) {
        int row = -1, col = -1;
        
        for (int i = 0; i < 9 && row == -1; i++)
            for (int j = 0; j < 9 && row == -1; j++)
                if (board[i][j] == '.')
                    row = i, col = j;
                    
        return make_pair(row, col);
    }
};
