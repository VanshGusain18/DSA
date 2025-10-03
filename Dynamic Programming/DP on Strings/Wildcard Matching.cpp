// Recursive Approch

class Solution
{
public:
    bool fn(string s, string p, int i, int j)
    {
        if (i < 0 && j < 0)
            return true;
        if (j < 0 && i >= 0)
            return false;
        if (i < 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        if (s[i] == p[j] || p[j] == '?')
        {
            return fn(s, p, i - 1, j - 1);
        }
        else if (p[j] == '*')
        {
            return fn(s, p, i, j - 1) || fn(s, p, i - 1, j);
        }
        return false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.length(), m = p.length();
        return fn(s, p, n - 1, m - 1);
    }
};