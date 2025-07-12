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
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        queue<TreeNode *> q;
        map<TreeNode *, TreeNode *> mp;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *n = q.front();
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
            if (curr == k + 1)
                break;
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
        vector<int> res;
        while (!qq.empty())
        {
            res.push_back(qq.front()->val);
            qq.pop();
        }
        return res;
    }
};