// Brute Approch

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.length(), res = 0;
        for (int i = 0; i < n; i++)
        {
            int mfq = 0;
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++)
            {
                mp[s[j]]++;
                mfq = max(mfq, mp[s[j]]);
                int len = j - i + 1;
                int cnv = len - mfq;
                if (cnv <= k)
                {
                    res = max(res, len);
                }
                else
                    break;
            }
        }
        return res;
    }
};

// Better Approch

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.length(), res = 0;
        int l = 0, r = 0, mfq = 0;
        unordered_map<char, int> mp;
        while (r < n)
        {
            mp[s[r]]++;
            mfq = max(mfq, mp[s[r]]);
            int len = r - l + 1;
            int cnv = len - mfq;
            while (cnv > k)
            {
                mp[s[l]]--;
                mfq = 0;
                for (auto ele : mp)
                {
                    mfq = max(mfq, ele.second);
                }
                l++;
                len = r - l + 1;
                cnv = len - mfq;
            }
            res = max(res, len);
            r++;
        }
        return res;
    }
};

// Optimal Approch

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.length(), res = 0;
        int l = 0, r = 0, mfq = 0;
        unordered_map<char, int> mp;
        while (r < n)
        {
            mp[s[r]]++;
            mfq = max(mfq, mp[s[r]]);
            int len = r - l + 1;
            int cnv = len - mfq;
            if (cnv > k)
            {
                mp[s[l]]--;
                mfq = 0;
                for (auto ele : mp)
                {
                    mfq = max(mfq, ele.second);
                }
                l++;
                len = r - l + 1;
                cnv = len - mfq;
            }
            else
            {
                res = max(res, len);
            }
            r++;
        }
        return res;
    }
};