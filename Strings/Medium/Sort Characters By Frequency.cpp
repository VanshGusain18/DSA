class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.length();
        map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        for (auto temp : mp)
        {
            pq.push({temp.second, temp.first});
        }
        string res;
        while (!pq.empty())
        {
            pair<int, char> temp = pq.top();
            char c = temp.second;
            int f = temp.first;
            for (int i = 0; i < f; i++)
            {
                res += c;
            }
            pq.pop();
        }
        return res;
    }
};