class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<int>> adjList(V);
        for (int i = 0; i < edges.size(); i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(V, 0);
        vector<int> indeg(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adjList[i].size(); j++)
            {
                int node = adjList[i][j];
                indeg[node]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (!indeg[i])
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            int tp = q.front();
            ans.push_back(tp);
            q.pop();
            for (int i = 0; i < adjList[tp].size(); i++)
            {
                int node = adjList[tp][i];
                indeg[node]--;
                if (!indeg[node])
                    q.push(node);
            }
        }
        return ans;
    }
};