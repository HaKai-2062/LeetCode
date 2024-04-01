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
    int diameterOfBinaryTree(TreeNode* root)
    {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }

    int dfs(TreeNode* root, int& diameter)
    {
        if (root == NULL)
            return -1;

        int left = dfs(root->left, diameter);
        int right = dfs(root->right, diameter);

        diameter = std::max(left + right + 2, diameter);
        int height = 1 + std::max(left, right);
        return height;
    }
};