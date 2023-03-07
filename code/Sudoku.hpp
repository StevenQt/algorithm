//
// #37 https://leetcode.cn/problems/sudoku-solver/
//  Sudoku.h
//  project
//
//  Created by arevenge on 7/3/2023.
//

#ifndef Sudoku_h
#define Sudoku_h

#include <vector>

using namespace std;

class Solution {
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];
    bool valid;
    vector<pair<int, int>> space;
public:
    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == space.size()) {
            valid = true;
            return;
        }
        auto [i, j] = space[pos];
        for (int digt = 0; digt < 9 && !valid; ++digt) {
            if (!line[i][digt] && !column[j][digt] && !block[i/3][j/3][digt]) {
                char c = digt + '0' + 1;
                board[i][j] = c;
                line[i][digt] = column[j][digt] = block[i/3][j/3][digt] = true;
                dfs(board, pos + 1);
                line[i][digt] = column[j][digt] = block[i/3][j/3][digt] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(line, false, sizeof(line));
        memset(column, false, sizeof(column));
        memset(block, false, sizeof(block));
        valid = false;
        for (int i = 0; i < (int)board.size(); ++i) {
            for (int j = 0; j < (int)board[0].size(); ++j) {
                if (board[i][j] == '.') {
                    space.emplace_back(pair<int, int>(i, j));
                } else {
                    int digt = board[i][j] - '0' - 1;
                    line[i][digt] = column[j][digt] = block[i/3][j/3][digt] = true;
                }
            }
        }
        dfs(board, 0);
    }
};

/*
int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    cout << "input:" <<endl;
    for (int i = 0; i < (int)board.size(); ++i) {
        for (int j = 0; j < (int)board[0].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    Solution s;
    s.solveSudoku(board);
    cout << "solve:" <<endl;
    for (int i = 0; i < (int)board.size(); ++i) {
        for (int j = 0; j < (int)board[0].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

*/

#endif /* Sudoku_h */
