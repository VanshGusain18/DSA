/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "#";
        string res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *n = q.front();
            q.pop();
            if (n == nullptr)
                res += "#,";
            else
            {
                res += to_string(n->val) + ',';
                q.push(n->left);
                q.push(n->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data[0] == '#')
            return nullptr;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *n = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
            {
                n->left = nullptr;
            }
            else
            {
                TreeNode *ln = new TreeNode(stoi(str));
                n->left = ln;
                q.push(ln);
            }
            getline(s, str, ',');
            if (str == "#")
            {
                n->right = nullptr;
            }
            else
            {
                TreeNode *rn = new TreeNode(stoi(str));
                n->right = rn;
                q.push(rn);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));