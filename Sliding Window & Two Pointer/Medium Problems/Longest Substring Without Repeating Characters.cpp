// Brute Approch

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            vector<bool> hs(256, false);
            for (int j = i; j < n; j++)
            {
                if (hs[s[j]])
                    break;
                hs[s[j]] = true;
                cnt++;
                res = max(res, cnt);
            }
        }
        return res;
    }
};

// Optimal Solution

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0, n = s.length();
        unordered_map<char, int> mp;
        int r = 0, l = 0;
        while (r < n)
        {
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l)
            {
                l = mp[s[r]] + 1;
            }
            mp[s[r]] = r;
            int len = r - l + 1;
            res = max(len, res);
            r++;
        }
        return res;
    }
};