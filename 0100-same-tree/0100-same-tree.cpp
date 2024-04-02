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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        std::queue<TreeNode*> temp;
        temp.push(p);
        temp.push(q);

        while (!temp.empty())
        {
            TreeNode* pVal = temp.front();
            temp.pop();
            TreeNode* qVal = temp.front();
            temp.pop();

            if (pVal == nullptr && qVal == nullptr)
                continue;

            if (pVal == nullptr || qVal == nullptr)
                return false;

            if (pVal->val != qVal->val)
                return false;

            temp.push(pVal->left);
            temp.push(qVal->left);
            temp.push(pVal->right);
            temp.push(qVal->right);
        }
        return true;
    }
};