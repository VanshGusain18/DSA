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
    int amountOfTime(TreeNode *root, int start)
    {
        queue<TreeNode *> q;
        map<TreeNode *, TreeNode *> mp;
        TreeNode *target;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *n = q.front();
            if (n->val == start)
                target = n;
            q.pop();
            if (n->left)
            {
                q.push(n->left);
                mp[n->left] = n;
            }
            if (n->right)
            {
                q.push(n->right);
                mp[n->right] = n;
            }
        }
        queue<TreeNode *> qq;
        map<TreeNode *, bool> mpp;
        qq.push(target);
        mpp[target] = true;
        int curr = 0;
        while (!qq.empty())
        {
            curr++;
            int size = qq.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *n = qq.front();
                qq.pop();
                if (n->left && !mpp[n->left])
                {
                    qq.push(n->left);
                    mpp[n->left] = true;
                }
                if (n->right && !mpp[n->right])
                {
                    qq.push(n->right);
                    mpp[n->right] = true;
                }
                if (mp[n] && !mpp[mp[n]])
                {
                    qq.push(mp[n]);
                    mpp[mp[n]] = true;
                }
            }
        }
        return curr - 1;
    }
};