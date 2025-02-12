// Brute Aproch

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// Optimal Aproch

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int fq[26] = {0}, n = s.length();
        for (int i = 0; i < n; i++)
        {
            fq[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++)
        {
            fq[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (fq[i] != 0)
                return false;
        }
        return true;
    }
};