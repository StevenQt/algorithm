#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

int rob(vector<int>& nums) 
{
    int size = nums.size();
    if (size == 0) return 0;     

    vector<int> maxv(size, 0);

    for (int i = 0; i < size; ++i) 
    {
        if (i == 0) 
        {
            maxv[0] = nums[0];
        }
        else if (i == 1) 
        {
            maxv[1] = std::max(maxv[0], nums[1]);
        }
        else 
        {
            maxv[i] = std::max(maxv[i - 1], maxv[i - 2] + nums[i]);
        }
    } 
   
    return maxv[size - 1];
}