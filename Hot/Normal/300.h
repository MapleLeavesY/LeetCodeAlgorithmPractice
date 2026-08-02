#include <vector>


class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) 
    {
        int size = nums.size();
        std::vector<int> dp(size, 1);
        int result = 1;
        dp[0] = 1;
        for(int i = 1; i < size; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            result = std::max(result, dp[i]);
        }
        return result;
    }
};