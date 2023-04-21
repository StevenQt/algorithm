#pragma once

#include <map>
#include <vector>

using namespace std;

vector<int> sameNums(vector<int> nums1, vector<int> nums2) 
{
    int size1 = nums1.size();
    int size2 = nums2.size();

    map<int, int> flagmap;
    vector<int> results;

    for (int i = 0; i < size1; ++i) 
    {
        flagmap[nums1[i]] = 1;
    }

    for (int i = 0; i < size2; ++i) 
    {
        auto it = flagmap.find(nums2[i]);
        if (it != flagmap.end())
            results.push_back(nums2[i]);
    }

    return results;
}
