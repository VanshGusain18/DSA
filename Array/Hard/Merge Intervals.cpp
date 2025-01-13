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