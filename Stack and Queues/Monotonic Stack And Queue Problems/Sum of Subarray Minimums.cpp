// Better Approch

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        long long ans = 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            int mini = INT_MAX;
            for (int j = i; j < n; j++)
            {
                mini = min(mini, arr[j]);
                ans = (ans + mini) % MOD;
            }
        }
        return (int)ans;
    }
};