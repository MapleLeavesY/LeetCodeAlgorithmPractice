#include <vector>

#pragma region dpAI解法
class Solution {
public:
    bool canPartition(std::vector<int>& nums) 
    {
        int size = nums.size();
        int sumAll{ 0 };
        for(auto num : nums) sumAll += num;
        
        if(sumAll % 2 != 0) return false;
        int target = sumAll / 2;
        
        std::vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(auto num : nums)
        {
            for(int i = target; i >= num; i--)
            {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};

#pragma endregion