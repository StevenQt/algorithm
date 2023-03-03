/*
#1487 https://leetcode.cn/problems/making-file-names-unique/
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
    string addSuffix(string name, int k) {
        return name + "(" + to_string(k) + ")";
    }

    vector<string> getFolderNames(vector<string> names) {
        vector<string> result;
        unordered_map<string, int> index;
        for (const auto& name : names) {
            if (index.count(name) == 0) {
                index[name] = 1;
                result.push_back(name);
            } else {
                int k = index[name];
                while (index.count(addSuffix(name, k))) {
                    k++;
                }
                result.push_back(addSuffix(name, k));
                index[name] = k + 1;
                index[addSuffix(name, k)] = 1;
            }
        }
        return result;
    }
};
