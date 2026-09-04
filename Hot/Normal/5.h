#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) 
    {
        int left = 0;
        int size = s.size();

        std::string result = "";
        for(int i = 1; i < size; i++)
        {
            std::string str = s.substr(left, i);

            int l = 0;
            int r = s.size() - 1;
            bool canAdd = true;
            while(l < r)
            {
                if(str[l] != str[r]) 
                {
                    canAdd = false;
                    break;
                }
                l++;
                r--;
            }
            if(canAdd)
            {
                result = str.size() > result.size()
                    ? str
                    : result ;
                left = i + 1;
            }
        }
        return result;
    }
};