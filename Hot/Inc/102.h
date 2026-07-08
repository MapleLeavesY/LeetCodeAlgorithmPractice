#include <queue>
#include <vector>
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
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        if(root == nullptr) return {};
        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty())
        {
            std::vector<int> Layer;
            int number = queue.size();
            while(number--)
            {
                TreeNode* temp = queue.front();
                queue.pop();
                Layer.push_back(temp->val);
                if(temp->left != nullptr) { queue.push(temp->left); }
                if(temp->right != nullptr) { queue.push(temp->right); }
            }
            result.push_back(Layer);
        }
        return result;
    }
};