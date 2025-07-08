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
    int maxDepth(TreeNode *root, int &maxi)
    {
        if (root == nullptr)
            return 0;
        int lh = max(0, maxDepth(root->left, maxi));
        int rh = max(0, maxDepth(root->right, maxi));
        maxi = max(lh + rh + root->val, maxi);
        return root->val + max(lh, rh);
    }

    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        maxDepth(root, maxi);
        return maxi;
    }
};