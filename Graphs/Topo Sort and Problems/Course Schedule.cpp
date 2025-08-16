class Solution
{
public:
    bool hasCycle(int n, vector<vector<int>> &adjList)
    {
        queue<int> q;
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < adjList[i].size(); j++)
            {
                int node = adjList[i][j];
                indeg[node]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 0)
                q.push(i);
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
                    q.push(node);
            }
        }
        return ans.size() != n;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adjList(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adjList[b].push_back(a);
        }
        return !hasCycle(numCourses, adjList);
    }
};
