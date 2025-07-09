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
    void fn(TreeNode *root, vector<string> &res, string temp)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            temp += to_string(root->val);
            res.push_back(temp);
        }
        temp += to_string(root->val) + "->";
        if (root->left)
            fn(root->left, res, temp);
        if (root->right)
            fn(root->right, res, temp);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        string temp;
        fn(root, res, temp);
        return res;
    }
};