#include <vector>
#include <stack>

class Solution {
public:
    int rob(std::vector<int>& nums) 
    {
        int dp_1{};
        int dp_2{};
        for(int num : nums)
        {
            int maxPrevValue = std::max(num + dp_2, dp_1);
            dp_2 = dp_1;
            dp_1 = maxPrevValue;
        }
        return dp_1;
    }
};