#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) 
    {
        int maxSelect = 0;
        int size = nums.size();
        
        for(int i = 0; i < size; i++)
        {
            int num = nums[i];
            if(i > maxSelect) break;
            maxSelect = std::max(maxSelect, i + num);
        }

        return maxSelect >= size - 1 ? true : false;
    }
};