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

// Optimal Aproch

class Solution
{
public:
    int fn(string &s, int k)
    {
        if (k == 0)
            return 0;
        int left = 0, cnt = 0;
        unordered_map<char, int> fq;
        for (int right = 0; right < s.length(); right++)
        {
            fq[s[right]]++;
            while (fq.size() > k)
            {
                fq[s[left]]--;
                if (fq[s[left]] == 0)
                    fq.erase(s[left]);
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;
    }

    int countSubstr(string &s, int k)
    {
        // code here.
        return fn(s, k) - fn(s, k - 1);
    }
};