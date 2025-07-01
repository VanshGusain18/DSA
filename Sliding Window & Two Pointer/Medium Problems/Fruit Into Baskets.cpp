// Brute Approch

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            set<int> st;
            for (int j = i; j < n; j++)
            {
                st.insert(fruits[j]);
                if (st.size() <= 2)
                {
                    int len = j - i + 1;
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
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size(), res = 0;
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        while (r < n)
        {
            mp[fruits[r]]++;
            while (mp.size() > 2)
            {
                mp[fruits[l]]--;
                if (!mp[fruits[l]])
                    mp.erase(fruits[l]);
                l++;
            }
            int len = r - l + 1;
            res = max(res, len);
            r++;
        }
        return res;
    }
};