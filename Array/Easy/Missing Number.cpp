class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int x1 = 0, x2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            x1 = x1 ^ (nums[i]);
            x2 = x2 ^ i;
        }
        x2 = x2 ^ n;
        return x1 ^ x2;
    }

    int missingNumber(vector<int> &a, int N)
    {
        // Write your code here.
        int s = 0;
        for (int i = 0; i < a.size(); i++)
        {
            s += a[i];
        }
        return ((N * (N + 1) / 2) - s);
    }
};