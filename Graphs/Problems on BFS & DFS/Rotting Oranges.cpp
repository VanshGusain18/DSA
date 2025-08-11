class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int cnt = 0;
        while (!q.empty())
        {
            int sz = q.size();
            bool rot = false;

            for (int j = 0; j < sz; j++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();

                if (x - 1 >= 0 && grid[x - 1][y] == 1)
                {
                    grid[x - 1][y] = 2;
                    q.push({x - 1, y});
                    rot = true;
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1)
                {
                    grid[x][y - 1] = 2;
                    q.push({x, y - 1});
                    rot = true;
                }
                if (x + 1 < rows && grid[x + 1][y] == 1)
                {
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                    rot = true;
                }
                if (y + 1 < cols && grid[x][y + 1] == 1)
                {
                    grid[x][y + 1] = 2;
                    q.push({x, y + 1});
                    rot = true;
                }
            }

            if (rot)
                cnt++;
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return cnt;
    }
};

// Cleaner Approch

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 2)
                {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
            }
        }
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        int tm = 0;
        while (!q.empty())
        {
            int row = q.front().first.first, col = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] != 2)
                    return -1;
            }
        }
        return tm;
    }
};
