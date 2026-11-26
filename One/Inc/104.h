#include <queue>
#include <stack>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//第一种--广度优先算法
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr) return 0;
        std::queue<TreeNode*> queue;
        int result = 0;
        queue.push(root);
        while(!queue.empty())
        {
            TreeNode* temp;
            int levelLayer = queue.size();
            while(levelLayer--)
            {
                temp = queue.front();
                queue.pop();

                if(temp->right != nullptr) { queue.push(temp->right); }
                if(temp->left != nullptr) { queue.push(temp->left); }
            }
            result++;
        }
        return result;
    }
};
//第二种--深度优先算法
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr) return 0;
        std::stack<std::pair<TreeNode*, int>> stack;
        int result = 0;
        stack.push({ root, 0 });
        while(!stack.empty())
        {
            TreeNode* temp = stack.top().first;
            int number = stack.top().second;
            stack.pop();

            result = std::max(result, number);

            if(temp->right != nullptr) { stack.push({ temp->right, number + 1 }); }
            if(temp->left != nullptr) { stack.push({ temp->left, number + 1 }); }
        }
        return result + 1;
    }
};


