/*
#1653 https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/
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
    int minimumDeletions(string s) {
        int counta = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == 'a') {
                counta++;
            }
        }

        int result = counta;
        int countb = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == 'a') {
                counta--;
            } else {
                countb++;
            }
            result = min(result, counta + countb);
        }
        
        return result;
    }
};

