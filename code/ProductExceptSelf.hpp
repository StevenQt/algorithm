#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> productExceptSelf(vector<int> nums) 
{
    int size = nums.size();
    vector<int> vi(size, 0);
    int i, mut = 1;
    for (i = size - 1; i >= 0; --i) 
    {
        mut = mut * nums[i];
        vi[i] = mut;
    }

    mut = 1;
    for (i = 0; i < size - 1; ++i) 
    {
        vi[i] = mut * vi[i + 1];
        mut = mut * nums[i];
    }

    vi[i] = mut;  

    return vi;
}