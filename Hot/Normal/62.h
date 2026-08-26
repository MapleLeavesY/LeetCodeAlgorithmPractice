
enum class Dirction
{
    Right,
    Down,
};


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