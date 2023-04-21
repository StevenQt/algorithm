#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int colsize = grid.size();
        int rowsize = grid[0].size();

        vector<vector<int>> tmps;
        vector<int> tmp;

        tmp.clear();
        for (int i = 0; i < rowsize + 2; i++)
            tmp.push_back(0);
        tmps.push_back(tmp);
        
        for (int i = 0; i < colsize; ++i)
        {
            tmp.clear();
            tmp.push_back(0);
            for (int j = 0; j < rowsize; ++j)
            {
                tmp.push_back(grid[i][j]);
            }
            tmp.push_back(0);
            tmps.push_back(tmp);
        }

        tmp.clear();
        for (int i = 0; i < rowsize + 2; i++)
            tmp.push_back(0);
        tmps.push_back(tmp);

        int sum = 0;

        for (int i = 1; i < colsize + 1; ++i) 
        {
            for (int j = 1; j < rowsize + 1; ++j) 
            {
                if (tmps[i][j])
                {
                    if (tmps[i - 1][j] == 0)
                        sum++;

                    if (tmps[i + 1][j] == 0)
                        sum++;

                    if (tmps[i][j - 1] == 0)
                        sum++;

                    if (tmps[i][j + 1] == 0)
                        sum++;
                }
            }
        }    

        return sum;
    }
};

#include <iostream>

int main()
{
    vector<vector<int>> grid;
    vector<int> tmp;

    tmp.clear();
    tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(0);
    tmp.push_back(0);
    grid.push_back(tmp);

    tmp.clear();
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(0);
    grid.push_back(tmp);

    tmp.clear();
    tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(0);
    tmp.push_back(0);
    grid.push_back(tmp);

    tmp.clear();
    tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(0);
    tmp.push_back(0);
    grid.push_back(tmp);

    Solution s;
    int result = s.islandPerimeter(grid);
    std::cout << result << std::endl;

    getchar();

    return 0;
}