#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#pragma region 缺失的第一个正数 41
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        int number = 1;
        for(int right = 0; right < nums.size(); right++)
        {
            mp[nums[right]] = right;
            while(mp.count(number)) number++;
        }
        return number;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        
    }
};
#pragma endregion