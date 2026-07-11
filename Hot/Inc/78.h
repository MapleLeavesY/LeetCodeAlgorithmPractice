#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> result;
        std::vector<int> path;

        PrevL(nums, result, path, 0);
        return result;
    }
private:
    void PrevL
    (
        std::vector<int>& nums, 
        std::vector<std::vector<int>>& result, 
        std::vector<int>& path,
        int index
    )
    {
        result.push_back(path);

        for(int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);

            PrevL(nums, result, path, i + 1);

            path.pop_back();
        }
    }
};