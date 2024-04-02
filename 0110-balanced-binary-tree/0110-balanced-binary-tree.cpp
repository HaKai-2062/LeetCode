/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isBalanced(TreeNode* root)
    {
        bool balanceCheck = true;
        dfs(root, balanceCheck);
        return balanceCheck;
    }

    int dfs(TreeNode* root, bool& balanceCheck)
    {
        if (root == nullptr)
            return -1;

        int left = dfs(root->left, balanceCheck);
        int right = dfs(root->right, balanceCheck);

        int height = std::max(left, right) + 1;

        if (std::abs(left - right) > 1)
        {
            balanceCheck = false;
        }
        
        return height;
    }
};