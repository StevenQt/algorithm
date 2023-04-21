/************************************************************************
 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221
10.     13211311123113112211                                                                  
************************************************************************/

#include <string>
using namespace std;

string countAndSay(int n) 
{
	if (n == 1) return string("1");

	string tmp = countAndSay(n - 1);
	int i = 1, count = 1;
	string result = string("");
	char sc = tmp[0];

	while(i < tmp.size()) 
	{
		if (tmp[i] == sc) 
		{
			count++;
		}
		else 
		{
			result += (char)(count + '0');
			result += sc;
			sc = tmp[i];
			count = 1;
		}

		i++;
	}

	if (count > 0) 
	{
		result += (char)(count + '0');
		result += sc;		
	}

	return result;
}