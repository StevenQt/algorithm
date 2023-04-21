/*
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
*/

/*
["0","0","0","1"]
["1","1","0","1"]
["1","1","1","1"]
["0","1","1","1"]
["0","1","1","1"]
*/

#include <vector>
#include <algorithm>
using namespace std;

int maxSquare(vector<vector<char>>& matrix)
{
	if (matrix.size() == 0) 
		return 0;

	int col = matrix.size();
	int row = matrix[0].size();
	int max = 0;

	int i, j;
	vector<vector<int>> dp;
	dp.resize(col);
	for (i = 0; i < col; ++i)
		dp[i].resize(row);

	for (i = 0; i < col; i++)
	{
		dp[i][0] = matrix[i][0] - '0';
		if (matrix[i][0] == '1') max = 1;
	}		

	for (j = 0; j < row; j++)
	{
		dp[0][j] = matrix[0][j] - '0';
	    if (matrix[0][j] == '1') max = 1;
	}		

	for (int i = 1; i < col; ++i) 
	{
		for (int j = 1; j < row; j++) 
		{
			if (matrix[i][j] == '1')				
			{
				int minv = min(dp[i - 1][j], dp[i][j - 1]);
				dp[i][j] = 1 + min(dp[i - 1][j - 1], minv);

				if (dp[i][j] > max)
					max = dp[i][j];
			}
			else 
			{
				dp[i][j] = 0;
			}
		}
	}

	return max * max;
}