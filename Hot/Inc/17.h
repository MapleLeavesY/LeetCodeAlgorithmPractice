#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<char, std::string> _cache =
    {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    std::vector<std::string> letterCombinations(std::string digits) 
    {
        std::vector<std::string> result;
        std::string path;
        PrevL(result, digits, path, 0);
        return result;
    }
private:
    void PrevL
    (
        std::vector<std::string>& result,
        std::string& digits,
        std::string& path,
        int index
    )
    {
        if(path.size() == digits.size())
        {
            result.push_back(path);
            return;
        }
        for(int i = 0; i < _cache[digits[index]].size(); i++)
        {
            path.push_back(_cache[digits[index]][i]);

            PrevL(result, digits, path, index + 1);
            
            path.pop_back();
        }
    }
};