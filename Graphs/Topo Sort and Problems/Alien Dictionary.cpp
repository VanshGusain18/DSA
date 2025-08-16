class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &adjList)
    {
        vector<int> indeg(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adjList[i].size(); j++)
            {
                int node = adjList[i][j];
                indeg[node]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            int tp = q.front();
            q.pop();
            ans.push_back(tp);

            for (int j = 0; j < adjList[tp].size(); j++)
            {
                int node = adjList[tp][j];
                indeg[node]--;
                if (indeg[node] == 0)
                {
                    q.push(node);
                }
            }
        }
        return ans;
    }

    string findOrder(vector<string> &words)
    {
        unordered_set<char> st;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                st.insert(words[i][j]);
            }
        }
        int k = st.size();
        unordered_map<char, int> mp;
        unordered_map<int, char> rev;
        int idx = 0;
        for (auto it = st.begin(); it != st.end(); it++)
        {
            char c = *it;
            mp[c] = idx;
            rev[idx] = c;
            idx++;
        }
        vector<vector<int>> adjList(k);
        for (int i = 0; i < words.size() - 1; i++)
        {
            string first = words[i], second = words[i + 1];
            if (first.size() > second.size() && first.substr(0, second.size()) == second)
            {
                return "";
            }
            for (int j = 0; j < first.size() && j < second.size(); j++)
            {
                if (first[j] != second[j])
                {
                    adjList[mp[first[j]]].push_back(mp[second[j]]);
                    break;
                }
            }
        }
        vector<int> topo = topoSort(k, adjList);
        if (topo.size() != k)
        {
            return "";
        }
        string order = "";
        for (int i = 0; i < topo.size(); i++)
        {
            order += rev[topo[i]];
        }
        return order;
    }
};