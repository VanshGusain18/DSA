class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<vector<int>> adjRev(v);
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                adjRev[graph[i][j]].push_back(i);
            }
        }
        vector<int> inDeg(v, 0);
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < adjRev[i].size(); j++)
            {
                int node = adjRev[i][j];
                inDeg[node]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (!inDeg[i])
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty())
        {
            int tp = q.front();
            q.pop();
            ans.push_back(tp);

            for (int j = 0; j < adjRev[tp].size(); j++)
            {
                int node = adjRev[tp][j];
                inDeg[node]--;
                if (inDeg[node] == 0)
                    q.push(node);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};