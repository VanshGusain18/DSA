class Solution
{
public:
    void func(vector<int> nums, vector<vector<int>> &res, vector<int> temp, int i)
    {
        res.push_back(temp);
        for (int j = i; j < nums.size(); j++)
        {
            if (j == i || nums[j] != nums[j - 1])
            {
                temp.push_back(nums[j]);
                func(nums, res, temp, j + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        func(nums, res, temp, 0);
        return res;
    }
};