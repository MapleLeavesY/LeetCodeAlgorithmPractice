#include <queue>

#pragma region 对称二叉树


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
    bool isSymmetric(TreeNode* root) 
    {
        return GetSymmetric(root->left, root->right);
    }
private:
    bool GetSymmetric(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right == nullptr) return true;

        if(left == nullptr || right == nullptr) return false;
        if(left->val != right->val) return false;

        return GetSymmetric(left->left, right->right) && GetSymmetric(left->right, right->left);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if(root == nullptr) return true;
        std::queue<TreeNode*> queue;
        queue.push(root->left);
        queue.push(root->right);
        while(!queue.empty())
        {
            TreeNode* left = queue.front();
            queue.pop();
            TreeNode* right = queue.front();
            queue.pop();

            if(left == nullptr && right == nullptr) continue;

            if(left == nullptr || right == nullptr) return false;
            if(left->val != right->val) return false;

            queue.push(left->left);
            queue.push(right->right);

            queue.push(left->right);
            queue.push(right->left);
        }
        return true;

    } 
};
#pragma endregion