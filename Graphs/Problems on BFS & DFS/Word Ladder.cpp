class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        set<string> st(wordList.begin(), wordList.end());
        int n = beginWord.length();
        q.push({beginWord, 1});
        while (!q.empty())
        {
            string wrd = q.front().first;
            int len = q.front().second;
            q.pop();
            for (int i = 0; i < n; i++)
            {
                char original = wrd[i];
                for (char j = 'a'; j <= 'z'; j++)
                {
                    wrd[i] = j;
                    if (st.find(wrd) != st.end())
                    {
                        if (wrd == endWord)
                        {
                            return len + 1;
                        }
                        q.push({wrd, len + 1});
                        st.erase(wrd);
                    }
                }
                wrd[i] = original;
            }
        }
        return 0;
    }
};