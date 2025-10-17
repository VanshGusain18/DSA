class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp(n, 1);
        vector<int> hash(n);
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
        }
        int maxi = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && temp[i] < temp[j] + 1)
                {
                    temp[i] = temp[j] + 1;
                    hash[i] = j;
                    if (temp[maxi] < temp[i])
                    {
                        maxi = i;
                    }
                }
            }
        }
        vector<int> ans;
        while (hash[maxi] != maxi)
        {
            ans.push_back(nums[maxi]);
            maxi = hash[maxi];
        }
        ans.push_back(nums[maxi]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};