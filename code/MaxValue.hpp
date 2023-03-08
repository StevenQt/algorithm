//
//  #Offer.47 https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/
//  MaxValue.h
//  project
//
//  Created by arevenge on 8/3/2023.
//

#ifndef MaxValue_h
#define MaxValue_h
#include <vector>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>> board) {
        int r = (int)board.size();
        int c = (int)board[0].size();
        vector<vector<int>> dp(r, vector<int>(c));
        dp[0][0] = board[0][0];
        for (int i = 1; i < c; ++i) {
            dp[0][i] = dp[0][i - 1] + board[0][i];
        }
        for (int i = 1; i < r; ++i) {
            dp[i][0] = dp[i - 1][0] + board[i][0];
        }
        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + board[i][j];
            }
        }
        return dp[r - 1][c - 1];
    }
};

#endif /* MaxValue_h */
