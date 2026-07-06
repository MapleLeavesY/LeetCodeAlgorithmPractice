#include <vector>
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

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root == nullptr) return {};
        std::stack<TreeNode*> stack;
        std::vector<int> result;
        TreeNode* current = root;
        while(current != nullptr || !stack.empty())
        {
            while(current != nullptr)
            {
                stack.push(current);
                current = current->left;
            }
            current = stack.top();
            stack.pop();
            result.push_back(current->val);

            current = current->right;
        }
        return result;
    }
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        std::vector<int> result;
        GetValue(root, result);
        return result;
    }
private:
    void GetValue(TreeNode* root, std::vector<int>& result)
    {
        if(root == nullptr) return;
        GetValue(root->left, result);
        result.push_back(root->val);
        GetValue(root->right, result);
    }
};