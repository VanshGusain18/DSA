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
    int countleft(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + countleft(root->left);
    }

    int countright(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + countright(root->right);
    }

    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = countleft(root->left);
        int right = countright(root->right);
        if (left == right)
        {
            return (1 << (left + 1)) - 1;
        }
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};