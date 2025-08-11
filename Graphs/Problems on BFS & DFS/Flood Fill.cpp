// bfs

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int r = image.size(), c = image[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis = image;
        q.push({sr, sc});
        int stcol = vis[sr][sc];
        vis[sr][sc] = color;
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && image[nrow][ncol] == stcol && vis[nrow][ncol] != color)
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = color;
                }
            }
        }
        return vis;
    }
};