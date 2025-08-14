class Solution
{
public:
    void bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, set<vector<pair<int, int>>> &st, int i, int j, int r, int c)
    {
        queue<pair<int, int>> q;
        int br = i, bc = j;
        q.push({br, bc});
        vis[br][bc] = 1;

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        vector<pair<int, int>> temp;

        while (!q.empty())
        {
            auto [rcurr, ccurr] = q.front();
            q.pop();
            temp.push_back({rcurr - br, ccurr - bc});

            for (int k = 0; k < 4; k++)
            {
                int nr = rcurr + drow[k];
                int nc = ccurr + dcol[k];
                if (nr >= 0 && nr < r && nc >= 0 && nc < c && !vis[nr][nc] && grid[nr][nc])
                {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        st.insert(temp);
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0));
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] && !vis[i][j])
                {
                    bfs(grid, vis, st, i, j, r, c);
                }
            }
        }
        return st.size();
    }
};