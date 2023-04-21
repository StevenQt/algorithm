#pragma once

#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<vector<int>> intervals;
    vector<int> nums1;
    nums1.push_back(5);
    nums1.push_back(7);
    intervals.push_back(nums1);

    vector<int> nums2;
    nums2.push_back(1);
    nums2.push_back(10);
    intervals.push_back(nums2);

    vector<int> nums3;
    nums3.push_back(8);
    nums3.push_back(10);
    intervals.push_back(nums3);

    vector<int> nums4;
    nums4.push_back(15);
    nums4.push_back(18);
    intervals.push_back(nums4);

    vector<vector<int>> result = merge(intervals);

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i][0] << "->" << result[i][1] << endl;
    }

    getchar();
    return 0;
}

vector<vector<int>> merge(vector<vector<int>> intervals) 
{
    int size = intervals.size();
    if (size == 0 || size == 1)
        return intervals;

    vector<vector<int>> result;
    vector<int> tmp;
    tmp.resize(2);

    std::sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) 
    { 
        return a[0] < b[0];
    });

    tmp = intervals[0];
    int i = 1;

    while(i < size)
    {
        if (intervals[i][0] <= tmp[1])
        {
            tmp[1] = std::max(tmp[1], intervals[i][1]);
            i++;
        }
        else
        {
            result.push_back(tmp);
            tmp = intervals[i];
            i++;
        }
    }

    result.push_back(tmp);

    return result;
}