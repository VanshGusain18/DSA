class Solution
{
public:
    int romanToInt(string s)
    {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'I')
            {
                if (s[i + 1] == 'V' && i != n - 1 || s[i + 1] == 'X' && i != n - 1)
                    cnt--;
                else
                    cnt++;
            }
            else if (s[i] == 'X')
            {
                if (s[i + 1] == 'L' && i != n - 1 || s[i + 1] == 'C' && i != n - 1)
                    cnt -= 10;
                else
                    cnt += 10;
            }
            else if (s[i] == 'C')
            {
                if (s[i + 1] == 'D' && i != n - 1 || s[i + 1] == 'M' && i != n - 1)
                    cnt -= 100;
                else
                    cnt += 100;
            }
            else if (s[i] == 'V')
                cnt += 5;
            else if (s[i] == 'L')
                cnt += 50;
            else if (s[i] == 'D')
                cnt += 500;
            else if (s[i] == 'M')
                cnt += 1000;
        }
        return cnt;
    }
};