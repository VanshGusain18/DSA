// Brute Force

class Solution
{
public:
    int bfs(vector<vector<int>> &mat, int i, int j, int r, int c)
    {
        queue<pair<pair<int, int>, int>> q;
        q.push({{i, j}, 0});
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        visited[i][j] = true;
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int rcurr = q.front().first.first;
            int ccurr = q.front().first.second;
            int cnt = q.front().second;
            q.pop();
            if (mat[rcurr][ccurr] == 0)
                return cnt;
            for (int idx = 0; idx < 4; idx++)
            {
                int newRow = rcurr + drow[idx];
                int newCol = ccurr + dcol[idx];
                if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c && !visited[newRow][newCol])
                {
                    visited[newRow][newCol] = true;
                    q.push({{newRow, newCol}, cnt + 1});
                }
            }
        }
        return 0;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int r = mat.size(), c = mat[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] != 0)
                {
                    int cnt = bfs(mat, i, j, r, c);
                    ans[i][j] = cnt;
                }
            }
        }
        return ans;
    }
};

// Optimal Solution

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int r = mat.size(), c = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> ans(r, vector<int>(c));
        vector<vector<int>> vis(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int rcurr = q.front().first.first, ccurr = q.front().first.second, t = q.front().second;
            q.pop();
            ans[rcurr][ccurr] = t;
            for (int i = 0; i < 4; i++)
            {
                int nrow = rcurr + drow[i], ncol = ccurr + dcol[i];
                if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }
        return ans;
    }
};