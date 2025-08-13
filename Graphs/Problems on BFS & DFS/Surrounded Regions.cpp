class Solution
{
public:
    void dfs(vector<vector<char>> &board, vector<vector<int>> &vis, int i, int j, int r, int c)
    {
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        vis[i][j] = 1;

        for (int k = 0; k < 4; k++)
        {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && board[nrow][ncol] == 'O' && !vis[nrow][ncol])
            {
                dfs(board, vis, nrow, ncol, r, c);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int r = board.size();
        int c = board[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0));

        for (int j = 0; j < c; j++)
        {
            if (board[0][j] == 'O' && !vis[0][j])
                dfs(board, vis, 0, j, r, c);
            if (board[r - 1][j] == 'O' && !vis[r - 1][j])
                dfs(board, vis, r - 1, j, r, c);
        }

        for (int i = 0; i < r; i++)
        {
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(board, vis, i, 0, r, c);
            if (board[i][c - 1] == 'O' && !vis[i][c - 1])
                dfs(board, vis, i, c - 1, r, c);
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
