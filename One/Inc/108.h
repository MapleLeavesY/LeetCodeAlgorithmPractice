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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) 
    {
        return Build(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* Build(std::vector<int>& nums, int left, int right)
    {
        if(left > right) return nullptr;

        int mid = left + ((right - left) / 2);
        TreeNode* temp = new TreeNode(nums[mid]);

        temp->left = Build(nums, left, mid - 1);
        temp->right = Build(nums, mid + 1, right);

        return temp;
    }
};