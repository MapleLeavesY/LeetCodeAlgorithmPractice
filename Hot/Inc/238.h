#include <iostream>
#include <vector>

using namespace std;
#pragma region 除自身以外的乘积在数组中 238
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> answer(n);
        answer[0] = 1;
        int mul = 1;
        for(int i = 1; i < n; i++)
        {
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        for(int j = n - 2; j >= 0; j--)
        {
            mul *= nums[j + 1];
            answer[j] *= mul;
        }
        return answer;
    }
};
#pragma endregion