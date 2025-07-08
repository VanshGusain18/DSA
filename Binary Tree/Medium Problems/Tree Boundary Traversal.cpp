class Solution
{
public:
    void addleft(Node *root, vector<int> &res)
    {
        while (root)
        {
            if (root->left == nullptr && root->right == nullptr)
                break;
            res.push_back(root->data);
            if (root->left)
                root = root->left;
            else
                root = root->right;
        }
    }

    void addleaf(Node *root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            res.push_back(root->data);
        addleaf(root->left, res);
        addleaf(root->right, res);
    }

    void addright(Node *root, vector<int> &res)
    {
        if (root == nullptr || root->right == nullptr)
            return;
        root = root->right;
        stack<Node *> st;
        while (root != nullptr)
        {
            if (root->left == nullptr && root->right == nullptr)
                break;
            st.push(root);
            if (root->right != nullptr)
                root = root->right;
            else
                root = root->left;
        }
        while (!st.empty())
        {
            res.push_back(st.top()->data);
            st.pop();
        }
    }

    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;
        if (!(root->left == nullptr && root->right == nullptr))
        {
            res.push_back(root->data);
        }
        addleft(root->left, res);
        addleaf(root, res);
        addright(root, res);

        return res;
    }
};