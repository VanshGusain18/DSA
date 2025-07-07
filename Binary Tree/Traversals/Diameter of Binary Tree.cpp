// Brute Approch

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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
    }

    void checkdiff(TreeNode *root, int &maxi)
    {
        if (root == nullptr)
            return;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        maxi = max(maxi, lh + rh);
        checkdiff(root->left, maxi);
        checkdiff(root->right, maxi);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxi = 0;
        checkdiff(root, maxi);
        return maxi;
    }
};