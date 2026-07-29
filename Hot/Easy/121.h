#include <vector>


class Solution {
public:
    int maxProfit(std::vector<int>& prices) 
    {
        int size = prices.size();
        
        int minBuyPrice = prices[0];
        int maxGet = 0;
        for(int i = 1; i < size; i++)
        {
            int currentBuyPrice = prices[i];

            maxGet = std::max(maxGet, currentBuyPrice - minBuyPrice);
            
            minBuyPrice = std::min(minBuyPrice, prices[i]);

        }
        return maxGet;
    }

};