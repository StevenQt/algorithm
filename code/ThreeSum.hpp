#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std; 

vector<vector<int>> twoSum(vector<int>& nums, int idx) 
{
    int value = -nums[idx];
    unordered_map<int, int> ihash;
    vector<vector<int>> tv;
    vector<int> tmp(2, 0);
    for (int i = idx + 1; i < nums.size(); ++i) 
    { 
        int dix = value - nums[i];
        auto it = ihash.find(dix);
        if (it != ihash.end()) 
        {
            tmp[0] = nums[it->second];
            tmp[1] = nums[i];
            tv.push_back(tmp);
        }
        
        ihash.insert(pair<int, int>(nums[i], i));         
    }    

    return tv;
}

vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> rv;
    int size = nums.size();
    if (size == 0) return rv;

    vector<vector<int>> tv;
    vector<int> tmp(3, 0);

    for (int i = 0; i < size; ++i) 
    {    
        tv = twoSum(nums, i);
        if (tv.size() > 0)
        {
            tmp[0] = nums[i];
            for (int t = 0; t < tv.size(); ++t)
            {
                tmp[1] = tv[t][0];
                tmp[2] = tv[t][1];
                rv.push_back(tmp);
            }              
        }
    }

    return rv;
}

#include <iterator>

int main(int argc, char* argv[])
{
    vector<int> v = { -1, 0, 1, 2, -1, -4, 1, -1, 3, -4, -3, 4, 5, 6, -9 };
    vector<vector<int>> result = threeSum(v);

    for (int i = 0; i < result.size(); ++i)
    {
        copy(result[i].begin(), result[i].end(), ostream_iterator<int>(std::cout, " "));
        cout << std::endl;
    }

    getchar();
    return 0;
}