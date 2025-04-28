class Solution
{
public:
    void func(vector<int> &num, vector<int> &temp, vector<vector<int>> &res, int k, int n, int sum, int i)
    {
        if (temp.size() == k && sum == n)
        {
            res.push_back(temp);
            return;
        }
        if (temp.size() > k || sum > n)
            return;

        for (int j = i; j < num.size(); j++)
        {
            temp.push_back(num[j]);
            func(num, temp, res, k, n, sum + num[j], j + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> temp;
        vector<vector<int>> res;
        func(num, temp, res, k, n, 0, 0);
        return res;
    }
};