// Recursive Approch

class Solution
{
public:
    int fn(int r, int c)
    {
        if (r == 0 && c == 0)
            return 1;
        if (r < 0 || c < 0)
            return 0;
        int up = fn(r - 1, c);
        int right = fn(r, c - 1);
        return up + right;
    }

    int uniquePaths(int m, int n)
    {
        return fn(m - 1, n - 1);
    }
};