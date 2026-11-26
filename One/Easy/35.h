#include <vector>


#pragma region 搜索插入位置--二分
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) 
    {
        int size = nums.size();
        int current  = (size - 1)/ 2;
        int lastSelect = current;

        while(current >= 0 && current < size)
        {
            if(nums[current] == target)
            {
                return current;
            }

            if(nums[current] > target)
            {
                lastSelect = current;
                current--;
                continue;
            }
            if(nums[current] < target && nums[lastSelect] > target)
            {
                return lastSelect;
            }

            if(nums[current] < target)
            {
                lastSelect = current;
                current++;
                continue;
            }
            if(nums[current] > target && nums[lastSelect] < target)
            {
                return current;
            }
        }
        if(current < 0)
        return 0;
        return current;
    }
};

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) 
    {
        int size = nums.size();
        int left = 0;
        int right = size;

        while(left < right)
        {
            int middle = left + (right - left) / 2;

            if(nums[middle] == target)
            {
                return middle;
            }
            if(nums[middle] < target)
            {
                left = middle + 1;
                continue;
            }
            if(nums[middle] > target)
            {
                right = middle;
                continue;
            }
        }
        return left;
    }
};
#pragma endregion
