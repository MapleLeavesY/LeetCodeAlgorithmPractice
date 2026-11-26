#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
class Solution {
public:
    std::vector<int> partitionLabels(std::string s) 
    {
        std::vector<int> result;
        int size = s.size();
        int left{ 0 };
    
        char currentChar;
        std::unordered_map<char, int> map;
        std::unordered_set<char> set;
        for(auto c : s)
        {
            map[c]++;
        }

        for(int i = 0; i < size; i++)
        {
            currentChar = s[i];
            map[currentChar]--;

            if(map[currentChar] > 0) { set.insert(currentChar); }
            else{ set.erase(currentChar); }

            if(set.empty())
            {
                int pushInt = i - left;
                left = i + 1;
                result.push_back(pushInt + 1);
            }
        }
        return result;
    }
};