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
    std::vector<int> rightSideView(TreeNode* root) 
    {
        if(root == nullptr) return {};
        std::queue<TreeNode*> queue;
        std::vector<int> result;
        queue.push(root);
        while(!queue.empty())
        {   
            int Layer = queue.size();
            TreeNode* temp;
            while(Layer--)
            {
                temp = queue.front();
                queue.pop();

                if(temp->left != nullptr) queue.push(temp->left);
                if(temp->right != nullptr) queue.push(temp->right);

            }
            if(temp != nullptr) result.push_back(temp->val);
        }
        return result;
    }
};