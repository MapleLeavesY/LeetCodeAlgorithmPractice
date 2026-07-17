#include <vector>
#include <string>


class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) 
    {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> path;

        Prev(result, path, s, 0);
        return result;
    }
private:
    void Prev
    (
        std::vector<std::vector<std::string>>& result,
        std::vector<std::string>& path,
        std::string& s,
        int select
    )
    {
        if(select >= s.size())
        {
            result.push_back(path);
            return;
        }

        for(int i = select; i < s.size(); i++)
        {

            if(!GetValueisChild(s, select, i)) continue;
            
            std::string temp;
            temp = s.substr(select, i - select + 1);

            path.push_back(temp);

            Prev(result, path, s, i + 1);

            path.pop_back();
        }
    }
    bool GetValueisChild(std::string path, int start, int end)
    {
        if(path.size() == 0) return false;
        int left = start;
        int right = end;

        while(left < right)
        {
            if(path[left] != path[right]) return false;

            left++;
            right--;
        }
        return true;
    }
};