#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxv(vector<int>& nums, int& max) 
{
    if (nums.size() == 0)
    {
        max = 0;
        return -1;
    }

    int index = 0;
    max = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        if (max < nums[i])
        {
            max = nums[i];
            index = i;
        }
    }

    return index;    
}

int minv(vector<int>& nums, int& min)
{
    if (nums.size() == 0)
    {
        min = 0;
        return -1;
    }

    int index = 0;
    min = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        if (min > nums[i])
        {
            min = nums[i];
            index = i;
        }          
    }

    return index;
}

int maximumGap(vector<int>& nums) 
{
    int size = nums.size();
    if (size < 2) return 0;
    if (size == 2) return abs(nums[0] - nums[1]);

    int max = 0, min = 0;
    maxv(nums, max);
    minv(nums, min);

    if (min == max) return 0;

    int csize = size - 1;
    vector<int> l(csize, max);
    vector<int> h(csize, min);  

    double step = (max - min) * 1.0 / csize;   

    for (int i = 0; i < size; ++i) 
    {          
        int t = (nums[i] - min) / step;
        if (t == csize) t = csize - 1;
        if (nums[i] > h[t])
            h[t] = nums[i];    
        
        if (nums[i] < l[t])
            l[t] = nums[i];        
    }  

    int dmax = 0;
    for (int i = 0; i < csize - 1; ++i)
    {
        if (l[i + 1] == max && h[i + 1] == min)
        {
            l[i + 1] = l[i];
            h[i + 1] = h[i];
            continue;
        }

        int d = l[i + 1] - h[i];
        if (d > dmax) dmax = d;
    }      

    return dmax;
}