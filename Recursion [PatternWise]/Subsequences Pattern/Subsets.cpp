// Itrative Approch

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < pow(2, n); i++)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    temp.push_back(nums[j]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

// Recursive Approch

class Solution
{
public:
    void func(vector<int> &nums, vector<int> &temp, vector<vector<int>> &res, int i)
    {
        if (i == nums.size())
        {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        func(nums, temp, res, i + 1);
        temp.pop_back();
        func(nums, temp, res, i + 1);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> temp;
        func(nums, temp, res, 0);
        return res;
    }
};