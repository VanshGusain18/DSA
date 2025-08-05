class Solution
{
public:
    void dfs(int node, vector<vector<int>> &isConnected, vector<int> &vis)
    {

        vis[node] = 1;
        int n = isConnected.size();

        for (int i = 0; i < n; i++)
        {
            if (isConnected[node][i] && !vis[i])
            {
                dfs(i, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int n = isConnected.size();

        int cnt = 0;

        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, isConnected, vis);
                cnt++;
            }
        }
        return cnt;
    }
};