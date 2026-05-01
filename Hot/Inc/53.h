#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int rear = nums[0];
        int result = nums[0];
        for(int i  = 1; i < nums.size(); i++)
        {
            rear = max(nums[i], rear + nums[i]);
            result = max(result, rear);
        }
        return result;
    }
};