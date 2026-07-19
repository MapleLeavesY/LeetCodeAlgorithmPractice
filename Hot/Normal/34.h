#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) 
    {
        int size = nums.size();
        int left = 0;
        int right = size;
        while(left < right) 
        {
            int middle = left + (right - left) / 2;
            
            if(nums[middle] == target)
            {
                left = middle;
                right = middle;
                while(left - 1 >= 0 && nums[left - 1] == target)
                {
                    left--;
                }
                while(right + 1 < size && nums[right + 1] == target)
                {
                    right++;
                }
                return { left, right };
            }
            if(nums[middle] < target)
            {
                left = middle + 1;
            }
            if(nums[middle] > target)
            {
                right = middle;
            }
        }

        return { -1, -1 };
    }
};

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) 
    {
        int start = Dichotomy(nums, target);

        if(start >= nums.size() || nums[start] != target) return { -1, -1 };

        int end = Dichotomy(nums, target + 1) - 1;

        return { start, end }; 
    }
private:
    int Dichotomy(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size();

        while(left < right)
        {
            int middle = left + (right - left) / 2;

            if(nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }
        return left;
    }
};