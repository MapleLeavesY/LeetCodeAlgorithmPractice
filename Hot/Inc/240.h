#include <iostream>
#include <vector>


#pragma region 二维矩阵搜索

//暴力解法 时间复杂度O(m * n)
class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
    {
        int XCount = static_cast<int>(matrix[0].size());
        int YCount = static_cast<int>(matrix.size());

        bool result = false;
        for(int y = 0; y < YCount; y++)
        {
            for(int x = 0; x < XCount; x++)
            {
                if(matrix[y][x] == target)
                {
                    result = true;
                    break;;
                }
            }
        }
        return result;
    }
};
//二叉树查找法 O(m + n)

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> matrix, int target)
    {
        int YCount = static_cast<int>(matrix.size());
        int XCount = static_cast<int>(matrix[0].size());
        
        int y = 0;
        int x = XCount - 1;
        bool result = false;
        while(x >= 0 && y < YCount)
        {
            if(matrix[y][x] > target) x--;
            if(matrix[y][x] < target) y++;
            if(matrix[y][x] == target) { result = true; break; }
        }
        return result;
    }
};
#pragma endregion