#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) 
    {
        int size = nums.size();
        int last_maxDistance{ 0 };
        int current_maxDistance { 0 };
        
        int nextChange = 0;
        int layer = 0;
        for(int i = 0; i < size - 1; i++)
        {
            int num = nums[i];
            if(i > current_maxDistance) break;
            current_maxDistance = std::max(current_maxDistance, i + num);
            if(i == last_maxDistance)
            {
                nextChange = current_maxDistance;
                last_maxDistance = current_maxDistance;
                layer++;
                if(last_maxDistance >= size - 1) break;
            }
        }
        return layer;
    }
};