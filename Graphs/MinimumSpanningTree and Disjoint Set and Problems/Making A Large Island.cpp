class DisjointSet
{
public:
    vector<int> parent, size;

    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        DisjointSet ds(r * c);
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (!grid[i][j])
                    continue;
                int comp = (c * i) + j;
                for (int dir = 0; dir < 2; dir++)
                {
                    int nr = drow[dir] + i, nc = dcol[dir] + j;
                    if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc])
                    {
                        int nigh = (c * nr) + nc;
                        ds.unionBySize(comp, nigh);
                    }
                }
            }
        }

        int maxi = 0;
        for (int i = 0; i < r * c; i++)
        {
            if (ds.findUPar(i) == i)
            {
                maxi = max(maxi, ds.size[i]);
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (!grid[i][j])
                {
                    unordered_set<int> st;
                    int comp = (c * i) + j;
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nr = drow[dir] + i, nc = dcol[dir] + j;
                        if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc])
                        {
                            int nigh = (c * nr) + nc;
                            st.insert(ds.findUPar(nigh));
                        }
                    }
                    int cnt = 1;
                    for (auto ele : st)
                    {
                        cnt += ds.size[ele];
                    }
                    maxi = max(maxi, cnt);
                }
            }
        }
        return maxi;
    }
};