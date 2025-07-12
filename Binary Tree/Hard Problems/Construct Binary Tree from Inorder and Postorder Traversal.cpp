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
    TreeNode *fn(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
    {
        if (postStart > postEnd || inStart > inEnd)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[postEnd]);
        int inRoot = mp[postorder[postEnd]];
        int numsLeft = inRoot - inStart;

        root->left = fn(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inRoot - 1, mp);
        root->right = fn(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, mp);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode *root = fn(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
        return root;
    }
};
