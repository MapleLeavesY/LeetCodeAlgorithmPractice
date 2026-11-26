#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) 
    {
        if(nums.size() == 0) return {};
        std::vector<std::vector<int>> result;
        std::vector<bool> canSelect(nums.size(), false);
        std::vector<int> path;
        PL(result, nums, canSelect, path);
        return result;
    }
private:
    void PL
    (
        std::vector<std::vector<int>>& result, 
        std::vector<int>& nums, 
        std::vector<bool>& canSelect, 
        std::vector<int>& path
    )
    {
        if(path.size() == nums.size())
        {
            result.push_back(path);
            return;
        } 
            

        for(int i = 0; i < nums.size(); i++)
        {
            if(canSelect[i])
            {
                continue;
            }
            path.push_back(nums[i]);
            canSelect[i] = true;

            PL(result, nums, canSelect, path);

            canSelect[i] = false;
            path.pop_back();
        }
    }
};