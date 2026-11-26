#include <vector>
#include <algorithm>

class Solution {
public:
    int search(std::vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            if(nums[middle] == target) return middle;

            if(nums[left] <= nums[middle])
            {//左边有序
                if(nums[left] <= target && nums[middle] > target)
                {
                    right = middle - 1;
                }
                else
                {
                    left = middle + 1;
                }
            }
            else
            {//右边有序
                if(nums[middle] < target && nums[right] >= target)
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle - 1;
                }
            }
        }
        return - 1;
    }
};