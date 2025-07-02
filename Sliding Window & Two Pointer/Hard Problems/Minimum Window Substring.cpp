// Brute Approch

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length();
        unordered_map<char, int> mp;
        for (int i = 0; i < t.length(); i++)
        {
            mp[t[i]]++;
        }
        int mini = INT_MAX, idx = -1;
        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> temp = mp;
            for (int j = i; j < n; j++)
            {
                temp[s[j]]--;
                bool flag = true;
                for (auto ele : temp)
                {
                    if (ele.second > 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    int len = j - i + 1;
                    if (len < mini)
                    {
                        mini = len;
                        idx = i;
                    }
                    break;
                }
            }
        }
        if (idx == -1)
            return "";
        string res;
        for (int i = idx; i < idx + mini; i++)
        {
            res += s[i];
        }
        return res;
    }
};

// Optimal Approch

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length();
        unordered_map<char, int> mp;
        for (int i = 0; i < t.length(); i++)
        {
            mp[t[i]]++;
        }
        int mini = INT_MAX, idx = -1;
        int r = 0, l = 0, cnt = 0;
        while (r < n)
        {
            if (mp[s[r]] > 0)
                cnt++;
            mp[s[r]]--;
            while (cnt == t.length())
            {
                if (r - l + 1 < mini)
                {
                    mini = r - l + 1;
                    idx = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        if (idx == -1)
            return "";
        string res;
        for (int i = idx; i < idx + mini; i++)
        {
            res += s[i];
        }
        return res;
    }
};