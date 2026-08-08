#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) 
    {
        int size = nums.size();
        int currentMin{ nums[0] };
        int currentMax{ nums[0] };
        int result { nums[0] };
        for(int i = 1; i < size; i++)
        {   
            int lastMax = currentMax;
            int lastMin = currentMin;

            currentMin = std::min(nums[i], lastMax * nums[i]);
            currentMin = std::min(currentMin, lastMin * nums[i]);
            currentMax = std::max(nums[i], lastMax * nums[i]);
            currentMax = std::max(currentMax, lastMin * nums[i]);
            result = std::max(result, currentMax);
        }
        return result;
    }
};