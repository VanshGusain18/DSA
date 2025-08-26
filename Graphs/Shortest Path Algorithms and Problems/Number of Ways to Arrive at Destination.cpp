class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < roads.size(); i++)
        {
            adjList[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adjList[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<long long> dist(n, 1e18);
        dist[0] = 0;
        vector<int> path(n, 0);
        path[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty())
        {
            int node = pq.top().second;
            long long wt = pq.top().first;
            pq.pop();
            if (wt > dist[node])
                continue;
            for (int i = 0; i < adjList[node].size(); i++)
            {
                int nn = adjList[node][i].first, nwt = adjList[node][i].second;
                if (dist[nn] > wt + nwt)
                {
                    dist[nn] = wt + nwt;
                    path[nn] = path[node];
                    pq.push({dist[nn], nn});
                }
                else if (dist[nn] == wt + nwt)
                {
                    path[nn] = (path[nn] + path[node]) % MOD;
                }
            }
        }
        return path[n - 1];
    }
};