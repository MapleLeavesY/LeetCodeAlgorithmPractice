#include <vector>
#include <string>

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


class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) 
    {
        bool result = false;
        std::string path;
        for(int height = 0; height < board.size(); height++)
        {
            for(int length = 0; length < board[0].size(); length++)
            {
                result = Prev(board, word, path, length, height, 0);
                if(result == true) return result;
            }
        }
        return result;
    }
private:
    bool Prev
    (
        std::vector<std::vector<char>>& board,
        std::string& word,
        std::string& path,
        int length,
        int height,
        int layer
    )
    {
        if
        (
            length >= board[0].size() || length < 0 ||
            height >= board.size() || height < 0
        )
        return false;
        if(board[height][length] != word[layer]) return false;
        if(layer == word.size() - 1)
        {
            return true;
        }
        if(board[height][length] == word[layer])
        {
            char save = board[height][length];
            path.push_back(board[height][length]);
            board[height][length] = '#';
            bool result = {
            //左
                Prev(board, word, path, length - 1, height, layer + 1) ||
                //右
                Prev(board, word, path, length + 1, height, layer + 1) ||
                //上
                Prev(board, word, path, length, height - 1, layer + 1) ||
                //下
                Prev(board, word, path, length, height + 1, layer + 1)
            };
            board[height][length] = save;
            path.pop_back();
            return result;
        }
        return false;
    }
};

#pragma endregion