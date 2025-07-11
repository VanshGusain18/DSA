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
    bool isSym(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        if (p->val == q->val && isSym(p->left, q->right) && isSym(p->right, q->left))
        {
            return true;
        }
        return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        return isSym(root->left, root->right);
    }
};