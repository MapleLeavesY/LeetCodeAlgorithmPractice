#include <vector>

class Solution {
public:
    int numSquares(int n) 
    {
        std::vector<int> vec(n + 1, n + 1);
        vec[0] = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j * j <= i; j++)
            {
                int sqr = j * j;
                vec[i] = std::min(vec[i], vec[i - sqr] + 1);
            }
        }
        return vec[n];
    }
};