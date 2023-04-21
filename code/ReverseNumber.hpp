#include <iostream>
using namespace std;

int reverseNumber(int x)
{
	const int kMaxINT = 0x7FFFFFFF;
	const int kMinINT = -kMaxINT - 1;

	int y = 0;
	while (x) 
	{
		if (y > kMaxINT / 10 || y < kMinINT / 10)
			return 0;

		y = y * 10 + x % 10;
		x = x / 10;
	}

	return y;
}