class Solution
{
public:
    void func(int n, vector<string> &board, vector<vector<string>> &res, int i, vector<int> &left, vector<int> &updig, vector<int> &dwdig)
    {
        if (i == n)
        {
            res.push_back(board);
        }
        for (int j = 0; j < n; j++)
        {
            if (left[j] == 0 && updig[i + j] == 0 && dwdig[n - 1 + i - j] == 0)
            {
                board[i][j] = 'Q';
                left[j] = 1;
                updig[i + j] = 1;
                dwdig[n - 1 + i - j] = 1;
                func(n, board, res, i + 1, left, updig, dwdig);
                board[i][j] = '.';
                left[j] = 0;
                updig[i + j] = 0;
                dwdig[n - 1 + i - j] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n);
        vector<vector<string>> res;
        string temp(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = temp;
        }
        vector<int> left(n, 0), updig(n * 2 - 1, 0), dwdig(n * 2 - 1, 0);
        func(n, board, res, 0, left, updig, dwdig);
        return res;
    }
};