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
};

class Solution
{
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // code here
        vector<int> ans;
        DisjointSet ds(n * m);
        vector<vector<int>> mat(n, vector<int>(m, 0));
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        int cnt = 0;
        for (int i = 0; i < operators.size(); i++)
        {
            int r = operators[i][0], c = operators[i][1];
            if (mat[r][c])
            {
                ans.push_back(cnt);
                continue;
            }
            mat[r][c] = 1;
            cnt++;
            for (int dir = 0; dir < 4; dir++)
            {
                int nrow = r + drow[dir], ncol = c + dcol[dir];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol])
                {
                    int comp = r * m + c, nigh = nrow * m + ncol;
                    if (ds.findUPar(comp) != ds.findUPar(nigh))
                    {
                        cnt--;
                        ds.unionByRank(comp, nigh);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};