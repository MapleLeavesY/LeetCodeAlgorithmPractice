#include <vector>
#include <queue>

#pragma region 翻转二叉树


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(root == nullptr) return nullptr;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            int levelLayer = queue.size();
            while(levelLayer--)
            {
                TreeNode* current = queue.front();
                queue.pop();
                if(current->right != nullptr) { queue.push(current->right); } 
                if(current->left != nullptr) { queue.push(current->left); } 
                TreeNode* left = current->left;
                TreeNode* right = current->right;    
                current->left = right;
                current->right = left;
            }

        }
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        Overturn(root);
        return root;
    }
private:
    void Overturn(TreeNode* root)
    {
        if(root == nullptr) return;
        TreeNode* current = root;
        TreeNode* right = current->right;
        TreeNode* left = current->left;
        Overturn(right);
        Overturn(left);
        current->left = right;
        current->right = left;

    }
};
#pragma endregion