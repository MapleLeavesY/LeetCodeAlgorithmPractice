#include <iostream>
#include <vector>
#include <cstring>
#include<unordered_set>

#pragma region 


enum class Direction
{
    Right = 0,
    Down,
    Left,
    Up
};

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        int rowCount = static_cast<int>(matrix.size());
        int colCount = static_cast<int>(matrix[0].size());

        // 记录每个位置是否访问过
        std::vector<std::vector<bool>> visited(
            rowCount,
            std::vector<bool>(colCount, false)
        );

        std::vector<int> result;
        result.reserve(rowCount * colCount);

        // 右、下、左、上
        int rowDirection[4] = {0, 1, 0, -1};
        int colDirection[4] = {1, 0, -1, 0};

        int row = 0;
        int col = 0;

        Direction direction = Direction::Right;

        int totalCount = rowCount * colCount;

        for (int count = 0; count < totalCount; count++)
        {
            // 记录当前位置
            result.push_back(matrix[row][col]);
            visited[row][col] = true;

            // 最后一个元素已经处理完，不再计算下一位置
            if (count == totalCount - 1)
            {
                break;
            }

            int directionIndex = static_cast<int>(direction);

            // 计算按照当前方向移动后的坐标
            int nextRow = row + rowDirection[directionIndex];
            int nextCol = col + colDirection[directionIndex];

            // 判断下一格是否越界或已经访问
            if (nextRow < 0 ||
                nextRow >= rowCount ||
                nextCol < 0 ||
                nextCol >= colCount ||
                visited[nextRow][nextCol])
            {
                // 顺时针切换方向
                direction = static_cast<Direction>(
                    (directionIndex + 1) % 4
                );

                directionIndex = static_cast<int>(direction);

                // 使用新方向重新计算下一位置
                nextRow = row + rowDirection[directionIndex];
                nextCol = col + colDirection[directionIndex];
            }

            // 真正移动一次
            row = nextRow;
            col = nextCol;
        }

        return result;
    }
};
/*
enum class Dirction
{
    Up = 0,Right,Down,Left
};

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) 
    {
        std::unordered_set<std::string> position;
        Dirction dirction = Dirction::Right;
        std::vector<int> result;
        int l = 0; int h = 0; 
        bool flag = true;
        bool switchDir = false;
        while (flag)
        {
            result.push_back(matrix[h][l]);
            position.insert("l" + std::to_string(l) + "h" + std::to_string(h));
            if(dirction == Dirction::Up)
            {
                h--;
                if(h > matrix.size() || position.find("l" + std::to_string(l) + "h" + std::to_string(h)) != position.end())
                {
                    switchDir = true;
                    h++;
                    dirction = static_cast<Dirction>((static_cast<int>(dirction) + 1) % 4);
                }
            }
            if(dirction == Dirction::Right)
            {
                l++;
                if(l > matrix[0].size() || position.find("l" + std::to_string(l) + "h" + std::to_string(h)) != position.end())
                {
                    switchDir = true;
                    l--;
                    dirction = static_cast<Dirction>((static_cast<int>(dirction) + 1) % 4);
                }
            }
            if(dirction == Dirction::Down)
            {
                h++;
                if(h > matrix.size() || position.find("l" + std::to_string(l) + "h" + std::to_string(h)) != position.end())
                {
                    switchDir = true;
                    h--;
                    dirction = static_cast<Dirction>((static_cast<int>(dirction) + 1) % 4);
                }
            }
            if(dirction == Dirction::Left)
            {
                l--;
                if(h > matrix[0].size() || position.find("l" + std::to_string(l) + "h" + std::to_string(h)) != position.end())
                {
                    switchDir = true;
                    l++;
                    dirction = static_cast<Dirction>((static_cast<int>(dirction) + 1) % 4);
                }
            }



            if(dirction == Dirction::Up)
            {
                h--;
                if(switchDir && position.find("l" + std::to_string(l) + "h" + std::to_string(h)) != position.end())
                {
                    flag = false;
                }
            }
            if(dirction == Dirction::Right)
            {
                l++;
                if(switchDir && position.find("l" + std::to_string(l) + "h" + std::to_string(h)) != position.end())
                {
                    flag = false;
                }
            }
            if(dirction == Dirction::Down)
            {
                h++;
                if(switchDir && position.find("l" + std::to_string(l) + "h" + std::to_string(h)) != position.end())
                {
                    flag = false;
                }
            }
            if(dirction == Dirction::Left)
            {
                l--;
                if(switchDir && position.find("l" + std::to_string(l) + "h" + std::to_string(h)) != position.end())
                {
                    flag = false;
                }
            }
        }
        return result;
    }
};

*/

#pragma endregion