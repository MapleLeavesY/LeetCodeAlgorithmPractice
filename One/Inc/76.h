#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
#pragma region 最小覆盖字串 76
/*
class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char, int> need, window;
        int left = 0, right = 0;
        int start = 0, end = 0;
        int value = 0, len = INT_MAX;
        int begin = 0;
        for(char key : t)
        {
            need[key]++;
        }
        while(right < s.size())
        {
            if(need.count(s[right]))
            {
                window[s[right]]++;

                if(window[s[right]] == need[s[right]])
                {
                    value++;
                }
            }
            while(value == need.size())
            {
                if(right - left + 1 < len)
                {
                    len = right - left + 1;
                    begin = left;
                }
                if(need.count(s[left]))
                {
                    if(window[s[left]] == need[s[left]])
                    {
                        value--;
                    }
                    window[s[left]]--;
                }
                left++;   
            }
            right++;
        }
        return len == INT_MAX ? "" : s.substr(begin, len);
    }
};
*/
class Solution {
public:
    string minWindow(string s, string t) 
    {
        int left = 0, right = 0;
        unordered_map<char, int> need, window;
        int start = 0, len = INT_MAX;
        int value = 0;

        for(int str : t)
            need[str]++;

        while(right < s.size())
        {
            if(need.count(s[right]))
            {
                window[s[right]]++;
                if(window[s[right]] == need[s[right]])
                    value++;
            }

            while(value == need.size())
            {
                if(right - left + 1 < len)
                {
                    start = left;
                    len = right - left + 1;
                }
                if(need.count(s[left]))
                {
                    if(window[s[left]] == need[s[left]])
                    {
                        value--;
                    }
                    window[s[left]]--;
                }
                left++;
            }
            right++;
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
#pragma endregion