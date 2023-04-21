#include <vector>
using namespace std;

bool isPalindrome(int x) 
{
	if (x < 0) return false;

	vector<int> vec(10, -1);

	int c = 0;
	int t = x;
	while (t) 
	{
		vec[c] = t % 10;
		c++;
		t = t / 10;
	}

	for (int i = 0; i < c / 2; ++i) 
	{
		if (vec[i] != vec[c - 1 - i])
		{
			return false;
		}
	}

	return true;
}