// Brute Approch

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < flights.size(); i++)
        {
            int from = flights[i][0], to = flights[i][1], ct = flights[i][2];
            adjList[from].push_back({to, ct});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> cost(n, 1e9);
        cost[src] = 0;
        pq.push({0, src, 0});
        while (!pq.empty())
        {
            int ct = pq.top()[0], node = pq.top()[1], st = pq.top()[2];
            pq.pop();
            if (node == dst)
                return ct;
            if (st > k)
                continue;
            for (int i = 0; i < adjList[node].size(); i++)
            {
                int nnode = adjList[node][i].first, nct = adjList[node][i].second;
                if (cost[nnode] > ct + nct)
                    cost[nnode] = ct + nct;
                pq.push({ct + nct, nnode, st + 1});
            }
        }
        return -1;
    }
};
