class Solution
{
public:
    int cnt = 1;

    void dfs(vector<vector<int>> &adjList, vector<int> &tin, vector<int> &low,
             vector<int> &vis, vector<vector<int>> &ans, int node, int par)
    {
        vis[node] = 1;
        tin[node] = low[node] = cnt;
        cnt++;
        for (int i = 0; i < adjList[node].size(); i++)
        {
            int nigh = adjList[node][i];
            if (nigh == par)
                continue;
            if (vis[nigh])
            {
                low[node] = min(low[node], tin[nigh]);
            }
            else
            {
                dfs(adjList, tin, low, vis, ans, nigh, node);
                low[node] = min(low[node], low[nigh]);
                if (low[nigh] > tin[node])
                {
                    ans.push_back({node, nigh});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < connections.size(); i++)
        {
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> tin(n);
        vector<int> low(n);
        vector<int> vis(n, 0);
        vector<vector<int>> ans;
        dfs(adjList, tin, low, vis, ans, 0, -1);
        return ans;
    }
};