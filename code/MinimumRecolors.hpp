//
// #2379 https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
//  MinimumRecolors.h
//  project
//
//  Created by arevenge on 9/3/2023.
//

#ifndef MinimumRecolors_h
#define MinimumRecolors_h

#include <string>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = 0, count = 0;
        while (r < k) {
            count += blocks[r] == 'W' ? 1 : 0;
            r++;
        }
        int result = count;
        while (r < (int)blocks.size()) {
            count += blocks[r] == 'W' ? 1 : 0;
            count -= blocks[l] == 'W' ? 1 : 0;
            if (count < result) {
                result = count;
            }
            r++;
            l++;
        }
        return result;
    }
};


#endif /* MinimumRecolors_h */
