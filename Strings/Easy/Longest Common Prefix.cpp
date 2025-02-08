class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = "";
        int n = strs.size();
        if (n == 1)
            return strs[0];
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (mini > strs[i].length())
            {
                mini = strs[i].length();
            }
        }
        int i = 0;
        while (i < mini)
        {
            char temp = strs[0][i], f = 0;
            for (int j = 0; j < n; j++)
            {
                if (strs[j][i] != temp)
                {
                    f++;
                    break;
                }
            }
            if (f == 0)
                res += temp;
            else
                return res;
            i++;
        }
        return res;
    }
};