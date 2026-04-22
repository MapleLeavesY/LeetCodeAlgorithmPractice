#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> mp;
        int other;
        for(int i = 0; i < nums.size(); i++)
        {
            other = target - nums[i];
            if(mp.count(other))
            {
                return{ mp[other], i};
            }
            mp[nums[i]] = i;
        }
        return{};
    }
};


struct ListNode 
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* result(new ListNode(NULL, nullptr));
        ListNode* car = result;
        int carry = 0;
        int sum = 0;
        int x, y;
        while ((l1 != nullptr) || (l2 != nullptr) || (carry != 0))
        {   
            x = 0; y = 0;
            if(l1) {x = l1->val; l1 = l1->next;}
            if(l2) {y = l2->val; l2 = l2->next;}
            sum = x + y + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* temp(new ListNode(sum, nullptr));
            car->next = temp;
            car = car->next;
        }
        return result->next;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {   
        unordered_map<char,int> map;
        int left = 0, maxResult = 0;
        for(int right = 0; right < s.size(); right++)
        {
            char temp = s[right];
            if(map.count(temp) && map[temp] >= left)
            {//在表中发现了temp值
                left = map[temp] + 1;
            }
            map[temp] = right;
            maxResult = max(maxResult, (right - left) + 1);
        }
        return maxResult;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mp;
        for(const string& str : strs)
        {
            string key =  str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto& pair : mp)
        {
            result.push_back(pair.second);
        } 
        return result;

    }
};

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;
        for(string str : strs)
        {
            int count[26] = { 0 };
            for(char c : str)
            {
                count[c - 'a'] += 1;
            }

            string key;
            for(int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + '#';
            }

            mp[key].push_back(str);
        }
        for(auto& pair : mp)
            result.push_back(pair.second);
        return result;
    }
};
class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int left = 0;
        for(int right = 0; right< nums.size(); right++)
        {
            if(nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};
class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int l = 0;
        int h = 0;
        int result = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left < right)
        {
            l = right - left;
            h = min(height[left], height[right]);
            result = max(result, (l * h));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return result;
    }
};

int main()
{


    cin.get();
}