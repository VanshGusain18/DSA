class Solution
{
public:
    bool isPal(int i, int j, const string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void func(string s, vector<vector<string>> &res, vector<string> &temp, int i)
    {
        if (i == s.length())
        {
            res.push_back(temp);
            return;
        }
        for (int j = i; j < s.length(); j++)
        {
            if (isPal(i, j, s))
            {
                temp.push_back(s.substr(i, j - i + 1));
                func(s, res, temp, j + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> temp;
        func(s, res, temp, 0);
        return res;
    }
};