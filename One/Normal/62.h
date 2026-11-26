#include <vector>

#pragma region 多维动态规划
enum class Dirction
{
    Right,
    Down,
};

// 自己思考的
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        if(m == 1 && n == 1) return 1;
        int dp { 0 };
        move(Dirction::Right, m, n, 1, 0, dp);
        move(Dirction::Down, m, n, 0, 1, dp);
        return dp;
    }

    void move
    (
        Dirction dirction,
        int m,
        int n,
        int positionX, 
        int positionY,
        int& dp
    )
    {
        if
        (
            positionX < 0 || positionX >= m ||
            positionY < 0 || positionY >= n
        )
        {
            return;
        }
        if(positionX == m - 1 && positionY == n - 1)
        {
            dp += 1;
            return;
        }
        
        move(Dirction::Right, m, n, positionX + 1, positionY, dp);
        move(Dirction::Down, m, n, positionX, positionY + 1, dp);
        
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        std::vector<std::vector<int>> dp
        (
            m,
            std::vector<int>(n, 0)
        );
        dp[0][0] = 1;
        for(int y = 0; y < m; y++)
        {
            for(int x = 0; x < n; x++)
            {
                if(y - 1 >= 0)
                {
                    dp[y][x] += dp[y - 1][x];
                }
                if(x - 1 >= 0)
                {
                    dp[y][x] += dp[y][x - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
#pragma endregion