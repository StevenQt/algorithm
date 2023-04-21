#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;  


int smallestDivisorTest(vector<int>& nums, int threshold) 
{  
    unsigned int sum = 0;    
    int index = 1;

    //cout << "start " << index << endl;

    while (1)
    { 
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += ceil((nums[i] * 1.0f) / index);
        }   
        if (sum <= threshold) break; 
        index++;
        sum = 0;
    }

    return index;
}

int smallestDivisor(vector<int>& nums, int threshold)
{
    int size = nums.size();
    if (size == 1) return ceil(nums[0] * 1.0f / threshold);

    unsigned int sum = 0;
    float fsum = 0.0f;
    int max = 0;
                          
    for (int i = 0; i < size; ++i)
    {
        fsum += (nums[i] * 1.0) / threshold;
        if (nums[i] > max) max = nums[i];
    }

    int l = ceil(fsum);
    int r = max;  
    int index = l; 

    while (l < r - 1)
    {     
        sum = 0;
        index = (l + r) / 2;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += ceil((nums[i] * 1.0f) / index);
        }
       
        if (sum > threshold) l = index;
        else r = index;  
    }

    //cout << "start " << index << endl;
    //cout << l << " " << r << endl; 
    
    sum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += ceil((nums[i] * 1.0f) / l);
    }

    if (sum <= threshold)  index = l;
    else index = r;       

    return index;
}