#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums) 
{		
	int min = 1;
	int max = nums[0];
	int tmax = nums[0];

	for (int i = 1; i < nums.size(); ++i)
	{
	    int cur = tmax * nums[i];
		int tmp = std::max(nums[i], cur);
		tmax = std::max(tmp, min * nums[i]);
		
		tmp = std::min(nums[i], cur);
		min = std::min(tmp, min * nums[i]);

		if (tmax > max) max = tmax;
	}

	return max;
}