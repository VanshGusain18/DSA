// Brute Aproch

class Solution
{
public:
    int countSubstr(string &s, int k)
    {
        // code here.
        int cnt = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            unordered_set<char> unique;
            for (int j = i; j < n; j++)
            {
                unique.insert(s[j]);
                if (unique.size() == k)
                    cnt++;
                if (unique.size() > k)
                    break;
            }
        }
        return cnt;
    }
};