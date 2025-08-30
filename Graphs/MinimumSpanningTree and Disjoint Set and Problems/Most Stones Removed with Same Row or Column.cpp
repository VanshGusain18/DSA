class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    int fn()
    {
        int cnt = 0;
        for (int i = 0; i < rank.size(); i++)
        {
            if (rank[i] > 0 && parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int r = INT_MIN, c = INT_MIN;
        for (int i = 0; i < stones.size(); i++)
        {
            r = max(r, stones[i][0]);
            c = max(c, stones[i][1]);
        }
        DisjointSet ds(r + c + 2);
        for (int i = 0; i < stones.size(); i++)
        {
            int cr = stones[i][0], cc = stones[i][1] + r + 1;
            ds.unionByRank(cr, cc);
        }
        return stones.size() - ds.fn();
    }
};