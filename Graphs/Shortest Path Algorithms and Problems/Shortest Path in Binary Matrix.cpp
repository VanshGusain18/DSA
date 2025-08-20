class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;

        vector<int> drow = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dcol = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int wt = q.front().second;
            q.pop();

            if (r == n - 1 && c == n - 1)
                return wt;

            for (int i = 0; i < 8; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && wt + 1 < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = wt + 1;
                    q.push({{nrow, ncol}, wt + 1});
                }
            }
        }
        return -1;
    }
};
