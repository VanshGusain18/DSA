class Solution
{
public:
    bool func(vector<vector<char>> &board, string &word, int i, int j, int pos, int n, int m)
    {
        if (pos == word.length())
            return true;
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[pos])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = func(board, word, i + 1, j, pos + 1, n, m) || func(board, word, i - 1, j, pos + 1, n, m) || func(board, word, i, j + 1, pos + 1, n, m) || func(board, word, i, j - 1, pos + 1, n, m);
        board[i][j] = temp;
        return found;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (func(board, word, i, j, 0, n, m))
                    return true;
            }
        }
        return false;
    }
};