class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> fq(26, 0);
            for (int j = i; j < n; j++)
            {
                fq[s[j] - 'a']++;
                int min = INT_MAX, max = INT_MIN;
                for (int k = 0; k < 26; k++)
                {
                    if (fq[k] > max)
                        max = fq[k];
                    if (fq[k] < min && fq[k] != 0)
                        min = fq[k];
                }
                cnt += max - min;
            }
        }
        return cnt;
    }
};