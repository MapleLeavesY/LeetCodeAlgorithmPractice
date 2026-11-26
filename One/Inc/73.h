#include <iostream>
#include <vector>

#pragma region 矩阵置零
class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix)
    {
        bool lCanClear = false;
        bool hCanClear = false;
        int L = matrix[0].size();
        int H = matrix.size();
        for(int l = 0; l < L; l++)
        {
            if(matrix[0][l] == 0)
            {
                lCanClear = true;
                break;
            }
        }
        for(int h = 0; h < H; h++)
        {
            if(matrix[h][0] == 0)
            {
                hCanClear = true;
                break;
            }
        }

        for(int h = 0; h < H; h++)
        {
            for(int l = 0; l < L; l++)
            {
                if(matrix[h][l] == 0)
                {
                    matrix[0][l] = 0;
                    matrix[h][0] = 0;
                }
            }
        }

        for(int l = 1; l < L; l++)
        {
            if(matrix[0][l] == 0)
            {
                for(int h = 1; h < H; h++)
                {
                    matrix[h][l] = 0;
                }
            }
        }
        for(int h = 1; h < H; h++)
        {
            if(matrix[h][0] == 0)
            {
                for(int l = 1; l < L; l++)
                {
                    matrix[h][l] = 0;
                }
            }
        }

        if(lCanClear)
        {
            for(int l = 0; l < L; l++)
            {
                matrix[0][l] = 0;
            }
        }
        if(hCanClear)
        {
            for(int h = 0; h < H; h++)
            {
                matrix[h][0] = 0;
            }
        }
    }
};
#pragma endregion