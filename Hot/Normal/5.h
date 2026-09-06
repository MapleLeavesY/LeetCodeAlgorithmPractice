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


class Solution {
public:
    std::string longestPalindrome(std::string s) 
    {
        int start = 0;
        int end = 0;
        int size = s.size();
        for(int i = 0; i < size; i++)
        {
            Catlage(s, i, i, start, end);

            Catlage(s, i, i + 1, start, end);
        }
        return s.substr(start, end - start + 1);
    }
private:
    void Catlage
    (
        const std::string& str,
        int leftBegin,
        int rightBegin,
        int& start,
        int& end
    )
    {
        if(leftBegin == rightBegin)
        {//中心点相同，为奇数对称
            int left = leftBegin;
            int right = leftBegin;

            while(left >= 0 && right < str.size())
            {
                if(str[left] != str[right]) break;
                if(end - start < right - left)
                {
                    start = left;
                    end = right;
                }
                left--;
                right++;
            }
            return;
        }
        //中心点左右对称，为偶数对称
        int left = leftBegin;
        int right = rightBegin;

        while(left >= 0 && right < str.size())
        {
            if(str[left] != str[right]) break;
            if(end - start < right - left)
            {
                start = left;
                end = right;
            }
            left--;
            right++;
        }
    }
};