#include <vector>
#include <limits>


class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) 
    {
        int ySize = grid.size();
        int xSize = grid[0].size();
    
        std::vector<std::vector<int>> dp
        (
            ySize,
            std::vector<int>(xSize, 0)
        );

        dp[0][0] = grid[0][0];

        for(int y = 0; y < ySize; y++)
        {
            for(int x = 0; x < xSize; x++)
            {
                int left = __INT_MAX__;
                int up = __INT_MAX__;
                if(y - 1 >= 0)
                {
                    up = dp[y - 1][x];
                }
                if(x - 1 >= 0)
                {
                    left = dp[y][x - 1];
                }
                int res = std::min(up, left);
                if(res == __INT_MAX__)
                    dp[y][x] = grid[y][x];
                else
                    dp[y][x] = grid[y][x] + res;
        
            }
        }
        return dp[ySize - 1][xSize - 1];
    }
};