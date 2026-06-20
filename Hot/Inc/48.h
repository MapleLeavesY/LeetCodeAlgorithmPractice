#include <iostream>
#include <vector>


#pragma region 旋转矩阵
class Solution
{
public:
    void rotate(std::vector<std::vector<int>>& matrix)
    {
        int YCount = static_cast<int>(matrix.size());
        int XCount = static_cast<int>(matrix[0].size());

        for(int y = 0; y < YCount; y++)
        {//对称交换
            for(int x = y; x < XCount; x++)
            {
                int switchNumber = matrix[y][x];
                matrix[y][x] = matrix[x][y];
                matrix[x][y] = switchNumber;
            }
        }
        for(int y = 0; y < YCount; y++)
        {//双指针前后切换
            int right = YCount - 1;
            int left = 0;
            while(left < right)
            {
                int switchNumber = matrix[y][left];
                matrix[y][left] = matrix[y][right];
                matrix[y][right] = switchNumber;
                left++;
                right--;
            }
        }
    }
};

#pragma endregion