
#include <climits>

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
    bool isValidBST(TreeNode* root) 
    {
        return isTree(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool isTree(TreeNode* root, long long left, long long right)
    {
        if(root == nullptr) return true;
        if(root->val >= right || root->val <= left) return false;

        bool canleft = isTree(root->left, left , root->val);
        bool canright = isTree(root->right, root->val, right);

        return canleft && canright;
    }
};