// Brute Approch

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            vector<int> arr(3, 0);
            for (int j = i; j < n; j++)
            {
                arr[s[j] - 'a'] = 1;
                if (arr[0] + arr[1] + arr[2] == 3)
                    cnt++;
            }
        }
        return cnt;
    }
};

// Better Approch

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            vector<int> arr(3, 0);
            for (int j = i; j < n; j++)
            {
                arr[s[j] - 'a'] = 1;
                if (arr[0] + arr[1] + arr[2] == 3)
                {
                    cnt += n - j;
                    break;
                }
            }
        }
        return cnt;
    }
};

// Optimal Approch

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int cnt = 0, n = s.length();
        vector<int> arr(3, -1);
        for (int i = 0; i < n; i++)
        {
            arr[s[i] - 'a'] = i;
            if (arr[0] != -1 && arr[1] != -1 && arr[2] != -1)
            {
                cnt += 1 + min({arr[0], arr[1], arr[2]});
            }
        }
        return cnt;
    }
};