class Solution
{
public:
    string reverseWords(string s)
    {
        s += " ";
        stack<string> st;
        string temp = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (!temp.empty())
                {
                    st.push(temp);
                    temp = "";
                }
            }
            else
            {
                temp += s[i];
            }
        }

        temp = "";
        while (st.size() != 1)
        {
            temp += st.top() + ' ';
            st.pop();
        }
        temp += st.top();
        return temp;
    }
};