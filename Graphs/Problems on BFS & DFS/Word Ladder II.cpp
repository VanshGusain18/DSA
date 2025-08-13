// Brute Approch

class Solution
{
public:
    void dfs(string endWord, vector<vector<string>> &res, vector<string> temp, unordered_set<string> &st, int len, int &mini, string curr)
    {
        if (temp[len - 1] == endWord)
        {
            if (len < mini)
            {
                mini = len;
                res.clear();
                res.push_back(temp);
            }
            else if (len == mini)
            {
                res.push_back(temp);
            }
            return;
        }
        if (len > mini)
        {
            return;
        }
        for (int i = 0; i < curr.length(); i++)
        {
            char org = curr[i];
            for (char j = 'a'; j <= 'z'; j++)
            {
                curr[i] = j;
                if (st.find(curr) != st.end())
                {
                    temp.push_back(curr);
                    st.erase(curr);
                    dfs(endWord, res, temp, st, len + 1, mini, curr);
                    temp.pop_back();
                    st.insert(curr);
                }
            }
            curr[i] = org;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> res;
        vector<string> temp = {beginWord};
        unordered_set<string> st(wordList.begin(), wordList.end());
        int mini = INT_MAX;
        dfs(endWord, res, temp, st, 1, mini, beginWord);
        return res;
    }
};