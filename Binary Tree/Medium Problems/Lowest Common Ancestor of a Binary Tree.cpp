// Brute Approch

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool fn(TreeNode *root, TreeNode *p, vector<TreeNode *> &aa)
    {
        if (root == nullptr)
            return false;
        aa.push_back(root);
        if (root == p)
        {
            return true;
        }
        if (fn(root->left, p, aa) || fn(root->right, p, aa))
        {
            return true;
        }
        aa.pop_back();
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> aa;
        vector<TreeNode *> bb;
        fn(root, p, aa);
        fn(root, q, bb);
        int mini = min(aa.size(), bb.size());
        TreeNode *res = new TreeNode(-1);
        for (int i = 0; i < mini; i++)
        {
            if (aa[i] == bb[i])
            {
                res = aa[i];
            }
            else
            {
                break;
            }
        }
        return res;
    }
};