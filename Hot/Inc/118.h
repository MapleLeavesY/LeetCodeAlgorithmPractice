#include <vector>
#include <queue>


#pragma region 118-杨辉三角-队列法
class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) 
    {
        std::vector<std::vector<int>> result;
        std::queue<int> queue;
        int Layer = 1;
        for(int i = 0; i < numRows; i++)
        {
            int layer = Layer;
            std::queue<int> save;
            std::vector<int> path;
            while(layer--)
            {
                if(layer == i)
                {
                    save.push(1);
                    path.push_back(1);
                    continue;
                }
                if(layer == 0)
                {
                    save.push(1);
                    path.push_back(1);
                    continue;
                }     

                int que0 = queue.front(); queue.pop();
                int que1 = queue.front();
                int delta = que0 + que1;
                
                save.push(delta);
                path.push_back(delta);
            }

            queue = save;
            Layer++;
            result.push_back(path);
        }
        return result;
    }
};
#pragma endregion

#pragma region 118杨辉三角--数组查询法

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) 
    {
        std::vector<std::vector<int>> result;

        for(int i = 0; i < numRows; i++)
        {
            std::vector<int> path;
            int layer = i + 1;
            for(int j = 0; j < layer; j++)
            {
                if(j - 1 >= 0 && j < i)
                {
                    int r0 = result[i - 1][j - 1];
                    int r1 = result[i - 1][j];
                    int delta = r0 + r1;
                    path.push_back(delta);
                }
                else
                {
                    path.push_back(1);
                }
            }
            result.push_back(path);
        }
        return result;
    }
};

#pragma endregion