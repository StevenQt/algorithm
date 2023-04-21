#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 ‰»Î:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

 ‰≥ˆ:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

int main()
{
    vector<vector<int>> queue;
    vector<int> nums1;
    nums1.push_back(7);
    nums1.push_back(0);
    queue.push_back(nums1);

    vector<int> nums2;
    nums2.push_back(4);
    nums2.push_back(4);
    queue.push_back(nums2);

    vector<int> nums3;
    nums3.push_back(7);
    nums3.push_back(1);
    queue.push_back(nums3);

    vector<int> nums4;
    nums4.push_back(5);
    nums4.push_back(0);
    queue.push_back(nums4);

    vector<int> nums5;
    nums5.push_back(6);
    nums5.push_back(1);
    queue.push_back(nums5);

    vector<int> nums6;
    nums6.push_back(5);
    nums6.push_back(2);
    queue.push_back(nums6);

    vector<vector<int>> result = reconstructQueue(queue);

    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << "[" << result[i][0] << "," << result[i][1] << "]" << endl;
    }

    getchar();
    return 0;
}

vector<vector<int>> reconstructQueue(vector<vector<int>> queue) 
{
    int size = queue.size();
    if (size < 2) return queue; 

    vector<vector<int>> result(size);
    vector<int> flags(size, -1);

    std::sort(queue.begin(), queue.end(), [](const vector<int>& a, 
        const vector<int>& b) { 
        if ((a[0] < b[0]) || ((a[0] == b[0]) && a[1] > b[1]))
        {
            return true;
        }
        return false;
    }); 
  
    for (int i = 0; i < size; ++i)
    {          
        int t = 0;
        int count = 0;
        int last = 0;
        while (t < size)
        {
            if (flags[t] == -1) count++;
            if (count == (queue[i][1] + 1)) break;
            t++;
        }

        if (t < size)
            flags[t] = i;
        else
            flags[last] = i;
    }
  

    for (int i = 0; i < size; ++i) 
    {
        result[i] = queue[flags[i]];
    }

    return result;
}
