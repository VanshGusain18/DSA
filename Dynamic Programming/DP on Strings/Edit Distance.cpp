// Recursive Approch

class Solution
{
public:
    int fn(string word1, string word2, int i, int j)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (word1[i] == word2[j])
            return fn(word1, word2, i - 1, j - 1);
        int del = 1 + fn(word1, word2, i, j - 1);
        int ins = 1 + fn(word1, word2, i - 1, j);
        int rep = 1 + fn(word1, word2, i - 1, j - 1);
        return min({del, ins, rep});
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        return fn(word1, word2, n - 1, m - 1);
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(string word1, string word2, vector<vector<int>> &dp, int i, int j)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i] == word2[j])
            return dp[i][j] = fn(word1, word2, dp, i - 1, j - 1);
        int del = 1 + fn(word1, word2, dp, i, j - 1);
        int ins = 1 + fn(word1, word2, dp, i - 1, j);
        int rep = 1 + fn(word1, word2, dp, i - 1, j - 1);
        return dp[i][j] = min({del, ins, rep});
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fn(word1, word2, dp, n - 1, m - 1);
    }
};

// Tabulation Approch

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    int del = dp[i][j - 1] + 1, ins = dp[i - 1][j] + 1, rep = dp[i - 1][j - 1] + 1;
                    dp[i][j] = min({del, ins, rep});
                }
            }
        }
        return dp[n][m];
    }
};