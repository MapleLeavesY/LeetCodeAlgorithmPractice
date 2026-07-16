#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) 
    {
        std::vector<std::string> result;
        std::string path;
        PrevL(result, path, n, 0, 0);
        return result;

    }
private:
    void PrevL
    (
        std::vector<std::string>& result,
        std::string& path,
        int n,
        int left,
        int right
    )
    {
        if(left == n && right == n)
        {
            result.push_back(path);
            return;
        }
        if(left < n)
        {
            path.push_back('(');
            PrevL(result, path, n, left + 1, right);
            path.pop_back();
        }

        if(right < left)
        {
            path.push_back(')');
            PrevL(result, path, n, left, right + 1);
            path.pop_back();
        }
    }
};