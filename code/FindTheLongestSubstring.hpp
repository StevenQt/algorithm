#include <iostream>
#include <string>

using namespace std;	

bool validPalindrome(string s) 
{
	int size = s.size();
	int left = 0;
	int right = size - 1;
	bool first = false;

	while (left < right)
	{
		if (s[left] != s[right]) 
		{		
			string sub1 = s.substr(left, right - left);
			string sub2 = s.substr(left + 1, right - left);
			if (isPalindrome(sub1) || isPalindrome(sub2)) 
				return true;
			else 
				return false;
		}
		else
		{
			left++;
			right--;
		}
	}
		
	return true;
}