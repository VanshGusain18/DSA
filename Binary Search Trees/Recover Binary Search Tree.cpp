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
    void fn(TreeNode *root, TreeNode *&low, TreeNode *&mid, TreeNode *&high, TreeNode *&prev)
    {
        if (root == nullptr)
            return;
        fn(root->left, low, mid, high, prev);
        if (root->val < prev->val)
        {
            if (low == nullptr)
            {
                low = prev;
                mid = root;
            }
            else
            {
                high = root;
            }
        }
        prev = root;
        fn(root->right, low, mid, high, prev);
    }

    void recoverTree(TreeNode *root)
    {
        TreeNode *low = nullptr;
        TreeNode *mid = nullptr;
        TreeNode *high = nullptr;
        TreeNode *prev = new TreeNode(INT_MIN);
        fn(root, low, mid, high, prev);
        if (!high)
        {
            swap(low->val, mid->val);
        }
        else
        {
            swap(low->val, high->val);
        }
    }
};