// Brute Approch

class Solution
{
public:
    bool fn(string s, int pos, int sum)
    {
        if (sum < 0)
            return false;
        if (pos == s.length())
        {
            if (!sum)
                return true;
            else
                return false;
        }
        if (s[pos] == '(')
            return fn(s, pos + 1, sum + 1);
        else if (s[pos] == ')')
            return fn(s, pos + 1, sum - 1);
        else
        {
            return fn(s, pos + 1, sum + 1) || fn(s, pos + 1, sum - 1) || fn(s, pos + 1, sum);
        }
    }

    bool checkValidString(string s)
    {
        return fn(s, 0, 0);
    }
};

// Optimal Solution

class Solution
{
public:
    bool checkValidString(string s)
    {
        int mini = 0, maxi = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                mini++;
                maxi++;
            }
            else if (s[i] == ')')
            {
                if (mini > 0)
                    mini--;
                maxi--;
            }
            else
            {
                maxi++;
                if (mini > 0)
                    mini--;
            }
            if (maxi < 0)
                return false;
        }
        if (!mini)
            return true;
        return false;
    }
};