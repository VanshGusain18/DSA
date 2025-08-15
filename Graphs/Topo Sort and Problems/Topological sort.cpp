class Solution
{
public:
    void dfs(int i, vector<vector<int>> &adjList, vector<int> &vis, stack<int> &st)
    {
        vis[i] = 1;
        for (int j = 0; j < adjList[i].size(); j++)
        {
            int neighbor = adjList[i][j];
            if (!vis[neighbor])
            {
                dfs(neighbor, adjList, vis, st);
            }
        }
        st.push(i);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<int>> adjList(V);
        for (int i = 0; i < edges.size(); i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adjList, vis, st);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};