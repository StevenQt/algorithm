#pragma once

#include <vector>
#include <algorithm>

using namespace std;

#include <iostream>
#include <sstream>
#include <iterator>
/*
ÊäÈë:
[0, 1, 0, 3, 12]

Êä³ö:
[1, 3, 12, 0, 0]
*/

int main()
{
    vector<int> nums = { 0, 1, 0, 3, 12 };
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    moveZeroes(nums);
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    getchar();
    return 0;
}

void moveZeroes(vector<int>& nums) 
{
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) 
    {
        if (nums[i] == 0)
        {
            count++;
        }
        else 
        {
            swap(nums[i], nums[i - count]);
        }
    }
}
