//
// #51 https://leetcode.cn/problems/n-queens/
//  SolveQueen.h
//  project
//
//  Created by arevenge on 9/3/2023.
//

#ifndef SolveQueen_h
#define SolveQueen_h

#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
    vector<vector<int>> solutions;
    unordered_set<int> columns;
    unordered_set<int> diagonal1;
    unordered_set<int> diagonal2;
    
public:
    vector<vector<string>> solveQueen(int n) {
        vector<int> queens(n, -1);
        backtrace(queens, n, 0, columns, diagonal1, diagonal2);
        vector<vector<string>> result;
        for (int c = 0; c < (int)solutions.size(); ++c) {
            auto board = vector<string>();
            for (int i = 0; i < n; ++i) {
                string row = string(n, '.');
                row[solutions[c][i]] = 'Q';
                board.push_back(row);
            }
            result.push_back(board);
        }
        return result;
    }
    
    void backtrace(vector<int>& queens,
                   int n,
                   int row,
                   unordered_set<int> columns,
                   unordered_set<int> diagonal1,
                   unordered_set<int> diagonal2) {
        if (row == n) {
            solutions.push_back(queens);
            return;
        }
        for (int col = 0; col < n; ++col) {
            auto cit = columns.find(col);
            if (cit != columns.end()) {
                continue;
            }
            int diff = row - col;
            auto dit1 = diagonal1.find(diff);
            if (dit1 != diagonal1.end()) {
                continue;
            }
            int sum = row + col;
            auto dit2 = diagonal2.find(sum);
            if (dit2 != diagonal2.end()) {
                continue;
            }
            queens[row] = col;
            columns.insert(col);
            diagonal1.insert(diff);
            diagonal2.insert(sum);
            backtrace(queens, n, row + 1, columns, diagonal1, diagonal2);
            queens[row] = -1;
            columns.erase(col);
            diagonal1.erase(diff);
            diagonal2.erase(sum);
        }
    }
};

#endif /* SolveQueen_h */
