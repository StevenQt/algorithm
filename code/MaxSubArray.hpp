#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) 
{
	int max = nums[0];
	int tmp = nums[0];

	for (int i = 1; i < nums.size(); ++i) 
	{
		tmp = std::max(nums[i], tmp + nums[i]);
		if (tmp > max) max = tmp;
	}

	return max;
}