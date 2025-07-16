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

class BSTIterator
{
private:
    stack<TreeNode *> st;
    bool reverse;

public:
    BSTIterator(TreeNode *root, bool r)
    {
        reverse = r;
        pushAll(root);
    }

    int next()
    {
        TreeNode *tp = st.top();
        st.pop();
        if (reverse)
            pushAll(tp->left);
        else
            pushAll(tp->right);
        return tp->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node != nullptr)
        {
            st.push(node);
            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next(), j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};