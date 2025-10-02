// Brute Approch

class Solution
{
public:
    int fn(string text1, string text2, int i1, int i2)
    {
        if (i1 < 0 || i2 < 0)
            return 0;
        if (text1[i1] == text2[i2])
        {
            return 1 + fn(text1, text2, i1 - 1, i2 - 1);
        }
        return max(fn(text1, text2, i1, i2 - 1), fn(text1, text2, i1 - 1, i2));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        return fn(text1, text2, n1 - 1, n2 - 1);
    }
};

// Memoization Approch

class Solution
{
public:
    int fn(string text1, string text2, vector<vector<int>> dp, int i1, int i2)
    {
        if (i1 < 0 || i2 < 0)
            return 0;
        if (dp[i1][i2] != -1)
            return dp[i1][i2];
        if (text1[i1] == text2[i2])
        {
            return 1 + fn(text1, text2, dp, i1 - 1, i2 - 1);
        }
        return dp[i1][i2] = max(fn(text1, text2, dp, i1, i2 - 1), fn(text1, text2, dp, i1 - 1, i2));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return fn(text1, text2, dp, n1 - 1, n2 - 1);
    }
};