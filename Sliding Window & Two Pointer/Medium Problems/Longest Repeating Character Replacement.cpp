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