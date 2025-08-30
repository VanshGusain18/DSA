class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mp.find(mail) != mp.end())
                {
                    ds.unionByRank(mp[mail], i);
                }
                else
                {
                    mp[mail] = i;
                }
            }
        }
        vector<vector<string>> temp(n);
        for (auto &it : mp)
        {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            temp[node].push_back(mail);
        }
        vector<vector<string>> res;
        for (int i = 0; i < n; i++)
        {
            if (temp[i].empty())
                continue;
            sort(temp[i].begin(), temp[i].end());
            vector<string> list;
            list.push_back(accounts[i][0]);
            for (string &mail : temp[i])
            {
                list.push_back(mail);
            }
            res.push_back(list);
        }
        return res;
    }
};
