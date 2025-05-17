class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        int n = num.length();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() > num[i] && k)
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k)
        {
            st.pop();
            k--;
        }
        string res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        if (res.empty())
            return "0";
        while (res.size() > 1 && res[0] == '0')
            res.erase(0, 1);
        return res;
    }
};