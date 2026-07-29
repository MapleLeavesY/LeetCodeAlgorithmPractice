#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) 
    {
        bool result{false};
        int size = nums.size();
        JumpTryMax(nums, 0, size, result);

        return result;
    }
private:
    void JumpTryMax
    (
        std::vector<int>& nums,
        int select,
        int size,
        bool& result
    )
    {
        if(result == true) return;
        if(select >= size) return;
        if(select == size - 1)
        {
            result = true;
            return;
        }
        int canJumpDistance = nums[select];

        for(int i = canJumpDistance; i > 0; i--)
        {
            JumpTryMax(nums, select + i, size, result);
        }
    }
};