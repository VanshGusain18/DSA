class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // code here
        queue<pair<Node *, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            Node *n = p.first;
            int x = p.second;
            if (mp.find(x) == mp.end())
            {
                mp[x] = n->data;
            }
            if (n->left)
                q.push({n->left, x - 1});
            if (n->right)
                q.push({n->right, x + 1});
        }
        vector<int> res;
        for (auto x : mp)
        {
            res.push_back(x.second);
        }
        return res;
    }
};