#include <vector>
#include <string>

enum class Dirction
{
    up = 0, down, left, right, init
};

#pragma region 79单词搜索

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) 
    {
        std::string path;
        bool result = false;
        for(int height = 0; height < board.size(); height++)
        {
            for(int length = 0; length < board[0].size(); length++)
            {
                Prev(board, path, result, word, height, length, 0);
            }
        }
        return result;
    }
private:
    void Prev
    (
        std::vector<std::vector<char>>& board,
        std::string& path,
        bool& result,
        std::string word,
        int height,
        int length,
        int layer
    )
    {
        if
        (
            height >= board.size() || height < 0 ||
            length >= board[0].size() || length < 0
        )
        return;
        if(board[height][length] != word[layer]) return;
        if(layer == word.size() - 1)
        {
            result = true;
            return;
        }

        if(board[height][length] == word[layer])
        {
            char save;
            //左
            path.push_back(board[height][length]);
            save = board[height][length];
            board[height][length] = '#';
            Prev(board, path, result, word, height, length - 1, layer + 1);
            board[height][length] = save;
            path.pop_back();
            //右
            path.push_back(board[height][length]);
            save = board[height][length];
            board[height][length] = '#';
            Prev(board, path, result, word, height, length + 1, layer + 1);
            board[height][length] = save;
            path.pop_back();
            //上
            path.push_back(board[height][length]);
            save = board[height][length];
            board[height][length] = '#';
            Prev(board, path, result, word, height - 1, length, layer + 1);
            board[height][length] = save;
            path.pop_back();
            //下
            path.push_back(board[height][length]);
            save = board[height][length];
            board[height][length] = '#';
            Prev(board, path, result, word, height + 1, length, layer + 1);
            board[height][length] = save;
            path.pop_back();
        } 
    }
};

#pragma endregion