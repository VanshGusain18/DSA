// Brute Approch (dfs)

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

// Optimal Approch (bfs)

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<vector<string>, int>> q;
        q.push({{beginWord}, 1});

        vector<vector<string>> ans;
        vector<string> wordsToErase;

        while (!q.empty())
        {
            int qsize = q.size();
            wordsToErase.clear();

            for (int k = 0; k < qsize; k++)
            {
                auto front = q.front();
                q.pop();

                vector<string> seq = front.first;
                int cnt = front.second;
                string word = seq.back();

                if (word == endWord)
                {
                    if (ans.empty() || ans[0].size() == seq.size())
                    {
                        ans.push_back(seq);
                    }
                    continue;
                }

                for (int i = 0; i < word.size(); i++)
                {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        word[i] = c;
                        if (st.find(word) != st.end())
                        {
                            seq.push_back(word);
                            q.push({seq, cnt + 1});
                            seq.pop_back();
                            wordsToErase.push_back(word);
                        }
                    }
                    word[i] = original;
                }
            }

            for (auto &w : wordsToErase)
                st.erase(w);
        }

        return ans;
    }
};