// Better Approch

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++)
        {
            vector<int> temp = {intervals[i][0], intervals[i][1]};
            if (i == 0 || temp[1] > result.back()[1])
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (intervals[j][0] <= temp[1])
                    {
                        if (intervals[j][1] > temp[1])
                        {
                            temp[1] = intervals[j][1];
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                result.push_back(temp);
            }
        }
        return result;
    }
};

// Optimal Approch

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        vector<int> temp = {intervals[0][0], intervals[0][1]};
        for (int i = 1; i < n; i++)
        {
            if (temp[1] >= intervals[i][0])
            {
                if (temp[1] < intervals[i][1])
                {
                    temp[1] = intervals[i][1];
                }
            }
            else
            {
                result.push_back(temp);
                temp = {intervals[i][0], intervals[i][1]};
            }
        }
        result.push_back(temp);
        return result;
    }
};