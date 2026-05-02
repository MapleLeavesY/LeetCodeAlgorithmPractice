#include <iostream>
#include <vector>

using namespace std;
#pragma region 轮转数组
class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        int size = nums.size();
        vector<int> result(size);
        int sum = 0;
        for(int i =  0; i < nums.size(); i++)
        {
            sum = (i + k) % size;
            result[sum] = nums[i];
        }
        for (int j = 0; j < nums.size(); j++)
        {
            nums[j] = result[j];
        }
    }
};
#pragma endregion