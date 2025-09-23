// Recursive Approch

class Solution
{
public:
    int fn(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
    {
        if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
        {
            return -1e8;
        }
        if (i == r - 1)
        {
            if (j1 == j2)
            {
                return grid[i][j1];
            }
            return grid[i][j1] + grid[i][j2];
        }
        int dcol[3] = {-1, 0, 1};
        int maxi = INT_MIN;
        for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < 3; j++)
            {
                int value = 0;
                if (j1 == j2)
                {
                    value = grid[i][j1] + fn(i + 1, j1 + dcol[k], j2 + dcol[j], r, c, grid);
                }
                else
                {
                    value = grid[i][j1] + grid[i][j2] + fn(i + 1, j1 + dcol[k], j2 + dcol[j], r, c, grid);
                }
                maxi = max(maxi, value);
            }
        }
        return maxi;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        return fn(0, 0, c - 1, r, c, grid);
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
        {
            return -1e8;
        }
        if (i == r - 1)
        {
            if (j1 == j2)
            {
                return grid[i][j1];
            }
            return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int dcol[3] = {-1, 0, 1};
        int maxi = INT_MIN;
        for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < 3; j++)
            {
                int value = 0;
                if (j1 == j2)
                {
                    value = grid[i][j1] + fn(i + 1, j1 + dcol[k], j2 + dcol[j], r, c, grid, dp);
                }
                else
                {
                    value = grid[i][j1] + grid[i][j2] + fn(i + 1, j1 + dcol[k], j2 + dcol[j], r, c, grid, dp);
                }
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        return fn(0, 0, c - 1, r, c, grid, dp);
    }
};