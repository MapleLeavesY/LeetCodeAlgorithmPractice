#include <vector>
#include <stack>

class Solution {
public:
    int rob(std::vector<int>& nums) 
    {
        int dp1{};
        int dp2{};
        for(int num : nums)
        {
            int maxNumber = std::max(dp1, dp2 + num);
            dp2 = dp1;
            dp1 = maxNumber;
        }
        return dp1;
    }
};