class Solution
{
public:
    void func(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &temp, int sum, int i)
    {
        if (sum == target)
        {
            res.push_back(temp);
            return;
        }
        if (i == candidates.size() || sum > target)
        {
            return;
        }
        for (int j = i; j < candidates.size(); j++)
        {
            if (j == i || candidates[j] != candidates[j - 1])
            {
                temp.push_back(candidates[j]);
                func(candidates, target, res, temp, sum + candidates[j], j + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        func(candidates, target, res, temp, 0, 0);
        return res;
    }
};