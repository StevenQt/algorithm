/*
#982 https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/
*/
#pragma once
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> cnt(1 << 16);
        for (int x : nums) {
            for (int y : nums) {
                ++cnt[x & y];
            }
        }
        int count = 0;
        for (int x : nums) {
            for (int mask = 0; mask < (1 << 16); ++mask) {
                if ((x & mask) == 0) {
                    count += cnt[mask];
                }
            }
        }
        return count;
    }
};
