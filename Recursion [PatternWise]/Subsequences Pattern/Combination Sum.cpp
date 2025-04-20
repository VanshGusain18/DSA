class Solution
{
public:
    void func(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &temp, int i, int sum)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            res.push_back(temp);
            return;
        }
        if (i == candidates.size())
            return;
        temp.push_back(candidates[i]);
        func(candidates, target, res, temp, i, sum + candidates[i]);
        temp.pop_back();
        func(candidates, target, res, temp, i + 1, sum);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> temp;
        func(candidates, target, res, temp, 0, 0);
        return res;
    }
};