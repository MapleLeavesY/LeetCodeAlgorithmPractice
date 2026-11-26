#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
    {
        int height = matrix.size() - 1;
        int length = 0;
        while(height >= 0 && height < matrix.size())
        {
            if(matrix[height][0] == target)
            {
                return true;
            }
            if(matrix[height][0] > target)
            {
                height--;
                continue;
            }
            if(matrix[height][0] < target)
            {
                break;
            }
        }
        if(height < 0) height = 0;
        while(length >= 0 && length < matrix[0].size())
        {
            if(matrix[height][length] == target)
            {
                return true;
            }
            if(matrix[height][length] < target)
            {
                length++;
                continue;
            }
            if(matrix[height][length] > target)
            {
                break;
            }
        }
        return false;
    }
};