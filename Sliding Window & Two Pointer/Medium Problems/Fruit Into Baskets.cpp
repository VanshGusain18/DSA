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