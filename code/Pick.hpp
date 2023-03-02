/*
#398 https://leetcode.cn/problems/random-pick-index/
*/
#pragma once
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int, vector<int>> pos_;
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            pos_[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        auto& idxs = pos_[target];
        int idx = rand() % idxs.size();
        return idxs[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
