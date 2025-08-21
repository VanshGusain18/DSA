class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> dist(r, vector<int>(c, 1e9));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<int> drow = {1, 0, -1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if (row == r - 1 && col == c - 1)
                return diff;
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c)
                {
                    int newEffort = max(diff, abs(heights[row][col] - heights[nrow][ncol]));
                    if (newEffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};
