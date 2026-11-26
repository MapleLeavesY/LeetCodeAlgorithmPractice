#include <vector>
#include <algorithm>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) 
    {
        int size = coins.size();
        std::sort(coins.begin(), coins.end());
        std::vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(i < coins[j]) break;
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] == amount + 1  ? -1 : dp[amount];
    }
};