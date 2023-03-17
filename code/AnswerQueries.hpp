//
// #2389 https://leetcode.cn/problems/longest-subsequence-with-limited-sum/
//  AnswerQueries.h
//  project
//
//  Created by arevenge on 17/3/2023.
//

#ifndef AnswerQueries_h
#define AnswerQueries_h

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int> nums, vector<int> queries) {
        size_t n = nums.size(), m = queries.size();
        sort(begin(nums), end(nums));
        vector<int> f(n + 1);
        for (int i = 0; i < (int)n; ++i) {
            f[i + 1] = f[i] + nums[i];
        }
        vector<int> answer(m);
        for (int i = 0; i < (int)m; ++i) {
            answer[i] = int(upper_bound(f.begin(), f.end(), queries[i]) - f.begin() - 1);
        }
        return answer;
    }
};


#endif /* AnswerQueries_h */
