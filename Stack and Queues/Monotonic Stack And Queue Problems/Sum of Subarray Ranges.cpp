// Brute Approch

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int mini = nums[i], maxi = maxi = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                cnt += maxi - mini;
            }
        }
        return cnt;
    }
};