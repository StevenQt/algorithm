#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int translateNumber(int num) 
{
    vector<int> bitv;
    int tmp = num;
    while (tmp) 
    {
        bitv.push_back(tmp % 10);
        tmp = tmp / 10;
    }

    copy(bitv.begin(), bitv.end(), ostream_iterator<int>(std::cout, " "));
    cout << std::endl;

    int size = bitv.size();
    vector<int> dp(size, 1);

    for (int i = size - 2; i >= 0; --i) 
    {
        dp[i] = dp[i+1];
        tmp = bitv[i+1] * 10 + bitv[i];  
        if (tmp >= 0 && tmp < 26)
            dp[i] += 1;            
    }

    copy(dp.begin(), dp.end(), ostream_iterator<int>(std::cout, " "));
    cout << std::endl;

    return dp[0];  	
}