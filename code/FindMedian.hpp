#include <iostream>
#include <vector>
using namespace std;

double findMedian(vector<int> nums1, vector<int> nums2) 
{
	int size1 = nums1.size();
	int size2 = nums2.size();
	int haf1 = size1 / 2;
	int haf2 = size2 / 2;
	bool single = (size1 + size2) % 2 ? true : false;
	double result = 0.0;
	
	if (size1 == 0) 
	{
		if (single)
			result = nums2[haf2] * 1.0;
		else
			result = (nums2[haf2 - 1] + nums2[haf2]) * 1.0 / 2;
		return result;
	}
	else if (size2 == 0) 
	{
		if (single)
			result = nums1[haf1] * 1.0;
		else
			result = (nums1[haf1 - 1] + nums1[haf1]) * 1.0 / 2;
		return result;
	}

	if (size1 == 1 && size2 == 1)
	{
		result = (nums1[0] + nums2[0]) * 1.0 / 2;
		return result;
	}

	if (size1 == 1)
	{
		if (single)
		{
			if (nums1[0] >= nums2[haf2])
				result = nums2[haf2] * 1.0;
			else if (nums1[0] >= nums2[haf2 - 1])
				result = nums1[0] * 1.0;
			else
				result = nums2[haf2 - 1] * 1.0;
		}
		else
		{
			if (nums1[0] == nums2[haf2])
			{
				result = nums1[0] * 1.0;
			}				
			else if (nums1[0] > nums2[haf2])
			{
				if (nums1[0] > nums2[haf2 + 1])
					result = (nums2[haf2] + nums2[haf2 + 1]) * 1.0 / 2;
				else
					result = (nums2[haf2] + nums1[0]) * 1.0 / 2;
			}
			else 
			{
				if (nums1[0] < nums2[haf2 - 1])
					result = (nums2[haf2] + nums2[haf2 - 1]) * 1.0 / 2;
				else
					result = (nums2[haf2] + nums1[0]) * 1.0 / 2;
			}
		}

		return result;
	}
	
	if (size2 == 1) 
	{
		if (single)
		{
			if (nums2[0] >= nums1[haf1])
				result = nums1[haf1] * 1.0;
			else if (nums2[0] >= nums1[haf1 - 1])
				result = nums2[0] * 1.0;
			else
				result = nums1[haf1 - 1] * 1.0;
		}
		else
		{
			if (nums2[0] == nums1[haf1])
			{
				result = nums2[0] * 1.0;
			}
			else if (nums2[0] > nums1[haf1])
			{
				if (nums2[0] > nums1[haf1 + 1])
					result = (nums1[haf1] + nums1[haf1 + 1]) * 1.0 / 2;
				else
					result = (nums1[haf1] + nums2[0]) * 1.0 / 2;
			}
			else
			{
				if (nums2[0] < nums1[haf1 - 1])
					result = (nums1[haf1] + nums1[haf1 - 1]) * 1.0 / 2;
				else
					result = (nums1[haf1] + nums2[0]) * 1.0 / 2;
			}
		}

		return result;
	}

	int v1 = haf1;
	int v2 = haf2;

	int d1 = nums1[v1];
	int d2 = nums2[v2];

	//0 index exit 
	//1 size exit
    //2 3 normal exit
	int state = 0;

	bool direct = true;
	if (d1 > d2) direct = false;

	while (1) 
	{
		if (v1 == 0 || v2 == 0 || v1 == size1 - 1 || v2 == size2 - 1)
		{
			state = 0;
			break;
		}

		if (d1 > d2) 
		{
			if (direct)
			{
				state = 2;
				break;
			}

			v1 = v1 / 2;
			v2 = v2 + (size2 - v2) / 2;
			d1 = nums1[v1];
			d2 = nums2[v2];
		}
		else
		{
			if (!direct)
			{
				state = 3;
				break;
			}

			v1 = v1 + (size1 - v1) / 2;
			v2 = v2 / 2;
			d1 = nums1[v1];
			d2 = nums2[v2];
		}
	}

	cout << "v1:" << v1 << endl;
	cout << "v2:" << v2 << endl;

	cout << endl;

	cout << "d1:" << d1 << endl;
	cout << "d2:" << d2 << endl;

	if (v1 == size1 - 1 && v2 == size2 - 1)
	{
		int d11 = nums1[v1 - 1];
		int d22 = nums2[v2 - 1];

		if (d1 > d2) 
		{
			if (d22 > d11)
				result = (d22 + d2) * 1.0 / 2;
			else
				result = (d11 + d2) * 1.0 / 2;
		}
		else 
		{
			if (d11 > d22)
				result = (d11 + d1) * 1.0 / 2;
			else
				result = (d22 + d1) * 1.0 / 2;
		}

		return result;
	}
	

	if (v1 == 0) 
	{	
		
	}
	else if (v2 == 0)
	{
		if (d1 < d2) 
		{
			if (single)
				result = d1 * 1.0;
			else
				result = (d1 + d2) * 1.0 / 2;
		}
		else 
		{
		}
	}
	else 
	{
		if (single) 
		{
			if (d1 > d2)
			{
				result =
			}
			else 
			{
			}		
		}
	}
	
	return result;
}

int main(int argc, char* argv[])
{
	vector<int> v1 = { 1, 2, 3 };
	vector<int> v2 = { 1, 2, 3 };

	double result = findMedian(v1, v2);
	cout << result << endl;

	getchar();
	return 0;
}