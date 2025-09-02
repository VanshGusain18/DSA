class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> dist(r, vector<int>(c, 1e9));
        dist[0][0] = grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!pq.empty())
        {
            int wt = pq.top()[0], row = pq.top()[1], col = pq.top()[2];
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int nr = row + drow[i], nc = col + dcol[i];
                if (nr >= 0 && nr < r && nc >= 0 && nc < c)
                {
                    int curr = max(wt, grid[nr][nc]);
                    if (dist[nr][nc] > curr)
                    {
                        dist[nr][nc] = curr;
                        pq.push({curr, nr, nc});
                    }
                }
            }
        }
        return dist[r - 1][c - 1];
    }
};