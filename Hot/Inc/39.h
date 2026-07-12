#include <vector>
#include <algorithm>
#pragma region 组合总和--暴力解法

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) 
    {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        int sum = 0;
        PrevL(candidates, result, path, target, sum);
        std::sort(result.begin(), result.end());

        auto temp = std::unique(result.begin(), result.end());
        result.erase(temp, result.end());

        return result;
    }
private:
    void PrevL
    (
        std::vector<int>& candidates,
        std::vector<std::vector<int>>& result,
        std::vector<int>& path,
        int target,
        int& sum
    )
    {
        if(sum == target)
        {
            std::vector<int> temp;
            temp = path;
            std::sort(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }
        if(sum > target)
        {
            return;
        }
        for(int i = 0; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            PrevL(candidates, result, path, target, sum += candidates[i]);

            sum-= candidates[i];
            path.pop_back();
        }
    }
};

#pragma endregion

#pragma region 组合总和--树剪枝
class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) 
    {
        std::vector<std::vector<int>> result;
        std::vector<int> path;

        std::sort(candidates.begin(), candidates.end());
        PrevL(candidates, result, path, target, 0);
        return result;
    }
private:
    void PrevL
    (
        std::vector<int>& candidates,
        std::vector<std::vector<int>>& result,
        std::vector<int>& path,
        int surplus,
        int index
    )
    {
        if(surplus == 0)
        {
            result.push_back(path);
            return;
        }
        if(surplus < 0)
        {
            return;
        }
        for(int i = index; i < candidates.size(); i++)
        {
            
            path.push_back(candidates[i]);
            surplus -= candidates[i];

            PrevL(candidates, result, path, surplus, i);

            path.pop_back();
            surplus += candidates[i];
        }
    }
};
#pragma endregion