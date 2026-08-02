#include <vector>


class Solution {
public:
    int maxProduct(std::vector<int>& nums) 
    {
        int size = nums.size();
        std::vector<int> dp(size);
        int result = nums[0];

        dp[0] = nums[0];
        for(int i = 1; i < size; i++)
        {
            for(int j = 0; j < i; j++)
            {
                dp[i] = std::max(nums[i], dp[i - 1] * nums[i]);

                if(nums[j] >= 0 || dp[i] >= 0) continue;

                 
            }
        }
        return result;
    }
};