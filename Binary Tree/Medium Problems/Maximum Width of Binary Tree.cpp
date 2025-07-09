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
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        int diff = 0;
        q.push({root, 0});
        while (!q.empty())
        {
            int s = q.size(), mini = q.front().second, left, right;
            for (int i = 0; i < s; i++)
            {
                auto p = q.front();
                q.pop();
                TreeNode *n = p.first;
                int curr = p.second - mini;
                if (i == 0)
                    left = curr;
                if (i == s - 1)
                    right = curr;
                if (n->left)
                    q.push({n->left, (long long)curr * 2 + 1});
                if (n->right)
                    q.push({n->right, (long long)curr * 2 + 2});
            }
            diff = max(diff, right - left + 1);
        }
        return diff;
    }
};