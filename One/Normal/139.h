#include <vector>
#include <string>
#include <unordered_set>
class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) 
    {
        int size = s.size();
        std::vector<bool> dp(size + 1, false);
        std::unordered_set<std::string> _cache(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for(int i = 1; i <= size; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(!dp[j]) continue;
                std::string path = s.substr(j, i - j);

                if(_cache.find(path) != _cache.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[size];
    }
};