#include <stack>


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
    int kthSmallest(TreeNode* root, int k) 
    {
        if(root == nullptr) return -1;
        std::stack<TreeNode*> track;
        k--;
        while(root != nullptr || !track.empty())
        {
            while(root != nullptr)
            {
                track.push(root);
                root = root->left;
            }

            root = track.top();
            track.pop();

            if(k == 0) return root->val;
            else k--;

            root = root->right;
        }
        return -1;
    }
};