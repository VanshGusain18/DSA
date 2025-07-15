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
    bool fn(TreeNode *root, long long mini, long long maxi)
    {
        if (root == nullptr)
            return true;
        if (root->val >= maxi || root->val <= mini)
            return false;
        return fn(root->left, mini, root->val) && fn(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode *root)
    {
        return fn(root, LLONG_MIN, LLONG_MAX);
    }
};